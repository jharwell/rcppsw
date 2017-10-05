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
         event_data_get());
  const hfsm_state* state = static_cast<const hfsm_state*>(row->state());
  int rval = event_signal::UNHANDLED;
  while (rval != event_signal::HANDLED) {
    rval = state->invoke_state_action(this, event_data_get());
    if (event_signal::HANDLED == rval) {
      break;
    }
    state = state->parent();
    const_cast<event_data*>(event_data_get())->type(event_type::CHILD);
  } /* while() */
} /* state_engine_step() */

void hfsm::state_engine_step(const state_map_ex_row* const row_ex) {
  ER_ASSERT(nullptr != row_ex->state(), "FATAL: null state?");
  ER_VER("Invoking state action: state%d, data=%p", current_state(),
         event_data_get());
  const hfsm_state* state = static_cast<const hfsm_state*>(row_ex->state());
  int rval = event_signal::UNHANDLED;
  while (rval != event_signal::HANDLED) {
    rval = state->invoke_state_action(this, event_data_get());
    if (event_signal::HANDLED == rval) {
      break;
    }
    state = state->parent();
    const_cast<event_data*>(event_data_get())->type(event_type::CHILD);
  } /* while() */
} /* state_engine_step() */

void hfsm::inject_event(int signal, int type) {
  external_event(current_state(),
                 rcppsw::make_unique<const event_data>(signal, type));
} /* inject event */

void hfsm::change_parent(uint state,
                   rcppsw::patterns::state_machine::state* new_parent) {
  hfsm_state_map_row* map = const_cast<hfsm_state_map_row*>(
      static_cast<const hfsm_state_map_row*>(state_map(state)));
  hfsm_state_map_ex_row* map_ex = const_cast<hfsm_state_map_ex_row*>(
      static_cast<const hfsm_state_map_ex_row*>(state_map_ex(state)));

  ER_ASSERT(!(nullptr == map && nullptr == map_ex),
            "FATAL: Both state maps are NULL!");

  if (map != nullptr) {
    map->parent(new_parent);
  }
  map_ex->parent(new_parent);
} /* change_state() */

NS_END(state_machine, patterns, rcppsw);
