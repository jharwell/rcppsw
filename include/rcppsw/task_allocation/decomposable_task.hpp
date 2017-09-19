/**
 * @file decomposable_task.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_DECOMPOSABLE_TASK_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_DECOMPOSABLE_TASK_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "rcppsw/task_allocation/logical_task.hpp"
#include "rcppsw/task_allocation/task_sequence.hpp"
#include "rcppsw/task_allocation/abort_probability.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template<class T1, class T2>
class decomposable_task : public logical_task {
 public:
  decomposable_task(const std::string& name, logical_task* const parent,
                    double alpha,
                    double abort_reactivity, double abort_offset) :
      logical_task(name, parent, alpha),
      m_abort_prob(abort_reactivity, abort_offset) {
  }

  double abort_prob(void) {
    return m_abort_prob.calc(this->exec_time(), this->estimate(),
                             m_subtask1->estimate(), m_subtask2->estimate());
  }

  /**
   * @brief Get the task sequence for a decomposable task.
   *
   * @param parent The parent for the task sequence. If NULL, the current object
   * is taken to be the parent of the task sequence.
   *
   * @return
   */
  task_sequence sequence(logical_task* const parent) {
    if (nullptr == parent) {
      return m_subtask1->sequence(this) + m_subtask2->sequence(this);
    } else {
      return m_subtask1->sequence(parent) + m_subtask2->sequence(parent);
    }
  }

 private:
  abort_probability m_abort_prob;
  T1 *const m_subtask1;
  T2 *const m_subtask2;
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_DECOMPOSABLE_TASK_HPP_ */
