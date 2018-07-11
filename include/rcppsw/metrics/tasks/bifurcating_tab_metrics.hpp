/**
 * @file bifurcating_tab_metrics.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_TASKS_BIFURCATING_TAB_METRICS_HPP_
#define INCLUDE_RCPPSW_METRICS_TASKS_BIFURCATING_TAB_METRICS_HPP_

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
 * @class bifurcating_tab_metrics
 * @ingroup metrics tasks
 *
 * @brief Interface defining metrics that can be collected on tasks as they are
 * executed.
 */
class bifurcating_tab_metrics : public virtual base_metrics {
 public:
  bifurcating_tab_metrics(void) = default;
  ~bifurcating_tab_metrics(void) override = default;

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
   * @return Valid only when \ref has_new_allocation() returns \c TRUE.
   */
  virtual bool employed_partitioning(void) const = 0;

  /**
   * @brief This function should return \c TRUE if the task it is currently
   * executing is different than the one that it executed last time (this is
   * the definition of changing allocation).
   *
   * @return Undefined unless \ref has_new_allocation() returns \c TRUE.
   */
  virtual bool task_changed(void) const = 0;
};

NS_END(tasks, metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_TASKS_BIFURCATING_TAB_METRICS_HPP_ */
