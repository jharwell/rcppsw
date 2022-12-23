/**
 * \file pid_loop.cpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/control/pid_loop.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::control {

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

} /* namespace rcppsw::control */
