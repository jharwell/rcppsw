/**
 * \file state_exit_action.hpp
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

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"
#include "rcppsw/patterns/fsm/event.hpp"
#include "rcppsw/patterns/fsm/state_exit.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, fsm);
class base_fsm;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class state_exit_action
 * \ingroup patterns fsm
 *
 * \brief state_exit_action takes two template arguments:
 *
 * \tparam SM A state machine class.
 * \tparam Func A state machine member function pointer.
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

NS_END(fsm, patterns, rcppsw);

