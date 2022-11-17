/**
 * \file pid_loop.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class pid_loop
 * \ingroup control
 *
 * \brief A simple PID loop class.
 */
class pid_loop {
 public:
  /**
   * \param kp proportional gain.
   * \param ki Integral gain.
   * \param kd Derivative gain.
   * \param dt Loop interval time (linear interpolation used).
   * \param max Maximum value of manipulated variable and integral term.
   * \param min Minimum value of manipulated variable and integral term.
   */
  pid_loop(double kp, double kd, double ki, double dt, double min, double max)
      : m_kp(kp),
        m_kd(kd),
        m_ki(ki),
        m_dt(dt),
        m_min(min),
        m_max(max),
        m_istate(0),
        m_prev_error(0.0) {}

  /**
   * \brief Calculate a new value for the manipulated variable.
   *
   * \param setpoint Desired value of the manipulated variable.
   * \param pv Current value of the variable.
   *
   * \return Correctional term.
   */
  double calculate(double setpoint, double pv);

  /**
   * \brief Reset the integral state, previous error (setpoint - pv)
   */
  void reset(void) {
    m_istate = 0.0;
    m_prev_error = 0.0;
  }

  /**
   * \brief Get the minimal value of manipulated variable/integral term.
   */
  void min(double min) { m_min = min; }

  /**
   * \brief Get the max value of manipulated variable/integral term.
   */
  void max(double max) { m_max = max; }

 private:
  /* clang-format off */
  double m_kp;
  double m_kd;
  double m_ki;
  double m_dt;
  double m_min;
  double m_max;
  double m_istate;
  double m_prev_error;
  /* clang-format on */
};

NS_END(control, rcppsw);

