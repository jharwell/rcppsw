/**
 * @file state_machine.cpp
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
#include "rcppsw/patterns/state_machine/state_machine.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace fsm = rcppsw::patterns::state_machine;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
fsm::simple_fsm::simple_fsm(uint8_t max_states, uint8_t initial_state) :
    MAX_STATES_(max_states),
    current_state_(initial_state),
    new_state_(false),
    event_generated_(false),
    event_data_(NULL),
    mutex_() {
  assert(MAX_STATES_ < EVENT_IGNORED);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void fsm::simple_fsm::external_event(uint8_t new_state,
                                    const event_data* data) {
  /* if we are supposed to ignore this event */
  if (new_state == EVENT_IGNORED) {
    if (data) {
      delete data;
    }
  }  else {
    mutex_.lock();
    /* generate the event and execute the state engine */
    internal_event(new_state, data);
    state_engine();
    mutex_.unlock();
  }
}

void fsm::simple_fsm::internal_event(uint8_t new_state,
                                    const event_data* data) {
  if (data == NULL)
    data = new event_data();

  event_data_ = data;
  event_generated_ = true;
  current_state_ = new_state;
}


void fsm::simple_fsm::state_engine(void) {
  const state_map_row* map = state_map();
  if (map != NULL) {
    state_engine(map);
  } else {
    const state_map_row_ex* map_ex = state_map_ex();
    if (map_ex != NULL) {
      state_engine(map_ex);
    }
    else {
      assert(0);
    }
  }
}

void fsm::simple_fsm::state_engine(const state_map_row* const map) {
  const event_data* data_tmp = NULL;

  /* While events are being generated keep executing states */
  while (event_generated_) {
    /* verity new state is valid */
    assert(new_state_ < MAX_STATES_);

    const state_base* state = map[new_state_].State;
    data_tmp = event_data_;
    event_data_ = NULL;
    event_generated_ = FALSE;

    /* ready to update to new state */
    current_state(new_state_);

    /* execute state action passing in event data */
    assert(state != NULL);
    state->invoke_state_action(this, data_tmp);

    if (data_tmp) {
      delete data_tmp;
      data_tmp = NULL;
    }
  } /* while() */
} /* state_engine() */

void fsm::simple_fsm::state_engine(const state_map_row_ex* const map_ex) {
  const event_data* data_tmp = NULL;

  /*
   * While events are being generated keep executing states.
   */
  while (event_generated_) {
    /* verify new state is valid */
    assert(new_state_ < MAX_STATES_);

    const state_base* state = map_ex[new_state_].state;
    const state_guard_base* guard = map_ex[new_state_].guard;
    const state_entry_base* entry = map_ex[new_state_].entry;
    const state_exit_base* exit = map_ex[current_state_].exit;

    data_tmp = event_data_;
    event_data_ = NULL;
    event_generated_ = FALSE;

    /* execute guard condition */
    bool guard_res = true;
    if (NULL != guard) {
      guard_res = guard->invoke_guard_condition(this, data_tmp);
    }

    if (guard_res == true) {
      /* transitioning to a new state? */
      if (new_state_ != current_state_) {
        /* execute state exit action before switching to new state */
        if (NULL != exit) {
          exit->invoke_exit_action(this);
        }

        /* execute state entry action on the new state */
        if (NULL != entry) {
          entry->invoke_entry_action(this, data_tmp);
        }

        /* Ensure exit/entry actions didn't call interval_event() by accident */
        assert(false == event_generated_);
      }

      /* Now we're ready to switch to the new state */
      current_state(new_state_);

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
