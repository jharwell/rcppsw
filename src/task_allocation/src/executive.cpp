/**
 * @file executive.cpp
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
#include "rcppsw/task_allocation/executive.hpp"
#include "rcppsw/task_allocation/partitionable_polled_task.hpp"
#include "rcppsw/task_allocation/partitionable_task.hpp"
#include "rcppsw/task_allocation/task_decomposition_graph.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
executive::executive(const std::shared_ptr<rcppsw::er::server> &server,
                     const std::shared_ptr<task_decomposition_graph> &graph)
    : client(server), m_graph(graph) {
  client::insmod("task_executive", rcppsw::er::er_lvl::DIAG,
                 rcppsw::er::er_lvl::NOM);
}

executive::~executive(void) = default;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
task_graph_vertex executive::get_next_task(const task_graph_vertex &last_task) {
  m_last_task = last_task;
  /*
   * We are being run for the first time, so run the partitioning algorithm on
   * the root of the tree.
   */
  if (nullptr == last_task) {
    return get_first_task();
  }
  ER_ASSERT(task_decomposition_graph::vertex_parent(*m_graph, m_current_task),
            "FATAL: All tasks must have a parent");

  /* Easy case: the current task is partitionable */
  if (m_current_task->is_partitionable()) {
    return get_task_from_partitionable(m_current_task);
  }

  /*
   * Harder case: the current task is not partitionable, so go get its parent,
   * which MUST be partitionable by definition
   */
  if (task_decomposition_graph::vertex_parent(*m_graph, m_current_task) !=
      m_current_task) {
    return get_task_from_non_partitionable(m_current_task);
  }
  /* single atomic task in hierarchy */
  return m_current_task;
} /* get_next_task() */

task_graph_vertex
executive::get_task_from_partitionable(const task_graph_vertex &task) {
  auto partitionable = std::dynamic_pointer_cast<partitionable_task>(
      task_decomposition_graph::vertex_parent(*m_graph, task));
  std::vector<task_graph_vertex> kids = m_graph->children(task);
  if (task == m_graph->root()) {
    return partitionable->partition(kids[1], kids[2]);
  } else {
    return partitionable->partition(kids[0], kids[1]);
  }
} /* get_task_from_partitionable() */

task_graph_vertex
executive::get_task_from_non_partitionable(const task_graph_vertex &task) {
  ER_ASSERT(task_decomposition_graph::vertex_parent(*m_graph, task)
                ->is_partitionable(),
            "FATAL: Non-partitionable tasks must have a partitionable parent");
  auto partitionable = std::dynamic_pointer_cast<partitionable_task>(
      task_decomposition_graph::vertex_parent(*m_graph, task));
  auto executable = std::dynamic_pointer_cast<executable_task>(partitionable);
  std::vector<task_graph_vertex> kids = m_graph->children(executable);
  if (executable == m_graph->root()) {
    return partitionable->partition(kids[1], kids[2]);
  } else {
    return partitionable->partition(kids[0], kids[1]);
  }
} /* get_task_from_non_partitionable() */

task_graph_vertex executive::get_first_task(void) {
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
  auto partitionable =
      std::dynamic_pointer_cast<partitionable_task>(m_graph->root());
  std::vector<task_graph_vertex> kids = m_graph->children(m_graph->root());

  /* +1 for the self-reference */
  ER_ASSERT(3 == kids.size(), "FATAL: Root node does not have 2 children");
  return partitionable->partition(kids[1], kids[2]);
} /* get_first_task() */

void executive::task_init_random(const task_graph_vertex &task, int lb,
                                 int ub) {
  ER_ASSERT(!task->is_partitionable(), "FATAL: Task is partitionable");
  task->init_random(lb, ub);
} /* task_init_random() */

void executive::task_init_random(const task_graph_vertex &task,
                                 const task_graph_vertex &partition, int lb,
                                 int ub) {
  ER_ASSERT(task->is_partitionable(),
            "FATAL: Cannot initialize non-partitionable task last partition");
  auto partitionable =
      std::dynamic_pointer_cast<partitionable_polled_task>(task);
  partitionable->init_random(partition, lb, ub);
} /* task_init_random() */

double executive::task_abort_prob(const task_graph_vertex &task) {
  if (task->is_atomic()) {
    return 0.0;
  }
  return task->calc_abort_prob();
} /* task_abort_prob() */

const task_graph_vertex &executive::root_task(void) const {
  return m_graph->root();
} /* root_task() */

const task_graph_vertex &executive::parent_task(const task_graph_vertex &v) {
  return task_decomposition_graph::vertex_parent(m_graph, v);
} /* parent_task() */

NS_END(task_allocation, rcppsw);
