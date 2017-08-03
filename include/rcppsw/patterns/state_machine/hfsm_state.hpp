/**
 * @file hfsm_state.hpp
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

#ifndef INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_HFSM_STATE_HPP_
#define INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_HFSM_STATE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <assert.h>
#include "rcppsw/patterns/state_machine/event.hpp"
#include "rcppsw/patterns/state_machine/state.hpp"
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, state_machine);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class hfsm_state: public state {
 public:
  virtual ~hfsm_state(void) {}

  virtual int invoke_state_action(
      base_fsm* sm,
      const event* event) const = 0;
};

/**
 * @brief hfsm_state_action takes three template arguments:
 *
 * - A state machine class.
 * - A state function event data type (derived from event_data).
 * - A state machine member function pointer.
 */
template <class SM, class parent_state,
          class Event, void (SM::*Func)(const Event*)>
class hfsm_state_action : public hfsm_state {
 public:
  virtual ~hfsm_state_action() {}
  virtual int invoke_state_action(base_fsm* sm,
                                   const event* event) const {
    /* Downcast the state machine and event data to the correct derived type */
    SM* derived_fsm = static_cast<SM*>(sm);
    const Event* derived_event = NULL;

    assert(event);
    /*
     * If this check fails, there is a mismatch between the STATE_DECLARE event
     * data type and the data type being sent to the state function.
     */
    derived_event = dynamic_cast<const Event*>(event);
    assert(derived_event);
    return (derived_fsm->*Func)(derived_event);
  }
};


NS_END(state_machine, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_HFSM_STATE_HPP_ */
