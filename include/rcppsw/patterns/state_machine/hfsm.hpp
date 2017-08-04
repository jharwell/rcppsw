/**
 * @file hfsm.hpp
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

#ifndef INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_HFSM_HPP_
#define INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_HFSM_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include <typeinfo>
#include <cstddef>
#include <mutex>
#include "rcppsw/patterns/state_machine/hfsm_state.hpp"
#include "rcppsw/patterns/state_machine/base_fsm.hpp"

/*******************************************************************************
 * State Macros
 ******************************************************************************/
#define HFSM_STATE_DECLARE(fsm, parent_fsm, parent_handler, state_name, event) \
  void ST_##state_name(__unused const event*);                          \
  rcppsw::patterns::state_machine::hfsm_state_action<fsm,                                           \
                                                     parent_fsm,        \
                                                     event,             \
                                                     &parent_fsm::ST_##parent_handler, \
                                                     &fsm::ST_##state_name> state_name;

#define HFSM_STATE_DEFINE(fsm, state_name, event) FSM_STATE_DEFINE(fsm, state_name, event)
#define HFSM_STATE_MAP_ENTRY(state_name) FSM_STATE_MAP_ENTRY(state_name)
#define HFSM_STATE_MAP_ENTRY_EX(state_name, parent_state) FSM_STATE_MAP_ENTRY_EX(state_name, parent_state)
#define HFSM_STATE_MAP_ENTRY_EX_ALL(state_name, parent_state) FSM_STATE_MAP_ENTRY_EX_ALL(state_name, parent_state)


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, state_machine);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief hfsm implements a software-based state machine.
 */
class hfsm: public base_fsm {
 public:
  /**
   * @param max_states The maximum number of state machine states.
   * @param initial_state Initial state machine state.
   */
  explicit hfsm(std::shared_ptr<common::er_server> server) : base_fsm(server) {}

  virtual ~hfsm() {}

  int ST_base_state(__unused const event* e) { return event::EVENT_HANDLED; }

 private:
  hfsm(const hfsm& fsm) = delete;
  hfsm& operator=(const hfsm& fsm) = delete;
};

NS_END(state_machine, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_HFSM_HPP_ */
