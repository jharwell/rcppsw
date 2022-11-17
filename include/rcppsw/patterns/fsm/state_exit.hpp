/**
 * \file state_exit.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, fsm);
class base_fsm;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class state_exit
 * \ingroup patterns fsm
 *
 * \brief Abstract exit base class that all exit classes inherit from.
 */
class state_exit {
 public:
  virtual ~state_exit(void) = default;

  /**
   * \brief Called by the state machine engine to execute a state exit
   * action. Called when leaving a state.
   *
   * \param sm A state machine instance.
   */
  virtual void invoke_exit_action(base_fsm* sm) const = 0;
};

NS_END(fsm, patterns, rcppsw);

