/**
 * @file convergence_metrics.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_SWARM_CONVERGENCE_METRICS_HPP_
#define INCLUDE_RCPPSW_METRICS_SWARM_CONVERGENCE_METRICS_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "rcppsw/metrics/base_metrics.hpp"
#include "rcppsw/math/radians.hpp"
#include "rcppsw/math/vector2.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics, swarm);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @class convergence_metrics
 * @ingroup metrics swarm
 *
 * @brief Defines the metrics to be collected at the ensemble level in order
 * to calculate the swarm's convergence. Measures adapted from:
 *
 * - Szabo2014 (robot interaction degree)
 * - Turgut2008 (angular order)
 * - Turgut2008/Balch2000 (positional entropy)
 *
 * Metrics are collected every timestep.
 */
class convergence_metrics : public virtual rcppsw::metrics::base_metrics {
 public:
  convergence_metrics(void) = default;

  /**
   * @brief Return a vector of distances (one per robot), to each robot's
   * closest neighbor. Used to calculate swarm interaction degree
   */
  virtual std::vector<double> robot_nearest_neighbors(void) const = 0;

  /**
   * @brief Return a vector of radians (one per robot), that is each robot's
   * orientation in 2D space.
   */
  virtual std::vector<math::radians> robot_headings(void) const = 0;

  /**
   * @brief Return a vector of 2D coordinates (one per robot), that is each
   * robots position in 2D space.
   */
  virtual std::vector<math::vector2d> robot_positions(void) const = 0;
};

NS_END(swarm, metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_SWARM_CONVERGENCE_METRICS_HPP_ */
