/**
 * \file bi_tab.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_TA_DS_BI_TAB_HPP_
#define INCLUDE_RCPPSW_TA_DS_BI_TAB_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <utility>

#include "rcppsw/er/client.hpp"
#include "rcppsw/metrics/tasks/bi_tab_metrics.hpp"
#include "rcppsw/ta/partition_probability.hpp"
#include "rcppsw/ta/subtask_sel_probability.hpp"
#include "rcppsw/ta/config/task_partition_config.hpp"
#include "rcppsw/math/rng.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta);
class polled_task;

namespace ds {
class bi_tdgraph;
} /* namespace ds */

NS_START(ds);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class bi_tab
 * \ingroup ta ds
 *
 * \brief Represents Bi Task Allocation Block (TAB) which consists of a root
 * task and two subtasks the root task decomposes into. The subtasks may or may
 * not be capable of being further decomposed, and therefore the roots of
 * additional TABs.
 */
class bi_tab final : public metrics::tasks::bi_tab_metrics,
                     public er::client<bi_tab> {
 public:
  static constexpr char kPartitionSrcExec[] = "exec";
  static constexpr char kPartitionSrcInterface[] = "interface";
  static constexpr char kSubtaskSelSrcExec[] = "exec";
  static constexpr char kSubtaskSelSrcInterface[] = "interface";

  struct elements {
    const bi_tdgraph* graph;
    polled_task* root;
    polled_task* child1;
    polled_task* child2;
  };
  bi_tab(const struct elements* elts,
         const config::task_partition_config* partitioning,
         const config::src_sigmoid_sel_config* subtask_sel);

  ~bi_tab(void) override = default;

  /* Necessary for use in boost::variant */
  bi_tab(const bi_tab& other) = default;
  bi_tab& operator=(const bi_tab& other) = delete;


  /* bi TAB metrics */
  bool subtask1_active(void) const override {
    return m_active_task == m_child1;
  }
  bool subtask2_active(void) const override {
    return m_active_task == m_child2;
  }
  bool employed_partitioning(void) const override {
    return m_employed_partitioning;
  }
  bool root_active(void) const override { return m_active_task == m_root; }

  /**
   * \brief Update the partition probability based after a task has been
   * finished or aborted. Happens as part of \ref task_abort_update() and \ref
   * task_finish_update(), so should never need to be called directly, except in
   * corner cases during initialization.
   */
  void partition_prob_update(math::rng* rng);

  /**
   * \brief Performs the next task allocation.
   *
   * 1. Determines if partitioning should be employed at the root of TAB. If
   *    not, the active task is set to the root of the TAB and returned.
   * 2. If partitioning is employed, one of the two subtasks in the TAB is
   *    selected, the active task is updated accordingly, and the selected
   *    subtask is returned.
   *
   * \param rng The RNG to use during task allocation
   */
  polled_task* task_allocate(math::rng* rng);

  /**
   * \brief Return the activity task in the TAB (that is, the task that is
   * currently being executed). If the active task in the executive is not in
   * this TAB, then nullptr is returned.
   */

  const polled_task* active_task(void) const { return m_active_task; }

  /**
   * \brief Updates the TAB after task abort.
   *
   * The active task is set to NULL, and the last task and last subtask fields
   * are updated as applicable. Partitioning probability for the TAB is updated
   * as well.
   *
   * \param aborted The task that was just aborted (which MUST be contained in
   *                the current TAB, or an assertion will be triggered).
   * \param rng The RNG to use during updating, per configuration.
   */
  void task_abort_update(polled_task* aborted, math::rng* rng);

  /**
   * \brief Updates the TAB after task finsh.
   *
   * The active task is set to NULL, and the last task and last subtask fields
   * are updated as applicable. Partitioning probability for the TAB is updated
   * as well.
   *
   * \param finished The task that was just finished (which MUST be contained in
   *                 the current TAB, or an assertion will be triggered).
   * \param rng The RNG to use during updating, per configuration.
   */

  void task_finish_update(polled_task* finished, math::rng* rng);

  /**
   * \brief Returns \c TRUE iff the argument is one of the 3 tasks in the TAB.
   *
   * \param task The task to check.
   */
  bool contains_task(const polled_task* task) const RCSW_PURE;

  /**
   * \brief Returns \c TRUE iff the argument is the root task in the TAB.
   *
   * \param task The task to check.
   */
  bool task_is_root(const polled_task* task) const RCSW_PURE;

  /**
   * \brief Returns \c TRUE iff the argument is one of the child tasks in the
   * TAB.
   *
   * \param task The task to check.
   */
  bool task_is_child(const polled_task* task) const RCSW_PURE;

  /**
   * \brief Return the TAB root (always a partitionable task), also known as
   * task0 within the TAB.
   */
  const polled_task* root(void) const { return m_root; }

  /**
   * \brief Return the left child of the root (we use a left-to-right numbering
   * scheme).
   */
  const polled_task* child1(void) const { return m_child1; }

  /**
   * \brief Return the right child of the root (we use a left-to-right numbering
   * scheme).
   */
  const polled_task* child2(void) const { return m_child2; }

  /**
   * \brief Return the most recently executed task; updated on task abort or
   * finish in \ref task_abort_update() and \ref task_finish_update
   * respectively.
   */
  const polled_task* last_task(void) const { return m_last_task; }

  /**
   * \brief Return the most recently executed subtask task1 or task2; updated on
   * task abort or finish in \ref task_abort_update() and \ref
   * task_finish_update respectively.
   */
  void last_subtask(const polled_task* t) { m_last_subtask = t; }

  /**
   * \brief As a result of the most recent allocation, did our active task
   * change?
   */
  bool task_changed(void) const override {
    return m_active_task != m_last_task;
  }

  /**
   * \brief As a result of the most recent allocation, did the depth of our task
   * within the TAB change? i.e. it was the root before and now it is one of the
   * subtasks or vice versa.
   */
  bool task_depth_changed(void) const override;

  /**
   * \brief Return the current value of the partition probability within the
   * TAB. Does not recompute.
   */
  double partition_prob(void) const override { return m_partition_prob.v(); }

  /**
   * \brief Return the current value of the subtask selection probability within
   * the TAB. Does not recompute.
   */
  double subtask_selection_prob(void) const override { return m_sel_prob.v(); }

 private:
  polled_task* subtask_allocate(math::rng* rng);
  std::pair<double, double> subtask_sw_calc(math::rng* rng);

  /* clang-format off */
  const bool              mc_always_partition;
  const bool              mc_never_partition;
  const std::string       mc_partition_input;
  const std::string       mc_subtask_sel_input;
  const bi_tdgraph*       mc_graph;

  polled_task* const         m_root;
  polled_task* const         m_child1;
  polled_task* const         m_child2;
  bool                       m_employed_partitioning{false};
  const polled_task*         m_last_task{nullptr};
  const polled_task*         m_last_subtask{nullptr};
  const polled_task*         m_active_task{nullptr};

  subtask_sel_probability    m_sel_prob;
  partition_probability      m_partition_prob;
  /* clang-format on */
};

NS_END(ds, ta, rcppsw);

#endif /* INCLUDE_RCPPSW_TA_DS_BI_TAB_HPP_ */
