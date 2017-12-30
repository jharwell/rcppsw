/**
 * @file subtask_selection_probability.cpp
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
#include "rcppsw/task_allocation/subtask_selection_probability.hpp"
#include <assert.h>
#include <cmath>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void subtask_selection_probability::init_brutschy2014(double reactivity,
                                                      double offset,
                                                      double gamma) {
  m_reactivity = reactivity;
  m_offset = offset;
  m_gamma = gamma;
} /* init_() */

double subtask_selection_probability::calc(const time_estimate* subtask1,
                                           const time_estimate* subtask2) {
  if ("brutschy2014" == mc_method) {
    return calc_brutschy2014(*subtask1, *subtask2);
  } else if ("random" == mc_method) {
    return calc_random();
  }
  assert(false);
} /* calc() */

double subtask_selection_probability::calc_random(void) {
  return 0.5;
} /* calc_random() */

double subtask_selection_probability::calc_brutschy2014(
    const time_estimate& subtask1,
    const time_estimate& subtask2) {
  /*
   * No information available--just pick randomly.
   */
  if (!(subtask1.last_result() > 0 && subtask2.last_result() > 0)) {
    return 0.5;
  } else if (!(subtask1.last_result() > 0)) { /* have info on subtask2 only */
    return 0.0;
  } else if (!(subtask2.last_result() > 0)) { /* have info on subtask1 only */
    return 1.0;
  }

  double r_ss = 0;
  if (subtask1 > subtask2) {
    r_ss = std::pow(subtask1.last_result(), 2) / subtask2.last_result();
  } else {
    r_ss = subtask1.last_result();
  }

  double tmp = 1.0 / m_reactivity * (subtask1.last_result() / r_ss - m_offset);
  return 1.0 / (1 + exp(-tmp)) * m_gamma;
} /* calc_brutschy2014() */

NS_END(task_allocation, rcppsw);
