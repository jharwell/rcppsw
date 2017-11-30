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

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
executive::~executive(void) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
executable_task* executive::get_next_task(executable_task* last_task) {
  /*
   * We are being run for the first time, so run the partitioning algorithm on
   * the root of the tree.
   */
  if (nullptr == last_task) {
    /*
     * The root was not partitionable, so we only have 1 choice for the next
     * task.
     */
    if (m_root->is_atomic()) {
      return m_root;
    }
    /*
     * The root IS partitionable, so partition it and (possibly) return a
     * subtask.
     */
    return m_root->partition();
  }
  ER_ASSERT(m_current_task->parent(), "FATAL: All tasks must have a parent");
  if (!m_current_task->is_partitionable()) {
    if (m_current_task->parent() != m_current_task) {
      ER_ASSERT(static_cast<executable_task*>(m_current_task->parent())->is_partitionable(),
                "FATAL: Non-partitionable tasks must have a partitionable parent");
      return static_cast<executable_task*>(m_current_task->parent())->partition();
    } else { /* single atomic task in hierarchy */
      return static_cast<executable_task*>(m_current_task);
    }
  } else {
    return m_current_task->partition();
  }
} /* get_next_task() */

double executive::task_abort_prob(const executable_task* const task) {
  if (task->is_atomic()) {
    return 0.0;
  } else {
    return static_cast<executable_task*>(task->parent())->calc_abort_prob();
  }
} /* task_abort_prob() */

NS_END(task_allocation, rcppsw);
