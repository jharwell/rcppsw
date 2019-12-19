/**
 * \file bi_tdgraph_metrics_collector.cpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
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
#include "rcppsw/ta/polled_task.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics, tasks);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
bi_tdgraph_metrics_collector::bi_tdgraph_metrics_collector(
    const std::string& ofname,
    uint interval,
    uint decomposition_depth)
    : base_metrics_collector(ofname, interval),
      m_int_depth_counts(decomposition_depth + 1),
      m_int_task_counts(
          static_cast<uint>(std::pow(2, decomposition_depth + 1) - 1)),
      m_int_tab_counts(
          static_cast<uint>(std::pow(2, decomposition_depth - 1) + 1)),
      m_cum_depth_counts(decomposition_depth + 1),
      m_cum_task_counts(
          static_cast<uint>(std::pow(2, decomposition_depth + 1) - 1)),
      m_cum_tab_counts(
          static_cast<uint>(std::pow(2, decomposition_depth - 1) + 1)) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
std::list<std::string> bi_tdgraph_metrics_collector::csv_header_cols(void) const {
  std::list<std::string> cols = dflt_csv_header_cols();

  for (size_t i = 0; i < m_int_depth_counts.size(); ++i) {
    cols.push_back("int_avg_depth" + rcppsw::to_string(i) + "_count");
  } /* for(i..) */

  for (size_t i = 0; i < m_cum_depth_counts.size(); ++i) {
    cols.push_back("cum_avg_depth" + rcppsw::to_string(i) + "_count");
  } /* for(i..) */

  for (size_t i = 0; i < m_int_task_counts.size(); ++i) {
    cols.push_back("int_avg_task" + rcppsw::to_string(i) + "_count");
  } /* for(i..) */

  for (size_t i = 0; i < m_cum_task_counts.size(); ++i) {
    cols.push_back("cum_avg_task" + rcppsw::to_string(i) + "_count");
  } /* for(i..) */

  for (size_t i = 0; i < m_int_tab_counts.size(); ++i) {
    cols.push_back("int_avg_tab" + rcppsw::to_string(i) + "_count");
  } /* for(i..) */

  for (size_t i = 0; i < m_cum_tab_counts.size(); ++i) {
    cols.push_back("cum_avg_tab" + rcppsw::to_string(i) + "_count");
  } /* for(i..) */
  return cols;
} /* csv_header_cols() */

void bi_tdgraph_metrics_collector::reset(void) {
  base_metrics_collector::reset();
  reset_after_interval();
} /* reset() */

void bi_tdgraph_metrics_collector::collect(
    const rcppsw::metrics::base_metrics& metrics) {
  auto& m = dynamic_cast<const bi_tdgraph_metrics&>(metrics);
  ++m_int_depth_counts[m.current_task_depth()];
  ++m_int_task_counts[m.current_task_id()];
  ++m_int_tab_counts[m.current_task_tab()];

  ++m_cum_depth_counts[m.current_task_depth()];
  ++m_cum_task_counts[m.current_task_id()];
  ++m_cum_tab_counts[m.current_task_tab()];
} /* collect() */

boost::optional<std::string> bi_tdgraph_metrics_collector::csv_line_build() {
  if (!((timestep() + 1) % interval() == 0)) {
    return boost::none;
  }
  std::string line;

  for (auto& count : m_int_depth_counts) {
    line += csv_entry_intavg(count);
  } /* for(count..) */

  for (auto& count : m_cum_depth_counts) {
    line += csv_entry_tsavg(count);
  } /* for(&count..) */

  for (auto& count : m_int_task_counts) {
    line += csv_entry_intavg(count);
  } /* for(&count..) */

  for (auto& count : m_cum_task_counts) {
    line += csv_entry_tsavg(count);
  } /* for(&count..) */

  for (auto& count : m_int_tab_counts) {
    line += csv_entry_intavg(count);
  } /* for(&count..) */

  for (size_t i = 0; i < m_cum_tab_counts.size() - 1; ++i) {
    line += csv_entry_tsavg(m_cum_tab_counts[i]);
  } /* for(i..) */

  line += csv_entry_tsavg(m_cum_tab_counts[m_cum_tab_counts.size() - 1], true);
  return boost::make_optional(line);
} /* store_foraging_stats() */

void bi_tdgraph_metrics_collector::reset_after_interval(void) {
  for (size_t i = 0; i < m_int_depth_counts.size(); ++i) {
    std::atomic_init(&m_int_depth_counts[i], 0U);
  } /* for(i..) */

  for (size_t i = 0; i < m_int_task_counts.size(); ++i) {
    std::atomic_init(&m_int_task_counts[i], 0U);
  } /* for(i..) */

  for (size_t i = 0; i < m_int_tab_counts.size(); ++i) {
    std::atomic_init(&m_int_tab_counts[i], 0U);
  } /* for(i..) */
} /* reset_after_interval() */

NS_END(metrics, rcppsw, tasks);
