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
#include <cassert>
#include <cmath>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Constants
 ******************************************************************************/
constexpr char subtask_selection_probability::kBrutschy2014[];
constexpr char subtask_selection_probability::kHarwell2018[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void subtask_selection_probability::init_sigmoid(double reactivity,
                                                 double offset,
                                                 double gamma) {
  m_reactivity = reactivity;
  m_offset = offset;
  m_gamma = gamma;
} /* init_sigmoid() */

double subtask_selection_probability::calc(const time_estimate* subtask1,
                                           const time_estimate* subtask2) {
  if ("brutschy2014" == mc_method) {
    return calc_brutschy2014(*subtask1, *subtask2);
  } else if ("harwell2018" == mc_method) {
      return calc_harwell2018(*subtask1, *subtask2);
  } else if ("random" == mc_method) {
    return calc_random();
  }
  assert(false);
  return 0.0;
} /* calc() */

__const double subtask_selection_probability::calc_random(void) {
  return 0.5;
} /* calc_random() */

double subtask_selection_probability::calc_brutschy2014(
    const time_estimate& int_est1,
    const time_estimate& int_est2) {
  return calc_sigmoid(int_est1, int_est2);
} /* calc_brutschy2014() */

double subtask_selection_probability::calc_harwell2018(
    const time_estimate& exec_est1,
    const time_estimate& exec_est2) {
  return calc_sigmoid(exec_est2, exec_est1);
} /* calc_harwell2018() */

double subtask_selection_probability::calc_sigmoid(
    const time_estimate& est1,
    const time_estimate& est2) {
  /*
   * No information available--just pick randomly.
   */
  if (!(est1.last_result() > 0 && est2.last_result() > 0)) {
    return 0.5;
  } else if (!(est1.last_result() > 0)) { /* have info on est2 only */
    return 0.0;
  } else if (!(est2.last_result() > 0)) { /* have info on est1 only */
    return 1.0;
  }

  double r_ss = 0;
  if (est1 > est2) {
    r_ss = std::pow(est1.last_result(), 2) / est2.last_result();
  } else {
    r_ss = est1.last_result();
  }

  double tmp = 1.0 / m_reactivity * (est1.last_result() / r_ss - m_offset);
  return 1.0 / (1 + exp(-tmp)) * m_gamma;
} /* calc_sigmoid() */

NS_END(task_allocation, rcppsw);
