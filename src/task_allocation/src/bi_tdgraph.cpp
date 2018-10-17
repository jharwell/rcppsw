/**
 * @file bi_tdgraph.cpp
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
#include "rcppsw/task_allocation/bi_tdgraph.hpp"
#include <random>

#include "rcppsw/task_allocation/bi_tdgraph_executive.hpp"
#include "rcppsw/task_allocation/polled_task.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
constexpr char bi_tdgraph::kTABInitRoot[];
constexpr char bi_tdgraph::kTABInitRandom[];
constexpr char bi_tdgraph::kTABInitMaxDepth[];

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
bi_tdgraph::bi_tdgraph(const struct task_allocation_params* const params)
    : ER_CLIENT_INIT("rcppsw.ta.bi_tdgraph"),
      mc_params(*params),
      m_tab_sw_prob(&mc_params.tab_sel) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void bi_tdgraph::active_tab_init(const std::string& method) {
  if (kTABInitRoot == method) {
    ER_INFO("Using graph root initial TAB");
    for (auto &t : m_tabs) {
      if (t.root() == tdgraph::root()) {
        m_active_tab = &t;
      }
    } /* for(&t..) */


  } else if (kTABInitRandom == method) {
    ER_INFO("Using random initial TAB");
    m_active_tab = &(*std::next(m_tabs.begin(), std::rand() % m_tabs.size()));
  } else if (kTABInitMaxDepth == method) {
    ER_INFO("Using max_depth initial TAB");
    std::vector<bi_tab*> indices;
    int max_depth = 0;
    for (auto &t : m_tabs) {
      int tab_depth = vertex_depth(t.root());
      if (tab_depth > max_depth) {
        max_depth = tab_depth;
      }
    } /* for(&t..) */
    for (auto &t : m_tabs) {
      if (vertex_depth(t.root()) == max_depth) {
        indices.push_back(&t);
      }
    } /* for(&t..) */

    ER_INFO("Found %zu TABs at depth %d", indices.size(), max_depth);
    m_active_tab = indices[std::rand() % indices.size()];
  } else {
    ER_FATAL_SENTINEL("Bad TAB init method '%s'", method.c_str());
  }
  ER_INFO("Initial TAB rooted at '%s'",
          m_active_tab->root()->name().c_str());
} /* active_tab_init() */

status_t bi_tdgraph::install_tab(const std::string &parent,
                                 const std::vector<polled_task *> &children) {
  return install_tab(find_vertex(parent), children);
} /* install_tab() */

status_t bi_tdgraph::install_tab(const polled_task *parent,
                                 const std::vector<polled_task *> &children) {
  ER_ASSERT(2 == children.size(),
            "Bi tdgraph cannot handle non-binary bifurcations");
  m_tabs.emplace_back(this,
                      const_cast<polled_task*>(parent),
                      children[0],
                      children[1],
                      &mc_params.partitioning,
                      &mc_params.subtask_sel);
  /*
   * Not needed if a priori execution time estimates are used, but is needed
   * if they are not and the root of the tdgraph is partitionable in order to
   * avoid having a partition probability of 0. Doing this gives you an
   * initial partition probability of 0.5 in that case.
   */
  m_tabs.back().partition_prob_update();

  return tdgraph::set_children(parent, children);
} /* install_tab() */


void bi_tdgraph::active_tab_update(const polled_task* const current_task) {
  /*
   * We know that the active tab cannot change if any of the following are true:
   *
   * - The last executed task in the TAB is the TAB root and the parent of that
   *   task is the task itself (active TAB root = root of decomposition graph).
   *
   * - The last executed task in the TAB is a child, AND said task is not
   *   partitionable (task is a leaf of decomposition graph with no children).
   */
  bool is_tdgraph_root = (active_tab()->last_task() == active_tab()->root() &&
                          vertex_parent(*this, active_tab()->last_task()) == active_tab()->last_task());
  bool is_tdgraph_leaf = (active_tab()->last_task() == active_tab()->child1() ||
                          active_tab()->last_task() == active_tab()->child2()) &&
                         !active_tab()->last_task()->is_partitionable();

  bi_tab* new_tab = m_active_tab;
  if (active_tab()->contains_task(current_task) &&
      (is_tdgraph_root || is_tdgraph_leaf)) {
    ER_DEBUG("Active TAB unchanged: last task '%s' was tdgraph root or leaf",
             active_tab()->last_task()->name().c_str());
    return;
  }

  /*
   * The active TAB can change, so compute the probability of it doing so.
   */
  double prob_up = m_tab_sw_prob(active_tab(), tab_parent(active_tab()));
  double prob_down = m_tab_sw_prob(tab_parent(active_tab()), active_tab());
  ER_INFO("TAB w/root='%s' up prob=%f, down prob=%f",
          active_tab()->root()->name().c_str(),
          prob_up,
          prob_down);
  /*
   * If the current task (which is the just finished/abort task) is the root of
   * the active TAB, then we are considering going "up" a TAB level to one that
   * is not as specialized. If it is not the root of the active TAB, then we are
   * considering going "down" a TAB level to one that is more specialized.
   */
  if (current_task == active_tab()->root()) {
    if (prob_up <= static_cast<double>(std::rand()) / RAND_MAX) {
      new_tab = tab_parent(active_tab());
    }
  } else {
    if (prob_down <= static_cast<double>(std::rand()) / RAND_MAX) {
      new_tab = tab_child(active_tab(), current_task);
    }
  }
  m_active_tab = new_tab;
  ER_INFO("New active TAB root='%s'", new_tab->root()->name().c_str());
} /* active_tab_update() */

bi_tab* bi_tdgraph::tab_child(const bi_tab* const tab,
                              const polled_task* const current_task) const {
  ER_ASSERT(tab->child1() == current_task || tab->child2() == current_task,
            "Task '%s' not in TAB rooted at '%s'",
            current_task->name().c_str(),
            tab->root()->name().c_str());

  const bi_tab* ret = nullptr;
  for (auto &t : m_tabs) {
    if (t.root() == current_task &&
        (tab->child1() == t.root() || tab->child2() == t.root())) {
      return const_cast<bi_tab*>(&t);
    }
  } /* for(&tab..) */
  ER_FATAL_SENTINEL("TAB has no children?");
  return const_cast<bi_tab*>(ret);
} /* tab_child() */

bi_tab* bi_tdgraph::root_tab(void) const {
  for (auto &t : m_tabs) {
    if (vertex_parent(t.root()) == t.root()) { /* self */
      return const_cast<bi_tab*>(&t);
    }
  } /* for(&tab..) */
  return nullptr;
} /* root_tab() */

bi_tab* bi_tdgraph::tab_parent(const bi_tab* const tab) const {
  uint count = 0;
  const bi_tab* ret = nullptr;
  if (tab == root_tab()) {
    return const_cast<bi_tab*>(tab);
  }
  for (auto &t : m_tabs) {
    if (tab == &t) { /* self */
      continue;
    } else if (t.child1() == tab->root() || t.child2() == tab->root()) {
      ++count;
      ret = &t;
    }
  } /* for(&tab..) */
  ER_ASSERT(count <= 1, "TAB has more than one parent?");
  return const_cast<bi_tab*>(ret);
} /* tab_parent() */

NS_END(rcppsw, task_allocation);
