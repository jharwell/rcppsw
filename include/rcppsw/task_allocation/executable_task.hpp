/**
 * @file executable_task.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_EXECUTABLE_TASK_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_EXECUTABLE_TASK_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "rcppsw/task_allocation/time_estimate.hpp"
#include "rcppsw/task_allocation/logical_task.hpp"
#include "rcppsw/task_allocation/abort_probability.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);
struct task_params;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class executable_task
 *
 * @brief Represents the executable concept of a task, which encompasses:
 *
 * - A possibly updated estimate of the time it takes to do a task. If a task is
 *   only made to be executed once, then this field is unused.
 * - A method of decomposing this (possibly decomposable) task into a sequence
 *   of simpler tasks. Each "simpler" task can have a parent.
 */
class executable_task : public logical_task {
 public:
  executable_task(const std::string& name,
                  const struct task_params* const params,
                  executable_task* const parent = nullptr);
  executable_task(const executable_task& other);

  virtual ~executable_task(void);

  /**
   * @brief Get the current estimate of the task's execution time.
   *
   * This is NOT updated at the end of the \ref task_execute() function, as it
   * is possible that some executable tasks are only run once, and therefore the
   * execution time is irrelevant, or that the user does not care how long a
   * task takes, only that it finishes.
   */
  const time_estimate& current_time_estimate(void) const { return m_estimate; }

  /**
   * @brief Update the current estimate of the task execution time by using a
   * weighted sum of the previous estimate and the new value. See
   * \ref time_estimate.
   *
   * @param last_measure The last measured execution time, in seconds.
   */
  void update_time_estimate(double last_measure) { m_estimate.calc(last_measure); }

  /**
   * @brief The method that all tasks must define that specifies how to execute
   * the task.
   */
  virtual void task_execute(void) = 0;

  /**
   * @brief Get the probability of aborting an executable task.
   */
  double calc_abort_prob(void) {
    return m_abort_prob.calc(this->exec_time(),
                             this->current_time_estimate());
  }

  /**
   * @brief Get the last execution time of the task.
   */
  double exec_time(void) const { return m_exec_time; }

  virtual logical_task* partition(void) { return nullptr; }
  bool is_atomic(void) const { return m_is_atomic; }
  void set_atomic(void) { m_is_atomic = true; }
  bool is_partitionable(void) const { return m_is_partitionable; }
  void set_partitionable(void) { m_is_partitionable = true; }

  /**
   * @brief Calculate how long a "step" of task execution took.
   *
   * This is a public function, rather than being computed internally, because
   * there are many different methods of estimating time, and the user should be
   * able to use whatever method they prefer.
   *
   * @param exec_time The current measure of execution time
   */
  virtual double calc_elapsed_time(double exec_time) const = 0;

  virtual double calc_start_time(void) const = 0;

  /**
   * @brief Update the calculated exec time for the task as a running sum.
   *
   * This is needed for accurate task abort calculations.
   */
  void update_exec_time(void) { m_exec_time = calc_elapsed_time(m_start_time); }

  void reset_exec_time(void) { m_start_time = calc_start_time(); }

 private:
  executable_task& operator=(const executable_task& other) = delete;

  bool m_is_atomic;
  bool m_is_partitionable;
  double m_exec_time;
  double m_start_time;
  time_estimate m_estimate;
  abort_probability m_abort_prob;
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_EXECUTABLE_TASK_HPP_ */
