/**
 * @file bi_tab_metrics.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_TASKS_BI_TAB_METRICS_HPP_
#define INCLUDE_RCPPSW_METRICS_TASKS_BI_TAB_METRICS_HPP_

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
 * @class bi_tab_metrics
 * @ingroup metrics tasks
 *
 * @brief Interface defining metrics that can be collected about the task
 * allocation each robot performs.
 *
 */
class bi_tab_metrics : public virtual base_metrics {
 public:
  bi_tab_metrics(void) = default;
  ~bi_tab_metrics(void) override = default;

  /**
   * @brief This function should return if subtask1 is currently the active
   * task.
   *
   * @return Valid at any time.
   */
  virtual bool subtask1_active(void) const = 0;

  /**
   * @brief This function should return if subtask2 is currently the active
   * task.
   *
   * @return Valid at any time.
   */
  virtual bool subtask2_active(void) const = 0;

  /**
   * @brief This function should return if the root is currently the active
   * task.
   *
   * @return Valid at any time.
   */
  virtual bool root_active(void) const = 0;

  /**
   * @brief This function should return \c TRUE, if a robot has chosen to employ
   * task partitioning when allocating itself its next task.
   *
   * @return Valid only when \ref task_changed() returns \c TRUE.
   */
  virtual bool employed_partitioning(void) const = 0;

  /**
   * @brief This function should return \c TRUE if the task that has just been
   * allocated is different than the one that it executed last time (this is the
   * definition of changing allocation).
   *
   * @return Undefined unless \ref task_changed() returns \c TRUE.
   */
  virtual bool task_changed(void) const = 0;

  /**
   * @brief This function should return \c TRUE iff the task that has just
   * been allocated is a different depth in the \ref tdgraph than the previous
   * task.
   *
   * @return Undefined unless \ref task_changed() returns \c TRUE.
   */
  virtual bool task_depth_changed(void) const = 0;

  /**
   * @brief Return the current partitioning probability for the root task in the
   * TAB.
   */
  virtual double partition_prob(void) const = 0;

  /**
   * @brief Return the current subtask selection probability for the root task
   * in the TAB.
   */
  virtual double subtask_selection_prob(void) const = 0;
};

NS_END(tasks, metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_TASKS_BI_TAB_METRICS_HPP_ */
