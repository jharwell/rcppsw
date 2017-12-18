/**
 * @file polled_hfsm.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_POLLED_HFSM_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_POLLED_HFSM_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "rcppsw/patterns/state_machine/hfsm.hpp"
#include "rcppsw/task_allocation/taskable.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief An FSM that can be part of a \ref task_sequence of \ref polled_task
 * instances.
 *
 * These FSMs are attached to \ref atomic_polled_task instances as their method
 * of execution.
 */
class polled_hfsm : public taskable, public patterns::state_machine::hfsm {
 public:
  explicit polled_hfsm(const std::shared_ptr<common::er_server>& server,
                       uint8_t max_states,
                       uint8_t initial_state = 0)
      : taskable(), hfsm(server, max_states, initial_state) {}
  virtual ~polled_hfsm(void) {}

  void task_reset(void) override { init(); }
};

NS_END(rcppsw, task_allocation);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_POLLED_HFSM_HPP_ */
