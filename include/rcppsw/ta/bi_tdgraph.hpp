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

#ifndef INCLUDE_RCPPSW_TA_BI_TDGRAPH_HPP_
#define INCLUDE_RCPPSW_TA_BI_TDGRAPH_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <list>
#include <random>
#include <string>

#include "rcppsw/ta/bi_tab.hpp"
#include "rcppsw/ta/bi_tab_sel_probability.hpp"
#include "rcppsw/ta/config/task_alloc_config.hpp"
#include "rcppsw/ta/tdgraph.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class bi_tdgraph
 * @ingroup rcppsw ta
 *
 * @brief Representation of an overall task (the root task) as a BINARY tree
 * representing the task decomposition of the root task at different
 * granularities (i.e. tasks of different levels of complexity).
 */
class bi_tdgraph final : public tdgraph, public er::client<bi_tdgraph> {
 public:
  static constexpr char kTABInitRoot[] = "root";
  static constexpr char kTABInitRandom[] = "random";
  static constexpr char kTABInitMaxDepth[] = "max_depth";

  explicit bi_tdgraph(const config::task_alloc_config* config);

  bi_tdgraph(const bi_tdgraph& other) = delete;
  bi_tdgraph& operator=(const bi_tdgraph& other) = delete;

  /**
   * @brief Set the children for an existing node.
   *
   * Do not call \ref tdgraph::set_children() directly, or your bi_tdgraph will
   * not work properly.
   *
   * @param parent The parent node, which MUST be partitionable.
   * @param children The list of children (must be exactly 2) to associate with
   * the parent.
   *
   * @return \ref status_t.
   */
  status_t install_tab(polled_task* parent, tdgraph::vertex_vector children);
  status_t install_tab(const std::string& parent,
                       tdgraph::vertex_vector children);

  /**
   * @brief Update the active TAB *BEFORE* task allocation is performed in the
   * executive that owns this graph.
   *
   * @param current_task The current task that just finished/aborted/whatever.
   */
  void active_tab_update(const polled_task* current_task);

  /**
   * @brief Get the active TAB for the graph.
   */
  const bi_tab* active_tab(void) const { return m_active_tab; }
  bi_tab* active_tab(void) { return m_active_tab; }
  void active_tab(bi_tab* active_tab) { m_active_tab = active_tab; }

  /**
   * @brief Return a uuid for the active tab (really just an index in the vector
   * of TABs).
   */
  RCSW_PURE int active_tab_id(void) const {
    return std::distance(
        m_tabs.begin(),
        std::find_if(m_tabs.begin(), m_tabs.end(), [this](const auto& tab) {
          return &tab == m_active_tab;
        }));
  }
  /**
   * @brief Get the parent TAB for the argument (i.e. the TAB which has as a
   * child the root of the TAB argument).
   */
  const bi_tab* tab_parent(const bi_tab* tab) const;
  const bi_tab* root_tab(void) const;
  bi_tab* root_tab(void);

  /**
   * @brief Get the child tab for the argument (i.e. the TAB whose root is the
   * left/right child of the argument)
   *
   * @param tab The tab.
   * @param current_task The current active task in the tab.
   */
  bi_tab* tab_child(const bi_tab* tab,
                    const polled_task* current_task) RCSW_PURE;

  void active_tab_init(const std::string& method);

 private:
  using tdgraph::set_children;

  void active_tab_init_root(void);
  void active_tab_init_random(void);
  void active_tab_init_max_depth(void);
  bi_tab* tab_parent(const bi_tab* tab);
  bool tab_parent_verify(const bi_tab* tab) const RCSW_PURE;

  /* clang-format off */
  const config::task_alloc_config mc_config;
  std::list<bi_tab>               m_tabs{};
  bi_tab *                        m_active_tab{nullptr};
  bi_tab_sel_probability          m_tab_sw_prob;
  std::default_random_engine      m_rng;
  /* clang-format on */
};

NS_END(ta, rcppsw);
#endif /* INCLUDE_RCPPSW_TA_BI_TDGRAPH_HPP_ */
