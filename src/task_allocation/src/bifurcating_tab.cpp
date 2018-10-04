/**
 * @file bifurcating_tab.cpp
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
#include "rcppsw/task_allocation/bifurcating_tab.hpp"
#include <cassert>

#include "rcppsw/task_allocation/partitionable_task.hpp"
#include "rcppsw/task_allocation/polled_task.hpp"
#include "rcppsw/task_allocation/bifurcating_tdgraph.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
bifurcating_tab::bifurcating_tab(const bifurcating_tdgraph* const graph,
                                 const polled_task *const root,
                                 const polled_task *const child1,
                                 const polled_task *const child2)
    : ER_CLIENT_INIT("rcppsw.ta.bifurcating_tab"),
      mc_graph(graph), m_root(root), m_child1(child1), m_child2(child2) {
  ER_ASSERT(m_root->is_partitionable(), "Root task not partitionable");
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void bifurcating_tab::change_active_task(const polled_task *const active_task) {
  if (nullptr != active_task) {
    ER_ASSERT(this->contains_task(active_task),
              "New active task '%s' not in TAB",
              active_task->name().c_str());
  }
  m_last_task = m_active_task;
  m_active_task = active_task;
} /* change_active_task() */

__rcsw_pure bool
bifurcating_tab::contains_task(const polled_task *const task) const {
  return task == m_root || task == m_child1 || task == m_child2;
} /* contains_task() */

__rcsw_pure bool
bifurcating_tab::task_is_root(const polled_task *const task) const {
  return task == m_root;
} /* task_is_root() */

__rcsw_pure bool
bifurcating_tab::task_is_child(const polled_task *const task) const {
  return task == m_child1 || task == m_child2;
} /* task_is_child() */

/*******************************************************************************
 * TAB Metrics
 ******************************************************************************/
bool bifurcating_tab::employed_partitioning(void) const {
  return dynamic_cast<const partitionable_task *>(m_root)
      ->employed_partitioning();
} /* employed_partitioning() */

bool bifurcating_tab::task_depth_changed(void) const {
  if (nullptr == m_last_task) {
    return true; /* first allocation */
  }
  return mc_graph->vertex_depth(m_active_task) !=
      mc_graph->vertex_depth(m_last_task);
} /* task_depth_changed() */

double bifurcating_tab::root_partition_prob(void) const {
  return dynamic_cast<const partitionable_task*>(m_root)->partition_prob();
} /* root_partition_prob() */

double bifurcating_tab::root_subtask_selection_prob(void) const {
  return dynamic_cast<const partitionable_task*>(m_root)->subtask_selection_prob();
} /* root_subtask_selection_prob() */


NS_END(task_allocation, rcppsw);
