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
class state_base {
 public:
  virtual ~state_base() {}
  /**
   * @brief Called by the state machine engine to execute a state action. If a guard
   * condition exists and it evaluates to false, the state action will not
   * execute.
   *
   * @param sm A state machine instance.
   * @param data The event data.
   */
  virtual void invoke_state_action(base_fsm* sm,
                                   const event_data* data) const = 0;
};

/**
 * @brief state_action takes three template arguments:
 *
 * - A state machine class.
 * - A state function event data type (derived from event_data).
 * - A state machine member function pointer.
 */
template <class SM, class Data, void (SM::*Func)(const Data*)>
class state_action : public state_base {
 public:
  virtual ~state_action() {}
  virtual void invoke_state_action(base_fsm* sm,
                                   const event_data* data) const {
    /* Downcast the state machine and event data to the correct derived type */
    SM* derived_fsm = static_cast<SM*>(sm);

    /*
     * If this check fails, there is a mismatch between the STATE_DECLARE event
     * data type and the data type being sent to the state function.  For
     * instance, given the following state defintion:
     *
     * STATE_DECLARE(Mybase_fsm, MyStateFunction, Myevent_data)
     *
     * The following internal event transition is valid:
     *
     * InternalEvent(ST_MY_STATE_FUNCTION, new Myevent_data());
     *
     * This next internal event is not valid and causes the assert to fail:
     *
     * InternalEvent(ST_MY_STATE_FUNCTION, new Otherevent_data());
     */
    const Data* derived_data = dynamic_cast<const Data*>(data);
    FPC_ASSERT(nullptr != derived_data);

    // Call the state function
    (derived_fsm->*Func)(derived_data);
  }
};

/**
 * @brief Abstract guard base class that all guards classes inherit from.
 */
class state_guard_base {
  virtual ~state_guard_base() {}
 public:
  /**
   * @brief Called by the state machine engine to execute a guard condition action. If guard
   * condition evaluates to TRUE the state action is executed. If FALSE, no state transition
   * is performed.
   *
   * @param sm A state machine instance.
   * @param data The event data.
   *
   * @return Returns TRUE if no guard condition or the guard condition evaluates
   * to TRUE.
  */
  virtual bool invoke_guard_condition(base_fsm* sm,
                                      const event_data* data) const = 0;
};

/** @brief state_guard_condition takes three template arguments:
 *
 * - A state machine class.
 * - A state function event data type (derived from event_data).
 * - A state machine member function pointer.
 */
template <class SM, class Data, bool (SM::*Func)(const Data*)>
class state_guard_condition : public state_guard_base {
 public:
  virtual ~state_guard_condition() {}
  virtual bool invoke_guard_condition(base_fsm* sm,
                                      const event_data* data) const {
    SM* derived_fsm = static_cast<SM*>(sm);
    const Data* derived_data = dynamic_cast<const Data*>(data);
    FPC_ASSERT(nullptr != derived_data);
    return (derived_fsm->*Func)(derived_data);
  }
};

/**
 * @brief Abstract entry base class that all entry classes inherit from.
 */
class state_entry_base {
  virtual ~state_entry_base() {}
 public:
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
 * @brief state_entry_action takes three template arguments:
 *
 * - A state machine class
 * - A state function event data type (derived from event_data).
 * - A state machine  member function pointer.
*/
template <class SM, class Data, void (SM::*Func)(const Data*)>
class state_entry_action : public state_entry_base {
 public:
  virtual void invoke_entry_action(base_fsm* sm,
                                   const event_data* data) const {
    SM* derived_fsm = static_cast<SM*>(sm);
    const Data* derived_data = dynamic_cast<const Data*>(data);
    FPC_ASSERT(derived_data);

    // Call the entry function
    (derived_fsm->*Func)(derived_data);
  }
};

/**
 * @brief Abstract exit base class that all exit classes inherit from.
 */
class state_exit_base {
  virtual ~state_exit_base() {}
 public:
  /**
   * @brief Called by the state machine engine to execute a state exit action. Called when
   * leaving a state.
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
class state_exit_action : public state_exit_base {
 public:
  virtual void invoke_exit_action(base_fsm* sm) const {
    SM* derivedSM = static_cast<SM*>(sm);
    (derivedSM->*Func)();
  }
  virtual ~state_exit_action() {}
};

NS_END(state_machine, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_STATE_HPP_ */
