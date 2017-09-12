/**
 * @file base_task.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_BASE_TASK_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_BASE_TASK_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "rcppsw/common/common.hpp"
#include "rcppsw/task_allocation/time_estimate.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class base_task {
 public:
  explicit base_task(const std::string& name, double estimate_alpha):
      m_exec_time(0.0), m_name(name), m_estimate(estimate_alpha) {}
  const std::string& name(void) const { return m_name; }
  const time_estimate& estimate(void) const { return m_estimate; }
  void update_estimate(double last_measure) { m_estimate.calc(last_measure); }
  double exec_time(void) const { return m_exec_time; }
  void update_exec_time(double exec_time) { m_exec_time = exec_time; }

 private:
  double m_exec_time;
  std::string m_name;
  time_estimate m_estimate;
};

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
typedef base_task atomic_task;

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_BASE_TASK_HPP_ */
