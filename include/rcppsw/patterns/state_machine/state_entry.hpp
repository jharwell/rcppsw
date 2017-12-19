/**
 * @file state_entry.hpp
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

#ifndef INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_STATE_ENTRY_HPP_
#define INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_STATE_ENTRY_HPP_

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
 * @brief Abstract entry base class that all entry classes inherit from.
 */
class state_entry {
 public:
  virtual ~state_entry(void) = default;

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

NS_END(state_machine, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_STATE_ENTRY_HPP_ */
