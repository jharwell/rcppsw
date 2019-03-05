/**
 * @file convergence_measure.hpp
 *
 * @copyright 2019 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_SWARM_CONVERGENCE_CONVERGENCE_MEASURE_HPP_
#define INCLUDE_RCPPSW_SWARM_CONVERGENCE_CONVERGENCE_MEASURE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <limits>
#include <algorithm>

#include "rcppsw/math/expression.hpp"
#include "rcppsw/math/normalize.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, swarm, convergence);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class convergence_measure
 * @ingroup swarm convergence
 *
 * @brief Base class for all convergence measurements that can be computed on
 * swarms. Provides common functionality needed by all derived classes (cannot
 * be used to do anything useful on its own).
 */
class convergence_measure : public math::expression<double> {
 public:
  convergence_measure(double epsilon, double epsilon_delta)
      : mc_epsilon(epsilon),
        mc_epsilon_delta(epsilon_delta) {}


  /**
   * @brief Set the raw value of the measure, computed at a given time.
   *
   * Also updates the min/max raw values that have been seen so far/since the
   * last reset.
   */
  void update_raw(double value) {
    m_raw = value;
    m_raw_min = std::min(m_raw, m_raw_min);
    m_raw_max = std::max(m_raw, m_raw_max);
  }
  double raw(void) const { return m_raw; }
  double raw_min(void) const { return m_raw_min; }
  double raw_max(void) const { return m_raw_max; }


  /**
   * @brief Set the normalized value of the measure, computed at a given
   * time. Any normalization calculation should be performed prior to calling
   * this function (i.e. this function does not perform normalization itself, so
   * you should not pass \ref raw()).
   */
  void set_norm(double value) { set_result(value); }

  void reset(void) {
    math::expression<double>::reset();
    m_raw = 0.0;
    m_raw_min = std::numeric_limits<double>::max();
    m_raw_max = std::numeric_limits<double>::min();
  }

  /**
   * @brief Update the state of the convergence measure. Prior to calling this
   * function in a derived class, the raw/normalized values need to have been
   * calculated and the min/max updated.
   *
   * @return \c TRUE iff convergence has been achieved according to configured
   * parameters and the current state of the swarm.
   */
  bool update_convergence_state(double time) {
    if (last_result() >= mc_epsilon) {
      if (!m_converged_prog) {
        m_time_start = time;
        m_converged_prog = true;
      }
      if (time - m_time_start >= mc_epsilon_delta) {
        m_converged = true;
        m_converged_prog = false;
      }
    } else {
      m_converged_prog = false;
    }
    return m_converged;
  }

  /**
   * @brief Return \c TRUE iff the measure is currently converged (i.e. has been
   * above the threshold for at least the specified length).
   */
  bool converged(void) const { return m_converged; }

 private:
  /* clang-format off */
  const double mc_epsilon{0.0};
  const double mc_epsilon_delta{0.0};

  bool   m_converged{false};
  bool   m_converged_prog{false};
  double m_time_start{0.0};

  double m_raw{0.0};
  double m_raw_min{0.0};
  double m_raw_max{0.0};
  /* clang-format on */
};

NS_END(convergence, swarm, rcppsw);

#endif /* INCLUDE_RCPPSW_SWARM_CONVERGENCE_CONVERGENCE_MEASURE_HPP_ */
