/**
 * @file atomic_polled_task.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_ATOMIC_POLLED_TASK_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_ATOMIC_POLLED_TASK_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <string>
#include "rcppsw/task_allocation/task_sequence.hpp"
#include "rcppsw/task_allocation/polled_task.hpp"
#include "rcppsw/task_allocation/polled_simple_fsm.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Represents a task that will be executed start to finish without
 * interruption, at least in the sense of being aborted.
 */
class atomic_polled_task : public polled_task {
 public:
  atomic_polled_task(const std::string& name, double estimate_alpha,
                     taskable * const mechanism,
                     polled_task* const parent = nullptr) :
      polled_task(name, estimate_alpha, mechanism, parent) {}

  /**
   * @brief Get the probability of aborting an atomic task.
   *
   * If the atomic task has a parent, then it is part of a partitioning set, and
   * so return the abort probability of that set. Otherwise, the probability of
   * aborting an atomic task is 0 (DUH).
   */
  double abort_prob(void) override {
    if (parent()) {
      return parent()->abort_prob();
    } else {
      return 0.0;
    }
  }
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_ATOMIC_POLLED_TASK_HPP_ */
