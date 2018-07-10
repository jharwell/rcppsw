/**
 * @file management_metrics_collector.cpp
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
  std::string line = base_metrics_collector::csv_header_build(header);
  return line + m_stats.name + "_" + CSV_COLNAME(child1.complete_count) +
      separator() +
      m_stats.name + "_" + CSV_COLNAME(child1.abort_count) +
      separator() +
      m_stats.name + "_" + CSV_COLNAME(child1.avg_exec_time) +
      separator();
  // clang-format on
} /* csv_header_build() */

void execution_metrics_collector::reset(void) {
  base_metrics_collector::reset();
  reset_after_interval();
} /* reset() */

void execution_metrics_collector::collect(
    const rcppsw::metrics::base_metrics& metrics) {
  auto& m = dynamic_cast<const execution_metrics&>(metrics);
  m_stats.abort_count += static_cast<uint>(m.task_aborted());
  m_stats.complete_count += static_cast<uint>(m.task_completed());

  /*
   * Task finish stats. current_task_name() is still valid because the task
   * has not been reset yet/new task has not been allocated.
   */
  if (m.task_completed()) {
    m_stats.cum_exec_time += m.task_last_exec_time();
    m_stats.cum_interface_time += m.task_last_interface_time();
  }
} /* collect() */

bool execution_metrics_collector::csv_line_build(std::string& line) {
  if (!((timestep() + 1) % interval() == 0)) {
    return false;
  }

  line = std::to_string(m_stats.complete_count) + separator() +
         std::to_string(m_stats.abort_count) + separator();

  double avg_exec = (m_stats.complete_count > 0)
                    ? m_stats.cum_exec_time /
                         m_stats.complete_count
                   : 0;
  double avg_int = (m_stats.complete_count > 0)
                    ? m_stats.cum_interface_time /
                    m_stats.complete_count
                    : 0;
  line += std::to_string(avg_exec) + separator();
  line += std::to_string(avg_int) + separator();
  return true;
} /* store_foraging_stats() */

void execution_metrics_collector::reset_after_interval(void) {
  m_stats = {0, 0, 0, 0, 0};
} /* reset_after_interval() */

NS_END(metrics, rcppsw, tasks);
