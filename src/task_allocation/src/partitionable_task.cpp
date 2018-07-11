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
#include "rcppsw/task_allocation/partitionable_task_params.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
partitionable_task::partitionable_task(
    std::shared_ptr<er::server> server,
    const struct partitionable_task_params *c_params)
    : client(server),
      m_always_partition(c_params->partitioning.always_partition),
      m_never_partition(c_params->partitioning.never_partition),
      m_selection_prob(&c_params->subtask_selection),
      m_partition_prob(&c_params->partitioning) {
  if (ERROR == client::attmod("partitionable_task")) {
    client::insmod("partitionable_task", rcppsw::er::er_lvl::DIAG,
                   rcppsw::er::er_lvl::NOM);
  }
}

/*******************************************************************************
 * Allocation Metrics
 ******************************************************************************/
__rcsw_pure bool partitionable_task::employed_partitioning(void) const {
  return m_employed_partitioning;
} /* employed_partitioning() */

std::string partitionable_task::subtask_selection(void) const {
  return m_last_partition->name();
} /* subtask_selection() */

/*******************************************************************************
 * General Member Functions
 ******************************************************************************/
void partitionable_task::update_partition_prob(const time_estimate &task,
                                               const time_estimate &subtask1,
                                               const time_estimate &subtask2) {
  m_partition_prob.calc(task, subtask1, subtask2);
}

polled_task* partitionable_task::partition(const polled_task* const partition1,
                                           const polled_task* const partition2) {
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
  std::string name = dynamic_cast<executable_task *>(this)->name();

  ER_NOM("Task '%s': partition_method=%s partition_prob=%f", name.c_str(),
         m_partition_prob.method().c_str(), partition_prob);

  /* We chose not to employ partitioning on the next task allocation */
  if (partition_prob <= static_cast<double>(random()) / RAND_MAX) {
    ER_NOM("Not employing partitioning: Return task '%s'", name.c_str());
    m_employed_partitioning = false;
    auto ret = dynamic_cast<polled_task*>(this);
    ER_ASSERT(nullptr != ret, "FATAL: Partitionable task is not pollable")
    return ret;
  }
  m_employed_partitioning = true;
  const polled_task* ret = nullptr;

  /* We have chosen to employ partitioning */
  double prob_12, prob_21;
  if (subtask_selection_probability::kMethodHarwell2018 ==
      m_selection_prob.method()) {
    prob_12 = m_selection_prob.calc(&partition1->exec_estimate(),
                                    &partition2->exec_estimate());
    prob_21 = m_selection_prob.calc(&partition2->exec_estimate(),
                                    &partition1->exec_estimate());
  } else {
    prob_12 = m_selection_prob.calc(&partition1->interface_estimate(),
                                    &partition2->interface_estimate());
    prob_21 = m_selection_prob.calc(&partition2->interface_estimate(),
                                    &partition1->interface_estimate());
  }

  ER_NOM("Task '%s': selection_method=%s, last_partition=%s",
         name.c_str(),
         m_selection_prob.method().c_str(),
         (nullptr != m_last_partition)? m_last_partition->name().c_str(): "None");

  ER_NOM("%s exec_est=%f/int_est=%f, %s exec_est=%f/int_est=%f",
         partition1->name().c_str(),
         partition1->exec_estimate().last_result(),
         partition1->interface_estimate().last_result(),
         partition2->name().c_str(),
         partition2->exec_estimate().last_result(),
         partition2->interface_estimate().last_result());

  ER_NOM("%s -> %s prob=%f, %s -> %s prob=%f",
         partition1->name().c_str(),
         partition2->name().c_str(),
         prob_12,
         partition2->name().c_str(),
         partition1->name().c_str(),
         prob_21);

  if (subtask_selection_probability::kMethodHarwell2018 ==
          m_selection_prob.method() ||
      subtask_selection_probability::kMethodBrutschy2014 ==
          m_selection_prob.method()) {
    /*
     * If we last executed subtask1, we calculate the probability of switching
     * to subtask2, based on time estimates.
     */
    if (m_last_partition == partition1 || nullptr == m_last_partition) {
      if (prob_12 >= static_cast<double>(random()) / RAND_MAX) {
        ret = partition2;
      } else {
        ret = partition1;
      }
    }
    /*
     * If we last executed subtask2, we calculate the probability of switching
     * to subtask1, based on time estimates.
     */
    else if (m_last_partition == partition2) {
      if (prob_21 >= static_cast<double>(random()) / RAND_MAX) {
        ret = partition1;
      } else {
        ret = partition2;
      }
    }
  } else if (subtask_selection_probability::kMethodRandom ==
             m_selection_prob.method()) {
    if (prob_12 >= static_cast<double>(random()) / RAND_MAX) {
      ret = partition1;
    } else {
      ret = partition2;
    }
  }
  ER_ASSERT(nullptr != ret, "FATAL: no task selected?");
  ER_NOM("Selected subtask '%s'", ret->name().c_str());
  return const_cast<polled_task*>(ret);
} /* partition() */

NS_END(task_allocation, rcppsw);
