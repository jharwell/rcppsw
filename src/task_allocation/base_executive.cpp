/**
 * @file base_executive.cpp
 *
 * @copyright 2018 John Harwell, All rights reserved.
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
#include "rcppsw/task_allocation/base_executive.hpp"
#include "rcppsw/task_allocation/polled_task.hpp"
#include "rcppsw/task_allocation/task_executive_params.hpp"
#include "rcppsw/task_allocation/tdgraph.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
base_executive::base_executive(const struct task_executive_params* const params,
                               std::unique_ptr<tdgraph> graph)
    : ER_CLIENT_INIT("rcppsw.ta.executive.base"),
      m_update_exec_ests(params->update_exec_ests),
      m_update_interface_ests(params->update_interface_ests),
      m_graph(std::move(graph)) {}

base_executive::~base_executive(void) = default;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
__rcsw_pure const polled_task* base_executive::root_task(void) const {
  return m_graph->root();
} /* root_task() */

__rcsw_pure polled_task* base_executive::root_task(void) {
  return m_graph->root();
} /* root_task() */

const polled_task* base_executive::parent_task(const polled_task* v) {
  return tdgraph::vertex_parent(*m_graph, v);
} /* parent_task() */

NS_END(task_allocation, rcppsw);
