/**
 * @file polled_task.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_POLLED_TASK_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_POLLED_TASK_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "rcppsw/task_allocation/logical_task.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Represents a task whose execution can/should be monitored by the user
 * to determine when it has finished.
 */
class polled_task : public logical_task {
 public:
  polled_task(const std::string& name, polled_task* const parent,
              double estimate_alpha) :
      logical_task(name, parent, estimate_alpha) {}

  virtual ~polled_task(void) {}

  /**
   * @brief Reset the task so that it is ready for execution again.
   */
  virtual void task_reset(void) {}

  /**
   * @brief Execute the task.
   *
   */
  virtual void task_execute(void) = 0;

  /**
   * @brief Determine if the task has finished yet.
   *
   * @return TRUE if the task has finished, and FALSE otherwise.
   */
  virtual bool task_finished(void) = 0;
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_POLLED_TASK_HPP_ */
