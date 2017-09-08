/**
 * @file hfsm.cpp
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/patterns/state_machine/hfsm.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, state_machine);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void hfsm::state_engine_step(const state_map_row* const row) {
  ER_ASSERT(nullptr != row->state(), "FATAL: null state?");
  ER_VER("Invoking state action: state%d, data=%p", current_state(),
         get_event_data());
  const hfsm_state* state = static_cast<const hfsm_state*>(row->state());
  while (event_signal::HANDLED !=
         state->invoke_state_action(this, get_event_data())) {
    state = state->parent();
  } /* while() */
} /* state_engine_step() */

void hfsm::state_engine_step(const state_map_ex_row* const row_ex) {
  ER_ASSERT(nullptr != row_ex->state(), "FATAL: null state?");
  ER_VER("Invoking state action: state%d, data=%p", current_state(),
         get_event_data());
  const hfsm_state* state = static_cast<const hfsm_state*>(row_ex->state());
  while (event_signal::HANDLED !=
         state->invoke_state_action(this, get_event_data())) {
    state = state->parent();
  } /* while() */
} /* state_engine_step() */

NS_END(state_machine, patterns, rcppsw);
