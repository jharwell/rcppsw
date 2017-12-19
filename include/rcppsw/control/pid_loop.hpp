/**
 * @file pid_loop.hpp
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

#ifndef INCLUDE_RCPPSW_CONTROL_PID_LOOP_HPP_
#define INCLUDE_RCPPSW_CONTROL_PID_LOOP_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class pid_loop
 *
 * @brief A simple PID loop class.
 *
 *  Kp -  proportional gain.
 *  Ki -  Integral gain.
 *  Kd -  Derivative gain.
 *  dt -  Loop interval time (linear interpolation used).
 *  max - Maximum value of manipulated variable and integral term.
 *  min - Minimum value of manipulated variable and integral term.
 */
class pid_loop {
 public:
  pid_loop(double Kp, double Kd, double Ki, double dt, double min, double max)
      : m_Kp(Kp),
        m_Kd(Kd),
        m_Ki(Ki),
        m_dt(dt),
        m_min(min),
        m_max(max),
        m_istate(0),
        m_prev_error(0.0) {}

  /**
   * @brief Calculate a new value for the manipulated variable.
   *
   * @param setpoint Desired value of the manipulated variable.
   * @param pv Current value of the variable.
   *
   * @return Correctional term .
   */
  double calculate(double setpoint, double pv);
  void min(double min) { m_min = min; }
  void max(double max) { m_max = max; }
  void reset(void) { m_istate = 0.0; }
  double integral(void) const { return m_istate; }
  double dt(void) const { return m_dt; }
  void dt(double dt) { m_dt = dt; }
  double Kp(void) const { return m_Kp; }
  void Kp(double Kp) { m_Kp = Kp; }
  double Kd(void) const { return m_Kd; }
  void Kd(double Kd) { m_Kd = Kd; }
  double Ki(void) const { return m_Ki; }
  void Ki(double Ki) { m_Ki = Ki; }

 private:
  double m_Kp;
  double m_Kd;
  double m_Ki;
  double m_dt;
  double m_min;
  double m_max;
  double m_istate;
  double m_prev_error;
};

NS_END(control, rcppsw);

#endif /* INCLUDE_RCPPSW_CONTROL_PID_LOOP_HPP_ */
