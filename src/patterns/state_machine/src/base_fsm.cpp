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
#include "rcppsw/patterns/state_machine/base_fsm.hpp"
#include <cassert>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, state_machine);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
base_fsm::base_fsm(const std::shared_ptr<er::server>& server,
                   uint8_t max_states,
                   uint8_t initial_state)
    : er::client(server),
      mc_max_states(max_states),
      m_current_state(initial_state),
      m_next_state(0),
      m_initial_state(initial_state),
      m_previous_state(0),
      m_last_state(0),
      m_event_generated(false),
      m_event_data(nullptr),
      m_mutex() {
  ER_ASSERT(mc_max_states < event_signal::IGNORED, "FATAL: Too many states");
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void base_fsm::init(void) {
  m_mutex.lock();
  m_event_generated = false;

  update_state(initial_state());
  next_state(initial_state());
  m_event_data.reset(nullptr);
  m_mutex.unlock();
} /* init() */

void base_fsm::external_event(uint8_t new_state,
                              std::unique_ptr<const event_data> data) {
  ER_VER("Received external event: new_state=%d data=%p",
         new_state,
         reinterpret_cast<const void*>(data.get()));

  ER_ASSERT(event_signal::FATAL != new_state,
            "The impossible event happened...");

  /* if we are not supposed to ignore this event */
  if (new_state != event_signal::IGNORED) {
    m_mutex.lock();
    /*
     * Generate the event and execute the state engine. If data was passed in,
     * pass that along to the handler function.
     */
    m_event_data = std::move(data);
    internal_event(new_state, std::move(m_event_data));
    state_engine();
    m_event_data.reset(nullptr);
    m_mutex.unlock();
  }
}

void base_fsm::internal_event(uint8_t new_state,
                              std::unique_ptr<const event_data> data) {
  ER_VER("Generated internal event: current_state=%d new_state=%d data=%p",
         current_state(),
         new_state,
         reinterpret_cast<const void*>(data.get()));
  next_state(new_state);
  m_event_generated = true;
  if (m_event_data != data) {
    m_event_data = std::move(data);
  }
}

void base_fsm::state_engine(void) {
  const state_map_row* map = state_map(0);
  const state_map_ex_row* map_ex = state_map_ex(0);

  ER_ASSERT(!(nullptr == map && nullptr == map_ex),
            "FATAL: Both state maps are NULL!");

  if (map != nullptr) {
    state_engine_map();
  }
  state_engine_map_ex();
} /* state_engine() */

void base_fsm::state_engine_map(void) {
  /* While events are being generated keep executing states */
  while (m_event_generated) {
    /* verity new state is valid */
    ER_ASSERT(next_state() < max_states(), "FATAL: new state is out of range");

    /* ready to update to new state */
    m_event_generated = false;
    update_state(next_state());
    const state_map_row* row = state_map(current_state());
    state_engine_step(row);
  } /* while() */
} /* state_engine_map() */

void base_fsm::state_engine_map_ex(void) {
  /*
   * While events are being generated keep executing states.
   */
  while (m_event_generated) {
    m_event_generated = false;
    /* verify new state is valid */
    ER_ASSERT(next_state() < max_states(), "FATAL: new state is out of range");
    const state_guard* guard = state_map_ex(next_state())->guard();
    const state_entry* entry = state_map_ex(next_state())->entry();
    const state_exit* exit = state_map_ex(current_state())->exit();

    /* execute guard condition */
    bool guard_res = true;
    if (nullptr != guard) {
      ER_VER("Executing guard condition for state %d", current_state());
      guard_res = guard->invoke_guard_condition(this, m_event_data.get());
    }

    if (!guard_res) {
      continue;
    }

    /* transitioning to a new state? */
    if (next_state() != current_state()) {
      /* execute state exit action before switching to new state */
      if (nullptr != exit) {
        ER_VER("Executing exit action for state %d", current_state());
        exit->invoke_exit_action(this);
      }

      /* execute state entry action on the new state */
      if (nullptr != entry) {
        ER_VER("Executing entry action for new state %d", next_state());
        entry->invoke_entry_action(this, m_event_data.get());
      }

      /* Ensure exit/entry actions didn't call interval_event() by accident */
      ER_ASSERT(!m_event_generated,
                "FATAL: entry/exit actions called internal_event()!");
    }
    /* Now we're ready to switch to the new state */
    update_state(next_state());
    const state_map_ex_row* row = state_map_ex(current_state());
    state_engine_step(row);
  } /* while() */
} /* state_engine_map_ex() */

void base_fsm::state_engine_step(const state_map_row* const c_row) {
  ER_ASSERT(nullptr != c_row->state(), "FATAL: null state?");
  ER_VER("Invoking state action: state%d, data=%p",
         current_state(),
         reinterpret_cast<const void*>(m_event_data.get()));
  c_row->state()->invoke_state_action(this, event_data_get());
} /* state_engine_step() */

void base_fsm::state_engine_step(const state_map_ex_row* const c_row_ex) {
  ER_ASSERT(nullptr != c_row_ex->state(), "FATAL: null state?");
  ER_VER("Invoking state action: state%d, data=%p",
         current_state(),
         reinterpret_cast<const void*>(m_event_data.get()));
  c_row_ex->state()->invoke_state_action(this, event_data_get());
} /* state_engine_step() */

void base_fsm::update_state(uint8_t new_state) {
  if (new_state != m_current_state) {
    m_previous_state = m_current_state;
  }
  m_last_state = m_current_state;
  m_current_state = new_state;
} /* update_state() */

NS_END(state_machine, patterns, rcppssw);
