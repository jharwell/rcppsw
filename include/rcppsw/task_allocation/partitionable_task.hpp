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
#include <string>
#include <list>
#include "rcppsw/task_allocation/logical_task.hpp"
#include "rcppsw/task_allocation/abort_probability.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Represents a task that can be partitioned at runtime into two subtasks,
 * which may or may not themselves be partitionable.
 *
 * The \ref task_sequence that represents this class is not a template or
 * constructor argument, so that \ref partitionable_task instances can be
 * constructed after their simpler, constituent subtasks.
 */
template<class T1, class T2>
class partitionable_task : public logical_task {
  static_assert(std::is_base_of<logical_task, T1>::value,
                "FATAL: template argument must be a logical_task");
  static_assert(std::is_base_of<logical_task, T2>::value,
                "FATAL: template argument must be a logical_task");

 public:
  partitionable_task(const std::string& name, logical_task* const parent,
                    double alpha,
                    double abort_reactivity, double abort_offset) :
      logical_task(name, parent, alpha),
      m_abort_prob(abort_reactivity, abort_offset),
      m_sequence() {}

  double abort_prob(void) {
    return m_abort_prob.calc(this->exec_time(), this->estimate(),
                             m_subtask1->estimate(), m_subtask2->estimate());
  }
  const T1* subtask1(void) const { return m_subtask1; }
  const T2* subtask2(void) const { return m_subtask2; }
  void self_sequence(const std::list<logical_task>& tasks) {
    m_sequence.set_tasks(tasks, this);
  }
  task_sequence<logical_task> self_sequence(
      __unused logical_task* const parent) {
    return m_sequence;
  }

 private:
  abort_probability m_abort_prob;
  task_sequence<logical_task> m_sequence;
  T1 *const m_subtask1;
  T2 *const m_subtask2;
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_PARTITIONABLE_TASK_HPP_ */
