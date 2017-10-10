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
#include "rcppsw/task_allocation/polled_task.hpp"
#include "rcppsw/task_allocation/partitionable_task.hpp"
#include "rcppsw/task_allocation/task_sequence.hpp"
#include "rcppsw/task_allocation/abort_probability.hpp"
#include "rcppsw/task_allocation/partition_probability.hpp"
#include "rcppsw/task_allocation/task_params.hpp"

/*******************************************************************************
 * Namespacesp
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A \ref partitionable_task whose execution is polled periodically by
 * the user to see if it has finished yet.
 */
template<class T1, class T2>
class partitionable_polled_task : public polled_task,
                                  public partitionable_task<T1, T2> {
  static_assert(std::is_base_of<polled_task, T1>::value,
                "FATAL: template argument must be a polled task");
  static_assert(std::is_base_of<polled_task, T2>::value,
                "FATAL: template argument must be a polled task");

 public:
  partitionable_polled_task(const std::string& name,
                            const struct task_params* const params,
                            std::unique_ptr<taskable>& mechanism,
                            polled_task* const parent = nullptr) :
      polled_task(name, params->estimation_alpha, mechanism, parent),
      partitionable_task<T1, T2>(),
      m_abort_prob(params->reactivity, params->abort_offset),
      m_partition_prob(params->reactivity) {}

  /**
   * @brief Get the probability of aborting a partitionable task.
   *
   * If the atomic task has a parent, then it is part of a partitioning set, and
   * so return the abort probability of that set. Otherwise, the probability of
   * aborting an atomic task is 0 (DUH).
   */
  double abort_prob(void) override {
    return m_abort_prob.calc(this->exec_time(), this->estimate(),
                             this->partition1()->estimate(),
                             this->partition2()->estimate());
  }
  double partition_prob(void) override {
    return m_partition_prob.calc(this->estimate(),
                                 this->partition1()->estimate(),
                                 this->partition2()->estimate());
  }


 private:
  abort_probability m_abort_prob;
  partition_probability m_partition_prob;
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_PARTITIONABLE_POLLED_TASK_HPP_ */
