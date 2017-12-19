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
executive::executive(const std::shared_ptr<rcppsw::er::server>& server,
                     executable_task* root)
    : client(server),
      m_current_task(nullptr),
      m_task_abort_cleanup(nullptr),
      mc_root(root) {
  client::insmod("task_executive",
                 rcppsw::er::er_lvl::DIAG,
                 rcppsw::er::er_lvl::NOM);
      }

executive::~executive(void) = default;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void executive::task_abort_cleanup(
    std::function<void(executable_task* const)> cb) {
  m_task_abort_cleanup = std::move(cb);
} /* task_abort_cleanup() */

const std::function<void(executable_task* const)>& executive::task_abort_cleanup(
    void) const {
  return m_task_abort_cleanup;
} /* task_abort_cleanup() */

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
    if (mc_root->is_atomic()) {
      return mc_root;
    }
    /*
     * The root IS partitionable, so partition it and (possibly) return a
     * subtask.
     */
    return mc_root->partition();
  }
  ER_ASSERT(m_current_task->parent(), "FATAL: All tasks must have a parent");
  if (!m_current_task->is_partitionable()) {
    if (m_current_task->parent() != m_current_task) {
      ER_ASSERT(static_cast<executable_task*>(m_current_task->parent())
                    ->is_partitionable(),
                "FATAL: Non-partitionable tasks must have a partitionable "
                "parent");
      return static_cast<executable_task*>(m_current_task->parent())->partition();
    }
    /* single atomic task in hierarchy */
    return static_cast<executable_task*>(m_current_task);
  } else {
    return m_current_task->partition();
  }
} /* get_next_task() */

double executive::task_abort_prob(executable_task* task) {
  if (task->is_atomic()) {
    return 0.0;
  }
  return task->calc_abort_prob();
} /* task_abort_prob() */

NS_END(task_allocation, rcppsw);
