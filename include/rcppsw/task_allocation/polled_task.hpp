/**
 * @file polled_task.hpp
 * @ingroup task_allocation
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_POLLED_TASK_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_POLLED_TASK_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "rcppsw/patterns/visitor/visitable.hpp"
#include "rcppsw/task_allocation/executable_task.hpp"
#include "rcppsw/task_allocation/taskable.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class polled_task
 *
 * @brief Represents a task whose execution can/should be monitored by the user
 * to determine when it has finished.
 */
class polled_task : public executable_task, public taskable {
 public:
  polled_task(const std::string& name,
              const struct task_params* const c_params,
              std::unique_ptr<taskable>& mechanism,
              polled_task* parent = nullptr)
      : executable_task(name, c_params, parent),
        m_mechanism(std::move(mechanism)) {}
  virtual ~polled_task(void);

  polled_task& operator=(const polled_task& other) = delete;
  polled_task(const polled_task& other) = delete;

  taskable* mechanism(void) const { return m_mechanism.get(); }

  void task_execute(void) override { m_mechanism->task_execute(); }
  void task_reset(void) override { m_mechanism->task_reset(); }
  bool task_running(void) const override { return m_mechanism->task_running(); }
  bool task_finished(void) const override {
    return m_mechanism->task_finished();
  }

  /**
   * @brief Initialize the execution time estimates of the task randomly within
   * the specified range.
   */
  void init_random(uint lb, uint ub) {
    executable_task::update_exec_estimate(rand() % (ub - lb + 1) + lb);
  }

 private:
  std::unique_ptr<taskable> m_mechanism;
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_POLLED_TASK_HPP_ */
