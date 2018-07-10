/**
 * @file bifurcating_tab.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_BIFURCATING_TAB_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_BIFURCATING_TAB_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/metrics/tasks/bifurcating_tab_metrics.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);
class polled_task;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class bifurcating_tab
 * @ingroup task_allocation
 *
 * @brief Represents Bifurcating Task Allocation Block (TAB) which consists of a root
 * task and two subtasks the root task decomposes into. The subtasks are atomic,
 * and cannot be decomposed further.
 */
class bifurcating_tab : public metrics::tasks::bifurcating_tab_metrics {
 public:
  bifurcating_tab(const polled_task* root,
                      const polled_task* child1,
                      const polled_task* child2);

  ~bifurcating_tab(void) override = default;

  bifurcating_tab& operator=(const bifurcating_tab& other) = delete;
  bifurcating_tab(const bifurcating_tab& other) = delete;

  void change_active_task(const polled_task* active_task);
  bool contains_task(const polled_task* active_task) const;
  bool task_is_root(const polled_task* task) const;
  bool task_is_child(const polled_task* task) const;

  /* bifurcating TAB metrics */
  bool subtask1_active(void) const override { return m_active_task == m_child1; }
  bool subtask2_active(void) const override { return m_active_task == m_child2; }
  bool root_active(void) const override { return m_active_task == m_root; }
  bool task_changed(void) const override { return m_active_task != m_last_task; }
  bool employed_partitioning(void) const override;

 private:
  // clang-format off
  const polled_task* m_last_task{nullptr};
  const polled_task* m_active_task{nullptr};
  const polled_task* const m_root;
  const polled_task* const m_child1;
  const polled_task* const m_child2;
  // clang-format on
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_BIFURCATING_TAB_HPP_ */
