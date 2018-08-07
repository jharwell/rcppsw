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
#include "rcppsw/task_allocation/abort_params.hpp"
#include <cmath>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
abort_probability::abort_probability(const struct abort_params *const params)
    : abort_probability(params->reactivity, params->offset) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
double abort_probability::calc(double exec_time,
                               const time_estimate &whole_task) {
  if (!(whole_task.last_result() > 0)) {
    return set_result(kNO_EST_ABORT_PROB);
  }

  double theta =
      m_reactivity * (m_offset - exec_time / whole_task.last_result());
  return set_result(1.0 / (1 + std::exp(theta)));
} /* calc() */

double abort_probability::operator()(double exec_time,
                                     const time_estimate &whole_task) {
  return calc(exec_time, whole_task);
} /* operator() */

NS_END(task_allocation, rcppsw);
