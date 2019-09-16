/**
 * @file bi_tdgraph_allocator.hpp
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

#ifndef INCLUDE_RCPPSW_TA_BI_TDGRAPH_ALLOCATOR_HPP_
#define INCLUDE_RCPPSW_TA_BI_TDGRAPH_ALLOCATOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "rcppsw/common/common.hpp"
#include "rcppsw/er/client.hpp"
#include "rcppsw/math/rng.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);
class polled_task;
namespace ds {
class bi_tdgraph;
} /* namespace ds */

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class bi_tdgraph_allocator
 * @ingroup rcppsw ta
 *
 * @brief Allocate a task from a \ref bi_tdgraph according to a specified policy.
 */
class bi_tdgraph_allocator : public er::client<bi_tdgraph_allocator> {
 public:
  static constexpr char kPolicyRandom[] = "random";
  static constexpr char kPolicyGreedyGlobal[] = "greedy_global";
  static constexpr char kPolicyStochGreedyNBHD[] = "stoch_greedy_nbhd";

  bi_tdgraph_allocator(const std::string& policy,
                       ds::bi_tdgraph* graph,
                       math::rng* rng)
      : ER_CLIENT_INIT("rcppsw.ta.bi_tdgraph_allocator"),
        mc_policy(policy),
        m_graph(graph),
        m_rng(rng) {}

  bi_tdgraph_allocator(const bi_tdgraph_allocator&) = delete;
  bi_tdgraph_allocator& operator=(const bi_tdgraph_allocator&) = delete;

  polled_task* operator()(void) const {
    if (kPolicyRandom == mc_policy) {
      return alloc_random();
    } else if (kPolicyGreedyGlobal == mc_policy) {
      return alloc_greedy_global();
    } else if (kPolicyStochGreedyNBHD == mc_policy) {
      return alloc_stoch_greedy_nbhd();
    }
    ER_FATAL_SENTINEL("Bad allocation policy '%s'", mc_policy.c_str());
    return nullptr;
  }

  /**
   * @brief Allocate a task using a matroid neighborhood approach, applying
   * stochasticity to the allocation process.
   *
   * Take the task with the minimum execution time within a neighborhood,
   * applying stochasticity to the task allocation process to attempt to make it
   * more robust/flexible. A neighborhood is defined as all tasks reachable from
   * the most recently executed task within some distance.
   */
  polled_task* alloc_stoch_greedy_nbhd(void) const;

  /**
   * @brief Allocate a task using a matroid optimization approach (strict
   * greedy). No stochasticity is applied.
   */
  polled_task* alloc_greedy_global(void) const;

  /**
   * @brief Allocate a task by choosing a random vertex within the graph and
   * return it.
   */
  polled_task* alloc_random(void) const;

  /* clang-format off */
  const std::string mc_policy;

  ds::bi_tdgraph*   m_graph;
  math::rng*        m_rng;
  /* clang-format on */
};

NS_END(ta, rcppsw);

#endif /* INCLUDE_RCPPSW_TA_BI_TDGRAPH_ALLOCATOR_HPP_ */
