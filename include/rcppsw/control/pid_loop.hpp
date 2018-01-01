/**
 * @file pid_loop.hpp
 * @ingroup control
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
 */
class pid_loop {
 public:
  /**
   *
   * @param Kp proportional gain.
   * @param Ki Integral gain.
   * @param Kd Derivative gain.
   * @param dt Loop interval time (linear interpolation used).
   * @param max Maximum value of manipulated variable and integral term.
   * @param min Minimum value of manipulated variable and integral term.
   */
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
   * @return Correctional term.
   */
  double calculate(double setpoint, double pv);

  /**
   * @brief Get the minimal value of manipulated variable/integral term.
   */
  void min(double min) { m_min = min; }

  /**
   * @brief Get the max value of manipulated variable/integral term.
   */
  void max(double max) { m_max = max; }

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
