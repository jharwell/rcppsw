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
#include <string>

#include "rcppsw/ta/base_executive.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);
class bi_tdgraph;
struct executive_config;

namespace ds {
class bi_tab;
} /* namespace ds */

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
  using start_notify_cb = std::function<void(const polled_task*,
                                             const ds::bi_tab*)>;

  bi_tdgraph_executive(const config::task_executive_config* exec_config,
                       const config::task_alloc_config* const alloc_config,
                       std::unique_ptr<ds::ds_variant> ds,
                       math::rng*rng);

  /**
   * @brief Get the TAB corresponding to the currently active task.
   */
  const ds::bi_tab* active_tab(void) const RCSW_PURE;

  /**
   * @brief Set an optional callback that will be run when a new task is
   * started.
   *
   * The callback will be passed a pointer to the task that was just started.
   */
  void task_start_notify(const start_notify_cb& cb) {
    m_task_start_notify.push_back(cb);
  }

  const polled_task* root_task(void) const RCSW_PURE;

  /**
   * @brief Get the parent task of the specified one.
   */
  const polled_task* parent_task(const polled_task* v);

  const ds::bi_tdgraph* graph(void) const;

 protected:
  polled_task* root_task(void) RCSW_PURE;
  ds::bi_tdgraph* graph(void);

 private:
  polled_task* task_allocate(const polled_task* last_task) override;
  void task_start_handle(polled_task* new_task) override;
  void task_abort_handle(polled_task* task) override;
  void task_finish_handle(polled_task* task) override;

  void active_tab_update(void);
  /* clang-format off */
  std::list<start_notify_cb> m_task_start_notify{};
  /* clang-format on */
};

NS_END(ta, rcppsw);

#endif /* INCLUDE_RCPPSW_TA_BI_TDGRAPH_EXECUTIVE_HPP_ */
