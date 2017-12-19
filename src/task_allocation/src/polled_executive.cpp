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
    if (executive::root()->is_partitionable()) {
      auto* p = dynamic_cast<partitionable_polled_task*>(executive::root());
      p->update_partition_prob(p->exec_estimate(),
                               p->partition1()->exec_estimate(),
                               p->partition1()->exec_estimate());
    }

    handle_task_start(
        static_cast<polled_task*>(executive::get_next_task(nullptr)));
  }
  auto* current = dynamic_cast<polled_task*>(executive::current_task());
  ER_ASSERT(current, "FATAL: polled_executive can only work with polled tasks");

  if (current->task_finished()) {
    ER_NOM("Task '%s' finished", current->name().c_str());
    handle_task_finish(current);
  } else {
    double prob = executive::task_abort_prob(current);
    ER_VER("Task '%s' abort probability: %f", current->name().c_str(), prob);

    if (static_cast<double>(rand()) / RAND_MAX <= prob) {
      ER_NOM("Task '%s' aborted", current->name().c_str());
      handle_task_abort(current);
    } else {
      current->task_execute();
      current->update_exec_time();
      current->update_interface_time();
    }
  }
} /* run() */

void polled_executive::handle_task_abort(polled_task* task) {
  task->update_exec_time();
  task->update_exec_estimate(task->exec_time());
  task->reset_exec_time();
  task->update_exec_time();
  task->reset_interface_time();
  task->update_interface_time();

  partitionable_polled_task* p = nullptr;
  if (!task->is_partitionable()) {
    p = dynamic_cast<partitionable_polled_task*>(task->parent());
    p->last_partition(task);
  } else {
    p = dynamic_cast<partitionable_polled_task*>(task);
  }
  p->update_partition_prob(p->exec_estimate(),
                           p->partition1()->exec_estimate(),
                           p->partition2()->exec_estimate());

  if (executive::task_abort_cleanup()) {
    executive::task_abort_cleanup()(task);
  }
  task->task_reset();
  task = static_cast<polled_task*>(executive::get_next_task(task));
  handle_task_start(task);
} /* handle_task_abort() */

void polled_executive::handle_task_finish(polled_task* task) {
  task->update_exec_time();
  task->update_exec_estimate(task->exec_time());
  task->reset_exec_time();
  task->update_exec_time();
  task->reset_interface_time();
  task->update_interface_time();

  partitionable_polled_task* p = nullptr;
  if (!task->is_partitionable()) {
    p = dynamic_cast<partitionable_polled_task*>(task->parent());
    p->last_partition(task);
  } else {
    p = dynamic_cast<partitionable_polled_task*>(task);
  }
  if (!p->is_atomic()) {
    p->update_partition_prob(p->exec_estimate(),
                             p->partition1()->exec_estimate(),
                             p->partition2()->exec_estimate());
  }
  task = static_cast<polled_task*>(executive::get_next_task(task));

  handle_task_start(task);
  task->task_execute();
} /* handle_task_finish() */

void polled_executive::handle_task_start(polled_task* new_task) {
  ER_NOM("Starting new task '%s'", new_task->name().c_str());

  new_task->task_reset();
  new_task->task_start(nullptr);
  new_task->reset_exec_time();
  current_task(new_task);
} /* handle_task_start() */

NS_END(task_allocation, rcppsw);
