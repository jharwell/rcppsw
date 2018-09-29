/**
 * @file distribution_metrics.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_TASKS_DISTRIBUTION_METRICS_HPP_
#define INCLUDE_RCPPSW_METRICS_TASKS_DISTRIBUTION_METRICS_HPP_

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
 * @class distribution_metrics
 * @ingroup metrics tasks
 *
 * @brief Interface defining metrics that can be collected about the current
 * task distribution of a \ref tdgraph.
 *
 */
class distribution_metrics : public virtual base_metrics {
 public:
  distribution_metrics(void) = default;
  ~distribution_metrics(void) override = default;

  /**
   * @brief Return the depth of the curent task within the task decomposition
   * graph, or -1 if there is no current task.
   */
  virtual int current_task_depth(void) const = 0;

  /**
   * @brief Return a uuid for the current task, for use in calculating overall
   * task distribution, or -1 if no current task.
   */
  virtual int current_task_id(void) const = 0;

  /**
   * @brief Return a uuid for the TAB that the current task belongs to.
   */
  virtual int current_task_tab(void) const = 0;
};

NS_END(tasks, metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_TASKS_DISTRIBUTION_METRICS_HPP_ */
