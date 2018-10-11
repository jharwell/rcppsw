/**
 * @file bi_tdgraph_executive.cpp
 *
 * @copyright 2018 John Harwell, All rights reserved.
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
#include "rcppsw/task_allocation/bi_tdgraph_executive.hpp"
#include "rcppsw/task_allocation/bi_tdgraph.hpp"
#include "rcppsw/task_allocation/partitionable_polled_task.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
bi_tdgraph_executive::bi_tdgraph_executive(
    bool update_exec_ests,
    bi_tdgraph *const graph)
    : base_executive(update_exec_ests, graph),
      ER_CLIENT_INIT("rcppsw.ta.executive.bi_tdgraph") {
  auto bigraph = static_cast<bi_tdgraph *>(base_executive::graph());
  bigraph->install_cb(this);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
__rcsw_pure const bi_tab *
bi_tdgraph_executive::active_tab(void) const {
  auto bigraph = static_cast<const bi_tdgraph *>(graph());
  return bigraph->active_tab();
} /* active_tab() */

void bi_tdgraph_executive::run(void) {
  if (nullptr == current_task()) {
    /*
     * When starting a partitionable task for the first time, we need to update
     * its partition probability so that if the task (or any of its children)
     * have not been executed before, we get a partition probability of 0.5,
     * rather than the 0 we get if we do not do this.
     */
    if (root_task()->is_partitionable() && !root_task()->is_atomic()) {
      auto p = static_cast<partitionable_polled_task *>(root_task());
      auto kids = graph()->children(p);
      ER_ASSERT(3 == kids.size(),
                "Non-atomic partitionable task has %zu kids (expected %d)",
                kids.size(), 3);
      p->update_partition_prob(p->task_exec_estimate(),
                               kids[1]->task_exec_estimate(),
                               kids[2]->task_exec_estimate());
    }

    handle_task_start(get_next_task(nullptr));
  }

  if (current_task()->task_finished()) {
    ER_INFO("Task '%s' finished", current_task()->name().c_str());
    handle_task_finish(current_task());
  } else {
    double prob = task_abort_prob(current_task());
    ER_TRACE("Task '%s' abort probability: %f", current_task()->name().c_str(),
             prob);

    if (static_cast<double>(std::rand()) / RAND_MAX <= prob) {
      ER_INFO("Task '%s' aborted", current_task()->name().c_str());
      handle_task_abort(current_task());
    } else {
      current_task()->task_execute();
      current_task()->update_exec_time();
      current_task()->update_interface_time();
    }
  }
} /* run() */

void bi_tdgraph_executive::handle_task_abort(polled_task *task) {
  task->task_aborted(true);
  for (auto cb : task_abort_notify()) {
    cb(task);
  } /* for(cb..) */

  task->update_exec_time();
  if (update_exec_ests()) {
    task->update_exec_estimate(task->exec_time());
  }
  task->reset_exec_time();
  task->update_exec_time();
  task->reset_interface_time();
  task->update_interface_time();

  /* task partition probability still updated even on abort */
  update_task_partition_prob(
      task->is_partitionable() ? task : tdgraph::vertex_parent(*graph(), task));

  /*
   * Among other things: handle the setting of the last partition of whatever
   * partitionable task the aborted one was a child of.
   */

  task->task_aborted(false); /* already been handled by callback */

  task->task_reset();
  task = get_next_task(task);
  handle_task_start(task);
} /* handle_task_abort() */

void bi_tdgraph_executive::handle_task_finish(polled_task *task) {
  for (auto cb : task_finish_notify()) {
    cb(task);
  } /* for(cb..) */

  task->update_exec_time();
  if (update_exec_ests()) {
    task->update_exec_estimate(task->exec_time());
  }

  task->reset_exec_time();
  task->update_exec_time();
  task->reset_interface_time();
  task->update_interface_time();

  update_task_partition_prob(
      task->is_partitionable() ? task : tdgraph::vertex_parent(*graph(), task));

  task = get_next_task(task);
  handle_task_start(task);
  task->task_execute();
} /* handle_task_finish() */

void bi_tdgraph_executive::handle_task_start(polled_task *new_task) {
  ER_INFO("Starting new task '%s'", new_task->name().c_str());

  for (auto cb : m_task_alloc_notify) {
    cb(new_task, active_tab());
  } /* for(cb..) */

  ER_ASSERT(!(new_task->is_atomic() && new_task->is_partitionable()),
            "Task %s cannot be both atomic and partitionable",
            new_task->name().c_str());
  new_task->task_reset();
  new_task->task_start(nullptr);
  new_task->reset_exec_time();
  current_task(new_task);
} /* handle_task_start() */

void bi_tdgraph_executive::update_task_partition_prob(
    polled_task *task) {
  ER_ASSERT(task->is_partitionable(),
            "Cannot update partition probability of non-partitionable task");
  std::vector<polled_task *> kids = graph()->children(task);

  if (task == graph()->root()) {
    static_cast<partitionable_polled_task *>(task)->update_partition_prob(
        task->task_exec_estimate(),
        kids[1]->task_exec_estimate(),
        kids[2]->task_exec_estimate());
  } else {
    static_cast<partitionable_polled_task *>(task)->update_partition_prob(
        task->task_exec_estimate(),
        kids[0]->task_exec_estimate(),
        kids[1]->task_exec_estimate());
  }
} /* update_task_partition_prob() */


polled_task *bi_tdgraph_executive::do_get_next_task(void) {
  /*
   * Update our active TAB so that we perform partitioning from the correct
   * place.
   */
  auto bigraph = static_cast<bi_tdgraph *>(graph());
  bigraph->active_tab_update(current_task());
  auto partitionable = dynamic_cast<partitionable_task *>(
      bigraph->active_tab()->root());
  ER_ASSERT(nullptr != partitionable,
            "Task %s not partitionable",
            active_tab()->root()->name().c_str())
      std::vector<polled_task *> kids = graph()->children(active_tab()->root());
  if (active_tab()->root() == graph()->root()) {
    return partitionable->task_allocate(kids[1], kids[2]);
  } else {
    return partitionable->task_allocate(kids[0], kids[1]);
  }
} /* do_get_next_task() */

NS_END(task_allocation, rcppsw);
