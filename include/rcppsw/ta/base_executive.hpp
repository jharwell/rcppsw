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

#ifndef INCLUDE_RCPPSW_TA_BASE_EXECUTIVE_HPP_
#define INCLUDE_RCPPSW_TA_BASE_EXECUTIVE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>

#include "rcppsw/er/client.hpp"
#include "rcppsw/ta/polled_task.hpp"
#include "rcppsw/ta/tdgraph.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);
namespace config {
struct task_executive_config;
} /* namespace config */

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class base_executive
 * @ingroup rcppsw ta
 *
 * @brief Base class for runtime task task executives.
 */
class base_executive : public rcppsw::er::client<base_executive> {
 public:
  using abort_notify_cb = std::function<void(polled_task*)>;
  using finish_notify_cb = std::function<void(polled_task*)>;

  /**
   * @brief Creates the base executive.
   *
   * @param config Initialization parameters/config.
   *
   * @param graph Graph to manage. Takes ownership of the object (can't use the
   *              language to communicate that with unique_ptr because of
   *              casting reasons).
   */
  base_executive(const config::task_executive_config* config,
                 std::unique_ptr<tdgraph> graph);
  ~base_executive(void) override;

  base_executive& operator=(const base_executive& other) = delete;
  base_executive(const base_executive& other) = delete;

  /**
   * @brief The means by which the task executive will run one
   * timestep.
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
   * The callback will be passed the task that was aborted, before the active
   * task is reset and after any time estimates have been updated on the aborted
   * task (the task is marked as aborted before calling).
   */
  void task_abort_notify(const abort_notify_cb& cb) {
    m_task_abort_notify.push_back(cb);
  }
  const std::list<abort_notify_cb>& task_abort_notify(void) const {
    return m_task_abort_notify;
  }

  /**
   * @brief Set an optional callback that will be run when a task finishes.
   *
   * The callback will be passed a pointer to the task that was just finished,
   * before the task is reset and after time estimates are updated on the
   * finished task. The task will have its execution and interface times updated
   * (if applicable) prior to the call.
   */
  void task_finish_notify(const finish_notify_cb& cb) {
    m_task_finish_notify.push_back(cb);
  }
  const std::list<finish_notify_cb>& task_finish_notify(void) const {
    return m_task_finish_notify;
  }

  /**
   * @brief Get the parent task of the specified one.
   */
  const polled_task* parent_task(const polled_task* v);

  const tdgraph* graph(void) const { return m_graph.get(); }
  bool update_exec_ests(void) const { return m_update_exec_ests; }
  bool update_interface_ests(void) const { return m_update_interface_ests; }

 protected:
  const polled_task* root_task(void) const RCSW_PURE;
  polled_task* root_task(void) RCSW_PURE;

  void current_task(polled_task* current_task) {
    m_current_task = current_task;
  }

  tdgraph* graph(void) { return m_graph.get(); }

 private:
  /* clang-format off */
  bool                        m_update_exec_ests;
  bool                        m_update_interface_ests;
  polled_task*                m_current_task{nullptr};
  std::list<abort_notify_cb>  m_task_abort_notify{};
  std::list<finish_notify_cb> m_task_finish_notify{};
  std::unique_ptr<tdgraph>    m_graph;
  /* clang-format on */
};

NS_END(ta, rcppsw);

#endif /* INCLUDE_RCPPSW_TA_BASE_EXECUTIVE_HPP_ */
