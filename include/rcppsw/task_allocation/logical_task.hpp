/**
 * @file logical_task.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_LOGICAL_TASK_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_LOGICAL_TASK_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "rcppsw/task_allocation/time_estimate.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Represents the logical concept of a task, @todo: which is...
 */
class logical_task {
 public:
  explicit logical_task(std::string name,
                        logical_task* parent = nullptr)
      : m_name(std::move(name)), m_parent(parent) {}

  virtual ~logical_task(void);

  logical_task(const logical_task& other) = default;

  /**
   * @brief Get the name of the task
   */
  const std::string& name(void) const { return m_name; }

  /**
   * @brief Get the parent of this task.
   *
   * @return The parent task, or NULL if no parent has been set.
   */
  logical_task* parent(void) const { return m_parent; }

  /**
   * @brief Set the parent for this task.
   */
  void parent(logical_task* parent) { m_parent = parent; }

  logical_task& operator=(const logical_task& other) = delete;

 private:
  std::string m_name;
  logical_task* m_parent;
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_LOGICAL_TASK_HPP_ */
