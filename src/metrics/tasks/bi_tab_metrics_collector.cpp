/**
 * @file bi_tab_metrics_collector.cpp
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
#include "rcppsw/metrics/tasks/bi_tab_metrics_collector.hpp"

#include "rcppsw/metrics/tasks/bi_tab_metrics.hpp"
#include "rcppsw/ta/polled_task.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics, tasks);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
bi_tab_metrics_collector::bi_tab_metrics_collector(const std::string& ofname,
                                                   uint interval)
    : base_metrics_collector(ofname, interval) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
std::list<std::string> bi_tab_metrics_collector::csv_header_cols(void) const {
  auto merged = dflt_csv_header_cols();
  auto cols = std::list<std::string>{
    /* clang-format off */
      "int_avg_subtask1_count",
      "cum_avg_subtask1_count",
      "int_avg_subtask2_count",
      "cum_avg_subtask2_count",
      "int_avg_partition_count",
      "cum_avg_partition_count",
      "int_avg_no_partition_count",
      "cum_avg_no_partition_count",
      "int_avg_task_sw_count",
      "cum_avg_task_sw_count",
      "int_avg_task_depth_sw_count",
      "cum_avg_task_depth_sw_count",
      "int_avg_partition_prob",
      "cum_avg_partition_prob",
      "int_avg_subtask_selection_prob",
      "cum_avg_subtask_selection_prob"
      /* clang-format on */
  };
  merged.splice(merged.end(), cols);
  return merged;
} /* csv_header_cols() */

void bi_tab_metrics_collector::reset(void) {
  base_metrics_collector::reset();
  reset_after_interval();
} /* reset() */

void bi_tab_metrics_collector::collect(
    const rcppsw::metrics::base_metrics& metrics) {
  auto& m = dynamic_cast<const bi_tab_metrics&>(metrics);
  if (m.employed_partitioning()) {
    ++m_int_partition_count;
    ++m_cum_partition_count;
    m_int_subtask1_count += static_cast<uint>(m.subtask1_active());
    m_cum_subtask1_count += static_cast<uint>(m.subtask1_active());
    m_int_subtask2_count += static_cast<uint>(m.subtask2_active());
    m_cum_subtask2_count += static_cast<uint>(m.subtask2_active());
  } else {
    ++m_int_no_partition_count;
    ++m_cum_no_partition_count;
  }

  m_int_partition_prob += m.partition_prob();
  m_int_subtask_selection_prob += m.subtask_selection_prob();
  m_cum_partition_prob += m.partition_prob();
  m_cum_subtask_selection_prob += m.subtask_selection_prob();
  m_int_task_sw_count += static_cast<uint>(m.task_changed());
  m_cum_task_sw_count += static_cast<uint>(m.task_changed());
  m_int_task_depth_sw_count += static_cast<uint>(m.task_depth_changed());
  m_cum_task_depth_sw_count += static_cast<uint>(m.task_depth_changed());
} /* collect() */

bool bi_tab_metrics_collector::csv_line_build(std::string& line) {
  if (!((timestep() + 1) % interval() == 0)) {
    return false;
  }
  /*
   * We want to capture average probability per robot, not per
   * timestep/interval, so we divide by the total # of task allocations
   * performed (# partitions + # no partitions).
   */
  double int_allocs = m_int_partition_count + m_int_no_partition_count;
  double cum_allocs = m_cum_partition_count + m_cum_no_partition_count;

  line += csv_entry_domavg(m_int_subtask1_count, int_allocs);
  line += csv_entry_domavg(m_cum_subtask1_count, cum_allocs);

  line += csv_entry_domavg(m_int_subtask2_count, int_allocs);
  line += csv_entry_domavg(m_cum_subtask2_count, cum_allocs);

  line += csv_entry_domavg(m_int_partition_count, int_allocs);
  line += csv_entry_domavg(m_cum_partition_count, cum_allocs);

  line += csv_entry_domavg(m_int_no_partition_count, int_allocs);
  line += csv_entry_domavg(m_cum_no_partition_count, cum_allocs);

  line += csv_entry_domavg(m_int_task_sw_count, int_allocs);
  line += csv_entry_domavg(m_cum_task_sw_count, cum_allocs);

  line += csv_entry_domavg(m_int_task_depth_sw_count, int_allocs);
  line += csv_entry_domavg(m_cum_task_depth_sw_count, cum_allocs);

  line += csv_entry_domavg(m_int_partition_prob, int_allocs);
  line += csv_entry_domavg(m_cum_partition_prob, cum_allocs);

  line += csv_entry_domavg(m_int_subtask_selection_prob, int_allocs);
  line += csv_entry_domavg(m_cum_subtask_selection_prob, cum_allocs);
  return true;
} /* store_foraging_stats() */

void bi_tab_metrics_collector::reset_after_interval(void) {
  m_int_subtask1_count = 0;
  m_int_subtask2_count = 0;
  m_int_partition_count = 0;
  m_int_no_partition_count = 0;
  m_int_task_sw_count = 0;
  m_int_task_depth_sw_count = 0;
  m_int_partition_prob = 0.0;
  m_int_subtask_selection_prob = 0.0;
} /* reset_after_interval() */

NS_END(metrics, rcppsw, tasks);
