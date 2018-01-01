/**
 * @file time_estimate.hpp
 * @ingroup task_allocation
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_TIME_ESTIMATE_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_TIME_ESTIMATE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/math/expression.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class time_estimate
 *
 * @brief Calculates an estimate of how long a task will take.
 *
 * Depends on:
 *
 * - Alpha: How much weight to give the past estimate, and how much to give the
 *   new measurement?
 *
 * - The last value of the time estimate.
 */
class time_estimate : public rcppsw::math::expression<double> {
 public:
  explicit time_estimate(double alpha) : m_alpha(alpha) {}

  double alpha(void) const { return m_alpha; }
  double calc(double current_measure);
  time_estimate operator+(const time_estimate& other) const;
  time_estimate operator/(const time_estimate& other) const;

 private:
  double m_alpha;
};

time_estimate operator-(const time_estimate& lhs, double d);
time_estimate operator-(double d, const time_estimate& rhs);
time_estimate operator*(const time_estimate& lhs, double d);
time_estimate operator*(double d, const time_estimate& rhs);
time_estimate operator/(double d, const time_estimate& rhs);
time_estimate operator/(const time_estimate& lhs, double d);
NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_TIME_ESTIMATE_HPP_ */
