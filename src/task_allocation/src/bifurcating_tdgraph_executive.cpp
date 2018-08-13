/**
 * @file bifurcating_tdgraph_executive.cpp
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
#include "rcppsw/task_allocation/bifurcating_tdgraph_executive.hpp"
#include "rcppsw/task_allocation/partitionable_polled_task.hpp"
#include "rcppsw/task_allocation/bifurcating_tdgraph.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
bifurcating_tdgraph_executive::bifurcating_tdgraph_executive(
    std::shared_ptr<rcppsw::er::server>& server,
    bifurcating_tdgraph* const graph)
    : base_executive(server, graph) {}


/*******************************************************************************
 * Member Functions
 ******************************************************************************/
__rcsw_pure const bifurcating_tab* bifurcating_tdgraph_executive::active_tab(void) const {
  auto bigraph = static_cast<const bifurcating_tdgraph*>(graph());
  return bigraph->active_tab();
} /* active_tab() */

void bifurcating_tdgraph_executive::run(void) {
  if (nullptr == current_task()) {
    /*
     * When starting a partitionable task for the first time, we need to update
     * its partition probability so that if the task (or any of its children)
     * have not been executed before, we get a partition probability of 0.5,
     * rather than the 0 we get if we do not do this.
     */
    if (root_task()->is_partitionable() &&
        !root_task()->is_atomic()) {
      auto p = static_cast<partitionable_polled_task*>(root_task());
      auto kids = graph()->children(p);
      ER_ASSERT(2 == kids.size(),
                "FATAL: Non-atomic partitionable task has %zu kids (expected %d)",
                kids.size(), 2);
      p->update_partition_prob(p->exec_estimate(), kids[0]->exec_estimate(),
                               kids[1]->exec_estimate());
    }

    handle_task_start(get_next_task(nullptr));
  }

  if (current_task()->task_finished()) {
    ER_NOM("Task '%s' finished", current_task()->name().c_str());
    handle_task_finish(current_task());
  } else {
    double prob = task_abort_prob(current_task());
    ER_VER("Task '%s' abort probability: %f", current_task()->name().c_str(), prob);

    if (static_cast<double>(std::rand()) / RAND_MAX <= prob) {
      ER_NOM("Task '%s' aborted", current_task()->name().c_str());
      handle_task_abort(current_task());
    } else {
      current_task()->task_execute();
      current_task()->update_exec_time();
      current_task()->update_interface_time();
    }
  }
} /* run() */

void bifurcating_tdgraph_executive::handle_task_abort(polled_task* task) {
  task->update_exec_time();
  task->update_exec_estimate(task->exec_time());
  task->reset_exec_time();
  task->update_exec_time();
  task->reset_interface_time();
  task->update_interface_time();
  task->task_aborted(true);

  /* task partition probability still updated even on abort */
  update_task_partition_prob(task->is_partitionable() ? task:
                             tdgraph::vertex_parent(*graph(), task));

  /*
   * Among other things: handle the setting of the last partition of whatever
   * partitionable task the aborted one was a child of.
   */
  for (auto cb : task_abort_cleanup()) {
    cb(task);
  } /* for(cb..) */

  task->task_aborted(false); /* already been handled by callback */

  task->task_reset();
  task = get_next_task(task);
  handle_task_start(task);
} /* handle_task_abort() */

void bifurcating_tdgraph_executive::handle_task_finish(polled_task* task) {
  task->update_exec_time();
  task->update_exec_estimate(task->exec_time());

  for (auto cb : task_finish_notify()) {
    cb(task);
  } /* for(cb..) */

  task->reset_exec_time();
  task->update_exec_time();
  task->reset_interface_time();
  task->update_interface_time();

  update_task_partition_prob(task->is_partitionable()? task:
                             tdgraph::vertex_parent(*graph(), task));

  task = get_next_task(task);
  handle_task_start(task);
  task->task_execute();
} /* handle_task_finish() */

void bifurcating_tdgraph_executive::handle_task_start(polled_task* new_task) {
  ER_NOM("Starting new task '%s'", new_task->name().c_str());

  for (auto cb : task_alloc_notify()) {
    cb(new_task);
  } /* for(cb..) */

  ER_ASSERT(!(new_task->is_atomic() && new_task->is_partitionable()),
            "FATAL: Task %s cannot be both atomic and partitionable",
            new_task->name().c_str());
  new_task->task_reset();
  new_task->task_start(nullptr);
  new_task->reset_exec_time();
  current_task(new_task);
} /* handle_task_start() */

void bifurcating_tdgraph_executive::update_task_partition_prob(
    polled_task* task) {
  ER_ASSERT(task->is_partitionable(),
            "FATAL: Cannot update partition probability of non-partitionable task");
  std::vector<polled_task*> kids = graph()->children(task);
  static_cast<partitionable_polled_task*>(task)->update_partition_prob(
      task->exec_estimate(),
      kids[0]->exec_estimate(),
      kids[1]->exec_estimate());
} /* update_task_partition_prob() */

polled_task* bifurcating_tdgraph_executive::do_get_next_task(void) {
  /* leaf of tree--perform partitioning at the parent */
  if (!current_task()->is_partitionable()) {
    return next_task_from_partitionable(tdgraph::vertex_parent(*graph(),
                                                               current_task()));
  }

  /*
   * Current task not leaf of tree. If it is the root task of the active TAB,
   * then perform partitioning with it. If it is a child task of the active TAB,
   * then perform partitioning with its parent. This allows for tasks that have
   * non-singular parents AND children to behave properly during execution in
   * terms of allocation.
   */
  auto bigraph = static_cast<bifurcating_tdgraph*>(graph());
  if (bigraph->active_tab()->task_is_child(current_task())) {
    return next_task_from_partitionable(tdgraph::vertex_parent(*graph(),
                                                               current_task()));
  }
  ER_FATAL_SENTINEL("FATAL: Task is neither leaf nor child of TAB?");
  return nullptr;
} /* do_get_next_task() */

polled_task* bifurcating_tdgraph_executive::next_task_from_partitionable(
    const polled_task* task) {
  auto partitionable = dynamic_cast<partitionable_task*>(
      tdgraph::vertex_parent(*graph(), task));
  std::vector<polled_task*> kids = graph()->children(task);
  if (task == graph()->root()) {
    return partitionable->partition(kids[1], kids[2]);
  } else {
    return partitionable->partition(kids[0], kids[1]);
  }
} /* next_task_from_partitionable() */

NS_END(task_allocation, rcppsw);
