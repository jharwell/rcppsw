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
#include <list>
#include <string>

#include "rcppsw/metrics/base_metrics_collector.hpp"
#include "rcppsw/er/client.hpp"
#include "rcppsw/ta/time_estimate.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, metrics, tasks);
namespace ta = rcppsw::ta;

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
class execution_metrics_collector final : public base_metrics_collector,
                                    public er::client<execution_metrics_collector> {
 public:
  /**
   * @param ofname Output file name.
   * @param interval Collection interval.
   */
  execution_metrics_collector(const std::string& ofname, uint interval);

  void reset(void) override;
  void collect(const rcppsw::metrics::base_metrics& metrics) override;
  void reset_after_interval(void) override;

  std::list<std::string> csv_header_cols(void) const override;
  bool csv_line_build(std::string& line) override;

 private:
  /**
   * @brief # Times the task has been completed within an interval.
   */
  uint              m_int_complete_count{0};

  /**
   * @brief # Times the task has been aborted within an interval.
   */
  uint              m_int_abort_count{0};

  /**
   * @brief # Times at their interface during an interval.
   */
  uint              m_int_interface_count{0};

  /**
   * @brief Execution times of the task within an interval.
   */
  double            m_int_exec_time{};

  /**
   * @brief Interface time of the task within an interval.
   */
  double            m_int_interface_time{0.0};

  ta::time_estimate m_int_exec_estimate{0};
  ta::time_estimate m_int_interface_estimate{0};

  uint              m_cum_complete_count{0};
  uint              m_cum_abort_count{0};
  uint              m_cum_interface_count{0};
  double            m_cum_exec_time{0.0};
  double            m_cum_interface_time{0.0};
  ta::time_estimate m_cum_exec_estimate{0};
  ta::time_estimate m_cum_interface_estimate{0};
};

NS_END(tasks, metrics, rcppsw);


#endif /* INCLUDE_RCPPSW_METRICS_TASKS_EXECUTION_METRICS_COLLECTOR_HPP_ */
