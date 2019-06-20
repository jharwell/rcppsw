/**
 * @file bi_tdgraph_executive.hpp
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

#ifndef INCLUDE_RCPPSW_TA_BI_TDGRAPH_EXECUTIVE_HPP_
#define INCLUDE_RCPPSW_TA_BI_TDGRAPH_EXECUTIVE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <memory>
#include <random>

#include "rcppsw/ta/base_executive.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);
class bi_tab;
class bi_tdgraph;
struct executive_config;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class bi_tdgraph_executive
 * @ingroup rcppsw ta
 *
 * @brief A task executive which tasks are run one step at a time and polled
 * until they are finished. Operates on \ref bi_tdgraph.
 */
class bi_tdgraph_executive final : public base_executive,
                                   public er::client<bi_tdgraph_executive> {
 public:
  using alloc_notify_cb = std::function<void(const polled_task*, const bi_tab*)>;

  bi_tdgraph_executive(const config::task_executive_config* config,
                       std::unique_ptr<bi_tdgraph> graph);

  void run(void) override;

  /**
   * @brief Get the TAB corresponding to the currently active task.
   */
  const bi_tab* active_tab(void) const;

  /**
   * @brief Set an optional callback that will be run when a new task allocation
   * occurs.
   *
   * The callback will be passed a pointer to the task that was just allocated.
   */
  void task_alloc_notify(const alloc_notify_cb& cb) {
    m_task_alloc_notify.push_back(cb);
  }

 private:
  polled_task* get_next_task(void);
  void active_tab_update(void);

  /**
   * @brief Get the next task to execute, if the most recently executed
   * one was partitionable (easy case).
   */
  polled_task* next_task_from_partitionable(polled_task* task);

  void handle_task_start(polled_task* new_task);
  void handle_task_abort(polled_task* task);
  void handle_task_finish(polled_task* task);

  /* clang-format off */
  std::list<alloc_notify_cb> m_task_alloc_notify{};
  std::default_random_engine m_rng{};
  /* clang-format on */
};

NS_END(ta, rcppsw);

#endif /* INCLUDE_RCPPSW_TA_BI_TDGRAPH_EXECUTIVE_HPP_ */
