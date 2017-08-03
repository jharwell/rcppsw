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
 *
 */
template <class C>
class hfsm: public base_fsm {
 public:
  /**
   * @param max_states The maximum number of state machine states.
   * @param initial_state Initial state machine state.
   */
  hfsm(std::shared_ptr<common::er_server> server) : base_fsm(server) {}

  virtual ~hfsm() {}

 protected:
  virtual void state_engine_step(__unused const state_map_row* const map) {
    ER_ASSERT(0, "FATAL: unhandled signal from call chain");
  } /* state_engine_step() */

  virtual void state_engine_step(__unused const state_map_ex_row* const map_ex) {
    ER_ASSERT(0, "FATAL: unhandled signal from call chain");
  } /* state_engine_step() */

 private:
  hfsm(const hfsm& fsm) = delete;
  hfsm& operator=(const hfsm& fsm) = delete;
};

NS_END(state_machine, patterns, rcppsw);
#endif /* INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_HFSM_HPP_ */
