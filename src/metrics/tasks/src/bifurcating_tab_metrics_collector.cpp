/**
 * @file bifurcating_tab_metrics_collector.cpp
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
#include "rcppsw/metrics/tasks/bifurcating_tab_metrics_collector.hpp"
#include <cassert>

#include "rcppsw/metrics/tasks/bifurcating_tab_metrics.hpp"
#include "rcppsw/task_allocation/polled_task.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics, tasks);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
bifurcating_tab_metrics_collector::bifurcating_tab_metrics_collector(
    const std::string &ofname, uint interval)
    : base_metrics_collector(ofname, interval),
      m_stats() {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
std::string
bifurcating_tab_metrics_collector::csv_header_build(const std::string &header) {
  // clang-format off
  std::string line = base_metrics_collector::csv_header_build(header);
  return line + "int_subtask1_count" + separator() +
      "cum_avg_subtask1_count" + separator() +
      "int_subtask2_count" + separator() +
      "cum_avg_subtask2_count" + separator() +
      "int_partition_count" + separator() +
      "cum_avg_partition_count" + separator() +
      "int_no_partition_count" + separator() +
      "cum_avg_no_partition_count" + separator() +
      "int_task_sw_count" + separator() +
      "cum_task_sw_count" + separator() +
      "int_task_depth_sw_count" + separator() +
      "cum_task_depth_sw_count" + separator();
  // clang-format on
  return line;
} /* csv_header_build() */

void bifurcating_tab_metrics_collector::reset(void) {
  base_metrics_collector::reset();
  reset_after_interval();
} /* reset() */

void bifurcating_tab_metrics_collector::collect(
    const rcppsw::metrics::base_metrics &metrics) {
  auto &m = dynamic_cast<const bifurcating_tab_metrics &>(metrics);
  if (m.employed_partitioning()) {
    ++m_stats.int_partition_count;
    ++m_stats.cum_partition_count;
    m_stats.int_subtask1_count += static_cast<uint>(m.subtask1_active());
    m_stats.cum_subtask1_count += static_cast<uint>(m.subtask1_active());
    m_stats.int_subtask2_count += static_cast<uint>(m.subtask2_active());
    m_stats.cum_subtask2_count += static_cast<uint>(m.subtask2_active());
  } else {
    ++m_stats.int_no_partition_count;
    ++m_stats.cum_no_partition_count;
  }

  m_stats.int_task_sw_count += static_cast<uint>(m.task_changed());
  m_stats.cum_task_sw_count += static_cast<uint>(m.task_changed());
  m_stats.int_task_depth_sw_count += static_cast<uint>(m.task_depth_changed());
  m_stats.cum_task_depth_sw_count += static_cast<uint>(m.task_depth_changed());
} /* collect() */

bool bifurcating_tab_metrics_collector::csv_line_build(std::string &line) {
  if (!((timestep() + 1) % interval() == 0)) {
    return false;
  }

  line += std::to_string(m_stats.int_subtask1_count) + separator();
  line += std::to_string(m_stats.cum_subtask1_count /
                         static_cast<double>(timestep() + 1)) +
          separator();
  line += std::to_string(m_stats.int_subtask2_count) + separator();
  line += std::to_string(m_stats.cum_subtask2_count /
                         static_cast<double>(timestep() + 1)) +
          separator();
  line += std::to_string(m_stats.int_partition_count) + separator();
  line += std::to_string(m_stats.cum_partition_count /
                         static_cast<double>(timestep() + 1)) +
          separator();
  line += std::to_string(m_stats.int_no_partition_count) + separator();
  line += std::to_string(m_stats.cum_no_partition_count /
                         static_cast<double>(timestep() + 1)) +
          separator();
  line += std::to_string(m_stats.int_task_sw_count) + separator();
  line += std::to_string(m_stats.cum_task_sw_count /
                         static_cast<double>(timestep() + 1)) +
          separator();
  line += std::to_string(m_stats.int_task_depth_sw_count) + separator();
  line += std::to_string(m_stats.cum_task_depth_sw_count /
                         static_cast<double>(timestep() + 1)) +
          separator();
  return true;
} /* store_foraging_stats() */

void bifurcating_tab_metrics_collector::reset_after_interval(void) {
  m_stats.int_subtask1_count = 0;
  m_stats.int_subtask2_count = 0;
  m_stats.int_partition_count = 0;
  m_stats.int_no_partition_count = 0;
  m_stats.int_task_sw_count = 0;
  m_stats.int_task_depth_sw_count = 0;
} /* reset_after_interval() */

NS_END(metrics, rcppsw, tasks);
