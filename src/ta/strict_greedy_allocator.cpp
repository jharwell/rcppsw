/**
 * @file strict_greedy_allocator.cpp
 *
 * @copyright 2019 John Harwell, All rights reserved.
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
#include "rcppsw/ta/strict_greedy_allocator.hpp"
#include <algorithm>
#include "rcppsw/ta/polled_task.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
polled_task* strict_greedy_allocator::operator()(
    const std::vector<polled_task*>& tasks) const {
  auto min_task = std::min_element(tasks.begin(), tasks.end(),
                                   [&](const auto* t1, const auto* t2) {
                                     return t1->task_exec_estimate() < t2->task_exec_estimate();
                                   });
    /* Only tasks that have equivalent minimum cost are eligible for selection */
    auto is_equiv_min = [&](const auto*e) {
      return e->task_exec_estimate() == (*min_task)->task_exec_estimate();
    };

    std::vector<polled_task*> equiv_min_tasks;
    std::copy_if(tasks.begin(),
                 tasks.end(),
                 std::back_inserter(equiv_min_tasks),
                 is_equiv_min);

    ER_ASSERT(equiv_min_tasks.size() >= 1, "No minimum cost task found?");

    /*
     * If there is more than one task with the same cost estimate, any of them
     * are OK to allocate, so pick randomly.
     */
    return equiv_min_tasks[m_rng->uniform(0, equiv_min_tasks.size() - 1)];
} /* alloc_strict_greedy() */

NS_END(ta, rcppsw);
