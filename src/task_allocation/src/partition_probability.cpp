/**
 * @file partition_probability.cpp
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
#include "rcppsw/task_allocation/partition_probability.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
double partition_probability::calc(const time_estimate& task_estimate,
                                   const time_estimate& subtask1_estimate,
                                   const time_estimate& subtask2_estimate) {
  if (task_estimate > subtask1_estimate + subtask2_estimate) {
    double res = 1 + std::exp(
        (-m_reactivity * ((task_estimate /
                           (subtask1_estimate + subtask2_estimate)) - 1.0)).last_result());
    return set_result(1/res);
  } else {
    double tmp = -m_reactivity * (1.0 -
                                  ((subtask1_estimate + subtask2_estimate) /
                                   (std::max(task_estimate.last_result(), 1.0)))).last_result();
    return set_result(1.0/(1.0 + std::exp(tmp)));
  }
} /* calc() */

NS_END(task_allocation, rcppsw);
