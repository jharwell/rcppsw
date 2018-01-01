/**
 * @file taskable.hpp
 * @ingroup task_allocation
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_TASKABLE_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_TASKABLE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Decls
 ******************************************************************************/
class taskable_argument;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A class that all classes wishing to be used as the mechanism by which
 * \ref executable_task objects execute themselves must inherit from.
 */
class taskable {
 public:
  taskable(void) = default;
  virtual ~taskable(void);

  /**
   * @brief Execute the task.
   */
  virtual void task_execute(void) = 0;

  /**
   * @brief Determine if the task has finished yet.
   *
   * @return \c TRUE if the task has finished, and \c FALSE otherwise.
   */
  virtual bool task_finished(void) const = 0;

  /**
   * @brief Determine if the task has is still running yet.
   *
   * @return \c TRUE if the task is still running, and \c FALSE otherwise.
   */
  virtual bool task_running(void) const = 0;

  /**
   * @brief Reset the task so that it is ready for execution again. Does nothing
   * by default.
   */
  virtual void task_reset(void) {}

  /**
   * @brief Start the task with the specified argument.
   */
  virtual void task_start(__unused const taskable_argument* c_arg) = 0;
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_TASKABLE_HPP_ */
