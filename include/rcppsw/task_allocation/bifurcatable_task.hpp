/**
 * @file bifurcatable_task.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_BIFURCATABLE_TASK_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_BIFURCATABLE_TASK_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/er/client.hpp"
#include "rcppsw/task_allocation/partition_probability.hpp"
#include "rcppsw/task_allocation/subtask_selection_probability.hpp"
#include "rcppsw/metrics/tasks/allocation_metrics.hpp"
#include "rcppsw/task_allocation/task_graph_vertex.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

class executable_task;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class bifurcatable_task
 * @ingroup task_allocation
 *
 * @brief A task that is capable of being partitioned into two subtasks that
 * when executed in sequence have the sum effect as the parent task.
 *
 * This class MUST be instantiated inside of \ref task_graph_vertex, and be
 * manipulated through shared_ptr.
 */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
class bifurcatable_task : public er::client,
                           public std::enable_shared_from_this<executable_task>,
                           public metrics::tasks::allocation_metrics {
 public:
  bifurcatable_task(const std::string& er_parent,
                     const struct bifurcatable_task_params* c_params);

  ~bifurcatable_task(void) override = default;

  bifurcatable_task(const bifurcatable_task& other) = delete;
  bifurcatable_task& operator=(const bifurcatable_task& other) = delete;

  /* allocation metrics */
  bool employed_partitioning(void) const override;
  std::string subtask_selection(void) const override;

  /**
   * @brief Partition the task according to the configured method, and return a
   * new task to execute.
   *
   * @param partition1 The first of the two subtasks the bifurcatable task was
   * initialized with.
   * @param partition2 The first of the two subtasks the bifurcatable task was
   * initialized with.
   *
   * @return The new task to execute.
   */
  task_graph_vertex partition(
      const task_graph_vertex& partition1,
      const task_graph_vertex& partition2);

  /**
   * @brief Update the partition probalitity of the current task.
   *
   * @param task The estimate of execution time for unpartitioned task.
   * @param subtask1 The estimate of execution time for partition 1.
   * @param subtask2 The estimate of execution time for partition 2.
   */
  void update_partition_prob(const time_estimate& task,
                             const time_estimate& subtask1,
                             const time_estimate& subtask2);

  /**
   * @brief Get the current partition probability.
   */
  double partition_prob(void) const { return m_partition_prob.last_result(); }

  /**
   * @brief Set subtask that was most recently selected to run when partitioning
   * was employed. Needed for some subtask selection methods.
   */
  void last_partition(const task_graph_vertex& last_partition) {
    m_last_partition = last_partition;
  }

 private:
  // clang-format off
  bool                          m_always_partition;
  bool                          m_never_partition;
  bool                          m_employed_partitioning{false};
  task_graph_vertex             m_last_partition{nullptr};
  subtask_selection_probability m_selection_prob;
  partition_probability         m_partition_prob;
  // clang-format on
};
#pragma GCC diagnostic pop
NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_BIFURCATABLE_TASK_TASK_HPP_ */
