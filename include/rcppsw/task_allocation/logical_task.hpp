/**
 * @file logical_task.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_LOGICAL_TASK_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_LOGICAL_TASK_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <list>
#include "rcppsw/task_allocation/time_estimate.hpp"
#include "rcppsw/task_allocation/task_sequence.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Represents the logical concept of a task, which encompasses:
 *
 * - A possibly updated estimate of the time it takes to do a task. If a task is
 *   only made to be executed once, then this field is unused.
 * - A method of decomposing this (possibly decomposable) task into a sequence
 *   of simpler tasks. Each "simpler" task can have a parent.
 */

class logical_task {
 public:
  explicit logical_task(const std::string& name, logical_task* const parent,
                        double estimate_alpha) :
      m_exec_time(0.0), m_name(name), m_parent(parent),
      m_estimate(estimate_alpha) {}
  logical_task(const logical_task& other) :
      m_exec_time(other.m_exec_time), m_name(other.m_name),
      m_parent(other.m_parent), m_estimate(other.m_estimate) {}

  virtual ~logical_task(void) {}

  /**
   * @brief Get the name of the task
   */
  const std::string& name(void) const { return m_name; }

  /**
   * @brief Get the current estimate of the task's execution time.
   *
   * This is NOT updated at the end of the \ref task_execute() function, as it
   * is possible that some logical tasks are only run once, and therefore the
   * execution time is irrelevant, or that the user does not care how long a
   * task takes, only that it finishes.
   */
  const time_estimate& estimate(void) const { return m_estimate; }

  /**
   * @brief Update the current estimate of the task execution time by using a
   * weighted sum of the previous estimate and the new value. See
   * \ref time_estimate.
   *
   * @param last_measure The last measured execution time, in seconds.
   */
  void update_estimate(double last_measure) { m_estimate.calc(last_measure); }

  /**
   * @brief The method that all tasks must define that specifies how to execute
   * the task.
   *
   * Even though all the information needed to execute a task is contained in
   * \ref self_sequence(), derived classes may also wish to insert additional
   * logging, etc. in between executing the tasks that comprise this logical
   * task. Thus, the need for this function.
   */
  virtual void task_execute(void) = 0;

  /**
   * @brief Compute the sequence of subtasks that, in essence, define this task.
   *
   * @param parent The parent task. For \ref partionable_task instances, this
   * value will always be unused, as a \ref partitionable_task instance will
   * always be the parent of the task sequence that comprises it. However, for
   * \ref atomic_task instances, this CAN be used, if the \ref atomic_task is
   * executed as part of a larger task sequence. If the \ref atomic_task is
   * executed in a standalone fashion, then it is unused, as before.
   *
   * @return A \ref task_sequence of \ref logical_task instances (really
   * pointers to said instances). For \ref atomic_task instances, this should
   * always just return a sequence with a single entry: \ref this.
   */
  virtual task_sequence<logical_task*> self_sequence(
      logical_task* const parent) = 0;

  /**
   * @brief Calculate the probability of aborting this task.
   */
  virtual double abort_prob(void);

  /**
   * @brief Get the last execution time of the task.
   */
  double exec_time(void) const { return m_exec_time; }

  /**
   * @brief Set the last execution time of the task. This is a public function,
   * rather than being computed internally, because there are many different
   * methods of estimating time, and the user should be able to use whatever
   * method they prefer.
   */
  void update_exec_time(double exec_time) { m_exec_time = exec_time; }

  /**
   * @brief Get the parent of this task.
   *
   * @return The parent task, or NULL if no parent has been set.
   */
  logical_task* parent(void) const { return m_parent; }

  /**
   * @brief Set the parent for this task.
   */
  void parent(logical_task* parent) { m_parent = parent; }

  logical_task& operator=(const logical_task& other) = delete;

 private:
  double m_exec_time;
  std::string m_name;
  logical_task* m_parent;
  time_estimate m_estimate;
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_LOGICAL_TASK_HPP_ */
