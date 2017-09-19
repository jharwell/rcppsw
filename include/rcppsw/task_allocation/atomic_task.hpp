/**
 * @file atomic_task.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_ATOMIC_TASK_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_ATOMIC_TASK_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <string>

#include "rcppsw/task_allocation/task_sequence.hpp"
#include "rcppsw/task_allocation/logical_task.hpp"
#include "rcppsw/task_allocation/taskable_fsm.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class atomic_task : public logical_task, public taskable {
 public:
  atomic_task(const std::string& name, logical_task* const parent,
              double estimate_alpha, taskable_fsm& fsm) :
      logical_task(name, parent, estimate_alpha), m_fsm(fsm) {}

  task_sequence sequence(logical_task* const parent) {
    std::list<atomic_task*> tasks;
    tasks.push_back(this);
    return task_sequence(tasks, parent);
  }
  void task_start(void) { m_fsm.task_start(); }
  void task_reset(void) {m_fsm.task_reset(); }
  bool task_finished(void) { return m_fsm.task_finished(); }

 private:
  taskable_fsm& m_fsm;
};

NS_END(task_al.location, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_ATOMIC_TASK_HPP_ */
