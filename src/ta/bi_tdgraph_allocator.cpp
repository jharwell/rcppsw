/**
 * @file bi_tdgraph_allocator.cpp
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
#include "rcppsw/ta/bi_tdgraph_allocator.hpp"

#include <algorithm>
#include <vector>

#include "rcppsw/ta/ds/bi_tdgraph.hpp"
#include "rcppsw/ta/epsilon_greedy_allocator.hpp"
#include "rcppsw/ta/executable_task.hpp"
#include "rcppsw/ta/polled_task.hpp"
#include "rcppsw/ta/random_allocator.hpp"
#include "rcppsw/ta/stoch_nbhd1_allocator.hpp"
#include "rcppsw/ta/strict_greedy_allocator.hpp"
#include "rcppsw/ta/ucb1_allocator.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
polled_task* bi_tdgraph_allocator::operator()(const polled_task* current_task,
                                              uint alloc_count) const {
  std::vector<polled_task*> tasks(m_graph->n_vertices());
  m_graph->walk(
      [&](polled_task* task) { tasks[m_graph->vertex_id(task)] = task; });

  if (kPolicyRandom == mc_config->policy) {
    return random_allocator(m_rng)(tasks);
  } else if (kPolicyEplisonGreedy == mc_config->policy) {
    return epsilon_greedy_allocator(&mc_config->epsilon_greedy,
                                    m_rng)(tasks, alloc_count);
  } else if (kPolicyStrictGreedy == mc_config->policy) {
    return strict_greedy_allocator(m_rng)(tasks);
  } else if (kPolicyStochNBHD1 == mc_config->policy) {
    return stoch_nbhd1_allocator(m_rng, m_graph)(current_task);
  } else if (kPolicyUCB1 == mc_config->policy) {
    return ucb1_allocator(m_rng)(tasks, alloc_count);
  }
  ER_FATAL_SENTINEL("Bad allocation policy '%s'", mc_config->policy.c_str());
  return nullptr;
}

NS_END(ta, rcppsw);
