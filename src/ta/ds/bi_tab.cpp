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
#include "rcppsw/ta/ds/bi_tab.hpp"

#include <cassert>
#include <chrono>

#include "rcppsw/ta/ds/bi_tdgraph.hpp"
#include "rcppsw/ta/config/src_sigmoid_sel_config.hpp"
#include "rcppsw/ta/config/task_partition_config.hpp"
#include "rcppsw/ta/polled_task.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta, ds);

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
bi_tab::bi_tab(const struct elements* elts,
               const config::task_partition_config* const partitioning,
               const config::src_sigmoid_sel_config* const subtask_sel)
    : ER_CLIENT_INIT("rcppsw.ta.bi_tab"),
      mc_always_partition(partitioning->always_partition),
      mc_never_partition(partitioning->never_partition),
      mc_partition_input(partitioning->src_sigmoid.input_src),
      mc_subtask_sel_input(subtask_sel->input_src),
      mc_graph(elts->graph),
      m_root(elts->root),
      m_child1(elts->child1),
      m_child2(elts->child2),
      m_sel_prob(&subtask_sel->sigmoid),
      m_partition_prob(&partitioning->src_sigmoid.sigmoid),
      m_rng(std::chrono::system_clock::now().time_since_epoch().count()) {
  ER_ASSERT(m_root->is_partitionable(),
            "Root task '%s' not partitionable",
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
void bi_tab::task_abort_update(polled_task* const aborted) {
  ER_ASSERT(contains_task(aborted),
            "Aborted task '%s' not in TAB",
            aborted->name().c_str());
  partition_prob_update();
  m_last_task = aborted;
  if (subtask1_active() || subtask2_active()) {
    m_last_subtask = aborted;
  }
  m_active_task = nullptr;
} /* task_abort_update() */

void bi_tab::task_finish_update(polled_task* const finished) {
  ER_ASSERT(contains_task(finished),
            "Finished task '%s' not in TAB",
            finished->name().c_str());
  partition_prob_update();
  m_last_task = finished;
  if (subtask1_active() || subtask2_active()) {
    m_last_subtask = finished;
  }
  m_active_task = nullptr;
} /* task_finish_update() */

bool bi_tab::contains_task(const polled_task* const task) const {
  return task == m_root || task == m_child1 || task == m_child2;
} /* contains_task() */

bool bi_tab::task_is_root(const polled_task* const task) const {
  return task == m_root;
} /* task_is_root() */

bool bi_tab::task_is_child(const polled_task* const task) const {
  return task == m_child1 || task == m_child2;
} /* task_is_child() */

void bi_tab::partition_prob_update(void) {
  if (kPartitionSrcExec == mc_partition_input) {
    m_partition_prob(m_root->task_exec_estimate(),
                     m_child1->task_exec_estimate(),
                     m_child2->task_exec_estimate(),
                     m_rng);
  } else if (kPartitionSrcInterface == mc_partition_input) {
    int root_id = m_root->task_last_active_interface();
    int child1_id = m_child1->task_last_active_interface();
    int child2_id = m_child2->task_last_active_interface();
    if (root_id >= 0 && child1_id >= 0 && child2_id >= 0) {
      m_partition_prob(m_root->task_interface_estimate(root_id),
                       m_child1->task_interface_estimate(child1_id),
                       m_child2->task_interface_estimate(child2_id),
                       m_rng);

    } else {
      ER_WARN(
          "Cannot update partition prob for TAB rooted at '%s': >= 1 task has "
          "no last interface",
          m_root->name().c_str());
    }
  } else {
    ER_FATAL_SENTINEL("Bad partition input src '%s'",
                      mc_partition_input.c_str());
  }
} /* partition_prob_update() */

polled_task* bi_tab::task_allocate(void) {
  ER_ASSERT(!(mc_always_partition && mc_never_partition),
            "Cannot ALWAYS and NEVER partition");

  double partition_prob;

  if (mc_always_partition) {
    partition_prob = 1.0;
  } else if (mc_never_partition) {
    partition_prob = 0.0;
  } else {
    partition_prob = m_partition_prob.v();
    ER_INFO("TAB root='%s': partition_method=%s partition_prob=%f",
            m_root->name().c_str(),
            m_partition_prob.method().c_str(),
            partition_prob);
  }

  /* We chose not to employ partitioning on the next task allocation */
  std::uniform_real_distribution<> dist(0.0, 1.0);
  if (partition_prob <= dist(m_rng)) {
    ER_INFO("Not employing partitioning: Return task '%s'",
            m_root->name().c_str());
    m_employed_partitioning = false;
    m_active_task = m_root;
    return m_root;
  }
  /* We have chosen to employ partitioning, so we must return a subtask */
  m_employed_partitioning = true;
  polled_task* ret = subtask_allocate();
  m_last_subtask = ret;
  return ret;
} /* task_allocate() */

std::pair<double, double> bi_tab::subtask_sw_calc(void) {
  double prob_12 = 0.0;
  double prob_21 = 0.0;
  const time_estimate* task1 = nullptr;
  const time_estimate* task2 = nullptr;

  if (subtask_sel_probability::kMethodHarwell2018 == m_sel_prob.method()) {
    if (kSubtaskSelSrcExec == mc_subtask_sel_input) {
      task1 = &m_child1->task_exec_estimate();
      task2 = &m_child2->task_exec_estimate();
    } else if (kSubtaskSelSrcInterface == mc_subtask_sel_input) {
      int child1_id = m_child1->task_last_active_interface();
      int child2_id = m_child2->task_last_active_interface();
      if (child1_id >= 0 && child2_id >= 0) {
        task1 = &m_child1->task_interface_estimate(child1_id);
        task2 = &m_child2->task_interface_estimate(child1_id);
      } else {
        /* fall through */
        ER_WARN(
            "Cannot calc subtask sel prob for TAB rooted at '%s': >= 1 task "
            "has no last interface: using random selection",
            m_root->name().c_str());
      }
    }
  } else if (subtask_sel_probability::kMethodBrutschy2014 ==
             m_sel_prob.method()) {
    /*
     * @todo: This will have to be updated if I ever want to use this method
     * with task with more than 1 interface. Brutschy2014 only ever used tasks
     * with 1 interface, so its OK for now.
     */
    task1 = &m_child1->task_interface_estimate(0);
    task2 = &m_child2->task_interface_estimate(0);
  } else { /* fall through (random) */
  }
  prob_12 = m_sel_prob(task1, task2, m_rng);
  prob_21 = m_sel_prob(task2, task1, m_rng);
  return std::make_pair(prob_12, prob_21);
} /* subtask_sw_calc() */

polled_task* bi_tab::subtask_allocate(void) {
  ER_INFO("Employing partitioning at task '%s': sel_method=%s, last_subtask=%s",
          m_root->name().c_str(),
          m_sel_prob.method().c_str(),
          (nullptr != m_last_subtask) ? m_last_subtask->name().c_str() : "None");

  auto probs = subtask_sw_calc();
  double prob_12 = probs.first;
  double prob_21 = probs.second;
  ER_INFO("%s exec_est=%f/int_est=%f, %s exec_est=%f/int_est=%f",
          m_child1->name().c_str(),
          m_child1->task_exec_estimate().v(),
          m_child1->task_interface_estimate(0).v(),
          m_child2->name().c_str(),
          m_child2->task_exec_estimate().v(),
          m_child2->task_interface_estimate(0).v());

  ER_INFO("%s -> %s prob=%f, %s -> %s prob=%f",
          m_child1->name().c_str(),
          m_child2->name().c_str(),
          prob_12,
          m_child2->name().c_str(),
          m_child1->name().c_str(),
          prob_21);

  polled_task* ret = nullptr;
  std::uniform_real_distribution<> dist(0.0, 1.0);
  /*
   * If we last executed child1, we calculate the probability of switching
   * to child2, based on time estimates.
   */
  if (m_last_subtask == m_child1 || nullptr == m_last_subtask) {
    if (prob_12 >= dist(m_rng)) {
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
    if (prob_21 >= dist(m_rng)) {
      ret = m_child1;
    } else {
      ret = m_child2;
    }
  }
  ER_INFO("Selected subtask '%s'", ret->name().c_str());
  m_active_task = ret;
  return ret;
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

NS_END(ds, ta, rcppsw);
