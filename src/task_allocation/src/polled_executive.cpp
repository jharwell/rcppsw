/**
 * @file polled_executive.cpp
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/task_allocation/polled_executive.hpp"
#include "rcppsw/task_allocation/polled_task.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void polled_executive::run(void) {
  if (nullptr == executive::current_task()) {
    new_task_start(static_cast<polled_task*>(executive::root()));
    return;
  }
  polled_task* current = dynamic_cast<polled_task*>(executive::current_task());
  ER_ASSERT(current, "FATAL: polled_executive can only work with polled tasks");

  if (current->task_finished()) {
    ER_NOM("Current task %s finished", current->name().c_str());
    current->update_exec_time();
    current->update_time_estimate(current->exec_time());
    current = static_cast<polled_task*>(executive::get_next_task(current));
    new_task_start(current);
    current->task_execute();
  } else {
    double prob = executive::task_abort_prob(current);
    ER_NOM("Current task %s abort probability: %.12f", current->name().c_str(),
           prob);

    if (static_cast<double>(rand()) / RAND_MAX <= prob) {
      ER_NOM("Current task %s aborted", current->name().c_str());
      current = static_cast<polled_task*>(executive::get_next_task(current));
      new_task_start(current);
    } else {
      current->task_execute();
      current->update_exec_time();
    }
  }
} /* run() */

void polled_executive::new_task_start(polled_task* const new_task) {
  new_task->task_reset();
  new_task->task_start(nullptr);
  current_task(new_task);
  ER_NOM("Started new task %s", new_task->name().c_str());
} /* new_task_start() */

NS_END(task_allocation, rcppsw);
