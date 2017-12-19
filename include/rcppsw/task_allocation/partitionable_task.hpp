/**
 * @file partitionable_task.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_PARTITIONABLE_TASK_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_PARTITIONABLE_TASK_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/er/client.hpp"
#include "rcppsw/task_allocation/partition_probability.hpp"
#include "rcppsw/task_allocation/subtask_selection_probability.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

class executable_task;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A task that is capable of being partitioned into two subtasks that
 * when executed in sequence have the sum effect as the parent task.
 */
class partitionable_task : public er::client {
 public:
  partitionable_task(const std::shared_ptr<er::server>& server,
                     const struct partitionable_task_params* c_params);

  virtual ~partitionable_task(void) = default;

  partitionable_task(const partitionable_task& other) = delete;
  partitionable_task& operator=(const partitionable_task& other) = delete;

  executable_task* partition(void);

  void update_partition_prob(const time_estimate& task,
                             const time_estimate& subtask1,
                             const time_estimate& subtask2);

  double partition_prob(void) const { return m_partition_prob.last_result(); }
  void last_partition(executable_task* last_partition) {
    m_last_partition = last_partition;
  }
  void partition1(executable_task* partition1) { m_partition1 = partition1; }
  void partition2(executable_task* partition2) { m_partition2 = partition2; }

  executable_task* partition1(void) const { return m_partition1; }
  executable_task* partition2(void) const { return m_partition2; }

 private:
  bool m_always_partition;
  bool m_never_partition;
  executable_task* m_partition1;
  executable_task* m_partition2;
  executable_task* m_last_partition;
  subtask_selection_probability m_selection_prob;
  partition_probability m_partition_prob;
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_PARTITIONABLE_TASK_TASK_HPP_ */
