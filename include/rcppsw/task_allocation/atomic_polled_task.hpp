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
  atomic_polled_task(const std::string& name, polled_task* const parent,
              double estimate_alpha, taskable& mechanism) :
      polled_task(name, parent, estimate_alpha), m_mechanism(mechanism) {}

  /**
   * @brief Get the task sequence representing an \ref atomic_task.
   *
   * Since atomic tasks cannot be decompsed any futher, all sequences returned
   * from atomic tasks have exactly 1 element (this task).
   *
   * @param parent The parent of the task (can be NULL).
   */
  task_sequence<atomic_polled_task*> self_sequence(logical_task* const parent);
  void task_execute(void) { m_mechanism.task_execute(); }
  void task_reset(void) {m_mechanism.task_reset(); }
  bool task_finished(void) { return m_mechanism.task_finished(); }

 private:
  taskable& m_mechanism;
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_ATOMIC_POLLED_TASK_HPP_ */
