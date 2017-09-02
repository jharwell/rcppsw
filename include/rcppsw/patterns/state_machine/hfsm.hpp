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

  /**
   * @brief The topmost state in the hierarchy, of which all states are
   * children. If an event gets all the way up to here, that's bad, because it
   * should have been handled at a lower layer.
   *
   * @return Does not return.
   */
  int ST_top_state(__unused const event_data* e) { assert(0); }
  virtual void init(void) {
    assert(initial_state() < event_signal::IGNORED);
    base_fsm::init();
  }

 private:
  hfsm(const hfsm& fsm) = delete;
  hfsm& operator=(const hfsm& fsm) = delete;
};

NS_END(state_machine, patterns, rcppsw);

/*******************************************************************************
 * State Macros
 ******************************************************************************/
#define HFSM_STATE_DECLARE(FSM, parent_fsm, \
                           parent_state, parent_state_data, \
                           state_name, state_data)                      \
  int ST_##state_name(__unused const state_data*);                      \
  rcppsw::patterns::state_machine::hfsm_state_action<FSM,               \
                                                     parent_fsm,        \
                                                     parent_state_data, \
                                                     state_data, \
                                                     &parent_fsm::ST_##parent_state, \
                                                     &FSM::ST_##state_name> state_name;

#define HFSM_STATE_DEFINE(FSM, state_name, event) FSM_STATE_DEFINE(FSM, state_name, event)
#define HFSM_GUARD_DECLARE(FSM, guardName, event_data) FSM_GUARD_DECLARE(FSM, guardName, event_data)
#define HFSM_GUARD_DEFINE(FSM, guardName, event_data) FSM_GUARD_DEFINE(FSM, guardName, event_data)
#define HFSM_ENTRY_DECLARE(FSM, entryName, event_data) FSM_ENTRY_DECLARE(FSM, entryName, event_data)
#define HFSM_ENTRY_DEFINE(FSM, entryName, event_data)  FSM_ENTRY_DEFINE(FSM, entryName, event_data)
#define HFSM_EXIT_DECLARE(FSM, exitName) FSM_EXIT_DECLARE(FSM, exitName)
#define HFSM_EXIT_DEFINE(FSM, exitName) FSM_EXIT_DEFINE(FSM, exitName)

/*******************************************************************************
 * State Map Macros
 ******************************************************************************/
#define HFSM_DEFINE_STATE_MAP_ACCESSOR(type) FSM_DEFINE_STATE_MAP_ACCESSOR(type)
#define HFSM_DEFINE_STATE_MAP(type, name) FSM_DEFINE_STATE_MAP(type, name)
#define HFSM_STATE_MAP_ENTRY(state_name) FSM_STATE_MAP_ENTRY(state_name)
#define HFSM_STATE_MAP_ENTRY_EX(state_name) FSM_STATE_MAP_ENTRY_EX(state_name)
#define HFSM_STATE_MAP_ENTRY_EX_ALL(state_name, guard_name, entry_name, exit_name) \
  {state_name, guard_name, entry_name, exit_name}
#define HFSM_VERIFY_STATE_MAP(type, name) FSM_VERIFY_STATE_MAP(type, name)

/*******************************************************************************
 * Transition Map Macros
 ******************************************************************************/
#define HFSM_DEFINE_TRANSITION_MAP(name) FSM_DEFINE_TRANSITION_MAP(name)
#define HFSM_TRANSITION_MAP_ENTRY(entry) FSM_TRANSITION_MAP_ENTRY(entry)
#define HFSM_VERIFY_TRANSITION_MAP(name) FSM_VERIFY_TRANSITION_MAP(name)

#endif /* INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_HFSM_HPP_ */
