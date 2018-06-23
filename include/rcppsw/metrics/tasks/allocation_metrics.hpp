/**
 * @file allocation_metrics.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_TASKS_ALLOCATION_METRICS_HPP_
#define INCLUDE_RCPPSW_METRICS_TASKS_ALLOCATION_METRICS_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

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
 * @class allocation_metrics
 * @ingroup metrics
 *
 * @brief Interface defining metrics that can be collected on tasks during
 * allocation.
 */
class allocation_metrics : public virtual base_metrics {
 public:
  allocation_metrics(void) = default;
  ~allocation_metrics(void) override = default;

  /**
   * @brief This function should return \c TRUE, if a robot has chosen to employ
   * task partitioning when allocating itself its next task.
   */
  virtual bool employed_partitioning(void) const = 0;

  /**
   * @brief If a robot has chosen to employ task partitioning, this this
   * function should return the name of the subtask that was selected.
   *
   * It should only be called if \ref employed_partitioning() returns \c TRUE.
   */
  virtual std::string subtask_selection(void) const = 0;
};

NS_END(tasks, metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_TASKS_ALLOCATION_METRICS_HPP_ */
