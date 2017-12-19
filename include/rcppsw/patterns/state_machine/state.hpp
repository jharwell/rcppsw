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
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, state_machine);

class base_fsm;
class event_data;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Abstract state base class that all states inherit from.
 */
class state {
 public:
  virtual ~state() = default;

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

NS_END(state_machine, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_STATE_HPP_ */
