/**
 * @file simple_fsm.cpp
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
#include "rcppsw/patterns/state_machine/simple_fsm.hpp"
#include "rcsw/common/fpc.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, state_machine);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
simple_fsm::simple_fsm(std::shared_ptr<common::er_server> server,
                   uint8_t max_states,
                   uint8_t initial_state) :
    base_fsm(server),
    mc_max_states(max_states),
    m_current_state(initial_state),
    m_next_state(0),
    m_initial_state(0) {
  assert(mc_max_states < event::EVENT_IGNORED);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void simple_fsm::state_engine_step(const state_map_row* const map) {
  ER_ASSERT(NULL != map[m_next_state].state, "FATAL: null state?");
  ER_DIAG("Invoking state action: state%d, data=%p", m_current_state,
          event_data());
  map[m_next_state].state->invoke_state_action(this,
                                               event_data());
} /* state_engine_step() */

void simple_fsm::state_engine_step(const state_map_ex_row* const map_ex) {
  ER_ASSERT(NULL != map_ex[m_next_state].state, "FATAL: null state?");
  ER_DIAG("Invoking state action: state%d, data=%p", m_current_state,
          event_data());
  map_ex[m_next_state].state->invoke_state_action(this,
                                                      event_data());
} /* state_engine_step() */

NS_END(state_machine, patterns, rcppssw);
