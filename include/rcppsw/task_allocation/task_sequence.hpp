/**
 * @file task_sequence.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_TASK_SEQUENCE_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_TASK_SEQUENCE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class logical_task;
class atomic_task;

class task_sequence {
 public:
  task_sequence(std::list<atomic_task*>& tasks, logical_task* const parent) :
      m_parent(parent), m_current_task(tasks.begin()), m_tasks(tasks) {}

  const logical_task* parent(void) const { return m_parent; }
  atomic_task* current_task(void) { return *m_current_task; }
  void advance_task(void) { ++m_current_task; }

 private:
  logical_task* const m_parent;
  std::list<atomic_task*>::iterator m_current_task;
  std::list<atomic_task*> m_tasks;
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_TASK_SEQUENCE_HPP_ */
