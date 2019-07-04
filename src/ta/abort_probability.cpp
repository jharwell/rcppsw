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
#include "rcppsw/ta/abort_probability.hpp"
#include <cmath>

#include "rcppsw/math/config/sigmoid_config.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
abort_probability::abort_probability(
    const math::config::sigmoid_config* const config)
    : sigmoid(config->reactivity, config->offset, config->gamma) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
double abort_probability::operator()(double exec_time,
                                     const time_estimate& whole_task) {
  if (!(whole_task.last_result() > 0)) {
    return set_result(kMIN_ABORT_PROB);
  }
  double ratio = exec_time / whole_task.last_result();
  double theta = 0.0;
  if (ratio <= offset()) {
    theta = reactivity() * (offset() - ratio);
  } else {
    theta = reactivity() * (ratio - offset());
  }
  return set_result(1.0 / (1 + std::exp(theta)) * gamma());
} /* operator() */

NS_END(ta, rcppsw);
