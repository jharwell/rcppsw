/**
 * @file simple_fsm.hpp
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

#ifndef INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_SIMPLE_FSM_HPP_
#define INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_SIMPLE_FSM_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include <typeinfo>
#include <cstddef>
#include <mutex>
#include "rcppsw/common/common.hpp"
#include "rcppsw/patterns/state_machine/event.hpp"
#include "rcppsw/patterns/state_machine/state.hpp"
#include "rcppsw/patterns/state_machine/base_fsm.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, state_machine);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief simple_fsm implements a software-based state machine.
 */
class simple_fsm: public base_fsm {
 public:
  /**
   * @param max_states The maximum number of state machine states.
   * @param initial_state Initial state machine state.
   */
  simple_fsm(std::shared_ptr<common::er_server> server,
             uint8_t max_states,
             uint8_t initial_state = 0);

  virtual ~simple_fsm(void) {}

  virtual uint8_t current_state(void) const { return m_current_state; }
  virtual uint8_t max_states(void) const { return mc_max_states; }

 protected:
  virtual uint8_t next_state(void) const { return m_next_state; }
  virtual uint8_t initial_state(void) const { return m_initial_state; }
  virtual void next_state(uint8_t next_state) { m_next_state = next_state; }
  virtual void update_state(uint8_t new_state) { m_current_state = new_state; }

  virtual void state_engine_step(const state_map_row* const map);
  virtual void state_engine_step(const state_map_ex_row* const map_ex);

 private:
  const uint8_t     mc_max_states;      /// The maximum # of fsm states.
  uint8_t           m_current_state;    /// The current state machine state.
  uint8_t           m_next_state;        /// The next state to transition to.
  uint8_t           m_initial_state;
};

NS_END(state_machine, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_SIMPLE_FSM_HPP_ */
