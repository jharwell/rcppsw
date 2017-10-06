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

/**
 * @brief A sequenc of tasks that represents how to execute another, higher
 * level task.
 */

template<class TaskTypePtr>
class task_sequence {
 public:
  /* constructors */
  task_sequence(void) :
      m_parent(nullptr), m_current_task(nullptr), m_tasks() {}
  explicit task_sequence(std::list<TaskTypePtr>& tasks) :
      m_parent(nullptr), m_current_task(tasks.begin()), m_tasks(tasks) {}
  task_sequence(std::list<TaskTypePtr>& tasks, logical_task* const parent) :
      m_parent(parent), m_current_task(tasks.begin()), m_tasks(tasks) {}
  task_sequence(const task_sequence& other) :
      m_parent(other.m_parent), m_current_task(other.m_current_task),
      m_tasks(other.m_tasks) {}

  /* member functions */
  /**
   * @brief Set the tasks and parent associated with the sequence.
   */
  void set_tasks(std::list<TaskTypePtr> tasks, logical_task* const parent) {
    m_tasks = tasks; m_current_task(tasks.begin());
    m_parent = parent;
  }

  void parent(logical_task* const parent) { m_parent = parent; }
  const logical_task* parent(void) const { return m_parent; }

  /**
   * @brief Get a reference to the current task in the task sequence.
   */
  TaskTypePtr current_task(void) { return *m_current_task; }

  /**
   * @brief Advance the task sequence to the next task.
   */
  void advance_task(void) { ++m_current_task; }

 private:
  task_sequence& operator=(const task_sequence& other) = delete;

  logical_task* const m_parent;
  typename std::list<TaskTypePtr>::iterator m_current_task;
  typename std::list<TaskTypePtr> m_tasks;
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_TASK_SEQUENCE_HPP_ */
