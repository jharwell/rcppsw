/**
 * \file state_action.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cassert>
#include "rcppsw/rcppsw.hpp"
#include "rcppsw/patterns/fsm/event.hpp"
#include "rcppsw/patterns/fsm/state.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::patterns::fsm {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class state_action0
 * \ingroup patterns fsm
 *
 * \tparam SM A state machine class.
 * \tparam Func A state machine member function pointer, which takes ZERO
 * arguments.
 */
template <class SM, int (SM::*Func)(void)>
class state_action0 : public state {
 public:
  state_action0(void) = default;
  state_action0(const state_action0&) = default;
  ~state_action0(void) override = default;

  int invoke_state_action(base_fsm* sm,
                          RCPPSW_UNUSED event_data*) const override {
    /* Downcast the state machine and event data to the correct derived type */
    auto* derived_fsm = static_cast<SM*>(sm);
    return (derived_fsm->*Func)();
  }
};

/**
 * \class state_action1
 * \ingroup patterns fsm
 *
 * \tparam SM A state machine class.
 * \tparam Event A state function event data type (derived from event_data).
 * \tparam Func A state machine member function pointer, which takes ONE
 * argument.
 */
template <class SM, class Event, int (SM::*Func)(Event*)>
class state_action1 : public state {
 public:
  state_action1(void) = default;
  ~state_action1(void) override = default;
  state_action1(const state_action1&) = default;

  int invoke_state_action(base_fsm* sm, event_data* data) const override {
    /* Downcast the state machine and event data to the correct derived type */
    auto* derived_fsm = static_cast<SM*>(sm);
    Event* derived_event = nullptr;

    /*
     * If this check fails, there is a mismatch between the STATE_DECLARE event
     * data type and the data type being sent to the state function.
     */
    if (nullptr != data) {
      derived_event = dynamic_cast<Event*>(data);
      assert(derived_event);
    }

    return (derived_fsm->*Func)(derived_event);
  }
};

} /* namespace rcppsw::patterns::fsm */

