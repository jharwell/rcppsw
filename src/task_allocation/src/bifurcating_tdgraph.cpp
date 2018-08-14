/**
 * @file bifurcating_tdgraph.cpp
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
#include "rcppsw/task_allocation/bifurcating_tdgraph.hpp"
#include "rcppsw/task_allocation/polled_task.hpp"
#include "rcppsw/task_allocation/partitionable_task.hpp"
#include "rcppsw/task_allocation/bifurcating_tdgraph_executive.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
bifurcating_tdgraph::bifurcating_tdgraph(std::shared_ptr<er::server> &server)
    : tdgraph(server) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void bifurcating_tdgraph::install_cb(bifurcating_tdgraph_executive* const e) {
  e->task_alloc_notify(std::bind(&bifurcating_tdgraph::task_alloc_cb,
                                 this,
                                 std::placeholders::_1));
  e->task_abort_notify(std::bind(&bifurcating_tdgraph::task_abort_cb,
                                 this,
                                 std::placeholders::_1));
} /* install_cb() */

status_t bifurcating_tdgraph::set_children(const std::string &parent,
                             const std::vector<polled_task*>& children) {
  return tdgraph::set_children(parent, children);
} /* set_children() */

status_t
bifurcating_tdgraph::set_children(const polled_task* parent,
                                  const std::vector<polled_task*>& children) {
  ER_ASSERT(2 == children.size(),
            "FATAL: Bifurcating tdgraph cannot handle non-binary bifurcations");
  m_tabs.emplace_back(parent,
                      children[0],
                      children[1]);
  return tdgraph::set_children(parent, children);
} /* set_children() */

void bifurcating_tdgraph::task_alloc_cb(const polled_task* const v) {
  for (auto &t : m_tabs) {
    if (t.contains_task(v)) {
      t.change_active_task(v);
      m_active_tab = &t;
    } else {
      t.change_active_task(nullptr);
    }
  } /* for(&r..) */
} /* task_alloc_cb() */

void bifurcating_tdgraph::task_abort_cb(const polled_task* const v) {
  auto parent = dynamic_cast<partitionable_task*>(vertex_parent(v));
  parent->last_partition(v);
} /* task_abort_cb() */

NS_END(rcppsw, task_allocation);
