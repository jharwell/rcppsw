/**
 * \file state_guard.hpp
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

