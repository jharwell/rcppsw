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

#ifndef INCLUDE_STATE_HPP_
#define INCLUDE_STATE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/state/event.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {
namespace patterns {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class simple_fsm;

/// @brief Abstract state base class that all states inherit from.
class state_base {
 public:
  /// Called by the state machine engine to execute a state action. If a guard
  /// condition exists and it evaluates to false, the state action will not
  /// execute.
  /// @param[in] sm - A state machine instance.
  /// @param[in] data - The event data.
  virtual void invoke_state_action(simple_fsm* sm,
                                   const event_data* data) const = 0;
};

/// @brief StateAction takes three template arguments: A state machine class,
/// a state function event data type (derived from event_data) and a state machine
/// member function pointer.
template <class SM, class Data, void (SM::*Func)(const Data*)>
class state_action : public state_base {
 public:
  /// @see state_base::Invokestate_action
  virtual void Invokestate_action(simple_fsm* sm, const event_data* data) const {
    // Downcast the state machine and event data to the correct derived type
    SM* derivedSM = static_cast<SM*>(sm);

    // If this check fails, there is a mismatch between the STATE_DECLARE
    // event data type and the data type being sent to the state function.
    // For instance, given the following state defintion:
    //    STATE_DECLARE(Mysimple_fsm, MyStateFunction, Myevent_data)
    // The following internal event transition is valid:
    //    InternalEvent(ST_MY_STATE_FUNCTION, new Myevent_data());
    // This next internal event is not valid and causes the assert to fail:
    //    InternalEvent(ST_MY_STATE_FUNCTION, new Otherevent_data());
    const Data* derivedData = dynamic_cast<const Data*>(data);
    ASSERT_TRUE(derivedData != NULL);

    // Call the state function
    (derivedSM->*Func)(derivedData);
  }
};


/// @brief Abstract guard base class that all guards classes inherit from.
class GuardBase {
 public:
  /// Called by the state machine engine to execute a guard condition action. If guard
  /// condition evaluates to TRUE the state action is executed. If FALSE, no state transition
  /// is performed.
  /// @param[in] sm - A state machine instance.
  /// @param[in] data - The event data.
  /// @return Returns TRUE if no guard condition or the guard condition evaluates to TRUE.
  virtual bool InvokeGuardCondition(simple_fsm* sm, const event_data* data) const = 0;
};

/// @brief GuardCondition takes three template arguments: A state machine class,
/// a state function event data type (derived from event_data) and a state machine
/// member function pointer.
template <class SM, class Data, bool (SM::*Func)(const Data*)>
class GuardCondition : public GuardBase
{
 public:
  virtual bool InvokeGuardCondition(simple_fsm* sm, const event_data* data) const
  {
    SM* derivedSM = static_cast<SM*>(sm);
    const Data* derivedData = dynamic_cast<const Data*>(data);
    ASSERT_TRUE(derivedData != NULL);

    // Call the guard function
    return (derivedSM->*Func)(derivedData);
  }
};

/// @brief Abstract entry base class that all entry classes inherit from.
class EntryBase
{
 public:
  /// Called by the state machine engine to execute a state entry action. Called when
  /// entering a state.
  /// @param[in] sm - A state machine instance.
  /// @param[in] data - The event data.
  virtual void InvokeEntryAction(simple_fsm* sm, const event_data* data) const = 0;
};

/// @brief EntryAction takes three template arguments: A state machine class,
/// a state function event data type (derived from event_data) and a state machine
/// member function pointer.
template <class SM, class Data, void (SM::*Func)(const Data*)>
class EntryAction : public EntryBase
{
 public:
  virtual void InvokeEntryAction(simple_fsm* sm, const event_data* data) const
  {
    SM* derivedSM = static_cast<SM*>(sm);
    const Data* derivedData = dynamic_cast<const Data*>(data);
    ASSERT_TRUE(derivedData != NULL);

    // Call the entry function
    (derivedSM->*Func)(derivedData);
  }
};

/// @brief Abstract exit base class that all exit classes inherit from.
class ExitBase
{
 public:
  /// Called by the state machine engine to execute a state exit action. Called when
  /// leaving a state.
  /// @param[in] sm - A state machine instance.
  virtual void InvokeExitAction(simple_fsm* sm) const = 0;
};

/// @brief ExitAction takes two template arguments: A state machine class and
/// a state machine member function pointer.
template <class SM, void (SM::*Func)(void)>
class ExitAction : public ExitBase
{
 public:
  virtual void InvokeExitAction(simple_fsm* sm) const
  {
    SM* derivedSM = static_cast<SM*>(sm);

    // Call the exit function
    (derivedSM->*Func)();
  }
};

} /* namespace patterns */
} /* namespace rcppsw */

#endif /* INCLUDE_STATE_HPP_ */
