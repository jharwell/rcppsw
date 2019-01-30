/**
 * @file interactivity.hpp
 *
 * @copyright 2018 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_SWARM_CONVERGENCE_INTERACTIVITY_HPP_
#define INCLUDE_RCPPSW_SWARM_CONVERGENCE_INTERACTIVITY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

#include "rcppsw/common/common.hpp"
#include "rcppsw/math/normalize.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, swarm, convergence);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class interactivity
 * @ingroup swarm
 *
 * @brief Calculates the degree of interaction of the swarm, given a list of
 * robot nearest neighbor distances from a swarm for a given instant. From
 * Szabo2014.
 *
 */
class interactivity {
 public:
  /**
   * @brief Return a raw interaction degree for the swarm (from Szabo2014).
   *
   * @param dists The set of closest neighbor distances, one per robot in the
   * swarm. It is assumed (but not checked!) that the swarm does not change size
   * over time.
   */
  double calc_raw(const std::vector<double>& dists) {
    m_raw = std::accumulate(dists.begin(), dists.end(), 0.0);
    m_d_min = std::min(m_d_min, m_raw);
    m_d_max = std::max(m_d_max, m_raw);
    return m_raw;
  }

  /**
   * @brief Return the normalized interaction degree from Szabo2014.
   *
   * @param dists The set of closest neighbor distances, one per robot in the
   * swarm. It is assumed (but not checked!) that the swarm does not change size
   * over time.
   */
  double calc_norm(const std::vector<double>& dists) {
    /*
     * The 1.0 - factor is because if the raw degree is HIGHER than any we have
     * yet seen, that means that the swarm the LEAST interactive we have yet
     * seen it, and so should receive a value of 0.
     */
    return m_norm = 1.0 - math::normalize(m_d_min, m_d_max, calc_raw(dists));
  }

  double raw(void) const { return m_raw; }
  double norm(void) const { return m_norm; }

  void reset(void) {
    m_raw = 0.0;
    m_norm = 0.0;
    m_d_min = std::numeric_limits<double>::max();
    m_d_max = std::numeric_limits<double>::min();
  }

 private:
  /* clang-format off */
  double m_d_min{std::numeric_limits<double>::max()};
  double m_d_max{std::numeric_limits<double>::min()};
  double m_raw{0.0};
  double m_norm{0.0};
  /* clang-format on */
};

NS_END(convergence, swarm, rcppsw);

#endif /* INCLUDE_RCPPSW_SWARM_CONVERGENCE_INTERACTIVITY_HPP_ */