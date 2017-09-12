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
#include "rcppsw/task_allocation/base_task.hpp"
#include "rcppsw/task_allocation/abort_probability.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class decomposable_task : public base_task {
 public:
  decomposable_task(const std::string& name,
                    const base_task& subtask1, const base_task& subtask2,
                    double alpha,
                    double abort_reactivity, double abort_offset) :
      base_task(name, alpha),
      m_abort_prob(abort_reactivity, abort_offset),
      m_subtask1(subtask1), m_subtask2(subtask2) {}

  double abort_prob(void) {
    return m_abort_prob.calc(this->exec_time(),
                             this->estimate(),
                             m_subtask1.estimate(),
                             m_subtask2.estimate());
  }

 private:
  abort_probability m_abort_prob;
  const base_task& m_subtask1;
  const base_task& m_subtask2;
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_DECOMPOSABLE_TASK_HPP_ */
