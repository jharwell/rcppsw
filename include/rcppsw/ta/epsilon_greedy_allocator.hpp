/**
 * \file epsilon_greedy_allocator.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_TA_EPSILON_GREEDY_ALLOCATOR_HPP_
#define INCLUDE_RCPPSW_TA_EPSILON_GREEDY_ALLOCATOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>

#include "rcppsw/common/common.hpp"
#include "rcppsw/er/client.hpp"
#include "rcppsw/math/rng.hpp"
#include "rcppsw/ta/config/epsilon_greedy_config.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);
class polled_task;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class epsilon_greedy_allocator
 * \ingroup ta
 *
 * \brief Allocates a task from a given set of a tasks, using a randomized
 * \f$\epsilon\f$ based method with either logarithmically or linearly bounded
 * regret.
 *
 * From Auer2002, Pini2012
 */
class epsilon_greedy_allocator : er::client<epsilon_greedy_allocator> {
 public:
  static constexpr char kRegretBoundLog[] = "log";
  static constexpr char kRegretBoundLinear[] = "linear";

  /*
   * From Auer2002, 5.0 is considered large enough to give a logarithmic regret
   * bound.
   */
  static constexpr double kC = 5.0;

  epsilon_greedy_allocator(const config::epsilon_greedy_config* config,
                           math::rng* rng)
      : ER_CLIENT_INIT("rcppsw.ta.epsilon_greedy_allocator"),
        mc_config(config),
        m_rng(rng) {}

  /* Not copy constructable/assignable by default */
  epsilon_greedy_allocator(const epsilon_greedy_allocator&) = delete;
  const epsilon_greedy_allocator& operator=(const epsilon_greedy_allocator&) =
      delete;

  /**
   * \brief Perform task allocation.
   *
   * \param tasks The current set of tasks.
   * \param alloc_count The total number of allocations so far.
   */
  polled_task* operator()(const std::vector<polled_task*>& tasks,
                          uint alloc_count) const;

 private:
  /* clang-format off */
  const config::epsilon_greedy_config* mc_config;
  math::rng*                           m_rng;
  /* clang-format on */
};

NS_END(ta, rcppsw);

#endif /* INCLUDE_RCPPSW_TA_EPSILON_GREEDY_ALLOCATOR_HPP_ */
