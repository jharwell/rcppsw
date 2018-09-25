/**
 * @file partitionable_polled_task.hpp
 *
 * @copyright 2017 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_PARTITIONABLE_POLLED_TASK_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_PARTITIONABLE_POLLED_TASK_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "rcppsw/task_allocation/partitionable_task.hpp"
#include "rcppsw/task_allocation/polled_task.hpp"

/*******************************************************************************
 * Namespacesp
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class partitionable_polled_task
 * @ingroup task_allocation
 *
 * @brief A \ref partitionable_task whose execution is polled periodically by
 * the user/executive to see if it has finished yet.
 */
class partitionable_polled_task : public polled_task, public partitionable_task {
 public:
  partitionable_polled_task(const std::string& name,
                            const struct partitionable_task_params* c_params,
                            std::unique_ptr<taskable> mechanism);


  /**
   * @brief Initialize the task with the specified last partition and a random
   * exec time estimate within the bounds specified
   *
   * @param partition The last subtask executed. This has to be passed in, and
   * not computed internally, because the task does not have pointers/references
   * to its children.
   * @param lb Lower bound for exec estimate.
   * @param ub Upper bound for exec estimate.
   */
  void init_random(const polled_task* partition,
                   uint lb, uint ub);
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_PARTITIONABLE_POLLED_TASK_HPP_ */
