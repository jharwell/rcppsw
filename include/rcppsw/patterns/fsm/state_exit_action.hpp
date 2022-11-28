/**
 * \file state_exit_action.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
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

