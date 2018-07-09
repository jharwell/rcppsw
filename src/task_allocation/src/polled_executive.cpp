/**
 * @file polled_executive.cpp
 *
 * @copyright 2017 John Harwell, All rights reserved.
 *
 * This file is part of RCPPSW.
 *
 * RCPPSW is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * RCPPSW is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * RCPPSW.  If not, see <http://www.gnu.org/licenses/
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/task_allocation/polled_executive.hpp"
#include "rcppsw/task_allocation/partitionable_polled_task.hpp"
#include "rcppsw/task_allocation/polled_task.hpp"
#include "rcppsw/task_allocation/task_decomposition_graph.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void polled_executive::run(void) {
  if (nullptr == executive::current_task()) {
    /*
     * When starting a partitionable task for the first time, we need to update
     * its partition probability so that if the task (or any of its children)
     * have not been executed before, we get a partition probability of 0.5,
     * rather than the 0 we get if we do not do this.
     */
    if (executive::root_task()->is_partitionable() &&
        !executive::root_task()->is_atomic()) {
      auto p = std::static_pointer_cast<partitionable_polled_task>(
          executive::root_task());
      std::vector<task_graph_vertex> kids = graph()->children(p);
      ER_ASSERT(2 == kids.size(),
                "FATAL: Non-atomic partitionable task has %zu kids (expected %d)",
                kids.size(), 2);
      p->update_partition_prob(p->exec_estimate(), kids[0]->exec_estimate(),
                               kids[1]->exec_estimate());
    }

    handle_task_start(executive::get_next_task(nullptr));
  }
  auto current =
      std::static_pointer_cast<polled_task>(executive::current_task());
  ER_ASSERT(current, "FATAL: polled_executive can only work with polled tasks");

  if (current->task_finished()) {
    ER_NOM("Task '%s' finished", current->name().c_str());
    handle_task_finish(current);
  } else {
    double prob = executive::task_abort_prob(current);
    ER_VER("Task '%s' abort probability: %f", current->name().c_str(), prob);

    if (static_cast<double>(random()) / RAND_MAX <= prob) {
      ER_NOM("Task '%s' aborted", current->name().c_str());
      handle_task_abort(current);
    } else {
      current->task_execute();
      current->update_exec_time();
      current->update_interface_time();
    }
  }
} /* run() */

void polled_executive::handle_task_abort(task_graph_vertex task) {
  task->update_exec_time();
  task->update_exec_estimate(task->exec_time());
  task->reset_exec_time();
  task->update_exec_time();
  task->reset_interface_time();
  task->update_interface_time();

  task_graph_vertex update = nullptr;
  auto partitionable =
      std::static_pointer_cast<partitionable_polled_task>(task);
  if (!task->is_partitionable()) {
    partitionable = std::static_pointer_cast<partitionable_polled_task>(
        task_decomposition_graph::vertex_parent(graph(), task));
    partitionable->last_partition(task);
  }
  std::vector<task_graph_vertex> kids = graph()->children(partitionable);
  partitionable->update_partition_prob(partitionable->exec_estimate(),
                                       kids[0]->exec_estimate(),
                                       kids[1]->exec_estimate());

  if (executive::task_abort_cleanup()) {
    executive::task_abort_cleanup()(task);
  }
  auto polled = std::dynamic_pointer_cast<polled_task>(task);
  polled->task_reset();
  task = executive::get_next_task(task);
  handle_task_start(task);
} /* handle_task_abort() */

void polled_executive::handle_task_finish(task_graph_vertex task) {
  task->update_exec_time();
  task->update_exec_estimate(task->exec_time());

  if (executive::task_finish_notify()) {
    executive::task_finish_notify()(task);
  }

  task->reset_exec_time();
  task->update_exec_time();
  task->reset_interface_time();
  task->update_interface_time();

  task_graph_vertex update = nullptr;
  auto partitionable =
      std::static_pointer_cast<partitionable_polled_task>(task);
  if (!task->is_partitionable()) {
    partitionable = std::static_pointer_cast<partitionable_polled_task>(
        task_decomposition_graph::vertex_parent(graph(), task));
    partitionable->last_partition(task);
  }
  std::vector<task_graph_vertex> kids = graph()->children(partitionable);
  partitionable->update_partition_prob(partitionable->exec_estimate(),
                                       kids[0]->exec_estimate(),
                                       kids[1]->exec_estimate());

  task = executive::get_next_task(task);
  handle_task_start(task);
  task->task_execute();
} /* handle_task_finish() */

void polled_executive::handle_task_start(task_graph_vertex new_task) {
  ER_NOM("Starting new task '%s'", new_task->name().c_str());

  if (executive::task_alloc_notify()) {
    executive::task_alloc_notify()(new_task);
  }

  auto polled = std::dynamic_pointer_cast<polled_task>(new_task);
  ER_ASSERT(!(polled->is_atomic() && polled->is_partitionable()),
            "FATAL: Task %s cannot be both atomic and partitionable",
            polled->name().c_str());
  polled->task_reset();
  polled->task_start(nullptr);
  polled->reset_exec_time();
  current_task(polled);
} /* handle_task_start() */

NS_END(task_allocation, rcppsw);
