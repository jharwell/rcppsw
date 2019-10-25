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
namespace config {
struct task_alloc_config;
} /* namespace config */

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class bi_tdgraph_allocator
 * @ingroup rcppsw ta
 *
 * @brief Allocate a task from a \ref bi_tdgraph according to a specified
 * policy.
 */
class bi_tdgraph_allocator : public er::client<bi_tdgraph_allocator> {
 public:
  /**
   * @brief Allocate a task by choosing a random vertex within the graph and
   * return it.
   */
  static constexpr char kPolicyRandom[] = "random";

  /**
   * @brief Allocate a task using the eplison-greedy method from Pini2012,
   * Auer2002.
   */
  static constexpr char kPolicyEplisonGreedy[] = "epsilon_greedy";

  /**
   * @brief Allocate a task using a matroid optimization approach (strict
   * greedy). No stochasticity is applied.
   */
  static constexpr char kPolicyStrictGreedy[] = "strict_greedy";

  /**
   * @brief Allocate a task using a stochastic neighborhood approach.
   *
   * Take the task with the minimum execution time within a neighborhood,
   * applying stochasticity to the task allocation process to attempt to make it
   * more robust/flexible. A neighborhood is defined as all tasks reachable from
   * the most recently executed task within some distance. For this method, that
   * distance is set to 1.
   */
  static constexpr char kPolicyStochNBHD1[] = "stoch_nbhd1";

  /**
   * @brief Allocate a task using the UCB1 policy from Auer2002,Pini2012.
   */
  static constexpr char kPolicyUCB1[] = "UCB1";

  bi_tdgraph_allocator(const config::task_alloc_config* config,
                       ds::bi_tdgraph* graph,
                       math::rng* rng)
      : ER_CLIENT_INIT("rcppsw.ta.bi_tdgraph_allocator"),
        mc_config(config),
        m_graph(graph),
        m_rng(rng) {}

  bi_tdgraph_allocator(const bi_tdgraph_allocator&) = delete;
  bi_tdgraph_allocator& operator=(const bi_tdgraph_allocator&) = delete;

  /**
   * @brief Allocate a task from a bi_tdgraph according to configuration
   *
   * @param current_task The most recently executed task (just finished).
   * @param alloc_count The total # of task allocations so far.
   */
  polled_task* operator()(const polled_task* current_task,
                          uint alloc_count) const;

  /* clang-format off */
  const config::task_alloc_config* mc_config;

  ds::bi_tdgraph*   m_graph;
  math::rng*        m_rng;
  /* clang-format on */
};

NS_END(ta, rcppsw);

#endif /* INCLUDE_RCPPSW_TA_BI_TDGRAPH_ALLOCATOR_HPP_ */
