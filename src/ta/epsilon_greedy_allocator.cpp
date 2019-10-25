/**
 * @file epsilon_greedy_allocator.cpp
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
#include "rcppsw/ta/epsilon_greedy_allocator.hpp"

#include <cmath>

#include "rcppsw/ta/strict_greedy_allocator.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
polled_task* epsilon_greedy_allocator::operator()(
    const std::vector<polled_task*>& tasks,
    uint alloc_count) const {
  double epsilon = 0;

  if (kRegretBoundLinear == mc_config->regret_bound) {
    epsilon = mc_config->epsilon;
    ER_INFO("Epsilon greedy: n_tasks=%zu, epsilon=%f", tasks.size(), epsilon);
  } else if (kRegretBoundLog == mc_config->regret_bound) {
    double term1 = 1.0;
    double term2 =
        (kC * tasks.size()) / (std::pow(mc_config->epsilon, 2) * alloc_count);
    epsilon = std::min(term1, term2);
    ER_INFO("Epsilon N-greedy: n_tasks=%zu,alloc_count=%u,epsilon=%f",
            tasks.size(),
            alloc_count,
            epsilon);

  } else {
    ER_FATAL_SENTINEL("Bad epsilon greedy regret bound: %s",
                      mc_config->regret_bound.c_str())
  }

  /*
   * Choose the greedy best task with probability 1.0 - epsilon. If there are
   * multiple best tasks, then a random one will be picked which will not
   * affect our regret bound.
   */
  if (1.0 - epsilon >= m_rng->uniform(0.0, 1.0)) {
    return strict_greedy_allocator(m_rng)(tasks);
  }
  /* otherwise, pick randomly */
  return tasks[m_rng->uniform(0, tasks.size() - 1)];
} /* operator()() */

NS_END(ta, rcppsw);
