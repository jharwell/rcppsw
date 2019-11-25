/**
 * \file execution_metrics_collector.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
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
#include <atomic>

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
 * \class execution_metrics_collector
 * \ingroup metrics tasks
 *
 * \brief Collector for metrics for an executable task across executions of that
 * task.
 */
class execution_metrics_collector final : public base_metrics_collector,
                                    public er::client<execution_metrics_collector> {
 public:
  /**
   * \param ofname Output file name.
   * \param interval Collection interval.
   */
  execution_metrics_collector(const std::string& ofname, uint interval);

  void reset(void) override;
  void collect(const rcppsw::metrics::base_metrics& metrics) override;
  void reset_after_interval(void) override;

  std::list<std::string> csv_header_cols(void) const override;
  boost::optional<std::string> csv_line_build(void) override;

 private:
  struct stats {
    /**
     * \brief # Times the task has been completed.
     */
    std::atomic_uint complete_count{0};

    /**
     * \brief # Times the task has been aborted.
     */
    std::atomic_uint abort_count{0};

    /**
     * \brief # Times at their interface.
     */
    std::atomic_uint interface_count{0};

    /**
     * \brief Execution times of the task.
     */
    std::atomic_uint exec_time{};

    /**
     * \brief Interface time of the task.
     */
    std::atomic_uint interface_time{0};

    std::atomic_uint exec_estimate{0};
    std::atomic_uint interface_estimate{0};
  };

  /* clang-format off */
  struct stats m_interval{};
  struct stats m_cum{};

  /* clang-format on */
};

NS_END(tasks, metrics, rcppsw);


#endif /* INCLUDE_RCPPSW_METRICS_TASKS_EXECUTION_METRICS_COLLECTOR_HPP_ */
