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
#include <cassert>
#include <cmath>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
double partition_probability::calc(const time_estimate& task,
                                   const time_estimate& subtask1,
                                   const time_estimate& subtask2) {
  if ("pini2011" == mc_method) {
    return calc_pini2011(task, subtask1, subtask2);
  }
  assert(false);
} /* calc() */

double partition_probability::calc_pini2011(const time_estimate& task,
                                            const time_estimate& subtask1,
                                            const time_estimate& subtask2) {
  /*
   * If we do not have samples from the task(s) denominator for either case,
   * then we artificially set that term to 0, which yields an exponent of 0, and
   * hence a partition probility of 0.5 (Hence the 2.0).
   */
  double tmp = 2.0;
  if (task > subtask1 + subtask2) {
    if ((subtask1 + subtask2).last_result() > 0) {
      tmp = 1 + std::exp((-m_reactivity * ((task / (subtask1 + subtask2)) - 1.0))
                             .last_result());
    }
    return set_result(1 / tmp);
  } else {
    if (task.last_result() > 0) {
      tmp = -m_reactivity * (1.0 - ((subtask1 + subtask2) / task).last_result());
      tmp = 1.0 + std::exp(tmp);
    }
    return set_result(1.0 / tmp);
  }
} /* calc() */

NS_END(task_allocation, rcppsw);
