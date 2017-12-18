/**
 * @file time_estimate.cpp
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
#include "rcppsw/task_allocation/time_estimate.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
double time_estimate::calc(double current_measure) {
  return set_result((1 - m_alpha) * last_result() + m_alpha * current_measure);
} /* calc() */

time_estimate time_estimate::operator+(const time_estimate& other) const {
  time_estimate r(this->alpha());
  r.set_result(this->last_result() + other.last_result());
  return r;
}

time_estimate time_estimate::operator/(const time_estimate& other) const {
  time_estimate r(this->alpha());
  r.set_result(this->last_result() / other.last_result());
  return r;
}

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
time_estimate operator-(const time_estimate& lhs, double d) {
  time_estimate r(lhs.alpha());
  r.set_result(lhs.last_result() - d);
  return r;
}

time_estimate operator-(double d, const time_estimate& rhs) {
  time_estimate r(rhs.alpha());
  r.set_result(rhs.last_result() - d);
  return r;
}

time_estimate operator*(const time_estimate& lhs, double d) {
  time_estimate r(lhs.alpha());
  r.set_result(lhs.last_result() * d);
  return r;
}

time_estimate operator*(double d, const time_estimate& rhs) {
  time_estimate r(rhs.alpha());
  r.set_result(rhs.last_result() * d);
  return r;
}

time_estimate operator/(double d, const time_estimate& rhs) {
  time_estimate r(rhs.alpha());
  r.set_result(rhs.last_result() / d);
  return r;
}

time_estimate operator/(const time_estimate& lhs, double d) {
  time_estimate r(lhs.alpha());
  r.set_result(lhs.last_result() / d);
  return r;
}

NS_END(task_allocation, rcppsw);
