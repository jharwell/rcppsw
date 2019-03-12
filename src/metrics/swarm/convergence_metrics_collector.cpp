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
#include "rcppsw/metrics/swarm/convergence_metrics.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics, swarm);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
convergence_metrics_collector::convergence_metrics_collector(
    const std::string& ofname,
    uint interval)
    : base_metrics_collector(ofname, interval) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
std::string convergence_metrics_collector::csv_header_build(
    const std::string& header) {
  return base_metrics_collector::csv_header_build(header) +
      /* clang-format off */
      "conv_epsilon" + separator() +
      "int_avg_interact_deg_raw" + separator() +
      "int_avg_interact_deg_norm" + separator() +
      "int_avg_interact_deg_converged" + separator() +
      "int_avg_ang_order_raw" + separator() +
      "int_avg_ang_order_norm" + separator() +
      "int_avg_ang_order_converged" + separator() +
      "int_avg_pos_entropy_raw" + separator() +
      "int_avg_pos_entropy_norm" + separator() +
      "int_avg_pos_entropy_converged" + separator() +
      "int_avg_task_dist_entropy_raw" + separator() +
      "int_avg_task_dist_entropy_norm" + separator() +
      "int_avg_task_dist_entropy_converged" + separator();
  /* clang-format on */
} /* csv_header_build() */

bool convergence_metrics_collector::csv_line_build(std::string& line) {
  if (!((timestep() + 1) % interval() == 0)) {
    return false;
  }

  line += std::to_string(m_conv_epsilon) + separator();

  /*
   * There are no cumulative metrics, because we also output dt values, which
   * are almost the same thing, and much more useful when calculating
   * convergence.
   */
  build_interact(line);
  build_ang_order(line);
  build_pos_entropy(line);
  build_tdist_entropy(line);
  return true;
} /* csv_line_build() */

void convergence_metrics_collector::build_tdist_entropy(std::string& line) {
  line += std::to_string(m_tdist_ent_stats.raw / interval()) + separator();
  line += std::to_string(m_tdist_ent_stats.norm / interval()) + separator();
  line += std::to_string(static_cast<double>(m_tdist_ent_stats.converged) /
                         interval()) + separator();
} /* build_tdist_entropy() */

void convergence_metrics_collector::build_pos_entropy(std::string& line) {
  line += std::to_string(m_pos_ent_stats.raw / interval()) + separator();
  line += std::to_string(m_pos_ent_stats.norm / interval()) + separator();
  line += std::to_string(static_cast<double>(m_pos_ent_stats.converged) /
                         interval()) + separator();
} /* build_pos_entropy() */

void convergence_metrics_collector::build_interact(std::string& line) {
  line += std::to_string(m_interact_stats.raw / interval()) + separator();
  line += std::to_string(m_interact_stats.norm / interval()) + separator();
  line += std::to_string(static_cast<double>(m_interact_stats.converged) /
                         interval()) + separator();
} /* build_interact() */

void convergence_metrics_collector::build_ang_order(std::string& line) {
  line += std::to_string(m_order_stats.raw / interval()) + separator();
  line += std::to_string(m_order_stats.norm / interval()) + separator();
  line += std::to_string(static_cast<double>(m_order_stats.converged)
                         / interval()) + separator();
} /* build_ang_order() */

void convergence_metrics_collector::collect(const metrics::base_metrics& metrics) {
  auto& m = dynamic_cast<const convergence_metrics&>(metrics);
  /*
   * Captured here, rather than as a constructor parameter in order to allow for
   * temporally varying convergence thresholds in the future if desired.
   */
  m_conv_epsilon = m.swarm_conv_epsilon();

  auto status = m.swarm_interactivity();
  m_interact_stats.raw += std::get<0>(status);
  m_interact_stats.norm += std::get<1>(status);
  m_interact_stats.converged += std::get<2>(status);

  status = m.swarm_angular_order();
  m_order_stats.raw += std::get<0>(status);
  m_order_stats.norm += std::get<1>(status);
  m_order_stats.converged += std::get<2>(status);

  status = m.swarm_positional_entropy();
  m_pos_ent_stats.raw += std::get<0>(status);
  m_pos_ent_stats.norm += std::get<1>(status);
  m_pos_ent_stats.converged += std::get<2>(status);

  status = m.swarm_task_dist_entropy();
  m_tdist_ent_stats.raw += std::get<0>(status);
  m_tdist_ent_stats.norm += std::get<1>(status);
  m_tdist_ent_stats.converged += std::get<2>(status);
} /* collect() */

void convergence_metrics_collector::reset(void) {
  base_metrics_collector::reset();
  reset_after_interval();
} /* reset() */

void convergence_metrics_collector::reset_after_interval(void) {
  m_interact_stats = {0.0, 0.0, false};
  m_order_stats = {0.0, 0.0, false};
  m_pos_ent_stats = {0.0, 0.0, false};
  m_tdist_ent_stats = {0.0, 0.0, false};
} /* reset_after_interval() */

NS_END(swarm, metrics, rcppsw);
