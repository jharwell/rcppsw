/**
 * \file ucb1_allocator.hpp
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

#ifndef INCLUDE_RCPPSW_TA_UCB1_ALLOCATOR_HPP_
#define INCLUDE_RCPPSW_TA_UCB1_ALLOCATOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>

#include "rcppsw/common/common.hpp"
#include "rcppsw/er/client.hpp"
#include "rcppsw/math/rng.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);
class polled_task;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class ucb1_allocator
 * \ingroup ta
 *
 * \brief Allocates a task from a given set of a tasks, using the UCB1 approach
 * from Pini2012,Auer2002, treating the task allocation problem as a multi-armed
 * bandit and achieving a logarithmic regret bound.
 */
class ucb1_allocator : er::client<ucb1_allocator> {
 public:
  explicit ucb1_allocator(math::rng* rng)
      : ER_CLIENT_INIT("rcppsw.ta.ucb1_allocator"), m_rng(rng) {}

  /* Not copy constructable/assignable by default */
  ucb1_allocator(const ucb1_allocator&) = delete;
  const ucb1_allocator& operator=(const ucb1_allocator&) = delete;

  /**
   * \brief Perform task allocation.
   *
   * \param tasks The current set of tasks.
   * \param alloc_count The total # of task allocations so far.
   */
  polled_task* operator()(const std::vector<polled_task*>& tasks,
                          uint alloc_count) const;

 private:
  /* clang-format off */
  math::rng* m_rng;
  /* clang-format on */
};

NS_END(ta, rcppsw);

#endif /* INCLUDE_RCPPSW_TA_UCB1_ALLOCATOR_HPP_ */
