/**
 * \file hfsm.cpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/patterns/fsm/hfsm.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::patterns::fsm {

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void hfsm::state_engine_step(const state_map_row* const c_row) {
  ER_ASSERT(nullptr != c_row->state(), "null state?");
  ER_TRACE("Invoking state action: state%d, data=%p",
           current_state(),
           reinterpret_cast<const void*>(event_data()));
  auto* state = static_cast<const hfsm_state*>(c_row->state());
  int rval = event_signal::ekUNHANDLED;
  while (rval != event_signal::ekHANDLED) {
    rval = state->invoke_state_action(this, event_data());

    if (event_signal::ekHANDLED == rval) {
      break;
    }
    /*
     * It is possible that we have gotten the HANDLED signal from a parent state
     * of a child that returned UNHANDLED. As such, we need to change both the
     * event type and the signal of the event so execution can continue
     * normally.
     */
    state = static_cast<hfsm_state*>(state->parent());
    event_data()->type(event_type::ekCHILD);
    event_data()->signal(rval);
  } /* while() */
} /* state_engine_step() */

void hfsm::state_engine_step(const state_map_ex_row* const c_row_ex) {
  ER_ASSERT(nullptr != c_row_ex->state(), "null state?");
  ER_TRACE("Invoking state action: state%d, data=%p",
           current_state(),
           reinterpret_cast<const void*>(event_data()));
  auto* state = static_cast<const hfsm_state*>(c_row_ex->state());
  int rval = event_signal::ekUNHANDLED;
  while (rval != event_signal::ekHANDLED) {
    rval = state->invoke_state_action(this, event_data());

    if (event_signal::ekHANDLED == rval) {
      break;
    }
    /*
     * It is possible that we have gotten the HANDLED signal from a parent state
     * of a child that returned UNHANDLED. As such, we need to change both the
     * event type and the signal of the event so execution can continue
     * normally.
     */
    state = static_cast<hfsm_state*>(state->parent());
    event_data()->type(event_type::ekCHILD);
    event_data()->signal(rval);
  } /* while() */
} /* state_engine_step() */

void hfsm::change_parent(uint8_t state,
                         rcppsw::patterns::fsm::state* new_parent) {
  auto* row = state_map(state);
  auto* row_ex = state_map_ex(state);

  ER_ASSERT(!(nullptr == row && nullptr == row_ex), "Both state maps are NULL!");

  if (nullptr != row) {
    auto* self = static_cast<hfsm_state*>(row->state());
    self->parent(new_parent);
  } else {
    auto* self = static_cast<hfsm_state*>(row_ex->state());
    self->parent(new_parent);
  }
} /* change_parent() */

} /* namespace rcppsw::patterns::fsm */
