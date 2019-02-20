/**
 * @file convergence_metrics_collector.cpp
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/metrics/swarm/convergence_metrics_collector.hpp"

#include "rcppsw/algorithm/clustering/entropy.hpp"
#include "rcppsw/metrics/swarm/convergence_metrics.hpp"
#include "rcppsw/swarm/convergence/angular_order.hpp"
#include "rcppsw/swarm/convergence/positional_entropy.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics, swarm);
namespace rcluster = rcppsw::algorithm::clustering;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
convergence_metrics_collector::convergence_metrics_collector(
    const std::string& ofname,
    uint interval,
    const swc::convergence_params* const params)
    : base_metrics_collector(ofname, interval), mc_params(*params) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
std::string convergence_metrics_collector::csv_header_build(
    const std::string& header) {
  return base_metrics_collector::csv_header_build(header) +
         /* clang-format off */
      "int_avg_interact_deg_raw" + separator() +
      "int_avg_interact_deg_raw_dt" + separator() +
      "int_avg_interact_deg_norm" + separator() +
      "int_avg_interact_deg_norm_dt" + separator() +
      "int_avg_ang_order" + separator() +
      "int_avg_ang_order_dt" + separator() +
      "int_avg_pos_entropy" + separator() +
      "int_avg_pos_entropy_dt" + separator();
  /* clang-format on */
} /* csv_header_build() */

bool convergence_metrics_collector::csv_line_build(std::string& line) {
  if (!((timestep() + 1) % interval() == 0)) {
    return false;
  }

  /*
   * Output interaction degree metrics (interval). There are no cumulative
   * metrics, because we also output dt values, which are almost the same
   * thing, and much more useful when calculating convergence.
   */
  double interact_raw = m_interact_stats.raw / interval();
  line += std::to_string(interact_raw) + separator();

  double dt = (interact_raw - m_interact_stats.start_raw);
  line += std::to_string(dt) + separator();

  double interact_norm = m_interact_stats.norm / interval();
  line += std::to_string(interact_norm) + separator();

  double norm_dt = (interact_norm - m_interact_stats.start_norm);
  line += std::to_string(norm_dt) + separator();

  /* output angular order metrics */
  double order = m_order_stats.order / interval();
  line += std::to_string(order) + separator();

  dt = (order - m_order_stats.start_order);
  line += std::to_string(dt) + separator();

  /* output positional entropy metrics */
  double entropy = m_pos_ent_stats.entropy / interval();
  line += std::to_string(entropy) + separator();
  dt = (entropy - m_pos_ent_stats.start_entropy);
  line += std::to_string(dt) + separator();

  return true;
} /* csv_line_build() */

void convergence_metrics_collector::collect(const metrics::base_metrics& metrics) {
  auto& m = dynamic_cast<const convergence_metrics&>(metrics);

  /* Collect interaction degree metrics.
   *
   * Note that each robot's distance to closest neighbor does not necessarily
   * appear in the same place in the result array on subsequent timesteps. This
   * is OK, because we are doing a cumulative addition with the results as we
   * collect metrics, so it doesn't really matter that you are not doing
   * strictly piecewise addition.
   */
  if (mc_params.interactivity.enable) {
    auto neighbors = m.robot_nearest_neighbors();
    m_interact_stats.raw += m_interact.calc_raw(neighbors);
    m_interact_stats.norm += m_interact.calc_norm(neighbors);
  }

  /* collect angular order metrics */
  if (mc_params.ang_order.enable) {
    auto headings = m.robot_headings();
    m_order_stats.order += swc::angular_order()(headings, mc_params.n_threads);
  }

  /* collect positional entropy metrics */
  if (mc_params.pos_entropy.enable) {
    auto robot_positions = m.robot_positions();
    auto clusterer =
        std::make_unique<rcluster::detail::entropy_impl<rmath::vector2d>>(
            mc_params.n_threads);
    auto alg = swc::positional_entropy(robot_positions,
                                       std::move(clusterer),
                                       mc_params.pos_entropy.horizon,
                                       mc_params.pos_entropy.horizon_delta);
    m_pos_ent_stats.entropy += alg();
  }
} /* collect() */

void convergence_metrics_collector::reset(void) {
  base_metrics_collector::reset();
  reset_after_interval();
} /* reset() */

void convergence_metrics_collector::reset_after_interval(void) {
  m_interact_stats.start_raw = m_interact_stats.raw / interval();
  m_interact_stats.start_norm = m_interact_stats.norm / interval();
  m_interact_stats.raw = 0.0;
  m_interact_stats.norm = 0.0;

  m_order_stats.start_order = m_order_stats.order / interval();
  m_order_stats.order = 0.0;

  m_pos_ent_stats.start_entropy = m_pos_ent_stats.entropy / interval();
  m_pos_ent_stats.entropy = 0.0;
} /* reset_after_interval() */

NS_END(swarm, metrics, rcppsw);
