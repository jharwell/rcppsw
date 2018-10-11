/**
 * @file bi_tdgraph.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_BI_TDGRAPH_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_BI_TDGRAPH_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <list>
#include <algorithm>

#include "rcppsw/task_allocation/tdgraph.hpp"
#include "rcppsw/task_allocation/bi_tab.hpp"
#include "rcppsw/task_allocation/bi_tab_selection_probability.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

class bi_tdgraph_executive;
struct sigmoid_selection_params;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class bi_tdgraph
 * @ingroup task_allocation
 *
 * @brief Representation of an overall task (the root task) as a BINARY tree
 * representing the task decomposition of the root task at different
 * granularities (i.e. tasks of different levels of complexity).
 */
class bi_tdgraph : public tdgraph, public er::client<bi_tdgraph> {
 public:
  explicit bi_tdgraph(const struct sigmoid_selection_params* params);

  bi_tdgraph(const bi_tdgraph& other) = delete;
  bi_tdgraph& operator=(const bi_tdgraph& other) = delete;

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
   * @brief Update the active TAB *BEFORE* task allocation is performed in the
   * executive that owns this graph.
   *
   * @param current_task The current task that just finished/aborted/whatever.
   */
  void active_tab_update(const polled_task* const current_task);

  /**
   * @brief Get the active TAB for the graph.
   */
  const bi_tab* active_tab(void) const { return m_active_tab; }
  bi_tab* active_tab(void) { return m_active_tab; }

  /**
   * @brief Return a uuid for the active tab (really just an index in the vector
   * of TABs).
   */
  __rcsw_pure int active_tab_id(void) const {
    return std::distance(m_tabs.begin(),
                         std::find_if(m_tabs.begin(),
                                      m_tabs.end(),
                                      [this](const auto & tab) {
                                      return &tab == m_active_tab;
                                      }));
  }
  /**
   * @brief Install task abort and alloc callbacks. Can't be done during
   * construction, as a graph is part of the executive, and so a reference to a
   * constructed executive object is not yet available.
   *
   * @param e The executive.
   */
  void install_cb(bi_tdgraph_executive* e);

 private:
  /**
   * @brief Get the parent TAB for the argument (i.e. the TAB which has as a
   * child the root of the TAB argument).
   */
  bi_tab* tab_parent(const bi_tab* tab) const;

  /**
   * @brief Get the child tab for the argument (i.e. the TAB whose root is the
   * left/right child of the argument)
   *
   * @param tab The tab.
   * @param current_task The current active task in the tab.
   */
  bi_tab* tab_child(const bi_tab* tab, const polled_task* current_task) const;

  /**
   * @brief Callback install in \ref tdgraph to handle updating a task's last
   * partition if it is aborted. This could be done in the executive, but
   * because it seems more related to a TAB, I'm putting it here.
   *
   * @param v The task that was just aborted.
   */
  void task_abort_cb(const polled_task* v);

  // clang-format off
  std::list<bi_tab>            m_tabs{};
  bi_tab *                     m_active_tab{nullptr};
  bi_tab_selection_probability m_tab_sw_prob;
  // clang-format on
};

NS_END(task_allocation, rcppsw);
#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_BI_TDGRAPH_HPP_ */
