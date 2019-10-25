/**
 * @file random_allocator.hpp
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

#ifndef INCLUDE_RCPPSW_TA_RANDOM_ALLOCATOR_HPP_
#define INCLUDE_RCPPSW_TA_RANDOM_ALLOCATOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>

#include "rcppsw/common/common.hpp"
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
 * @class random_allocator
 * @ingroup rcppsw ta
 *
 * @brief Allocates a task from a given set of a tasks by choosing one randomly.
 */
class random_allocator : er::client<random_allocator> {
 public:
  explicit random_allocator(math::rng* rng)
      : ER_CLIENT_INIT("rcppsw.ta.random_allocator"), m_rng(rng) {}

  /* Not copy constructable/assignable by default */
  random_allocator(const random_allocator& other) = delete;
  const random_allocator& operator=(const random_allocator& other) = delete;

  polled_task* operator()(const std::vector<polled_task*>& tasks) const {
    return tasks[m_rng->uniform(0, tasks.size() - 1)];
  }

 private:
  /* clang-format off */
  math::rng* m_rng;
  /* clang-format on */
};

NS_END(ta, rcppsw);

#endif /* INCLUDE_RCPPSW_TA_RANDOM_ALLOCATOR_HPP_ */
