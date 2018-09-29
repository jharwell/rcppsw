/**
 * @file base_executive.hpp
 *
 * @copyright 2018 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_BASE_EXECUTIVE_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_BASE_EXECUTIVE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <string>

#include "rcppsw/er/client.hpp"
#include "rcppsw/task_allocation/polled_task.hpp"
#include "rcppsw/task_allocation/tdgraph.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class base_executive
 * @ingroup task_allocation
 *
 * @brief Base class for runtime task task executives.
 */
class base_executive : public rcppsw::er::client<base_executive> {
 public:
  using abort_notify_cb = std::function<void(const polled_task*)>;
  using finish_notify_cb = std::function<void(const polled_task*)>;

  /**
   * @brief Creates the base executive.
   *
   * @param graph Graph to manage. Takes ownership of the object (can't use the
   *              language to communicate that with unique_ptr because of
   *              casting reasons).
   */
  explicit base_executive(tdgraph* graph);
  ~base_executive(void) override;

  base_executive& operator=(const base_executive& other) = delete;
  base_executive(const base_executive& other) = delete;

  /**
   * @brief The means by which the task executive will run one timestep/task/etc.
   */
  virtual void run(void) = 0;

  /**
   * @brief Get the task currently being run.
   */
  const polled_task* current_task(void) const { return m_current_task; }
  polled_task* current_task(void) { return m_current_task; }

  /**
   * @brief Set an optional callback that will be run when a task is aborted.
   *
   * The callback will be passed the task that was aborted, so if task-specific
   * abort callbacks are needed, they can be implemented that way.
   */
  void task_abort_notify(abort_notify_cb cb) { m_task_abort_notify.push_back(cb); }
  const std::list<abort_notify_cb>& task_abort_notify(void) const { return m_task_abort_notify; }

  /**
   * @brief Set an optional callback that will be run when a task finishes.
   *
   * The callback will be passed a pointer to the task that was just finished,
   * before the task is reset.
   */
  void task_finish_notify(finish_notify_cb cb) { m_task_finish_notify.push_back(cb); }
  const std::list<finish_notify_cb>& task_finish_notify(void) const { return m_task_finish_notify; }

  /**
   * @brief Get the last task that was executed before the current one.
   */
  const polled_task* last_task(void) const { return m_last_task; }

  /**
   * @brief Get the parent task of the specified one.
   */
  const polled_task* parent_task(const polled_task* task);

  /**
   * @brief Initialize the execution time estimate of the specified task within
   * the specified range (non-partitionable tasks).
   */
  void task_init_random(polled_task* task, uint lb, uint ub);

  /**
   * @brief Initialize the execution time estimate of the specified task within
   * the specified range (partitionable tasks).
   */
  void task_init_random(polled_task* task,
                        const polled_task* partition,
                        uint lb,
                        uint ub);

  const tdgraph* graph(void) const { return m_graph.get(); }

 protected:
  const polled_task* root_task(void) const;
  polled_task* root_task(void);

  void current_task(polled_task* current_task) {
    m_current_task = current_task;
  }

  /**
   * @brief After the current task is aborted or finished, figured what the next
   * task to run should be and return it.
   *
   * Note that it is only safe to return a reference to a node within the task
   * graph because the task executive only works with static graphs (i.e. those
   * that do not change during runtime).
   */
  polled_task* get_next_task(const polled_task* last_task);

  /**
   * @brief Get the probability of aborting the specified task.
   */
  double task_abort_prob(polled_task* task);

  tdgraph* graph(void) { return m_graph.get(); }

  virtual polled_task* do_get_next_task(void) = 0;

 private:
  /**
   * @brief Get the first task to be executed, which requires some special logic
   * to set up task pointers appropriately.
   */
  polled_task* get_first_task(void);

  // clang-format off
  polled_task*                m_current_task{nullptr};
  const polled_task*          m_last_task{nullptr};
  std::list<abort_notify_cb>  m_task_abort_notify{};
  std::list<finish_notify_cb> m_task_finish_notify{};
  std::unique_ptr<tdgraph>    m_graph;
  // clang-format on
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_BASE_EXECUTIVE_HPP_ */
