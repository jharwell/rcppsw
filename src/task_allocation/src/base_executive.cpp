/**
 * @file base_executive.cpp
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
#include "rcppsw/task_allocation/base_executive.hpp"
#include "rcppsw/task_allocation/partitionable_polled_task.hpp"
#include "rcppsw/task_allocation/partitionable_task.hpp"
#include "rcppsw/task_allocation/tdgraph.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
base_executive::base_executive(
    std::shared_ptr<rcppsw::er::server> server,
    tdgraph* const graph)
    : client(server), m_graph(graph) {
  client::insmod("task_base_executive", rcppsw::er::er_lvl::DIAG,
                 rcppsw::er::er_lvl::NOM);
}

base_executive::~base_executive(void) = default;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
polled_task* base_executive::get_next_task(const polled_task* last_task) {
  m_last_task = last_task;
  /*
   * We are being run for the first time, so run the partitioning algorithm on
   * the root of the tree.
   */
  if (nullptr == last_task) {
    return get_first_task();
  }
  ER_ASSERT(tdgraph::vertex_parent(*m_graph, m_current_task),
            "FATAL: All tasks must have a parent");
  return do_get_next_task();
} /* get_next_task() */

polled_task* base_executive::get_first_task(void) {
  /*
   * The root was not partitionable, so we only have 1 choice for the next
   * task.
   */
  if (m_graph->root()->is_atomic()) {
    return m_graph->root();
  }
  /*
   * The root IS partitionable, so partition it and (possibly) return a
   * subtask.
   */
  auto partitionable = dynamic_cast<partitionable_task*>(m_graph->root());
  auto kids = m_graph->children(m_graph->root());

  /* +1 for the self-reference */
  ER_ASSERT(3 == kids.size(), "FATAL: Root node does not have 2 children");
  return partitionable->partition(kids[1], kids[2]);
} /* get_first_task() */

void base_executive::task_init_random(polled_task* task, int lb,
                                 int ub) {
  ER_ASSERT(!task->is_partitionable(), "FATAL: Task is partitionable");
  task->init_random(lb, ub);
} /* task_init_random() */

void base_executive::task_init_random(polled_task* task,
                                           const polled_task* partition, int lb,
                                           int ub) {
  ER_ASSERT(task->is_partitionable(),
            "FATAL: Cannot initialize non-partitionable task last partition");
  auto partitionable = dynamic_cast<partitionable_polled_task*>(task);
  partitionable->init_random(partition, lb, ub);
} /* task_init_random() */

double base_executive::task_abort_prob(polled_task* const task) {
  if (task->is_atomic()) {
    return 0.0;
  }
  return task->calc_abort_prob();
} /* task_abort_prob() */

__rcsw_pure const polled_task* base_executive::root_task(void) const {
  return m_graph->root();
} /* root_task() */

polled_task* base_executive::root_task(void) {
  return m_graph->root();
} /* root_task() */

const polled_task* base_executive::parent_task(const polled_task* v) {
  return tdgraph::vertex_parent(*m_graph, v);
} /* parent_task() */

NS_END(task_allocation, rcppsw);
