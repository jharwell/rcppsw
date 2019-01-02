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
 * Constructors/Destructor
 ******************************************************************************/
execution_metrics_collector::execution_metrics_collector(
    const std::string &ofname, uint interval)
    : base_metrics_collector(ofname, interval),
      ER_CLIENT_INIT("rcppsw.metrics.tasks.execution_metrics_collector") {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
std::string
execution_metrics_collector::csv_header_build(const std::string &header) {
  /* clang-format off */
  return base_metrics_collector::csv_header_build(header) +
      "int_avg_exec_time" + separator() +
      "cum_avg_exec_time" + separator() +
      "int_avg_interface_time" + separator() +
      "cum_avg_interface_time" + separator() +
      "int_avg_exec_estimate" + separator() +
      "cum_avg_exec_estimate" + separator() +
      "int_avg_interface_estimate" + separator() +
      "cum_avg_interface_estimate" + separator() +
      "int_avg_abort_count" + separator() +
      "cum_avg_abort_count" + separator() +
      "int_avg_complete_count" + separator() +
      "cum_avg_complete_count" + separator() +
      "int_avg_interface_count" + separator() +
      "cum_avg_interface_count" + separator();
  /* clang-format on */
} /* csv_header_build() */

void execution_metrics_collector::reset(void) {
  base_metrics_collector::reset();
  reset_after_interval();
} /* reset() */

void execution_metrics_collector::collect(
    const rcppsw::metrics::base_metrics &metrics) {
  auto &m = dynamic_cast<const execution_metrics &>(metrics);
  ER_ASSERT(m.task_completed() || m.task_aborted(),
            "No task complete or task abort?");
  ER_ASSERT(!(m.task_completed() && m.task_aborted()),
            "Task complete AND task abort?");

  /*
   * Task finish stats are still valid because the current task in the executive
   * has not been updated (for abort or for finish).
   *
   * @todo Right now tasks update their interface/exec estimates unconditionally
   * when running, and so are the gathered metrics, but this should be able to
   * be switched on/off.
   */
  if (m.task_completed()) {
    ++m_int_complete_count;
    ++m_cum_complete_count;
  } else if (m.task_aborted()) {
    ++m_int_abort_count;
    ++m_cum_abort_count;
  }

  m_int_interface_count += m.task_at_interface();
  m_cum_interface_count += m.task_at_interface();

  m_int_exec_estimate += m.task_exec_estimate();
  m_cum_exec_estimate += m.task_exec_estimate();
  m_int_exec_time += m.task_last_exec_time();
  m_cum_exec_time += m.task_last_exec_time();

  /* Can be -1 if we aborted before getting to our task interface */
  int interface = m.task_last_active_interface();
  if (-1 != interface) {
    m_int_interface_time += m.task_last_interface_time(m.task_last_active_interface());
    m_cum_interface_time += m.task_last_interface_time(m.task_last_active_interface());
    m_int_interface_estimate += m.task_interface_estimate(m.task_last_active_interface());
    m_cum_interface_estimate += m.task_interface_estimate(m.task_last_active_interface());
  }
} /* collect() */

bool execution_metrics_collector::csv_line_build(std::string &line) {
  if (!((timestep() + 1) % interval() == 0)) {
    return false;
  }
  uint int_n_allocs = m_int_complete_count + m_int_abort_count;
  uint cum_n_allocs = m_cum_complete_count + m_cum_abort_count;

  line += (int_n_allocs > 0)
          ? std::to_string(m_int_exec_time / int_n_allocs) : "0";
  line += separator();

  line += (cum_n_allocs > 0)
          ? std::to_string(m_cum_exec_time / cum_n_allocs) : "0";
  line += separator();

  line += (int_n_allocs > 0)
          ? std::to_string(m_int_interface_time / int_n_allocs) : "0";
  line += separator();

  line += (cum_n_allocs > 0)
          ? std::to_string(m_cum_interface_time / cum_n_allocs) : "0";
  line += separator();

  line += (int_n_allocs > 0)
          ? std::to_string(m_int_exec_estimate.last_result() /
                           (int_n_allocs)) : "0";
  line += separator();
  line += (cum_n_allocs > 0)
          ? std::to_string(m_cum_exec_estimate.last_result() /
                           (cum_n_allocs)) : "0";
  line += separator();
  line += (int_n_allocs > 0)
          ? std::to_string(m_int_interface_estimate.last_result() /
                           (int_n_allocs))  : "0";
  line += separator();
  line += (cum_n_allocs > 0)
          ? std::to_string(m_cum_interface_estimate.last_result() /
                           (cum_n_allocs)) : "0";
  line += separator();
  line += std::to_string(static_cast<double>(m_int_abort_count) / interval()) + separator();
  line += std::to_string(static_cast<double>(m_cum_abort_count) / (timestep() + 1)) + separator();
  line += std::to_string(static_cast<double>(m_int_complete_count) / interval()) + separator();
  line += std::to_string(static_cast<double>(m_cum_complete_count) / (timestep() + 1)) + separator();
  line += std::to_string(static_cast<double>(m_int_interface_count) / interval()) + separator();
  line += std::to_string(static_cast<double>(m_cum_interface_count) / (timestep() + 1)) + separator();

  return true;
} /* store_foraging_stats() */

void execution_metrics_collector::reset_after_interval(void) {
  m_int_complete_count = 0;
  m_int_abort_count = 0;
  m_int_interface_count = 0;
  m_int_exec_time = 0;
  m_int_interface_time = 0;
  m_int_exec_estimate.reset();
  m_int_interface_estimate.reset();
} /* reset_after_interval() */

NS_END(metrics, rcppsw, tasks);
