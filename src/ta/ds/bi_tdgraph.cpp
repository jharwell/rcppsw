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
#include "rcppsw/ta/ds/bi_tdgraph.hpp"
#include "rcppsw/ta/polled_task.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta, ds);

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
bi_tdgraph::bi_tdgraph(const config::task_alloc_config* const config)
    : ER_CLIENT_INIT("rcppsw.ta.bi_tdgraph"),
      mc_config(*config),
      m_tab_sw_prob(&mc_config.matroid_stoch_nbhd.tab_sel) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void bi_tdgraph::active_tab_init(const std::string& method,
                                 math::rng* rng) {
  if (kTABInitRoot == method) {
    ER_INFO("Using graph root initial TAB");
    active_tab_init_root();
  } else if (kTABInitRandom == method) {
    ER_INFO("Using random initial TAB");
    active_tab_init_random(rng);
  } else if (kTABInitMaxDepth == method) {
    ER_INFO("Using max_depth initial TAB");
    active_tab_init_max_depth(rng);
  } else {
    ER_FATAL_SENTINEL("Bad TAB init method '%s'", method.c_str());
  }
  ER_INFO("Initial TAB rooted at '%s'", m_active_tab->root()->name().c_str());
} /* active_tab_init() */

void bi_tdgraph::active_tab_init_root(void) {
  for (auto& t : m_tabs) {
    if (t.root() == tdgraph::root()) {
      m_active_tab = &t;
    }
  } /* for(&t..) */
} /* active_tab_init_root() */

void bi_tdgraph::active_tab_init_max_depth(math::rng* rng) {
  std::vector<bi_tab*> indices;
  int max_depth = 0;
  for (auto& t : m_tabs) {
    int tab_depth = vertex_depth(t.root());
    if (tab_depth > max_depth) {
      max_depth = tab_depth;
    }
  } /* for(&t..) */
  for (auto& t : m_tabs) {
    if (vertex_depth(t.root()) == max_depth) {
      indices.push_back(&t);
    }
  } /* for(&t..) */

  ER_INFO("Found %zu TABs at depth %d", indices.size(), max_depth);
  m_active_tab = indices[rng->uniform(0, indices.size() - 1)];
} /* active_tab_init_max_depth() */

void bi_tdgraph::active_tab_init_random(math::rng* rng) {
  int index = rng->uniform(0, m_tabs.size());
  m_active_tab = &(*std::next(m_tabs.begin(), index));
} /* active_tab_init_random() */

status_t bi_tdgraph::install_tab(const std::string& parent,
                                 tdgraph::vertex_vector children,
                                 math::rng* rng) {
  return install_tab(find_vertex(parent), std::move(children), rng);
} /* install_tab() */

status_t bi_tdgraph::install_tab(polled_task* parent,
                                 tdgraph::vertex_vector children,
                                 math::rng* rng) {
  ER_ASSERT(2 == children.size(),
            "Bi tdgraph cannot handle non-binary bifurcations");
  bi_tab::elements elts = {.graph = this,
                           .root = parent,
                           .child1 = children[0].get(),
                           .child2 = children[1].get()};
  m_tabs.emplace_back(&elts,
                      &mc_config.matroid_stoch_nbhd.partitioning,
                      &mc_config.matroid_stoch_nbhd.subtask_sel);
  /*
   * Not needed if a priori execution time estimates are used, but is needed
   * if they are not and the root of the tdgraph is partitionable in order to
   * avoid having a partition probability of 0. Doing this gives you an
   * initial partition probability of 0.5 in that case.
   */
  m_tabs.back().partition_prob_update(rng);

  return tdgraph::set_children(parent, std::move(children));
} /* install_tab() */

void bi_tdgraph::active_tab_update(const polled_task* const current_task,
                                   math::rng* rng) {
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
                          vertex_parent(*this, active_tab()->last_task()) ==
                              active_tab()->last_task());
  bool is_tdgraph_leaf = (active_tab()->last_task() == active_tab()->child1() ||
                          active_tab()->last_task() == active_tab()->child2()) &&
                         !active_tab()->last_task()->is_partitionable();

  bi_tab* new_tab = m_active_tab;
  if (nullptr == current_task) {
    return; /* first time running executive */
  } else if (active_tab()->contains_task(current_task) &&
      (is_tdgraph_root || is_tdgraph_leaf)) {
    ER_DEBUG("Active TAB unchanged: last task '%s' was tdgraph root or leaf",
             active_tab()->last_task()->name().c_str());
    return;
  }

  /*
   * If the current task (which is the just finished/aborted task) is the root
   * of the active TAB, then we are considering going "up" a TAB level to one
   * that is not as specialized (i.e. we are too specialized for current
   * conditions).
   *
   * If it is not the root of the active TAB, then we are considering going
   * "down" a TAB level to one that is more specialized (i.e. conditions seem
   * good to specialize more).
   */
  if (current_task == active_tab()->root()) {
    double prob = m_tab_sw_prob(active_tab(),
                                tab_parent(active_tab()),
                                rng);

    ER_INFO("TAB switch up: active_tab root='%s',current_task='%s',prob=%f",
            active_tab()->root()->name().c_str(),
            current_task->name().c_str(),
            prob);

    if (prob >= rng->uniform(0.0, 1.0)) {
      new_tab = tab_parent(active_tab());
    }
  } else {
    double prob = m_tab_sw_prob(active_tab(),
                                tab_child(active_tab(), current_task),
                                rng);

    ER_INFO("TAB switch down: active_tab root='%s',current_task='%s',prob=%f",
            active_tab()->root()->name().c_str(),
            current_task->name().c_str(),
            prob);
    if (prob >= rng->uniform(0.0, 1.0)) {
      new_tab = tab_child(active_tab(), current_task);
    }
  }
  m_active_tab = new_tab;
  ER_INFO("New active TAB root='%s'", new_tab->root()->name().c_str());
} /* active_tab_update() */

bi_tab* bi_tdgraph::tab_child(const bi_tab* const tab,
                              const polled_task* const current_task) {
  ER_ASSERT(tab->child1() == current_task || tab->child2() == current_task,
            "Task '%s' not in TAB rooted at '%s'",
            current_task->name().c_str(),
            tab->root()->name().c_str());

  for (auto& t : m_tabs) {
    if (t.root() == current_task &&
        (tab->child1() == t.root() || tab->child2() == t.root())) {
      return &t;
    }
  } /* for(&tab..) */
  ER_FATAL_SENTINEL("TAB has no children?");
  return nullptr;
} /* tab_child() */

bi_tab* bi_tdgraph::root_tab(void) {
  auto it = std::find_if(m_tabs.begin(), m_tabs.end(), [&](const auto& t) {
    return vertex_parent(t.root()) == t.root();
  });
  return (it != m_tabs.end()) ? &(*it) : nullptr;
} /* root_tab() */

const bi_tab* bi_tdgraph::root_tab(void) const {
  auto it = std::find_if(m_tabs.begin(), m_tabs.end(), [&](const auto& t) {
    return vertex_parent(t.root()) == t.root();
  });
  return (it != m_tabs.end()) ? &(*it) : nullptr;
} /* root_tab() */

bi_tab* bi_tdgraph::tab_parent(const bi_tab* const tab) {
  ER_ASSERT(tab_parent_verify(tab), "TAB has more than one parent?");
  if (tab == root_tab()) {
    return root_tab();
  }
  auto it = std::find_if(m_tabs.begin(), m_tabs.end(), [&](const auto& t) {
    return (tab != &t && /* self */
            (t.child1() == tab->root() || t.child2() == tab->root()));
  });
  return (it != m_tabs.end()) ? &(*it) : nullptr;
} /* tab_parent() */

const bi_tab* bi_tdgraph::tab_parent(const bi_tab* const tab) const {
  return const_cast<bi_tdgraph*>(this)->tab_parent(tab);
} /* tab_parent() */

bool bi_tdgraph::tab_parent_verify(const bi_tab* const tab) const {
  uint count = 0;
  for (auto& t : m_tabs) {
    if (tab == &t) { /* self */
      continue;
    } else if (t.child1() == tab->root() || t.child2() == tab->root()) {
      ++count;
    }
  } /* for(&tab..) */
  return count <= 1;
} /* tab_parent() */

NS_END(ds, ta, rcppsw);
