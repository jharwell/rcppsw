/**
 * @file bi_tdgraph_metrics_collector.cpp
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/metrics/tasks/bi_tdgraph_metrics_collector.hpp"
#include <cmath>

#include "rcppsw/metrics/tasks/bi_tdgraph_metrics.hpp"
#include "rcppsw/task_allocation/polled_task.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics, tasks);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
bi_tdgraph_metrics_collector::bi_tdgraph_metrics_collector(
    const std::string &ofname, uint interval, uint decomposition_depth)
    : base_metrics_collector(ofname, interval),
      m_int_depth_counts(decomposition_depth + 1, 0),
      m_int_task_counts(std::pow(2, decomposition_depth + 1) - 1, 0),
      m_int_tab_counts(std::pow(2, decomposition_depth - 1) + 1, 0),
      m_cum_depth_counts(decomposition_depth + 1, 0),
      m_cum_task_counts(std::pow(2, decomposition_depth + 1) - 1, 0),
      m_cum_tab_counts(std::pow(2, decomposition_depth - 1) + 1, 0) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
std::string
bi_tdgraph_metrics_collector::csv_header_build(const std::string &header) {
  std::string line = base_metrics_collector::csv_header_build(header);

  for (size_t i = 0; i < m_int_depth_counts.size(); ++i) {
    line += "int_avg_depth" + std::to_string(i) + "_count" + separator();
  } /* for(i..) */

  for (size_t i = 0; i < m_cum_depth_counts.size(); ++i) {
    line += "cum_avg_depth" + std::to_string(i) + "_count" + separator();
  } /* for(i..) */

  for (size_t i = 0; i < m_int_task_counts.size(); ++i) {
    line += "int_avg_task" + std::to_string(i) + "_count" + separator();
  } /* for(i..) */

  for (size_t i = 0; i < m_cum_task_counts.size(); ++i) {
    line += "cum_avg_task" + std::to_string(i) + "_count" + separator();
  } /* for(i..) */

  for (size_t i = 0; i < m_int_tab_counts.size(); ++i) {
    line += "int_avg_tab" + std::to_string(i) + "_count" + separator();
  } /* for(i..) */

  for (size_t i = 0; i < m_cum_tab_counts.size(); ++i) {
    line += "cum_avg_tab" + std::to_string(i) + "_count" + separator();
  } /* for(i..) */
  return line;
} /* csv_header_build() */

void bi_tdgraph_metrics_collector::reset(void) {
  base_metrics_collector::reset();
  reset_after_interval();
} /* reset() */

void bi_tdgraph_metrics_collector::collect(
    const rcppsw::metrics::base_metrics &metrics) {
  auto &m = dynamic_cast<const bi_tdgraph_metrics &>(metrics);
  ++m_int_depth_counts[m.current_task_depth()];
  ++m_int_task_counts[m.current_task_id()];
  ++m_int_tab_counts[m.current_task_tab()];

  ++m_cum_depth_counts[m.current_task_depth()];
  ++m_cum_task_counts[m.current_task_id()];
  ++m_cum_tab_counts[m.current_task_tab()];
} /* collect() */

bool bi_tdgraph_metrics_collector::csv_line_build(std::string &line) {
  if (!((timestep() + 1) % interval() == 0)) {
    return false;
  }

  for (size_t i = 0; i < m_int_depth_counts.size(); ++i) {
    line += std::to_string(static_cast<double>(m_int_depth_counts[i]) /
                           interval()) + separator();
  } /* for(i..) */
  for (size_t i = 0; i < m_cum_depth_counts.size(); ++i) {
    line += std::to_string(static_cast<double>(m_cum_depth_counts[i]) /
                           (timestep() + 1)) + separator();
  } /* for(i..) */

  for (size_t i = 0; i < m_int_task_counts.size(); ++i) {
    line += std::to_string(static_cast<double>(m_int_task_counts[i]) /
                           interval()) + separator();
  } /* for(i..) */
  for (size_t i = 0; i < m_cum_task_counts.size(); ++i) {
    line += std::to_string(static_cast<double>(m_cum_task_counts[i]) /
                           (timestep() + 1)) + separator();
  } /* for(i..) */

  for (size_t i = 0; i < m_int_tab_counts.size(); ++i) {
    line += std::to_string(static_cast<double>(m_int_tab_counts[i]) /
                           interval()) + separator();
  } /* for(i..) */
  for (size_t i = 0; i < m_cum_tab_counts.size(); ++i) {
    line += std::to_string(static_cast<double>(m_cum_tab_counts[i]) /
                           (timestep() + 1)) + separator();
  } /* for(i..) */
  return true;
} /* store_foraging_stats() */

void bi_tdgraph_metrics_collector::reset_after_interval(void) {
  m_int_depth_counts.assign(m_int_depth_counts.size(), 0);
  m_int_task_counts.assign(m_int_task_counts.size(), 0);
  m_int_tab_counts.assign(m_int_tab_counts.size(), 0);
} /* reset_after_interval() */

NS_END(metrics, rcppsw, tasks);
