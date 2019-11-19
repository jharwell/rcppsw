/**
 * \file base_executive.cpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
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
#include "rcppsw/ta/base_executive.hpp"

#include "rcppsw/ta/config/task_executive_config.hpp"
#include "rcppsw/ta/ds/bi_tdgraph.hpp"
#include "rcppsw/ta/ds/ds_variant.hpp"
#include "rcppsw/ta/polled_task.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
base_executive::base_executive(
    const config::task_executive_config* const exec_config,
    const config::task_alloc_config* const alloc_config,
    std::unique_ptr<ds::ds_variant> ds,
    math::rng* rng)
    : ER_CLIENT_INIT("rcppsw.ta.base_executive"),
      mc_update_exec_ests(exec_config->update_exec_ests),
      mc_update_interface_ests(exec_config->update_interface_ests),
      mc_alloc_config(*alloc_config),
      m_ds(std::move(ds)),
      m_rng(rng) {}

base_executive::~base_executive(void) = default;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void base_executive::run(void) {
  /* First timestep of execution/allocation */
  if (nullptr == current_task()) {
    auto new_task = task_allocate(nullptr);
    ++m_alloc_count;
    task_start_handle(new_task);
    return;
  }

  if (current_task()->task_finished()) {
    ER_INFO("Task '%s' finished", current_task()->name().c_str());
    task_finish_handle(current_task());
    return;
  }

  double prob = current_task()->abort_prob_calc();
  ER_DEBUG("Task '%s' abort probability: %f",
           current_task()->name().c_str(),
           prob);
  if (prob >= m_rng->uniform(0.0, 1.0)) {
    ER_INFO("Task '%s' aborted, prob=%f", current_task()->name().c_str(), prob);
    task_abort_handle(current_task());
    return;
  }
  current_task()->task_execute();
  current_task()->exec_time_update();
  current_task()->interface_time_update();
  current_task()->abort_prob_update();
  current_task()->active_interface_update(0);
} /* run() */

void base_executive::task_abort_handle(polled_task* task) {
  /*
   * Estimate updating must be BEFORE time updating, because time updating
   * resets current execution time to 0, which results in estimates always
   * being 0! See #246.
   */
  task_ests_update(task);
  task_times_update(task);

  task->task_aborted(true);
  task->task_exec_count_inc();

  for (auto& cb : task_abort_notify()) {
    cb(task);
  } /* for(cb..) */

  task->task_aborted(false); /* already been handled in callback */
  auto new_task = task_allocate(task);
  ++m_alloc_count;
  task_start_handle(new_task);
} /* task_abort_handle() */

void base_executive::task_finish_handle(polled_task* task) {
  /*
   * Estimate updating must be BEFORE time updating, because time updating
   * resets current execution time to 0, which results in estimates always
   * being 0! See #246.
   */
  task_ests_update(task);
  task_times_update(task);
  task->task_exec_count_inc();

  for (auto& cb : task_finish_notify()) {
    cb(task);
  } /* for(cb..) */

  auto new_task = task_allocate(task);
  ++m_alloc_count;
  task_start_handle(new_task);
} /* task_finish_handle() */

void base_executive::task_start_handle(polled_task* const new_task) {
  ER_INFO("Starting new task '%s'", new_task->name().c_str());

  for (auto& cb : m_task_start_notify) {
    cb(new_task);
  } /* for(cb..) */

  do_task_start(new_task);
} /* task_start_handle() */

void base_executive::task_ests_update(polled_task* const task) {
  if (update_exec_ests()) {
    task->exec_estimate_update(task->exec_time());
  }

  if (update_interface_ests()) {
    /*
     * Not unconditional/assert(), because it is possible to abort before we
     * even get to our task interface, and if this happens before we have
     * managed to complete the interface while executing a task, then we cannot
     * update the interface estimate.
     */
    if (-1 != task->task_last_active_interface()) {
      task->interface_estimate_update(task->task_last_active_interface(),
                                      task->interface_time(
                                          task->task_last_active_interface()));
    }
  }
} /* task_ests_update() */

void base_executive::task_times_update(polled_task* const task) {
  task->exec_time_update();
  task->exec_time_reset();
  task->exec_time_update();

  task->interface_time_update();
  task->interface_time_reset();
  task->interface_time_update();
} /* task_times_update() */

void base_executive::do_task_start(polled_task* const task) {
  task->task_reset();
  task->task_start(nullptr);
  current_task(task);
} /* do_task_start() */

NS_END(ta, rcppsw);
