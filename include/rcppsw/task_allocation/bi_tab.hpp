/**
 * @file bi_tab.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_BI_TAB_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_BI_TAB_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <utility>

#include "rcppsw/metrics/tasks/bi_tab_metrics.hpp"
#include "rcppsw/er/client.hpp"
#include "rcppsw/task_allocation/partition_probability.hpp"
#include "rcppsw/task_allocation/subtask_sel_probability.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, task_allocation);
class polled_task;
class bi_tdgraph;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class bi_tab
 * @ingroup task_allocation
 *
 * @brief Represents Bi Task Allocation Block (TAB) which consists of a
 * root task and two subtasks the root task decomposes into. The subtasks are
 * may or may not be capable of being further decomposed, and therefore the
 * roots of additional TABs.
 */
class bi_tab : public metrics::tasks::bi_tab_metrics,
               public er::client<bi_tab> {
 public:
  static constexpr char kPartitionSrcExec[] = "exec";
  static constexpr char kPartitionSrcInterface[] = "interface";
  static constexpr char kSubtaskSelSrcExec[] = "exec";
  static constexpr char kSubtaskSelSrcInterface[] = "interface";

  bi_tab(const bi_tdgraph* const graph,
         polled_task* root,
         const polled_task* child1,
         const polled_task* child2,
         const struct task_partition_params* partitioning,
         const struct src_sigmoid_sel_params* subtask_sel);

  ~bi_tab(void) override = default;

  bi_tab& operator=(const bi_tab& other) = delete;
  bi_tab(const bi_tab& other) = default;

  void partition_prob_update(void);

  /**
   * @brief Performs the next task allocation:
   *
   * 1. Determines if partitioning should be employed at the root of TAB. If
   *    not, the active task is set to the root of the TAB and returned.
   * 2. If partitioning is employed, one of the two subtasks in the TAB is
   *    selected, the active task is updated accordingly, and the selected
   *    subtask is returned.
   */
  polled_task * task_allocate(void);

  const polled_task* active_task(void) const { return m_active_task; }

  /**
   * @brief Updates the TAB after task abort.
   *
   * The active task is set to NULL, and the last task and last subtask fields
   * are updated as applicable. Partitioning probability for the TAB is updated
   * as well.
   *
   * @param aborted The task that was just aborted (which MUST be contained in
   *                the current TAB, or an assertion will be triggered.)
   */
  void task_abort_update(polled_task* aborted);

  /**
   * @brief Updates the TAB after task finsh.
   *
   * The active task is set to NULL, and the last task and last subtask fields
   * are updated as applicable. Partitioning probability for the TAB is updated
   * as well.
   *
   * @param finished The task that was just finished (which MUST be contained in
   *                 the current TAB, or an assertion will be triggered.)
   */

  void task_finish_update(polled_task* finished);

  /**
   * @brief Returns \c TRUE iff the argument is one of the 3 tasks in the TAB.
   */
  bool contains_task(const polled_task* task) const;

  /**
   * @brief Returns \c TRUE iff the argument is the root task in the TAB.
   */
  bool task_is_root(const polled_task* task) const;

  /**
   * @brief Returns \c TRUE iff the argument is one of the child tasks in the
   * TAB.
   */
  bool task_is_child(const polled_task* task) const;

  const polled_task* root(void) const { return m_root; }
  polled_task* root(void) { return m_root; }
  const polled_task* child1(void) const { return m_child1; }
  const polled_task* child2(void) const { return m_child2; }
  const polled_task* last_task(void) const { return m_last_task; }
  void last_task(polled_task* const last_task) { m_last_task = last_task; }

  void last_subtask(const polled_task* t) { m_last_subtask = t; }

  /* bi TAB metrics */
  bool subtask1_active(void) const override { return m_active_task == m_child1; }
  bool subtask2_active(void) const override { return m_active_task == m_child2; }
  bool root_active(void) const override { return m_active_task == m_root; }
  bool employed_partitioning(void) const override {
    return m_employed_partitioning;
  }
  bool task_changed(void) const override { return m_active_task != m_last_task; }
  bool task_depth_changed(void) const override;
  double partition_prob(void) const override {
    return m_partition_prob.last_result();
  }
  double subtask_selection_prob(void) const override {
    return m_sel_prob.last_result();
  }

 private:
  polled_task* subtask_allocate(void);
  std::pair<double, double> subtask_sw_calc(void);

  /* clang-format off */
  const bool                mc_always_partition;
  const bool                mc_never_partition;
  const std::string         mc_partition_input;
  const std::string         mc_subtask_sel_input;
  const bi_tdgraph* const   mc_graph;

  bool                      m_employed_partitioning{false};
  const polled_task*        m_last_task{nullptr};
  const polled_task*        m_last_subtask{nullptr};
  const polled_task*        m_active_task{nullptr};

  polled_task* const        m_root;
  const polled_task* const  m_child1;
  const polled_task* const  m_child2;
  subtask_sel_probability   m_sel_prob;
  partition_probability     m_partition_prob;
  /* clang-format on */
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_BI_TAB_HPP_ */
