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
  bigraph->active_tab(bigraph->root_tab());

  if (nullptr != bigraph->active_tab()) {
    /*
     * Not needed if a priori execution time estimates are used, but is needed if
     * they are not and the root of the tdgraph is partitionable in order to avoid
     * having a partition probability of 0. Doing this gives you an initial
     * partition probability of 0.5 in that case.
     */
    bigraph->active_tab()->partition_prob_update();
    ER_INFO("Initial TAB rooted at '%s'",
            bigraph->active_tab()->root()->name().c_str());
  }
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
__rcsw_pure const bi_tab * bi_tdgraph_executive::active_tab(void) const {
  auto bigraph = static_cast<const bi_tdgraph *>(graph());
  return bigraph->active_tab();
} /* active_tab() */

void bi_tdgraph_executive::run(void) {
  auto bigraph = static_cast<bi_tdgraph *>(graph());
  /*
   * First timestep of execution/allocation
   */
  if (nullptr == current_task()) {
    /*
     * The root was not partitionable, so we only have 1 choice for the next
     * task.
     */
    if (nullptr == active_tab()) {
      handle_task_start(graph()->root());
      return;
    }
    handle_task_start(bigraph->active_tab()->task_allocate());
    return;
  }

  if (current_task()->task_finished()) {
    ER_INFO("Task '%s' finished", current_task()->name().c_str());
    handle_task_finish(current_task());
    return;
  }

  double prob = task_abort_prob(current_task());
  ER_TRACE("Task '%s' abort probability: %f", current_task()->name().c_str(),
             prob);
  if (static_cast<double>(std::rand()) / RAND_MAX <= prob) {
    ER_INFO("Task '%s' aborted", current_task()->name().c_str());
    handle_task_abort(current_task());
    return;
  }
  current_task()->task_execute();
  current_task()->update_exec_time();
  current_task()->update_interface_time();
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

  /* task partition probability still updated even on abort (for right now)*/
  if (nullptr != active_tab()) {
    auto bigraph = static_cast<bi_tdgraph *>(graph());
    bigraph->active_tab()->partition_prob_update();
  }

  /*
   * Among other things: handle the setting of the last partition of whatever
   * partitionable task the aborted one was a child of.
   */

  task->task_aborted(false); /* already been handled by callback */

  task->task_reset();
  task = get_next_task();
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

  /*
   * If the root was atomic then there is no need to updating partitioning
   * probability
   */
  if (nullptr != active_tab()) {
    auto bigraph = static_cast<bi_tdgraph *>(graph());
    bigraph->active_tab()->partition_prob_update();
  }

  task = get_next_task();
  handle_task_start(task);
  task->task_execute();
} /* handle_task_finish() */

void bi_tdgraph_executive::handle_task_start(polled_task *new_task) {
  ER_INFO("Starting new task '%s'", new_task->name().c_str());

  for (auto cb : m_task_alloc_notify) {
    cb(new_task, active_tab());
  } /* for(cb..) */

  new_task->task_reset();
  new_task->task_start(nullptr);
  new_task->reset_exec_time();
  current_task(new_task);
} /* handle_task_start() */

polled_task *bi_tdgraph_executive::get_next_task(void) {
  /*
   * Update our active TAB so that we perform partitioning from the correct
   * place.
   */
  auto bigraph = static_cast<bi_tdgraph *>(graph());
  bigraph->active_tab_update(current_task());
  std::vector<polled_task *> kids = graph()->children(active_tab()->root());
  return bigraph->active_tab()->task_allocate();
} /* get_next_task() */

NS_END(task_allocation, rcppsw);
