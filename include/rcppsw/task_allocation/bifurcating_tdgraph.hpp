/**
 * @file bifurcating_tdgraph.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_BIFURCATING_TDGRAPH_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_BIFURCATING_TDGRAPH_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <string>
#include <vector>

#include "rcppsw/task_allocation/tdgraph.hpp"
#include "rcppsw/task_allocation/bifurcating_tab.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

class bifurcating_tdgraph_executive;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class bifurcating_tdgraph
 * @ingroup task_allocation
 *
 * @brief Representation of an overall task (the root task) as a BINARY tree
 * representing the task decomposition of the root task at different
 * granularities (i.e. tasks of different levels of complexity).
 */
class bifurcating_tdgraph : public tdgraph,
                            public er::client<bifurcating_tdgraph> {
 public:
  bifurcating_tdgraph(void);

  bifurcating_tdgraph(const bifurcating_tdgraph& other) = delete;
  bifurcating_tdgraph& operator=(const bifurcating_tdgraph& other) = delete;

  /**
   * @brief Set the children for an existing node.
   *
   * @param parent The parent node, which MUST be a \ref partitionable_task.
   * @param children The list of children (must be exactly 2) to associate with
   * the parent.
   *
   * @return \ref status_t.
   */
  status_t set_children(const polled_task* parent,
                        const std::vector<polled_task*>& children) override;
  status_t set_children(const std::string& parent,
                        const std::vector<polled_task*>& children) override;


  /**
   * @brief Get the active TAB for the graph.
   */
  const bifurcating_tab* active_tab(void) const { return m_active_tab; }

  /**
   * @brief Install task abort and alloc callbacks. Can't be done during
   * construction, as a graph is part of the executive, and so a reference to a
   * constructed executive object is not yet available.
   *
   * @param e The executive.
   */
  void install_cb(bifurcating_tdgraph_executive* e);

 private:
  /**
   * @brief Callback install in \ref tdgraph to handle updating the TAB (if
   * needed) each time there is a new task allocation.
   *
   * @param v The task that was just allocated.
   */
  void task_alloc_cb(const polled_task* v);

  /**
   * @brief Callback install in \ref tdgraph to handle updating a task's last
   * partition if it is aborted. This could be done in the executive, but
   * because it seems more related to a TAB, I'm putting it here.
   *
   * @param v The task that was just aborted.
   */
  void task_abort_cb(const polled_task* v);

  // clang-format off
  std::list<bifurcating_tab> m_tabs{};
  const bifurcating_tab *    m_active_tab{nullptr};
  // clang-format on
};

NS_END(task_allocation, rcppsw);
#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_BIFURCATING_TDGRAPH_HPP_ */
