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
#include "rcppsw/task_allocation/polled_task.hpp"
#include "rcppsw/task_allocation/partitioning_params.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
partitionable_task::partitionable_task(
    const struct partitioning_params* partitioning,
    const struct sigmoid_selection_params* subtask_sel)
    : ER_CLIENT_INIT("rcppsw.ta.partitionable_task"),
      m_always_partition(partitioning->always_partition),
      m_never_partition(partitioning->never_partition),
      m_selection_prob(subtask_sel),
      m_partition_prob(&partitioning->sigmoid) {}

/*******************************************************************************
 * Allocation Metrics
 ******************************************************************************/
__rcsw_pure bool partitionable_task::employed_partitioning(void) const {
  return m_employed_partitioning;
} /* employed_partitioning() */

/*******************************************************************************
 * General Member Functions
 ******************************************************************************/
void partitionable_task::update_partition_prob(const time_estimate &task,
                                               const time_estimate &subtask1,
                                               const time_estimate &subtask2) {
  m_partition_prob.calc(task, subtask1, subtask2);
}

polled_task *
partitionable_task::task_allocate(const polled_task *const subtask1,
                                  const polled_task *const subtask2) {
  ER_ASSERT(!(m_always_partition && m_never_partition),
            "Cannot ALWAYS and NEVER partition");

  double partition_prob;
  std::string name = dynamic_cast<executable_task *>(this)->name();

  if (m_always_partition) {
    partition_prob = 1;
  } else if (m_never_partition) {
    partition_prob = 0;
  } else {
    partition_prob = m_partition_prob.last_result();
    ER_INFO("Task '%s': partition_method=%s partition_prob=%f", name.c_str(),
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
  /* We have chosen to employ partitioning */
  m_employed_partitioning = true;
  ER_INFO("Employing partitioning at task '%s': selection_method=%s, last_partition=%s", name.c_str(),
          m_selection_prob.method().c_str(),
          (nullptr != m_last_partition) ? m_last_partition->name().c_str()
          : "None");

  return subtask_allocate(subtask1, subtask2);
} /* task_allocate() */

polled_task* partitionable_task::subtask_allocate(
    const polled_task *const subtask1,
    const polled_task *const subtask2) {
  double prob_12, prob_21;
  if (subtask_selection_probability::kMethodHarwell2018 ==
      m_selection_prob.method()) {
    prob_12 = m_selection_prob(&subtask1->task_exec_estimate(),
                               &subtask2->task_exec_estimate());
    prob_21 = m_selection_prob(&subtask2->task_exec_estimate(),
                               &subtask1->task_exec_estimate());
  } else {
    prob_12 = m_selection_prob(&subtask1->task_interface_estimate(),
                               &subtask2->task_interface_estimate());
    prob_21 = m_selection_prob(&subtask2->task_interface_estimate(),
                               &subtask1->task_interface_estimate());
  }

  ER_INFO("%s exec_est=%f/int_est=%f, %s exec_est=%f/int_est=%f",
          subtask1->name().c_str(),
          subtask1->task_exec_estimate().last_result(),
          subtask1->task_interface_estimate().last_result(),
          subtask2->name().c_str(),
          subtask2->task_exec_estimate().last_result(),
          subtask2->task_interface_estimate().last_result());

  ER_INFO("%s -> %s prob=%f, %s -> %s prob=%f", subtask1->name().c_str(),
          subtask2->name().c_str(), prob_12, subtask2->name().c_str(),
          subtask1->name().c_str(), prob_21);

  const polled_task *ret = nullptr;
  if (subtask_selection_probability::kMethodHarwell2018 ==
          m_selection_prob.method() ||
      subtask_selection_probability::kMethodBrutschy2014 ==
          m_selection_prob.method()) {
    /*
     * If we last executed subtask1, we calculate the probability of switching
     * to subtask2, based on time estimates.
     */
    if (m_last_partition == subtask1 || nullptr == m_last_partition) {
      if (prob_12 >= static_cast<double>(std::rand()) / RAND_MAX) {
        ret = subtask2;
      } else {
        ret = subtask1;
      }
    }
    /*
     * If we last executed subtask2, we calculate the probability of switching
     * to subtask1, based on time estimates.
     */
    else if (m_last_partition == subtask2) {
      if (prob_21 >= static_cast<double>(std::rand()) / RAND_MAX) {
        ret = subtask1;
      } else {
        ret = subtask2;
      }
    }
  } else if (subtask_selection_probability::kMethodRandom ==
             m_selection_prob.method()) {
    if (prob_12 >= static_cast<double>(std::rand()) / RAND_MAX) {
      ret = subtask1;
    } else {
      ret = subtask2;
    }
  }
  ER_ASSERT(nullptr != ret, "No subtask selected?");
  ER_INFO("Selected subtask '%s'", ret->name().c_str());
  return const_cast<polled_task *>(ret);
} /* subtask_allocate() */

NS_END(task_allocation, rcppsw);
