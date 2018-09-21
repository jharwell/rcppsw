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

#ifndef INCLUDE_RCPPSW_SWARM_INTERACTIVITY_HPP_
#define INCLUDE_RCPPSW_SWARM_INTERACTIVITY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, swarm);

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
  double raw_degree(const std::vector<double>& dists) {
    double raw = std::accumulate(dists.begin(), dists.end(), 0.0);
    m_d_min = std::min(m_d_min, raw);
    m_d_max = std::max(m_d_max, raw);
    return raw;
  }
  /**
   * @brief Return the normalized interaction degree from Szabo2014.
   *
   * @param dists The set of closest neighbor distances, one per robot in the
   * swarm. It is assumed (but not checked!) that the swarm does not change size
   * over time.
   */
  double normed_degree(const std::vector<double>& dists) {
    double raw = raw_degree(dists);

    m_d_min = std::min(m_d_min, raw);
    m_d_max = std::max(m_d_max, raw);

    /*
     * If the max and min measurements are the same (happens on the first
     * invocation), then the normalized value is 0, 0.5 (halfway between the min
     * of 0.0 and max of 1.0). The 1.0 - factor is because if the raw degree is
     * HIGHER than any we have yet seen, that means that the swarm the LEAST
     * interactive we have yet seen it, and so should receive a value of 0.
     */
    if (m_d_max - m_d_min <= std::numeric_limits<double>::epsilon()) {
      return 0.5;
    } else {
      return 1.0 - (raw - m_d_min) / (m_d_max - m_d_min);
    }
  }

  void reset(void) {
    m_d_min = std::numeric_limits<double>::max();
    m_d_max = std::numeric_limits<double>::min();
  }

 private:
  // clang-format off
  double m_d_min{std::numeric_limits<double>::max()};
  double m_d_max{std::numeric_limits<double>::min()};
  // clang-format on
};

NS_END(swarm, rcppsw);

#endif /* INCLUDE_RCPPSW_SWARM_INTERACTIVITY_HPP_ */
