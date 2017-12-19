/**
 * @file executive.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_EXECUTIVE_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_EXECUTIVE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/er/client.hpp"
#include "rcppsw/task_allocation/executable_task.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Abstract interface for runtime task executives.
 */
class executive : public rcppsw::er::client {
 public:
  executive(const std::shared_ptr<rcppsw::er::server>& server,
            executable_task* root);
  ~executive(void) override;

  executive& operator=(const executive& other) = delete;
  executive(const executive& other) = delete;

  virtual void run(void) = 0;
  executable_task* current_task(void) const { return m_current_task; }

  /**
   * @brief Set an optional callback that will be run when a task is aborted.
   *
   * The callback will be passed the task that was aborted, so if task-specific
   * abort callbacks are needed, they can be implemented that way.
   */
  void task_abort_cleanup(std::function<void(executable_task* const)> cb);
  const std::function<void(executable_task* const)>& task_abort_cleanup(
      void) const;

 protected:
  executable_task* root(void) const { return mc_root; }
  void current_task(executable_task* current_task) {
    m_current_task = current_task;
  }
  executable_task* get_next_task(executable_task* last_task);
  double task_abort_prob(executable_task* task);

 private:
  executable_task* m_current_task;
  std::function<void(executable_task* const)> m_task_abort_cleanup;
  executable_task* const mc_root;
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_EXECUTIVE_HPP_ */
