/**
 * @file abort_probability.cpp
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
#include "rcppsw/task_allocation/abort_probability.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
double abort_probability::calc(double exec_time,
                               const time_estimate& whole_task) {
  double omega;
  if (!(whole_task.last_result() > 0)) {
    omega = -m_reactivity * m_proportionality;
  } else {
    if (exec_time/whole_task.last_result() <= -m_offset) {
      omega = -m_reactivity * (exec_time/whole_task.last_result() + m_offset);
    } else {
      omega = -m_reactivity * (-m_offset - exec_time/whole_task.last_result());
    }
  }
  return set_result(1 - std::exp(-omega));
} /* calc() */

NS_END(task_allocation, rcppsw);
