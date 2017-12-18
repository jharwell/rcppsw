/**
 * @file polled_simple_fsm.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_POLLED_SIMPLE_FSM_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_POLLED_SIMPLE_FSM_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "rcppsw/patterns/state_machine/simple_fsm.hpp"
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
class polled_simple_fsm : public taskable,
                          public patterns::state_machine::simple_fsm {
 public:
  polled_simple_fsm(const std::shared_ptr<er::server>& server,
                    uint8_t max_states)
      : taskable(), patterns::state_machine::simple_fsm(server, max_states) {}
  virtual ~polled_simple_fsm(void) {}

  void task_reset(void) override { init(); }
  void task_execute(void) override {
    generated_event(true);
    state_engine();
  }
};

NS_END(rcppsw, task_allocation);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_POLLED_SIMPLE_FSM_HPP_ */
