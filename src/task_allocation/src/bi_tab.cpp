/**
 * @file bi_tab.cpp
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
#include "rcppsw/task_allocation/bi_tab.hpp"
#include <cassert>

#include "rcppsw/task_allocation/polled_task.hpp"
#include "rcppsw/task_allocation/bi_tdgraph.hpp"
#include "rcppsw/task_allocation/partitioning_params.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
bi_tab::bi_tab(const bi_tdgraph* const graph,
               polled_task *const root,
               const polled_task *const child1,
               const polled_task *const child2,
               const struct partitioning_params* const partitioning,
               const struct sigmoid_selection_params* const subtask_sel)
    : ER_CLIENT_INIT("rcppsw.ta.bi_tab"),
      mc_always_partition(partitioning->always_partition),
      mc_never_partition(partitioning->never_partition),
      mc_graph(graph),
      m_root(root),
      m_child1(child1),
      m_child2(child2),
      m_selection_prob(subtask_sel),
      m_partition_prob(&partitioning->sigmoid) {
  ER_ASSERT(m_root->is_partitionable(), "Root task '%s' not partitionable",
            m_root->name().c_str());
  ER_ASSERT(!(m_root->is_atomic() && m_root->is_partitionable()),
            "Root task '%s' cannot be both atomic and partitionable",
            m_root->name().c_str());
  ER_ASSERT(!(m_child1->is_atomic() && m_child1->is_partitionable()),
            "Child1 task '%s' cannot be both atomic and partitionable",
            m_child1->name().c_str());
  ER_ASSERT(!(m_child2->is_atomic() && m_child2->is_partitionable()),
            "Child2 task '%s' cannot be both atomic and partitionable",
            m_child2->name().c_str());
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void bi_tab::change_active_task(const polled_task *const active_task) {
  if (nullptr != active_task) {
    ER_ASSERT(this->contains_task(active_task),
              "New active task '%s' not in TAB",
              active_task->name().c_str());
  }
  m_last_task = m_active_task;
  m_active_task = active_task;
} /* change_active_task() */

__rcsw_pure bool
bi_tab::contains_task(const polled_task *const task) const {
  return task == m_root || task == m_child1 || task == m_child2;
} /* contains_task() */

__rcsw_pure bool
bi_tab::task_is_root(const polled_task *const task) const {
  return task == m_root;
} /* task_is_root() */

__rcsw_pure bool
bi_tab::task_is_child(const polled_task *const task) const {
  return task == m_child1 || task == m_child2;
} /* task_is_child() */

void bi_tab::partition_prob_update(void) {
  m_partition_prob.calc(m_root->task_exec_estimate(),
                        m_child1->task_exec_estimate(),
                        m_child2->task_exec_estimate());
} /* partition_prob_update() */

polled_task * bi_tab::task_allocate(void) {
  ER_ASSERT(!(mc_always_partition && mc_never_partition),
            "Cannot ALWAYS and NEVER partition");

  double partition_prob;
  std::string name = dynamic_cast<executable_task *>(m_root)->name();

  if (mc_always_partition) {
    partition_prob = 1;
  } else if (mc_never_partition) {
    partition_prob = 0;
  } else {
    partition_prob = m_partition_prob.last_result();
    ER_INFO("TAB root='%s': partition_method=%s partition_prob=%f", name.c_str(),
            m_partition_prob.method().c_str(), partition_prob);
  }

  /* We chose not to employ partitioning on the next task allocation */
  if (partition_prob <= static_cast<double>(std::rand()) / RAND_MAX) {
    ER_INFO("Not employing partitioning: Return task '%s'", name.c_str());
    m_employed_partitioning = false;
    auto ret = dynamic_cast<polled_task *>(this);
    ER_ASSERT(nullptr != ret, "Partitionable task is not pollable")
    return ret;
  }
  /* We have chosen to employ partitioning, so we must return a subtask */
  m_employed_partitioning = true;
  polled_task* ret = subtask_allocate();
  m_last_subtask = ret;
  return ret;
} /* task_allocate() */

polled_task* bi_tab::subtask_allocate(void) {
  double prob_12, prob_21;
  ER_INFO("Employing partitioning at task '%s': selection_method=%s, last_subtask=%s",
          m_root->name().c_str(),
          m_selection_prob.method().c_str(),
          (nullptr != m_last_subtask) ? m_last_subtask->name().c_str()
          : "None");


  if (subtask_selection_probability::kMethodHarwell2018 ==
      m_selection_prob.method()) {
    prob_12 = m_selection_prob(&m_child1->task_exec_estimate(),
                               &m_child2->task_exec_estimate());
    prob_21 = m_selection_prob(&m_child2->task_exec_estimate(),
                               &m_child1->task_exec_estimate());
  } else if (subtask_selection_probability::kMethodBrutschy2014 ==
             m_selection_prob.method()) {
    prob_12 = m_selection_prob(&m_child1->task_interface_estimate(),
                               &m_child2->task_interface_estimate());
    prob_21 = m_selection_prob(&m_child2->task_interface_estimate(),
                               &m_child1->task_interface_estimate());
  }

  ER_INFO("%s exec_est=%f/int_est=%f, %s exec_est=%f/int_est=%f",
          m_child1->name().c_str(),
          m_child1->task_exec_estimate().last_result(),
          m_child1->task_interface_estimate().last_result(),
          m_child2->name().c_str(),
          m_child2->task_exec_estimate().last_result(),
          m_child2->task_interface_estimate().last_result());

  ER_INFO("%s -> %s prob=%f, %s -> %s prob=%f", m_child1->name().c_str(),
          m_child2->name().c_str(), prob_12, m_child2->name().c_str(),
          m_child1->name().c_str(), prob_21);

  const polled_task *ret = nullptr;
  if (subtask_selection_probability::kMethodHarwell2018 ==
          m_selection_prob.method() ||
      subtask_selection_probability::kMethodBrutschy2014 ==
          m_selection_prob.method()) {
    /*
     * If we last executed m_child1, we calculate the probability of switching
     * to m_child2, based on time estimates.
     */
    if (m_last_subtask == m_child1 || nullptr == m_last_subtask) {
      if (prob_12 >= static_cast<double>(std::rand()) / RAND_MAX) {
        ret = m_child2;
      } else {
        ret = m_child1;
      }
    }
    /*
     * If we last executed m_child2, we calculate the probability of switching
     * to m_child1, based on time estimates.
     */
    else if (m_last_subtask == m_child2) {
      if (prob_21 >= static_cast<double>(std::rand()) / RAND_MAX) {
        ret = m_child1;
      } else {
        ret = m_child2;
      }
    }
  } else if (subtask_selection_probability::kMethodRandom ==
             m_selection_prob.method()) {
    if (prob_12 >= static_cast<double>(std::rand()) / RAND_MAX) {
      ret = m_child1;
    } else {
      ret = m_child2;
    }
  }
  ER_ASSERT(nullptr != ret, "No subtask selected?");
  ER_INFO("Selected subtask '%s'", ret->name().c_str());
  return const_cast<polled_task *>(ret);
} /* subtask_allocate() */

/*******************************************************************************
 * TAB Metrics
 ******************************************************************************/
bool bi_tab::task_depth_changed(void) const {
  if (nullptr == m_last_task) {
    return true; /* first allocation */
  }
  return mc_graph->vertex_depth(m_active_task) !=
      mc_graph->vertex_depth(m_last_task);
} /* task_depth_changed() */

NS_END(task_allocation, rcppsw);
