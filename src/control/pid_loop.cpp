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
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
double pid_loop::calculate(double setpoint, double pv) {
  // Calculate error
  double error = setpoint - pv;

  // Proportional term
  double p_out = m_kp * error;

  // Integral state
  m_istate += error * m_dt;

  // Restrict integral max/min
  m_istate = std::min(m_istate, m_max);
  m_istate = std::max(m_istate, m_min);

  // Integral term
  double i_out = m_ki * m_istate;

  // Derivative term
  double d_out = m_kd * (error - m_prev_error) / m_dt;

  m_prev_error = error;
  double output = p_out + i_out + d_out;
  output = std::min(output, m_max);
  output = std::max(output, m_min);
  return output;
} /* calculate() */

NS_END(control, rcppsw);
