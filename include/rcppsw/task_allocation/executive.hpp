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
class task_decomposition_graph;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class executive
 * @ingroup task_allocation
 *
 * @brief Base class/interface for runtime task executives.
 */
class executive : public rcppsw::er::client {
 public:
  using event_cb = std::function<void(const task_graph_vertex&)>;

  executive(const std::shared_ptr<rcppsw::er::server>& server,
            const std::shared_ptr<task_decomposition_graph>& graph);
  ~executive(void) override;

  executive& operator=(const executive& other) = delete;
  executive(const executive& other) = delete;

  /**
   * @brief The means by which the task executive will run one timestep/task/etc.
   */
  virtual void run(void) = 0;

  /**
   * @brief Get the task currently being run.
   */
  const task_graph_vertex& current_task(void) const { return m_current_task; }

  /**
   * @brief Set an optional callback that will be run when a task is aborted.
   *
   * The callback will be passed the task that was aborted, so if task-specific
   * abort callbacks are needed, they can be implemented that way.
   */
  void task_abort_cleanup(event_cb cb) { m_task_abort_cleanup = cb; }
  const event_cb& task_abort_cleanup(void) const { return m_task_abort_cleanup; }

  /**
   * @brief Set an optional callback that will be run when a new task allocation
   * occurs.
   *
   * The callback will be passed a pointer to the task that was just allocated.
   */
  void task_alloc_notify(event_cb cb) { m_task_alloc_notify = cb; }
  const event_cb& task_alloc_notify(void) const { return m_task_alloc_notify; }

  /**
   * @brief Set an optional callback that will be run when a task finishes.
   *
   * The callback will be passed a pointer to the task that was just finished,
   * before the task is reset.
   */
  void task_finish_notify(event_cb cb) { m_task_finish_notify = cb; }
  const event_cb& task_finish_notify(void) const { return m_task_finish_notify; }

  /**
   * @brief Get the last task that was executed before the current one.
   */
  const task_graph_vertex& last_task(void) const { return m_last_task; }

  /**
   * @brief Get the parent task of the specified one.
   */
  const task_graph_vertex& parent_task(const task_graph_vertex& task);

 protected:
  const task_graph_vertex& root_task(void) const;
  void current_task(const task_graph_vertex& current_task) {
    m_current_task = current_task;
  }
  /**
   * @brief After the current task is aborted or finished, figured what the next
   * task to run should be and return it.
   *
   * Note that it is only safe to return a reference to a node within the task
   * graph because the executive only works with static graphs (i.e. those that
   * do not change during runtime).
   */
  task_graph_vertex get_next_task(const task_graph_vertex& last_task);

  /**
   * @brief Get the probability of aborting the specified task.
   */
  double task_abort_prob(const task_graph_vertex& task);

  std::shared_ptr<task_decomposition_graph> graph(void) const { return m_graph; }

 private:
  // clang-format off
  task_graph_vertex                         m_current_task{nullptr};
  task_graph_vertex                         m_last_task{nullptr};
  event_cb                                  m_task_abort_cleanup{nullptr};
  event_cb                                  m_task_alloc_notify{nullptr};
  event_cb                                  m_task_finish_notify{nullptr};
  std::shared_ptr<task_decomposition_graph> m_graph;
  // clang-format on
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_EXECUTIVE_HPP_ */
