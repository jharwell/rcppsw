/**
 * \file state.hpp
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
 * \class state
 * \ingroup patterns fsm
 *
 * \brief Abstract state base class that all states inherit from.
 */
class state {
 public:
  state(void) = default;
  state(const state&) = default;
  virtual ~state(void) = default;

  /**
   * \brief Called by the state machine engine to execute a state action. If a
   * guard condition exists and it evaluates to false, the state action will not
   * execute.
   *
   * \param sm A state machine instance.
   * \param data The event data.
   *
   * \return integer indicating whether or not the event was handled.
   */
  virtual int invoke_state_action(base_fsm* sm,
                                  event_data* data) const = 0;
};

NS_END(fsm, patterns, rcppsw);

