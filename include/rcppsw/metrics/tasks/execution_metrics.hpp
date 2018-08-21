/**
 * @file execution_metrics.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_TASKS_EXECUTION_METRICS_HPP_
#define INCLUDE_RCPPSW_METRICS_TASKS_EXECUTION_METRICS_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"
#include "rcppsw/metrics/base_metrics.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics, tasks);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class execution_metrics
 * @ingroup metrics tasks
 *
 * @brief Interface defining metrics that can be collected on tasks as they are
 * executed.
 */
class execution_metrics : public virtual base_metrics {
 public:
  execution_metrics(void) = default;
  ~execution_metrics(void) override = default;

  /**
   * @brief If \c TRUE, then the robot is currently at the task interface for
   * this task.
   */
  virtual bool task_at_interface(void) const = 0;

  /**
   * @brief This function should return the execution time of the most recent
   * execution of this task.
   */
  virtual double task_last_exec_time(void) const = 0;

  /**
   * @brief This function should return the interface time of the most recent
   * execution of task.
   */
  virtual double task_last_interface_time(void) const = 0;

  /**
   * @brief This function should return \c TRUE when the task has been completed
   * (not aborted).
   */
  virtual bool task_completed(void) const = 0;

  /**
   * @brief This function should return \c TRUE if the task has been aborted
   * (not completed).
   */
  virtual bool task_aborted(void) const = 0;
};

NS_END(tasks, metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_TASKS_EXECUTION_METRICS_HPP_ */
