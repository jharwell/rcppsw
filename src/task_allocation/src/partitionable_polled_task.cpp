/**
 * @file partitionable_polled_task.cpp
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
#include "rcppsw/task_allocation/partitionable_polled_task.hpp"
#include "rcppsw/task_allocation/task_params.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
partitionable_polled_task::partitionable_polled_task(
    const std::shared_ptr<er::server>& server,
    const std::string& name,
    const struct partitionable_task_params* c_params,
    std::unique_ptr<taskable>& mechanism,
    polled_task* parent)
    : polled_task(name, c_params, mechanism, parent),
      partitionable_task(server, c_params) {}

void partitionable_polled_task::init_random(uint lb, uint ub) {
  executable_task::update_exec_estimate(rand() % (ub - lb + 1) + lb);
  last_partition(rand() % 2 ? partition1(): partition2());
  partition1()->update_exec_estimate(rand() % (ub - lb + 1) + lb);
  partition2()->update_exec_estimate(rand() % (ub - lb + 1) + lb);
} /* init_random() */

NS_END(task_allocation, rcppsw);
