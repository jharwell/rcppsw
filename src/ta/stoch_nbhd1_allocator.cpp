/**
 * @file stoch_nbhd1_allocator.cpp
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
#include "rcppsw/ta/stoch_nbhd1_allocator.hpp"
#include <algorithm>
#include "rcppsw/ta/polled_task.hpp"
#include "rcppsw/ta/ds/bi_tdgraph.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
polled_task* stoch_nbhd1_allocator::operator()(
    const polled_task* current_task) const {
  /*
   * If there is no active TAB, then the root task is not partitionable, so
   * return it.
   */
  if (nullptr == m_graph->active_tab()) {
    return m_graph->root();
  } else {
    /*
     * Update our active TAB so that we perform partitioning from the correct
     * place. We have to pass in the current_task(), because the TAB's active
     * task has already been updated to be NULL after the task finish/abort
     * that brought us to this function.
     */
    m_graph->active_tab_update(current_task, m_rng);

    return m_graph->active_tab()->task_allocate(m_rng);
  }
} /* alloc_stoch_nbhd1() */

NS_END(ta, rcppsw);
