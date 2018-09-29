/**
 * @file bifurcating_tab_metrics_collector.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_TASKS_BIFURCATING_TAB_METRICS_COLLECTOR_HPP_
#define INCLUDE_RCPPSW_METRICS_TASKS_BIFURCATING_TAB_METRICS_COLLECTOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
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
 * @class bifurcating_tab_metrics_collector
 * @ingroup metrics tasks
 *
 * @brief Collector for metrics for a specific bifurcating Task Allocation Block
 * (TAB), which consists of a partitionable task and its two subtasks.
 *
 * Metrics should only be collected upon completion/abortion of a task. Metrics
 * are written out at the specified interval.
 */
class bifurcating_tab_metrics_collector : public base_metrics_collector {
 public:
  struct bifurcating_tab_stats {
    /**
     * @brief # Times subtask 1 was chosen if partitioning was employed.
     */
    uint int_subtask1_count;

    /**
     * @brief # Times subtask 2 was chosen if partitioning was employed.
     */
    uint int_subtask2_count;

    /**
     * @brief # Times partitioning was employed when allocating a task.
     */
    uint int_partition_count;

    /**
     * @brief # Times partitioning was not employed when allocating a task.
     */
    uint int_no_partition_count;

    /**
     * @brief # Times when task allocation resulted in a different task being
     * executed than previous.
     */
    uint int_task_sw_count;

    /**
     * @brief # Times when task allocation resulted in a task of a different
     * depth being executed than previous.
     */
    uint int_task_depth_sw_count;

    uint cum_subtask1_count;
    uint cum_subtask2_count;
    uint cum_partition_count;
    uint cum_no_partition_count;
    uint cum_task_sw_count;
    uint cum_task_depth_sw_count;
  };

  /**
   * @param ofname Output file name.
   * @param interval Collection interval.
   */
  bifurcating_tab_metrics_collector(const std::string& ofname,
                                    uint interval);

  void reset(void) override;
  void collect(const rcppsw::metrics::base_metrics& metrics) override;
  void reset_after_interval(void) override;

  std::string csv_header_build(const std::string& header) override;
  bool csv_line_build(std::string& line) override;
  bifurcating_tab_stats stats(void) const { return m_stats; }

 private:
  // clang-format off
  struct bifurcating_tab_stats m_stats;
  // clang-format on
};

NS_END(tasks, metrics, rcppsw);


#endif /* INCLUDE_RCPPSW_METRICS_TASKS_BIFURCATING_TAB_METRICS_COLLECTOR_HPP_ */
