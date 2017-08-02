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
#include <assert.h>
#include "rcppsw/patterns/state_machine/hfsm.hpp"
#include "rcppsw/patterns/state_machine/hfsm_state.hpp"
#include "rcsw/common/fpc.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, state_machine);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void hfsm::state_engine_step(const state_map_row* const map) {
  ER_ASSERT(NULL != map[next_state()].state, "FATAL: null state?");
  ER_DIAG("Invoking state action: state%d, data=%p", current_state(),
          event_data().get());
  int rval = map[next_state()].state->invoke_state_action(this,
                                               event_data().get());
  if (event::EVENT_HANDLED != rval) {
    map[next_state()].parent_state->invoke_state_action(this,
                                                 event_data().get());
  }
} /* state_engine_step() */

void hfsm::state_engine_step(const state_map_ex_row* const map_ex) {
  ER_ASSERT(NULL != map_ex[next_state()].state, "FATAL: null state?");
  ER_DIAG("Invoking state action: state%d, data=%p", current_state(),
          event_data().get());
  int rval = map_ex[next_state()].state->invoke_state_action(this,
                                                  event_data().get());
  if (event::EVENT_HANDLED != rval) {
    map_ex[next_state()].parent_state->invoke_state_action(this,
                                                        event_data().get());
  }
} /* state_engine_step() */

NS_END(state_machine, patterns, rcppssw);
