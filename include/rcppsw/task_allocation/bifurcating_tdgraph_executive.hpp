/**
 * @file bifurcating_tdgraph_executive.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_BIFURCATING_TDGRAPH_EXECUTIVE_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_BIFURCATING_TDGRAPH_EXECUTIVE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/task_allocation/base_executive.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);
class bifurcating_tab;
class bifurcating_tdgraph;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class bifurcating_tdgraph_executive
 * @ingroup task_allocation
 *
 * @brief A task executive which tasks are run one step at a time and polled
 * until they are finished. Operates on \ref bifurcating_tdgraph.
 */
class bifurcating_tdgraph_executive : public base_executive {
 public:
  bifurcating_tdgraph_executive(std::shared_ptr<rcppsw::er::server>& server,
                                bifurcating_tdgraph* graph);

  void run(void) override;

  /**
   * @brief Get the TAB corresponding to the currently active task.
   */
  const bifurcating_tab* active_tab(void) const;

 private:
  polled_task* do_get_next_task(void) override;
  polled_task* next_task_from_partitionable(const polled_task* task);
  void handle_task_start(polled_task* new_task);
  void handle_task_abort(polled_task* task);
  void handle_task_finish(polled_task* task);
  void update_task_partition_prob(polled_task* task);
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_BIFURCATING_TDGRAPH_EXECUTIVE_HPP_ */
