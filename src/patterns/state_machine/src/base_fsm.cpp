/**
 * @file base_fsm.cpp
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
#include "rcppsw/patterns/state_machine/base_fsm.hpp"
#include "rcsw/common/fpc.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, state_machine);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
base_fsm::base_fsm(std::shared_ptr<common::er_server> server,
                   uint8_t max_states,
                   uint8_t initial_state) :
    er_client(server),
    mc_max_states(max_states),
    m_current_state(initial_state),
    m_next_state(0),
    m_initial_state(initial_state),
    m_event_generated(false),
    m_event_data(nullptr),
    m_mutex() {
  assert(mc_max_states < event::EVENT_IGNORED);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void base_fsm::reset(void) {
  m_mutex.lock();
  m_event_generated = false;
  m_current_state = m_initial_state;
  m_event_data.reset(nullptr);
  m_mutex.unlock();
} /* reset() */

void base_fsm::external_event(uint8_t new_state, const event *data) {
  ER_DIAG("Received external event: new_state=%d data=%p",
         new_state, data);

  ER_ASSERT(event::EVENT_FATAL != new_state,
            "The impossible event happened...");

  /* if we are supposed to ignore this event */
  if (new_state == event::EVENT_IGNORED) {
    if (data) {
      delete data;
    }
  } else {
    m_mutex.lock();
    /* generate the event and execute the state engine */
    internal_event(new_state, data);
    state_engine();
    m_mutex.unlock();
  }
}

void base_fsm::internal_event(uint8_t new_state, const event* data) {
  ER_DIAG("Generated internal event: new_state=%d data=%p",
         new_state, data);
  m_next_state = new_state;
  m_event_data.reset(data);
  m_event_generated = true;
}


void base_fsm::state_engine(void) {
  const state_map_row* map = state_map();
  const state_map_ex_row* map_ex = state_map_ex();

  ER_ASSERT(!(NULL == map && NULL == map_ex),
            "FATAL: Both state maps are NULL!");

  if (map != NULL) {
    return state_engine(map);
  } else {
    return state_engine(map_ex);
  }
} /* state_engine() */

void base_fsm::state_engine(const state_map_row* const map) {
  FPC_CHECK(FPC_VOID, NULL != map);

  /* While events are being generated keep executing states */
  while (m_event_generated) {
    /* verity new state is valid */
    ER_ASSERT(m_next_state < mc_max_states,
              "FATAL: new state is out of range");

    /* ready to update to new state */
    m_event_generated = false;
    update_state(m_next_state);
    state_engine_step(map);
  } /* while() */
} /* state_engine() */

void base_fsm::state_engine(const state_map_ex_row* const map_ex) {
  FPC_CHECK(FPC_VOID, NULL != map_ex);

  /*
   * While events are being generated keep executing states.
   */
  while (m_event_generated) {
    m_event_generated = false;
    /* verify new state is valid */
    ER_ASSERT(m_next_state < mc_max_states,
              "FATAL: new state is out of range");
    const state_guard* guard = map_ex[m_next_state].guard;
    const state_entry* entry = map_ex[m_next_state].entry;
    const state_exit* exit = map_ex[m_current_state].exit;

    /* execute guard condition */
    bool guard_res = true;
    if (NULL != guard) {
      ER_DIAG("Executing guard condition for state %d", m_current_state);
      guard_res = guard->invoke_guard_condition(this, m_event_data.get());
    }

    if (guard_res == false) {
      continue;
    }
    /* transitioning to a new state? */
    if (m_next_state != m_current_state) {
      /* execute state exit action before switching to new state */
      if (NULL != exit) {
        ER_DIAG("Executing exit action for state %d", m_current_state);
        exit->invoke_exit_action(this);
      }

      /* execute state entry action on the new state */
      if (NULL != entry) {
        ER_DIAG("Executing entry action for new state %d", m_next_state);
        entry->invoke_entry_action(this, m_event_data.get());
      }

      /* Ensure exit/entry actions didn't call interval_event() by accident */
      ER_ASSERT(false == m_event_generated,
                "FATAL: entry/exit actions called internal_event()!");
    }

    /* Now we're ready to switch to the new state */
    update_state(m_next_state);

    state_engine_step(map_ex);
  } /* while(0) */
} /* state_engine() */

void base_fsm::state_engine_step(const state_map_row* const map) {
  ER_ASSERT(NULL != map[m_next_state].state, "FATAL: null state?");
  ER_DIAG("Invoking state action: state%d, data=%p", m_current_state,
          m_event_data.get());
  map[m_next_state].state->invoke_state_action(this,
                                                      m_event_data.get());
} /* state_engine_step() */

void base_fsm::state_engine_step(const state_map_ex_row* const map_ex) {
  ER_ASSERT(NULL != map_ex[m_next_state].state, "FATAL: null state?");
  ER_DIAG("Invoking state action: state%d, data=%p", m_current_state,
          m_event_data.get());
  map_ex[m_next_state].state->invoke_state_action(this,
                                                      m_event_data.get());
} /* state_engine_step() */

NS_END(state_machine, patterns, rcppssw);
