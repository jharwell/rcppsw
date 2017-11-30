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
    const std::string& name,
    const struct partitionable_task_params* const params,
    executable_task* const parent):
    executable_task(name, params, parent),
    client(server),
    m_selection_method(params->subtask_selection_method),
    m_partition1(nullptr),
    m_partition2(nullptr),
    m_last_partition(nullptr),
    m_selection_prob(1.0, 1/8, 0.01),
    m_partition_prob(params->reactivity) {
  if (ERROR == client::attmod("partitionable_task")) {
    client::insmod("partitionable_task",
                   rcppsw::er::er_lvl::DIAG,
                   rcppsw::er::er_lvl::NOM);
  }
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
executable_task* partitionable_task::partition(void) {
  ER_NOM("Task '%s': partition_prob=%f, selection_method=%s", name().c_str(),
         m_partition_prob.last_result(), m_selection_method.c_str());
  /* We chose not to employ partitioning on the next task allocation */
  if (m_partition_prob.last_result() <= static_cast<double>(rand()) / RAND_MAX) {
    ER_NOM("Not employing partitioning");
    return static_cast<executable_task*>(m_partition1->parent());
  }
  executable_task* ret = nullptr;

  /* We have chosen to employ partitioning */
  if ("brutschy2014" == m_selection_method) {
    double prob_12 = m_selection_prob.calc(m_partition1->current_time_estimate(),
                                           m_partition2->current_time_estimate());
    double prob_21 = m_selection_prob.calc(m_partition2->current_time_estimate(),
                                           m_partition1->current_time_estimate());
    ER_NOM("subtask1->subtask2 prob=%f, subtask2->subtask1 prob=%f",
           prob_12, prob_21);
    /*
     * If we last executed subtask1, we calculate the probability of switching
     * to subtask2, based on time estimates.
     */
      if (m_last_partition == m_partition1) {
        if (prob_12 >= static_cast<double>(rand()) / RAND_MAX) {
          ret = m_partition2;
        }
        ret = m_partition1;
      }
      /*
       * If we last executed subtask2, we calculate the probability of switching
       * to subtask1, based on time estimates
       */
      else if (m_last_partition == m_partition2) {
        if (prob_21 >= static_cast<double>(rand()) / RAND_MAX) {
          ret = m_partition1;
        }
        ret = m_partition2;
      }
    }
  /* We either have not executed either subtask yet, or have just chosen random */
  /* pick one of the two subtasks randomly */
  if ("random" == m_selection_method || nullptr == m_last_partition) {
    if (rand() % 2) {
      ret = m_partition1;
    } else {
      ret = m_partition2;
    }
  }
  ER_NOM("Selected subtask '%s'", ret->name().c_str());
  return ret;
} /* partition() */

void partitionable_task::init_random(uint lb, uint ub) {
  executable_task::update_time_estimate(rand() % (ub - lb + 1) + lb);
  m_partition1->update_time_estimate(rand() % (ub - lb + 1) + lb);
  m_partition2->update_time_estimate(rand() % (ub - lb + 1) + lb);
} /* init_random() */

NS_END(task_allocation, rcppsw);
