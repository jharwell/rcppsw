/**
 * @file management_metrics.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_TASKS_MANAGEMENT_METRICS_HPP_
#define INCLUDE_RCPPSW_METRICS_TASKS_MANAGEMENT_METRICS_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "rcppsw/common/common.hpp"
#include "rcppsw/metrics/tasks/allocation_metrics.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics, tasks);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class management_metrics
 * @ingroup metrics
 *
 * @brief Interface defining "meta" metrics relating to tasks, such as:
 *
 * - When a task is aborted.
 * - When a new task is allocated.
 */
class management_metrics : public virtual allocation_metrics {
 public:
  management_metrics(void) = default;
  ~management_metrics(void) override = default;

  /**
   * @brief This function should return \c TRUE if the robot has allocated
   * itself a NEW task and has started executing it.
   */
  virtual bool has_new_allocation(void) const = 0;

  /**
   * @brief This function should return \c TRUE if the task it is currently
   * executing is different than the one that it executed last time (this is
   * the definition of changing allocation).
   */
  virtual bool allocation_changed(void) const = 0;

  /**
   * @brief This function should return \c TRUE if the robot has just aborted
   * its current task.
   */
  virtual bool task_aborted(void) const = 0;

  /**
   * @brief Get the name of task that is currently being executed by a
   * robot.
   */
  virtual std::string current_task_name(void) const = 0;


  /**
   * @brief This function should return \c TRUE when a robot has just finished
   * its task (not aborting it).
   */
  virtual bool task_finished(void) const = 0;

  /**
   * @brief This function should return the execution time of the most recently
   * finished task.
   */
  virtual double task_last_exec_time(void) const = 0;
};

NS_END(tasks, metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_TASKS_MANAGEMENT_METRICS_HPP_ */
