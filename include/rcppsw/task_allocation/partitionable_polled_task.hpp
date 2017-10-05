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
#include <list>

#include "rcppsw/task_allocation/polled_task.hpp"
#include "rcppsw/task_allocation/task_sequence.hpp"
#include "rcppsw/task_allocation/abort_probability.hpp"

/*******************************************************************************
 * Namespaces
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
class partitionable_polled_task : public polled_task {
  static_assert(std::is_base_of<polled_task, T1>::value,
                "FATAL: template argument must be a polled task");
  static_assert(std::is_base_of<polled_task, T2>::value,
                "FATAL: template argument must be a polled task");

 public:
  partitionable_polled_task(const std::string& name, polled_task* const parent,
                    double alpha,
                    double abort_reactivity, double abort_offset) :
      polled_task(name, parent, alpha),
      m_abort_prob(abort_reactivity, abort_offset),
      m_sequence() {}

  double abort_prob(void) {
    return m_abort_prob.calc(this->exec_time(), this->estimate(),
                             m_subtask1->estimate(), m_subtask2->estimate());
  }
  const T1* subtask1(void) const { return m_subtask1; }
  const T2* subtask2(void) const { return m_subtask2; }
  void self_sequence(const std::list<polled_task>& tasks) {
    m_sequence.set_tasks(tasks, this);
  }
  task_sequence<logical_task> self_sequence(
      __unused logical_task* const parent) {
    return m_sequence;
  }

 private:
  abort_probability m_abort_prob;
  task_sequence<polled_task> m_sequence;
  T1 *const m_subtask1;
  T2 *const m_subtask2;
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_PARTITIONABLE_POLLED_TASK_HPP_ */
