/**
 * @file pid_loop.cpp
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
#include "rcppsw/control/pid_loop.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
double pid_loop::calculate(double setpoint, double pv) {
  // Calculate error
  double error = setpoint - pv;

  // Proportional term
  double Pout = m_Kp * error;

  // Integral term
  m_integral += error * m_dt;
  double Iout = m_Ki * m_integral;

  // Derivative term
  double derivative = (error - m_pre_error) / m_dt;
  double Dout = m_Kd * derivative;

  // Calculate total output
  double output = Pout + Iout + Dout;

  // Restrict to max/min
  output = std::min(output, m_max);
  output = std::max(output, m_min);

  m_pre_error = error;
  return output;
} /* calculate() */

NS_END(control, rcppsw);
