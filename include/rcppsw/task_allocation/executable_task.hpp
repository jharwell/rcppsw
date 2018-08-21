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
#include "rcppsw/task_allocation/logical_task.hpp"
#include "rcppsw/task_allocation/time_estimate.hpp"

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
 * @ingroup task_allocation
 *
 * @brief Represents the executable concept of a task, which encompasses:
 *
 * - A possibly updated estimate of the time it takes to do a task. If a task is
 *   only made to be executed once, then this field is unused.
 * - A method of decomposing this (possibly decomposable) task into a sequence
 *   of simpler tasks. Each "simpler" task can have a parent.
 *
 * This class is MUST be instantiated inside of \ref task_graph_vertex, and be
 * manipulated through shared_ptr.
 */
class executable_task : public logical_task {
 public:
  executable_task(const std::string& name,
                  const struct task_params* c_params);
  executable_task(const executable_task& other);

  ~executable_task(void) override;

  /**
   * @brief Initialize the task with a random execution time estimate within the
   * specified bounds.
   */
  void init_random(int lb, int ub) {
    update_exec_estimate(std::rand() % (ub - lb + 1) + lb);
  }

  /**
   * @brief Get the current estimate of the task's interface time.
   */
  const time_estimate& interface_estimate(void) const {
    return m_interface_estimate;
  }

  /**
   * @brief Get the current estimate of the task's execution time (which
   * includes its interface time).
   */
  const time_estimate& exec_estimate(void) const { return m_exec_estimate; }

  /**
   * @brief Update the current estimate of the task interface time by using a
   * weighted sum of the previous \ref time_estimate and the new value.
   *
   * @param last_measure The last measured time.
   */
  void update_interface_estimate(double last_measure) {
    m_interface_estimate.calc(last_measure);
  }

  /**
   * @brief Update the current estimate of the task execution time by using a
   * weighted sum of the previous \ref time_estimate and the new value.
   *
   * @param last_measure The last measured time.
   */
  void update_exec_estimate(double last_measure) {
    m_exec_estimate.calc(last_measure);
  }

  /**
   * @brief The method that all tasks must define that specifies how to execute
   * the task.
   */
  virtual void task_execute(void) = 0;

  /**
   * @brief Get the current interface time of the task.
   */
  double interface_time(void) const { return m_interface_time; }

  /**
   * @brief Get the last interface time of the task. This may be needed if the
   * interface time is needed for calculations on the timestep in which a task
   * finishes, at which time the regular interface time has been reset.
   */
  double last_interface_time(void) const { return m_last_interface_time; }

  /**
   * @brief Get the current execution time of the task.
   */
  double exec_time(void) const { return m_exec_time; }

  /**
   * @brief Get the last execution time of the task.
   */
  double last_exec_time(void) const { return m_last_exec_time; }

  /**
   * @brief Get if a task is currently atomic (i.e. not abortable).
   */
  bool is_atomic(void) const { return m_is_atomic; }

  /**
   * @brief Set a task as atomic, meaning that once executed, it cannot be
   * aborted.
   */
  void set_atomic(bool b) { m_is_atomic = b; }

  /**
   * @brief Get if a task is partitionable. This can be done with reflection,
   * but this is way cleaner.
   */
  bool is_partitionable(void) const { return m_is_partitionable; }

  /**
   * @brief Set a task as partitionable. Should only be set on
   * \ref partitionable_task objects, otherwise bad things will happen.
   */
  void set_partitionable(bool b) { m_is_partitionable = b; }

  /**
   * @brief Get the probability of aborting an executable task.
   */
  virtual double calc_abort_prob(void) = 0;

  /**
   * @brief Calculate the interface time of the current task for use in abort
   * calculations.
   */
  virtual double calc_interface_time(double start_time) = 0;

  /**
   * @brief Get the current time
   */
  virtual double current_time(void) const = 0;

  /**
   * @brief Update the calculated interface time for the task
   *
   * This is needed for accurate task abort calculations.
   */
  void update_interface_time(void) {
    m_interface_time = calc_interface_time(m_interface_start_time);
  }

  /**
   * @brief Because tasks can have multiple interfaces, they need a way to reset
   * their interface time upon leaving/entering an interface.
   */
  void reset_interface_time(void) {
    m_last_interface_time = m_interface_time;
    m_interface_start_time = current_time();
  }

  /**
   * @brief Update the calculated execution time for the task
   *
   * This is needed for accurate task abort calculations.
   */
  void update_exec_time(void) {
    m_exec_time = current_time() - m_exec_start_time;
  }

  /**
   * @brief Reset the execution time for the task. Should never be called
   * directly!
   */
  void reset_exec_time(void) {
    m_last_exec_time = m_exec_time;
    m_exec_start_time = current_time();
  }
  bool task_aborted(void) const { return m_task_aborted; }
  void task_aborted(bool task_aborted) { m_task_aborted = task_aborted; }

 private:
  bool m_is_atomic{false};
  bool m_is_partitionable{false};
  bool m_task_aborted{false};

  double m_interface_time{0.0};
  double m_last_interface_time{0.0};
  double m_interface_start_time{0.0};
  double m_exec_time{0.0};
  double m_last_exec_time{0.0};
  double m_exec_start_time{0.0};
  time_estimate m_interface_estimate;
  time_estimate m_exec_estimate;
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_EXECUTABLE_TASK_HPP_ */
