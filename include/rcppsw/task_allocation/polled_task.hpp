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
#include "rcppsw/task_allocation/taskable.hpp"

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
class polled_task : public logical_task, public taskable {
 public:
  polled_task(const std::string& name, double estimate_alpha,
              taskable* const mechanism,
              polled_task* const parent = nullptr) :
      logical_task(name, estimate_alpha, parent), m_mechanism(mechanism) {}
  virtual ~polled_task(void) {}

  taskable* mechanism(void) const { return m_mechanism; }

  void task_execute(void) override { m_mechanism->task_execute(); }
  void task_reset(void) override { m_mechanism->task_reset(); }
  bool task_finished(void) const override { return m_mechanism->task_finished(); }

 private:
  taskable * const m_mechanism;
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_POLLED_TASK_HPP_ */
