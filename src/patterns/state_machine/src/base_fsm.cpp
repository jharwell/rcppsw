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

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace fsm = rcppsw::patterns::state_machine;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
fsm::base_fsm::base_fsm(uint8_t max_states, uint8_t initial_state) :
    mc_max_states(max_states),
    m_current_state(initial_state),
    m_new_state(false),
    m_event_generated(false),
    m_event_data(NULL),
    m_mutex() {
  assert(mc_max_states < EVENT_IGNORED);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void fsm::base_fsm::external_event(uint8_t new_state,
                                    const event_data* data) {
  /* if we are supposed to ignore this event */
  if (new_state == EVENT_IGNORED) {
    if (data) {
      delete data;
    }
  }  else {
    m_mutex.lock();
    /* generate the event and execute the state engine */
    internal_event(new_state, data);
    state_engine();
    m_mutex.unlock();
  }
}

void fsm::base_fsm::internal_event(uint8_t new_state,
                                    const event_data* data) {
  if (data == NULL)
    data = new event_data();

  m_event_data = data;
  m_event_generated = true;
  m_current_state = new_state;
}


void fsm::base_fsm::state_engine(void) {
  const state_map_row* map = state_map();
  if (map != NULL) {
    state_engine(map);
  } else {
    const state_map_ex_row* map_ex = state_map_ex();
    if (map_ex != NULL) {
      state_engine(map_ex);
    }
    else {
      assert(0);
    }
  }
}

void fsm::base_fsm::state_engine(const state_map_row* const map) {
  const event_data* data_tmp = NULL;

  /* While events are being generated keep executing states */
  while (m_event_generated) {
    /* verity new state is valid */
    assert(m_new_state < mc_max_states);

    const state_base* state = map[m_new_state].state;
    data_tmp = m_event_data;
    m_event_data = NULL;
    m_event_generated = FALSE;

    /* ready to update to new state */
    current_state(m_new_state);

    /* execute state action passing in event data */
    assert(state != NULL);
    state->invoke_state_action(this, data_tmp);

    if (data_tmp) {
      delete data_tmp;
      data_tmp = NULL;
    }
  } /* while() */
} /* state_engine() */

void fsm::base_fsm::state_engine(const state_map_ex_row* const map_ex) {
  const event_data* data_tmp = NULL;

  /*
   * While events are being generated keep executing states.
   */
  while (m_event_generated) {
    /* verify new state is valid */
    assert(m_new_state < mc_max_states);

    const state_base* state = map_ex[m_new_state].state;
    const state_guard_base* guard = map_ex[m_new_state].guard;
    const state_entry_base* entry = map_ex[m_new_state].entry;
    const state_exit_base* exit = map_ex[m_current_state].exit;

    data_tmp = m_event_data;
    m_event_data = NULL;
    m_event_generated = FALSE;

    /* execute guard condition */
    bool guard_res = true;
    if (NULL != guard) {
      guard_res = guard->invoke_guard_condition(this, data_tmp);
    }

    if (guard_res == true) {
      /* transitioning to a new state? */
      if (m_new_state != m_current_state) {
        /* execute state exit action before switching to new state */
        if (NULL != exit) {
          exit->invoke_exit_action(this);
        }

        /* execute state entry action on the new state */
        if (NULL != entry) {
          entry->invoke_entry_action(this, data_tmp);
        }

        /* Ensure exit/entry actions didn't call interval_event() by accident */
        assert(false == m_event_generated);
      }

      /* Now we're ready to switch to the new state */
      current_state(m_new_state);

      /* execute the state action passing in event data */
      assert(NULL != state);
      state->invoke_state_action(this, data_tmp);
    }

    if (data_tmp) {
      delete data_tmp;
      data_tmp = NULL;
    }
  } /* while(0) */
} /* state_engine() */
