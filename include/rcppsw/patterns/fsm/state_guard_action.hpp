/**
 * \file state_guard_action.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/patterns/fsm/event.hpp"
#include "rcppsw/patterns/fsm/state_guard.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::patterns::fsm {

class base_fsm;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class state_guard_condition1
 * \ingroup patterns fsm
 *
 * \brief Condition to determine if a state's main action should be executed.
 *
 * \tparam SM A state machine class.
 * \tparam Event A state function event data type.
 * \tparam Func A state machine member function pointer that takes ONE argument
 */
template <class SM, class Event, bool (SM::*Func)(const Event*)>
class state_guard_condition1 : public state_guard {
 public:
  ~state_guard_condition1(void) override = default;

  bool invoke_guard_condition(base_fsm* sm,
                              const event_data* data) const override {
    auto* derived_fsm = static_cast<SM*>(sm);
    const Event* derived_event = NULL;

    if (nullptr != data) {
      derived_event = dynamic_cast<const Event*>(data);
      assert(derived_event);
    }
    return (derived_fsm->*Func)(derived_event);
  }
};

/**
 * \class state_guard_condition0
 *
 * \tparam SM A state machine class.
 * \tparam Func A state machine member function pointer that takes ZERO
 * arguments.
 */
template <class SM, bool (SM::*Func)(void)>
class state_guard_condition0 : public state_guard {
 public:
  ~state_guard_condition0(void) override = default;

  bool invoke_guard_condition(base_fsm* sm,
                              RCPPSW_UNUSED const event_data*) const override {
    auto* derived_fsm = static_cast<SM*>(sm);
    return (derived_fsm->*Func)();
  }
};

} /* namespace rcppsw::patterns::fsm */

