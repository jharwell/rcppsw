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
#include "rcppsw/ta/partition_probability.hpp"
#include <cmath>
#include "rcppsw/ta/sigmoid_sel_params.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);

/*******************************************************************************
 * Global Variable
 ******************************************************************************/
constexpr char partition_probability::kMethodPini2011[];

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
partition_probability::partition_probability(
    const struct sigmoid_sel_params* params)
    : sigmoid(params->sigmoid.reactivity,
              params->sigmoid.offset,
              params->sigmoid.gamma),
      ER_CLIENT_INIT("rcppsw.ta.partition_probability"),
      mc_method(params->method) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
double partition_probability::operator()(const time_estimate& task,
                                         const time_estimate& subtask1,
                                         const time_estimate& subtask2) {
  if (kMethodPini2011 == mc_method) {
    return calc_pini2011(task, subtask1, subtask2);
  }
  ER_FATAL_SENTINEL("Bad method '%s", mc_method.c_str());
  return 0.0;
} /* operator()() */

double partition_probability::calc_pini2011(const time_estimate& task,
                                            const time_estimate& subtask1,
                                            const time_estimate& subtask2) {
  /*
   * If we do not have samples from the task(s) denominator for either case,
   * then we artificially set that term to 0, which yields an exponent of 0, and
   * hence a partition probability of 0.5.
   */
  double theta = 0.0;
  if (task > subtask1 + subtask2) {
    if ((subtask1 + subtask2).last_result() > 0) {
      theta = reactivity() *
              (task / (subtask1 + subtask2) - offset()).last_result();
    }
  } else {
    if (task.last_result() > 0) {
      theta = reactivity() *
              (offset() - (subtask1 + subtask2) / task).last_result();
    }
  }
  return set_result(1.0 / (1 + std::exp(-theta)) * gamma());
} /* calc() */

NS_END(ta, rcppsw);
