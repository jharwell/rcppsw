/**
 * \file state_entry_action.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cassert>
#include "rcppsw/rcppsw.hpp"
#include "rcppsw/patterns/fsm/event.hpp"
#include "rcppsw/patterns/fsm/state_entry.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, fsm);
class base_fsm;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class state_entry_action0
 * \ingroup patterns fsm
 *
 * \brief Action to perform upon transition to a state.
 *
 * \tparam SM A state machine class
 * \tparam Func A state machine  member function pointer that takes ZERO
 * arguments.
 */
template <class SM, void (SM::*Func)(void)>
class state_entry_action0 : public state_entry {
 public:
  ~state_entry_action0(void) override = default;
  void invoke_entry_action(base_fsm* sm,
                           RCPPSW_UNUSED const event_data*) const override {
    auto* derived_fsm = static_cast<SM*>(sm);
    (derived_fsm->*Func)();
  }
};

/**
 * \class state_entry_action1
 * \ingroup patterns fsm
 *
 * \tparam SM A state machine class
 * \tparam Event A state function event data type (derived from event_data).
 * \tparam Func A state machine  member function pointer that takes ONE
 * argument.
 */
template <class SM, class Event, void (SM::*Func)(const Event*)>
class state_entry_action1 : public state_entry {
 public:
  ~state_entry_action1(void) override = default;

  void invoke_entry_action(base_fsm* sm, const event_data* data) const override {
    auto* derived_fsm = static_cast<SM*>(sm);
    const Event* derived_event = NULL;
    if (nullptr != data) {
      derived_event = dynamic_cast<const Event*>(data);
      assert(derived_event);
    }
    (derived_fsm->*Func)(derived_event);
  }
};

NS_END(fsm, patterns, rcppsw);

