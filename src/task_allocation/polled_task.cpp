/**
 * @file polled_task.cpp
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
#include <random>

#include "rcppsw/task_allocation/polled_task.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
polled_task::~polled_task(void) = default;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void polled_task::exec_estimate_init(const math::rangeu& bounds) {
  std::default_random_engine rng;
  std::uniform_int_distribution<> dist(bounds.lb(), bounds.ub());
  executable_task::exec_estimate_init(dist(rng));
} /* exec_estimate_init() */

NS_END(task_allocation, rcppsw);
