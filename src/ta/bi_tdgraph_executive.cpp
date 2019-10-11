/**
 * @file bi_tdgraph_executive.cpp
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/ta/bi_tdgraph_executive.hpp"

#include "rcppsw/ta/ds/bi_tdgraph.hpp"
#include "rcppsw/ta/config/task_executive_config.hpp"
#include "rcppsw/ta/task_allocator.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
bi_tdgraph_executive::bi_tdgraph_executive(
    const config::task_executive_config* const exec_config,
    const config::task_alloc_config* const alloc_config,
    std::unique_ptr<ds::ds_variant> ds,
    math::rng* rng)
    : base_executive(exec_config, alloc_config, std::move(ds), rng),
      ER_CLIENT_INIT("rcppsw.ta.executive.bi_tdgraph") {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
ds::bi_tdgraph* bi_tdgraph_executive::graph(void) {
  return static_cast<ds::bi_tdgraph*>(boost::get<ds::bi_tdgraph>(ds()));
} /* graph() */

const ds::bi_tdgraph* bi_tdgraph_executive::graph(void) const {
  return static_cast<const ds::bi_tdgraph*>(boost::get<const ds::bi_tdgraph>(ds()));
} /* graph() */

const ds::bi_tab* bi_tdgraph_executive::active_tab(void) const {
  return graph()->active_tab();
} /* active_tab() */

void bi_tdgraph_executive::task_abort_handle(polled_task* task) {
  task_times_update(task);
  task_ests_update(task);

  task->task_aborted(true);
  for (auto& cb : task_abort_notify()) {
    cb(task);
  } /* for(cb..) */

  /*
   * If the root was atomic then there is no active TAB that needs to be
   * updated.
   */
  if (nullptr != active_tab()) {
    graph()->active_tab()->task_abort_update(task, rng());
  }

  task->task_aborted(false); /* already been handled in callback */
  task_start_handle(task_allocate(task));
} /* task_abort_handle() */

void bi_tdgraph_executive::task_finish_handle(polled_task* task) {
  task_times_update(task);
  task_ests_update(task);

  for (auto& cb : task_finish_notify()) {
    cb(task);
  } /* for(cb..) */

  /*
   * If the root was atomic then there is no active TAB that needs to be
   * updated.
   */
  if (nullptr != active_tab()) {
    graph()->active_tab()->task_finish_update(task, rng());
  }
  task_start_handle(task_allocate(task));
} /* task_finish_handle() */

void bi_tdgraph_executive::task_start_handle(polled_task* const new_task) {
  ER_INFO("Starting new task '%s'", new_task->name().c_str());

  for (auto& cb : m_task_start_notify) {
    cb(new_task, active_tab());
  } /* for(cb..) */

  do_task_start(new_task);
} /* task_start_handle() */

polled_task* bi_tdgraph_executive::task_allocate(
    const polled_task* last_task) {
  auto ret =  boost::apply_visitor(task_allocator(alloc_config(),
                                                  rng(),
                                                  last_task),
                                   *ds());

  ER_ASSERT(!ret->task_aborted(),
            "Task '%s' marked as aborted during allocation",
            ret->name().c_str());
  ER_INFO("Allocated new task '%s'", ret->name().c_str());
  return ret;
} /* task_allocate() */

const polled_task* bi_tdgraph_executive::root_task(void) const {
  return graph()->root();
} /* root_task() */

polled_task* bi_tdgraph_executive::root_task(void) {
  return graph()->root();
} /* root_task() */

const polled_task* bi_tdgraph_executive::parent_task(const polled_task* v) {
  return ds::bi_tdgraph::vertex_parent(*graph(), v);
} /* parent_task() */

NS_END(ta, rcppsw);
