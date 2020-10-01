/**
 * \file state_action.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_PATTERNS_FSM_STATE_ACTION_HPP_
#define INCLUDE_RCPPSW_PATTERNS_FSM_STATE_ACTION_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cassert>
#include "rcppsw/common/common.hpp"
#include "rcppsw/patterns/fsm/event.hpp"
#include "rcppsw/patterns/fsm/state.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, fsm);

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
                          RCSW_UNUSED event_data*) const override {
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

NS_END(fsm, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_FSM_STATE_ACTION_HPP_ */
