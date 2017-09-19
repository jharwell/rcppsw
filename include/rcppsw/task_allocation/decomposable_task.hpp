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
  decomposable_task(const std::string& name,
                    double alpha,
                    double abort_reactivity, double abort_offset) :
      logical_task(name, alpha),
      m_abort_prob(abort_reactivity, abort_offset) {}

  double abort_prob(void) {
    return m_abort_prob.calc(this->exec_time(), this->estimate(),
                             m_subtask1.estimate(), m_subtask2.estimate());
  }
  task_sequence sequence(void) {
    return m_subtask1.sequence() + m_subtask2.sequence();
  }

 private:
  abort_probability m_abort_prob;
  T1 m_subtask1;
  T2 m_subtask2;
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_DECOMPOSABLE_TASK_HPP_ */
