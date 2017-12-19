/**
 * @file state_exit_action.hpp
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

#ifndef INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_STATE_EXIT_ACTION_HPP_
#define INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_STATE_EXIT_ACTION_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"
#include "rcppsw/patterns/state_machine/event.hpp"
#include "rcppsw/patterns/state_machine/state_exit.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, state_machine);
class base_fsm;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief state_exit_action takes two template arguments:
 *
 * - A state machine class.
 * - A state machine member function pointer.
 */
template <class SM, void (SM::*Func)(void)>
class state_exit_action : public state_exit {
 public:
  ~state_exit_action(void) override = default;

  void invoke_exit_action(base_fsm* sm) const override {
    auto* derived = static_cast<SM*>(sm);
    (derived->*Func)();
  }
};

NS_END(state_machine, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_STATE_EXIT_ACTION_HPP_ */
