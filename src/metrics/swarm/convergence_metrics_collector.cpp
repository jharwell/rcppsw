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
      "int_avg_interact_deg_raw" + separator() +
      "int_avg_interact_deg_raw_dt" + separator() +
      "int_avg_interact_deg_norm" + separator() +
      "int_avg_interact_deg_norm_dt" + separator() +
      "int_avg_ang_order_raw" + separator() +
      "int_avg_ang_order_raw_dt" + separator() +
      "int_avg_ang_order_norm" + separator() +
      "int_avg_ang_order_norm_dt" + separator() +
      "int_avg_pos_entropy_raw" + separator() +
      "int_avg_pos_entropy_raw_dt" + separator() +
      "int_avg_pos_entropy_norm" + separator() +
      "int_avg_pos_entropy_norm_dt" + separator();
  /* clang-format on */
} /* csv_header_build() */

bool convergence_metrics_collector::csv_line_build(std::string& line) {
  if (!((timestep() + 1) % interval() == 0)) {
    return false;
  }

  /*
   * There are no cumulative metrics, because we also output dt values, which
   * are almost the same thing, and much more useful when calculating
   * convergence.
   */
  double interact_raw = m_interact_stats.raw / interval();
  line += std::to_string(interact_raw) + separator();

  double raw_dt = (interact_raw - m_interact_stats.start_raw);
  line += std::to_string(raw_dt) + separator();

  double interact_norm = m_interact_stats.norm / interval();
  line += std::to_string(interact_norm) + separator();

  double norm_dt = (interact_norm - m_interact_stats.start_norm);
  line += std::to_string(norm_dt) + separator();

  /* output angular order metrics */
  double order_raw = m_order_stats.raw / interval();
  line += std::to_string(order_raw) + separator();

  raw_dt = (order_raw - m_order_stats.start_raw);
  line += std::to_string(raw_dt) + separator();

  double order_norm = m_order_stats.norm / interval();
  line += std::to_string(order_norm) + separator();

  norm_dt = (order_norm - m_order_stats.start_norm);
  line += std::to_string(norm_dt) + separator();

  /* output positional entropy metrics */
  double entropy_raw = m_pos_ent_stats.raw / interval();
  line += std::to_string(entropy_raw) + separator();
  raw_dt = (entropy_raw - m_pos_ent_stats.start_raw);
  line += std::to_string(raw_dt) + separator();

  double entropy_norm = m_pos_ent_stats.norm / interval();
  line += std::to_string(entropy_norm) + separator();
  raw_dt = (entropy_norm - m_pos_ent_stats.start_norm);
  line += std::to_string(norm_dt) + separator();

  return true;
} /* csv_line_build() */

void convergence_metrics_collector::collect(const metrics::base_metrics& metrics) {
  auto& m = dynamic_cast<const convergence_metrics&>(metrics);

  auto tmp = m.swarm_interactivity();
  m_interact_stats.raw += tmp.first;
  m_interact_stats.norm += tmp.second;

  tmp = m.swarm_angular_order();
  m_order_stats.raw += tmp.first;
  m_order_stats.norm += tmp.second;

  tmp = m.swarm_positional_entropy();
  m_pos_ent_stats.raw += tmp.first;
  m_pos_ent_stats.norm += tmp.second;
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

  m_order_stats.start_raw = m_order_stats.raw / interval();
  m_order_stats.start_norm = m_order_stats.norm / interval();
  m_order_stats.raw = 0.0;
  m_order_stats.norm = 0.0;

  m_pos_ent_stats.start_raw = m_pos_ent_stats.raw / interval();
  m_pos_ent_stats.start_norm = m_pos_ent_stats.norm / interval();
  m_pos_ent_stats.raw = 0.0;
  m_pos_ent_stats.norm = 0.0;
} /* reset_after_interval() */

NS_END(swarm, metrics, rcppsw);
