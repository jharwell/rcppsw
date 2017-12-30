/**
 * @file partitionable_task.cpp
 *
 * @copyright 2017 John Harwell, All rights reserved.
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
#include "rcppsw/task_allocation/partitionable_task.hpp"
#include "rcppsw/task_allocation/executable_task.hpp"
#include "rcppsw/task_allocation/task_params.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
partitionable_task::partitionable_task(
    const std::shared_ptr<er::server>& server,
    const struct partitionable_task_params* c_params)
    : client(server),
      m_always_partition(c_params->always_partition),
      m_never_partition(c_params->never_partition),
      m_partition1(nullptr),
      m_partition2(nullptr),
      m_last_partition(nullptr),
      m_selection_prob(c_params->subtask_selection_method),
      m_partition_prob(c_params->partition_method,
                       c_params->partition_reactivity) {
  if (ERROR == client::attmod("partitionable_task")) {
    client::insmod("partitionable_task",
                   rcppsw::er::er_lvl::DIAG,
                   rcppsw::er::er_lvl::NOM);
  }
  if ("brutschy2014" == c_params->subtask_selection_method) {
    m_selection_prob.init_brutschy2014(1.0, 2, 1);
  }
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void partitionable_task::update_partition_prob(const time_estimate& task,
                                               const time_estimate& subtask1,
                                               const time_estimate& subtask2) {
  m_partition_prob.calc(task, subtask1, subtask2);
}

executable_task* partitionable_task::partition(void) {
  ER_ASSERT(!(m_always_partition && m_never_partition),
            "FATAL: cannot ALWAYS and NEVER partition");

  double partition_prob;
  if (m_always_partition) {
    partition_prob = 1;
  } else if (m_never_partition) {
    partition_prob = 0;
  } else {
    partition_prob = m_partition_prob.last_result();
  }

  ER_NOM("Task '%s': partition_method=%s partition_prob=%f",
         m_partition1->parent()->name().c_str(),
         m_partition_prob.method().c_str(),
         partition_prob);

  /* We chose not to employ partitioning on the next task allocation */
  if (partition_prob <= static_cast<double>(rand()) / RAND_MAX) {
    ER_NOM("Not employing partitioning: Return task '%s'",
           m_partition1->parent()->name().c_str());
    return static_cast<executable_task*>(m_partition1->parent());
  }
  executable_task* ret = nullptr;

  /* We have chosen to employ partitioning */
  double prob_12 = m_selection_prob.calc(&m_partition1->exec_estimate(),
                                         &m_partition2->exec_estimate());
  double prob_21 = m_selection_prob.calc(&m_partition2->exec_estimate(),
                                         &m_partition1->exec_estimate());

  ER_NOM(
      "Task '%s': selection_method=%s subtask1->subtask2 "
      "prob=%f,subtask2->subtask1 prob=%f",
      m_partition1->parent()->name().c_str(),
      m_selection_prob.method().c_str(),
      prob_12,
      prob_21);

  if ("brutschy2014" == m_selection_prob.method()) {
    /*
     * If we last executed subtask1, we calculate the probability of switching
     * to subtask2, based on time estimates.
     */
    if (m_last_partition == m_partition1 || nullptr == m_last_partition) {
      if (prob_12 >= static_cast<double>(rand()) / RAND_MAX) {
        ret = m_partition2;
      } else {
        ret = m_partition1;
      }
    }
    /*
     * If we last executed subtask2, we calculate the probability of switching
     * to subtask1, based on time estimates
     */
    else if (m_last_partition == m_partition2) {
      if (prob_21 >= static_cast<double>(rand()) / RAND_MAX) {
        ret = m_partition1;
      } else {
        ret = m_partition2;
      }
    }
  } else if ("random" == m_selection_prob.method()) {
    if (prob_12 >= static_cast<double>(rand()) / RAND_MAX) {
      ret = m_partition1;
    } else {
      ret = m_partition2;
    }
  }
  ER_ASSERT(nullptr != ret, "FATAL: no task selected");
  ER_NOM("Selected subtask '%s'", ret->name().c_str());
  return ret;
} /* partition() */

NS_END(task_allocation, rcppsw);
