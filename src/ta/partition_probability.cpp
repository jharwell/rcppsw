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

#include "rcppsw/ta/config/sigmoid_sel_config.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
partition_probability::partition_probability(
    const config::sigmoid_sel_config* config)
    : sigmoid(config->sigmoid.reactivity,
              config->sigmoid.offset,
              config->sigmoid.gamma),
      ER_CLIENT_INIT("rcppsw.ta.partition_probability"),
      mc_method(config->method) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
double partition_probability::operator()(const time_estimate& task,
                                         const time_estimate& subtask1,
                                         const time_estimate& subtask2,
                                         std::default_random_engine& rng) {
  if (kMethodPini2011 == mc_method) {
    return calc_pini2011(task, subtask1, subtask2);
  } else if (kMethodRandom == mc_method) {
    return calc_random(rng);
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
    if ((subtask1 + subtask2).v() > 0) {
      theta = reactivity() * (task / (subtask1 + subtask2) - offset()).v();
    }
  } else {
    if (task.v() > 0) {
      theta = reactivity() * (offset() - (subtask1 + subtask2) / task).v();
    }
  }
  return eval(1.0 / (1 + std::exp(-theta)) * gamma());
} /* calc() */

double_t partition_probability::calc_random(std::default_random_engine& rng) {
  std::uniform_real_distribution<> dist(0.0, 1.0);
  return eval(dist(rng));
} /* calc_random() */

NS_END(ta, rcppsw);
