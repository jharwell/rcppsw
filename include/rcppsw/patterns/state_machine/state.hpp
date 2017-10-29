/**
 * @file state.hpp
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

#ifndef INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_STATE_HPP_
#define INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_STATE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <assert.h>
#include "rcppsw/patterns/state_machine/event.hpp"
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, state_machine);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class base_fsm;

/**
 * @brief Abstract state base class that all states inherit from.
 */
class state {
 public:
  virtual ~state() {}
  /**
   * @brief Called by the state machine engine to execute a state action. If a
   * guard condition exists and it evaluates to false, the state action will not
   * execute.
   *
   * @param sm A state machine instance.
   * @param data The event data.
   *
   * @return integer indicating whether or not the event was handled.
   */
  virtual int invoke_state_action(base_fsm* sm,
                                  const event_data* data) const = 0;
};

/**
 * @class state_action0
 * @brief Takes two template arguments:
 *
 * - A state machine class.
 * - A state machine member function pointer, which takes ZERO arguments.
 */
template <class SM, int (SM::*Func)(void)>
class state_action0 : public state {
 public:
  virtual ~state_action0(void) {}
  int invoke_state_action(base_fsm* sm, const event_data*) const override {
    /* Downcast the state machine and event data to the correct derived type */
    SM* derived_fsm = static_cast<SM*>(sm);
    return (derived_fsm->*Func)();
  }
};

/**
 * @class state_action1
 * @brief Takes three template arguments:
 *
 * - A state machine class.
 * - A state function event data type (derived from event_data).
 * - A state machine member function pointer, which takes ONE argument.
 */
template <class SM, class Event, int (SM::*Func)(const Event*)>
class state_action1 : public state {
 public:
  virtual ~state_action1(void) {}
  int invoke_state_action(base_fsm* sm, const event_data* data) const override {
    /* Downcast the state machine and event data to the correct derived type */
    SM* derived_fsm = static_cast<SM*>(sm);
    const Event* derived_event = NULL;

    /*
     * If this check fails, there is a mismatch between the STATE_DECLARE event
     * data type and the data type being sent to the state function.
     */
    if (data) {
      derived_event = dynamic_cast<const Event*>(data);
      assert(derived_event);
    }

    return (derived_fsm->*Func)(derived_event);
  }
};

/**
 * @brief Abstract guard base class that all guards classes inherit from.
 */
class state_guard {
 public:
  virtual ~state_guard() {}
  /**
   * @brief Called by the state machine engine to execute a guard condition
   * action. If guard condition evaluates to TRUE the state action is
   * executed. If FALSE, no state transition is performed.
   *
   * @param sm A state machine instance.
   *
   * @return Returns TRUE if no guard condition or the guard condition evaluates
   * to TRUE.
   */
  virtual bool invoke_guard_condition(base_fsm* sm, const event_data*) const = 0;
};

/** @brief state_guard_condition takes three template arguments:
 *
 * - A state machine class.
 * - A state function event data type (derived from event_data).
 * - A state machine member function pointer that takes ONE argument
 */
template <class SM, class Event, bool (SM::*Func)(const Event*)>
class state_guard_condition1 : public state_guard {
 public:
  virtual ~state_guard_condition1() {}
  bool invoke_guard_condition(base_fsm* sm,
                              const event_data* data) const override {
    SM* derived_fsm = static_cast<SM*>(sm);
    const Event* derived_event = NULL;
    if (data) {
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
  virtual ~state_guard_condition0() {}
  bool invoke_guard_condition(base_fsm* sm,
                              const event_data*) const override {
    SM* derived_fsm = static_cast<SM*>(sm);
    return (derived_fsm->*Func)();
  }
};

/**
 * @brief Abstract entry base class that all entry classes inherit from.
 */
class state_entry {
 public:
  virtual ~state_entry() {}

  /**
   * @brief Called by the state machine engine to execute a state entry
   * action (when entering a state).
   *
   * @param sm A state machine instance.
   * @param data The event data.
   */
  virtual void invoke_entry_action(base_fsm* sm,
                                   const event_data* data) const = 0;
};

/**
 * @brief state_entry_action takes two template arguments:
 *
 * - A state machine class
 * - A state function event data type (derived from event_data).
 * - A state machine  member function pointer that takes ZERO arguments.
*/
template <class SM, void (SM::*Func)(void)>
class state_entry_action0 : public state_entry {
 public:
  virtual ~state_entry_action0(void) {}
  void invoke_entry_action(base_fsm* sm,
                           const event_data*) const override {
    SM* derived_fsm = static_cast<SM*>(sm);
    (derived_fsm->*Func)();
  }
};

/**
 * @brief state_entry_action takes three template arguments:
 *
 * - A state machine class
 * - A state function event data type (derived from event_data).
 * - A state machine  member function pointer that takes ONE argument.
 */
template <class SM, class Event, void (SM::*Func)(const Event*)>
class state_entry_action1: public state_entry {
 public:
  virtual ~state_entry_action1(void) {}
  void invoke_entry_action(base_fsm* sm,
                           const event_data* data) const override {
    SM* derived_fsm = static_cast<SM*>(sm);
    const Event* derived_event = NULL;
    if (data) {
      derived_event = dynamic_cast<const Event*>(data);
      assert(derived_event);
    }
    (derived_fsm->*Func)(derived_event);
  }
};

/**
 * @brief Abstract exit base class that all exit classes inherit from.
 */
class state_exit {
 public:
  virtual ~state_exit() {}
  /**
   * @brief Called by the state machine engine to execute a state exit
   * action. Called when leaving a state.
   *
   * @param sm A state machine instance.
   */
  virtual void invoke_exit_action(base_fsm* sm) const = 0;
};

/**
 * @brief state_exit_action takes two template arguments:
 *
 * - A state machine class.
 * - A state machine member function pointer.
 */
template <class SM, void (SM::*Func)(void)>
class state_exit_action : public state_exit {
 public:
  virtual ~state_exit_action() {}
  void invoke_exit_action(base_fsm* sm) const override {
    SM* derivedSM = static_cast<SM*>(sm);
    (derivedSM->*Func)();
  }
};

NS_END(state_machine, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_STATE_HPP_ */
