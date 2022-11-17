/**
 * \file base_fsm.cpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/patterns/fsm/base_fsm.hpp"

#include <cassert>

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, fsm);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
base_fsm::base_fsm(uint8_t max_states, uint8_t initial_state)
    : ER_CLIENT_INIT("rcppsw.patterns.fsm.fsm"),
      mc_max_states(max_states),
      m_current_state(initial_state),
      m_initial_state(initial_state) {
  ER_ASSERT(mc_max_states < event_signal::ekIGNORED, "Too many states");
}

base_fsm::base_fsm(const base_fsm& other)
    : ER_CLIENT_INIT(other.logger_name()),
      mc_max_states(other.mc_max_states),
      m_current_state(other.current_state()),
      m_next_state(other.next_state()),
      m_initial_state(other.current_state()),
      m_previous_state(other.previous_state()),
      m_last_state(other.last_state()) {
  ER_ASSERT(mc_max_states < event_signal::ekIGNORED, "Too many states");
}

base_fsm& base_fsm::operator=(const base_fsm& other) {
  m_current_state = other.m_current_state;
  m_next_state = other.m_next_state;
  m_initial_state = other.m_initial_state;
  m_previous_state = other.m_previous_state;
  m_last_state = other.m_last_state;
  return *this;
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void base_fsm::init(void) {
  m_event_generated = false;
  update_state(initial_state());
  next_state(initial_state());
  m_event_data.reset(nullptr);
} /* init() */

void base_fsm::external_event(uint8_t new_state,
                              std::unique_ptr<class event_data> data) {
  ER_TRACE("Received external event: new_state=%d data=%p",
           new_state,
           reinterpret_cast<const void*>(data.get()));

  ER_ASSERT(event_signal::ekFATAL != new_state,
            "Received FATAL event: current_state=%u",
            current_state());

  if (new_state == event_signal::ekIGNORED) {
    return;
  }
  /* We are not supposed to ignore this event */

  /*
   * Generate the event and execute the state engine. If data was passed in,
   * pass that along to the handler function.
   */
  internal_event(new_state, std::move(data));
  m_event_data_hold = false;
  state_engine();

  /*
   * Derived FSMs may want/need access to the same event data across multiple
   * invocations of the FSM, which might even span multiple states, so if the
   * derived FSM signals NOT to reset the event data, then hold onto it;
   * otherwise reset it after each invocation of state_engine().
   */
  if (!m_event_data_hold) {
    m_event_data.reset(nullptr);
  }
} /* external_event() */

void base_fsm::internal_event(uint8_t new_state,
                              std::unique_ptr<class event_data> data) {
  ER_TRACE("Generated internal event: current_state=%d new_state=%d data=%p",
           current_state(),
           new_state,
           reinterpret_cast<const void*>(data.get()));
  next_state(new_state);
  m_event_generated = true;
  if (m_event_data != data) {
    event_data(std::move(data));
  }
}

void base_fsm::state_engine(void) {
  const state_map_row* map = state_map(0);
  const state_map_ex_row* map_ex = state_map_ex(0);

  if (nullptr != map) {
    state_engine_map();
  } else if (nullptr != map_ex) {
    state_engine_map_ex();
  } else {
    ER_FATAL_SENTINEL("Both state maps are NULL!");
  }
} /* state_engine() */

void base_fsm::state_engine_map(void) {
  /* While events are being generated keep executing states */
  while (m_event_generated) {
    /* verity new state is valid */
    ER_ASSERT(next_state() < max_states(),
              "New state %u is out of range [0-%u]",
              next_state(),
              max_states() - 1);

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
    ER_ASSERT(next_state() < max_states(),
              "New state %u is out of range [0-%u]",
              next_state(),
              max_states() - 1);
    const state_guard* guard = state_map_ex(next_state())->guard();
    const state_entry* entry = state_map_ex(next_state())->entry();
    const state_exit* exit = state_map_ex(current_state())->exit();

    /* execute guard condition */
    bool guard_res = true;
    if (nullptr != guard) {
      ER_TRACE("Executing guard condition for state %d", current_state());
      guard_res = guard->invoke_guard_condition(this, m_event_data.get());
    }

    if (!guard_res) {
      continue;
    }

    /* transitioning to a new state? */
    if (next_state() != current_state()) {
      /* execute state exit action before switching to new state */
      if (nullptr != exit) {
        ER_TRACE("Executing exit action for state %d", current_state());
        exit->invoke_exit_action(this);
      }

      /* execute state entry action on the new state */
      if (nullptr != entry) {
        ER_TRACE("Executing entry action for new state %d", next_state());
        entry->invoke_entry_action(this, m_event_data.get());
      }

      /* Ensure exit/entry actions didn't call interval_event() by accident */
      ER_ASSERT(!m_event_generated,
                "entry/exit actions called internal_event()!");
    }
    /* Now we're ready to switch to the new state */
    update_state(next_state());
    const state_map_ex_row* row = state_map_ex(current_state());
    state_engine_step(row);
  } /* while() */
} /* state_engine_map_ex() */

void base_fsm::state_engine_step(const state_map_row* const c_row) {
  ER_ASSERT(nullptr != c_row->state(), "null state?");
  ER_TRACE("Invoking state action: state%d, data=%p",
           current_state(),
           reinterpret_cast<const void*>(m_event_data.get()));
  c_row->state()->invoke_state_action(this, event_data());
} /* state_engine_step() */

void base_fsm::state_engine_step(const state_map_ex_row* const c_row_ex) {
  ER_ASSERT(nullptr != c_row_ex->state(), "null state?");
  ER_TRACE("Invoking state action: state%d, data=%p",
           current_state(),
           reinterpret_cast<const void*>(m_event_data.get()));
  c_row_ex->state()->invoke_state_action(this, event_data());
} /* state_engine_step() */

void base_fsm::update_state(uint8_t new_state) {
  if (new_state != m_current_state) {
    m_previous_state = m_current_state;
  }
  m_last_state = m_current_state;
  m_current_state = new_state;
} /* update_state() */

void base_fsm::inject_event(int signal, int type) {
  inject_event(std::make_unique<class event_data>(signal, type));
} /* inject event */

void base_fsm::inject_event(std::unique_ptr<class event_data> event) {
  external_event(current_state(), std::move(event));
} /* inject_event(std::unique_ptr<event_data> event)() */

NS_END(fsm, patterns, rcppssw);
