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
#include "rcppsw/ta/base_executive.hpp"
#include "rcppsw/ta/config/task_executive_config.hpp"
#include "rcppsw/ta/polled_task.hpp"
#include "rcppsw/ta/tdgraph.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
base_executive::base_executive(const config::task_executive_config* const config,
                               std::unique_ptr<tdgraph> graph)
    : ER_CLIENT_INIT("rcppsw.ta.executive.base"),
      m_update_exec_ests(config->update_exec_ests),
      m_update_interface_ests(config->update_interface_ests),
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

NS_END(ta, rcppsw);
