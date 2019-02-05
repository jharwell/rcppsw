/**
 * @file subtask_sel_probability.cpp
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
#include "rcppsw/task_allocation/subtask_sel_probability.hpp"
#include "rcppsw/task_allocation/sigmoid_sel_params.hpp"
#include "rcppsw/task_allocation/time_estimate.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Constants
 ******************************************************************************/
constexpr char subtask_sel_probability::kMethodBrutschy2014[];
constexpr char subtask_sel_probability::kMethodHarwell2018[];
constexpr char subtask_sel_probability::kMethodRandom[];

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
subtask_sel_probability::subtask_sel_probability(std::string method)
    : ER_CLIENT_INIT("rcppsw.ta.subtask_sel_prob"),
      sigmoid(),
      mc_method(std::move(method)) {
  if (kMethodHarwell2018 == method) {
    sigmoid::init(kHARWELL2018_REACTIVITY,
                   kHARWELL2018_OFFSET,
                   kHARWELL2018_GAMMA);
  } else if (kMethodBrutschy2014 == method) {
    sigmoid::init(kBRUTSCHY2014_REACTIVITY,
                   kBRUTSCHY2014_OFFSET,
                   kBRUTSCHY2014_GAMMA);
  } else if (kMethodRandom == method) {}
  ER_FATAL_SENTINEL("Bad method '%s' selected", method.c_str());
}

subtask_sel_probability::subtask_sel_probability(
    const struct sigmoid_sel_params *const params)
    : ER_CLIENT_INIT("rcppsw.ta.subtask_sel_prob"),
      sigmoid(&params->sigmoid),
      mc_method(params->method) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
__rcsw_const double subtask_sel_probability::calc_random(void) {
  return 0.5;
} /* calc_random() */

__rcsw_pure double subtask_sel_probability::calc_brutschy2014(
    const time_estimate &int_est1, const time_estimate &int_est2) {
  return calc_sigmoid(int_est1, int_est2);
} /* calc_brutschy2014() */

__rcsw_pure double subtask_sel_probability::calc_harwell2018(
    const time_estimate &exec_est1, const time_estimate &exec_est2) {
  return calc_sigmoid(exec_est2, exec_est1);
} /* calc_harwell2018() */

__rcsw_pure double
subtask_sel_probability::calc_sigmoid(const time_estimate &est1,
                                            const time_estimate &est2) {
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
  double theta = reactivity() * (est1.last_result() / r_ss - offset());
  return set_result(1.0 / (1 + std::exp(-theta)) * gamma());
} /* calc_sigmoid() */

double subtask_sel_probability::operator()(const time_estimate *subtask1,
                                                 const time_estimate *subtask2) {
  if (kMethodBrutschy2014 == mc_method) {
    return calc_brutschy2014(*subtask1, *subtask2);
  } else if (kMethodHarwell2018 == mc_method) {
    return calc_harwell2018(*subtask1, *subtask2);
  } else if (kMethodRandom == mc_method) {
    return calc_random();
  }
  ER_FATAL_SENTINEL("Bad method '%s' selected", mc_method.c_str());
  return 0.0;
} /* operator() */

NS_END(task_allocation, rcppsw);
