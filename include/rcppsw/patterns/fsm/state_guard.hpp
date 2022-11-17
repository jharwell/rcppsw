/**
 * \file state_guard.hpp
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
class event_data;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class state_guard
 * \ingroup patterns fsm
 *
 * \brief Abstract guard base class that all guards classes inherit from.
 */
class state_guard {
 public:
  virtual ~state_guard(void) = default;

  /**
   * \brief Called by the state machine engine to execute a guard condition
   * action. If guard condition evaluates to TRUE the state action is
   * executed. If FALSE, no state transition is performed.
   *
   * \param sm A state machine instance.
   *
   * \return Returns TRUE if no guard condition or the guard condition evaluates
   * to TRUE.
   */
  virtual bool invoke_guard_condition(base_fsm* sm, const event_data*) const = 0;
};

NS_END(fsm, patterns, rcppsw);

