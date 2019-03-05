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
#include <utility>
#include "rcppsw/metrics/base_metrics.hpp"

/*******************************************************************************
 * Namespaces/Decls
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
 * to calculate the swarm's convergence in various ways. Measures adapted from:
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
   * @brief Return the (raw, normalized) interaction degree of the swarm. See
   * \ref interactivity for the calculation/input variables.
   */
  virtual std::pair<double, double> swarm_interactivity(void) const = 0;

  /**
   * @brief Return the (raw, normalized) angular order of the swarm. See \ref
   * angular_order for the calculation/input variables.
   */
  virtual std::pair<double, double> swarm_angular_order(void) const = 0;

  /**
   * @brief Return the (raw, normalized) positional entropy of the swarm. See
   * \ref positional_entropy for the calculation/input variables.
   */
  virtual std::pair<double, double> swarm_positional_entropy(void) const = 0;
};

NS_END(swarm, metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_SWARM_CONVERGENCE_METRICS_HPP_ */
