/**
 * @file distribution_metrics_collector.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_TASKS_DISTRIBUTION_METRICS_COLLECTOR_HPP_
#define INCLUDE_RCPPSW_METRICS_TASKS_DISTRIBUTION_METRICS_COLLECTOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <string>

#include "rcppsw/metrics/base_metrics_collector.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics, tasks);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class distribution_metrics_collector
 * @ingroup metrics tasks
 *
 * @brief Collector for metrics about the current distribution of tasks in a
 * collection of agents executing tasks. Metrics are written out at the
 * specified interval.
 */
class distribution_metrics_collector : public base_metrics_collector {
 public:
  /**
   * @param ofname Output file name.
   * @param interval Collection interval.
   */
  distribution_metrics_collector(const std::string& ofname,
                                 uint interval,
                                 uint decomposition_depth);

  void reset(void) override;
  void collect(const rcppsw::metrics::base_metrics& metrics) override;
  void reset_after_interval(void) override;

  std::string csv_header_build(const std::string& header) override;
  bool csv_line_build(std::string& line) override;

 private:
  // clang-format off
  std::vector<uint> m_int_depth_counts;
  std::vector<uint> m_int_task_counts;
  std::vector<uint> m_int_tab_counts;
  std::vector<uint> m_cum_depth_counts;
  std::vector<uint> m_cum_task_counts;
  std::vector<uint> m_cum_tab_counts;
  // clang-format on
};

NS_END(tasks, metrics, rcppsw);


#endif /* INCLUDE_RCPPSW_METRICS_TASKS_DISTRIBUTION_METRICS_COLLECTOR_HPP_ */
