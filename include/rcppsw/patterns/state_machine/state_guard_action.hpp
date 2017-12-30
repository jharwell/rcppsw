/**
 * @file state_guard_action.hpp
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

#ifndef INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_STATE_GUARD_ACTION_HPP_
#define INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_STATE_GUARD_ACTION_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/patterns/state_machine/event.hpp"
#include "rcppsw/patterns/state_machine/state_guard.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, state_machine);

class base_fsm;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/** @brief state_guard_condition takes three template arguments:
 *
 * - A state machine class.
 * - A state function event data type (derived from event_data).
 * - A state machine member function pointer that takes ONE argument
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

/** @brief state_guard_condition takes three template arguments:
 *
 * - A state machine class.
 * - A state machine member function pointer that takes ZERO arguments.
 */
template <class SM, bool (SM::*Func)(void)>
class state_guard_condition0 : public state_guard {
 public:
  ~state_guard_condition0(void) override = default;

  bool invoke_guard_condition(base_fsm* sm,
                              __unused const event_data*) const override {
    auto* derived_fsm = static_cast<SM*>(sm);
    return (derived_fsm->*Func)();
  }
};

NS_END(state_machine, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_STATE_GUARD_ACTION_HPP_ */
