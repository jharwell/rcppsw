/**
 * @file execution_metrics_collector.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_TASKS_EXECUTION_METRICS_COLLECTOR_HPP_
#define INCLUDE_RCPPSW_METRICS_TASKS_EXECUTION_METRICS_COLLECTOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/metrics/base_metrics_collector.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics, tasks);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class execution_metrics_collector
 * @ingroup metrics tasks
 *
 * @brief Collector for metrics for an executable task across executions of that
 * task.
 */
class execution_metrics_collector : public base_metrics_collector {
 public:
  /**
   * @param ofname Output file name.
   * @param interval Collection interval.
   */
  execution_metrics_collector(const std::string& ofname, uint interval);

  void reset(void) override;
  void collect(const rcppsw::metrics::base_metrics& metrics) override;
  void reset_after_interval(void) override;

  std::string csv_header_build(const std::string& header) override;
  bool csv_line_build(std::string& line) override;

 private:
  struct execution_stats {
    /**
     * @brief Name of task.
     */
    std::string name{""};

    /**
     * @brief # Times the task has been completed within an interval.
     */
    uint        complete_count{0};


    /**
     * @brief # Times the task has been aborted within an interval.
     */
    uint        abort_count{0};

    /**
     * @brief Cumulative execution time of the task within an interval.
     */
    double      cum_exec_time{0.0};

    /**
     * @brief Cumulative interface time of the task within an interval.
     */
    double      cum_interface_time{0.0};
  };

  struct execution_stats m_stats;
};

NS_END(tasks, metrics, rcppsw);


#endif /* INCLUDE_RCPPSW_METRICS_TASKS_EXECUTION_METRICS_COLLECTOR_HPP_ */
