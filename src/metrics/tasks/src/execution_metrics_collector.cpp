/**
 * @file execution_metrics_collector.cpp
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
#include "rcppsw/metrics/tasks/execution_metrics_collector.hpp"
#include "rcppsw/metrics/tasks/execution_metrics.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics, tasks);

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define CSV_COLNAME(name) #name

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
execution_metrics_collector::execution_metrics_collector(
    const std::string& ofname,
    uint interval)
    : base_metrics_collector(ofname, interval),
      m_stats() {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
std::string execution_metrics_collector::csv_header_build(
    const std::string& header) {
  // clang-format off
  return base_metrics_collector::csv_header_build(header) +
      "int_avg_exec_time" + separator() +
      "cum_avg_exec_time" + separator() +
      "int_avg_interface_time" + separator() +
      "cum_avg_interface_time" + separator() +
      "int_avg_abort_count" + separator() +
      "cum_avg_abort_count" + separator() +
      "int_avg_complete_count" + separator() +
      "cum_avg_complete_count" + separator();
  // clang-format on
} /* csv_header_build() */

void execution_metrics_collector::reset(void) {
  base_metrics_collector::reset();
  reset_after_interval();
} /* reset() */

void execution_metrics_collector::collect(
    const rcppsw::metrics::base_metrics& metrics) {
  auto& m = dynamic_cast<const execution_metrics&>(metrics);
  /*
   * Task finish stats are still valid because the current task in the executive
   * has not been updated.
   */
  if (m.task_completed()) {
    m_stats.int_interface_time += m.task_last_interface_time();
    m_stats.cum_interface_time += m.task_last_interface_time();
    m_stats.int_exec_time += m.task_last_exec_time();
    m_stats.cum_exec_time += m.task_last_exec_time();
  }
  m_stats.int_abort_count += static_cast<uint>(m.task_aborted());
  m_stats.cum_abort_count += static_cast<uint>(m.task_aborted());
  m_stats.int_complete_count += static_cast<uint>(m.task_completed());
  m_stats.cum_complete_count += static_cast<uint>(m.task_completed());
} /* collect() */

bool execution_metrics_collector::csv_line_build(std::string& line) {
  if (!((timestep() + 1) % interval() == 0)) {
    return false;
  }

  line += (m_stats.int_complete_count > 0) ?
          std::to_string(m_stats.int_exec_time /
                         static_cast<double>(m_stats.int_complete_count)) :"0";
  line += separator();
  line += (m_stats.cum_complete_count > 0) ?
          std::to_string(m_stats.cum_exec_time /
                         static_cast<double>(m_stats.cum_complete_count)) :"0";
  line += separator();

  line += (m_stats.int_complete_count > 0) ?
          std::to_string(m_stats.int_interface_time /
                         static_cast<double>(m_stats.int_complete_count)) :"0";
  line += separator();
  line += (m_stats.cum_complete_count > 0) ?
          std::to_string(m_stats.cum_interface_time /
                         static_cast<double>(m_stats.cum_complete_count)) :"0";
  line += separator();

  line += std::to_string(m_stats.int_abort_count /
                         static_cast<double>(interval())) + separator();
  line += std::to_string(m_stats.cum_abort_count /
                         static_cast<double>(timestep() + 1)) + separator();
  line += std::to_string(m_stats.int_complete_count /
                         static_cast<double>(interval())) + separator();
  line += std::to_string(m_stats.cum_complete_count /
                         static_cast<double>(timestep() + 1)) + separator();

  return true;
} /* store_foraging_stats() */

void execution_metrics_collector::reset_after_interval(void) {
  m_stats.int_complete_count = 0;
  m_stats.int_abort_count = 0;
  m_stats.int_exec_time = 0;
  m_stats.int_interface_time = 0;
} /* reset_after_interval() */

NS_END(metrics, rcppsw, tasks);
