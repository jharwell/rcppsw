/**
 * @file task_allocator.hpp
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

#ifndef INCLUDE_RCPPSW_TA_TASK_ALLOCATOR_HPP_
#define INCLUDE_RCPPSW_TA_TASK_ALLOCATOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/variant/static_visitor.hpp>
#include <string>

#include "rcppsw/common/common.hpp"
#include "rcppsw/math/rng.hpp"
#include "rcppsw/ta/bi_tdgraph_allocator.hpp"
#include "rcppsw/ta/ds/ds_variant.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class task_allocator
 * @ingroup rcppsw ta
 *
 * @brief Maps the task data structure to its variant, and then applies the
 * corresponding allocation policy to the mapped variant to allocate a task.
 */
class task_allocator : public boost::static_visitor<polled_task*> {
 public:
  task_allocator(const config::task_alloc_config* config, math::rng* rng)
      : m_config(config), m_rng(rng) {}

  task_allocator& operator=(const task_allocator&) = delete;
  task_allocator(const task_allocator&) = delete;

  polled_task* operator()(ds::bi_tdgraph& graph,
                          const polled_task* last_task,
                          uint alloc_count) const {
    return bi_tdgraph_allocator(m_config, &graph, m_rng)(last_task, alloc_count);
  }

 private:
  /* clang-format off */
  const config::task_alloc_config* m_config;
  math::rng*                       m_rng;
  /* clang-format on */
};

NS_END(ta, rcppsw);

#endif /* INCLUDE_RCPPSW_TA_TASK_ALLOCATOR_HPP_ */
