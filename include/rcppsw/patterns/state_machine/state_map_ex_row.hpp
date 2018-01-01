/**
 * @file state_map_ex_row.hpp
 * @ingroup patterns state_machine
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

#ifndef INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_STATE_MAP_EX_ROW_HPP_
#define INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_STATE_MAP_EX_ROW_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/patterns/state_machine/state.hpp"
#include "rcppsw/patterns/state_machine/state_entry.hpp"
#include "rcppsw/patterns/state_machine/state_exit.hpp"
#include "rcppsw/patterns/state_machine/state_guard.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, state_machine);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class state_map_ex_row
 *
 * @brief A structure to hold a single row within the extended state map.
 */
class state_map_ex_row {
 public:
  state_map_ex_row(rcppsw::patterns::state_machine::state* state,
                   state_guard* guard,
                   state_entry* entry,
                   state_exit* exit)
      : m_state(state), m_guard(guard), m_entry(entry), m_exit(exit) {}

  rcppsw::patterns::state_machine::state* state(void) const { return m_state; }
  state_guard* guard(void) const { return m_guard; }
  state_entry* entry(void) const { return m_entry; }
  state_exit* exit(void) const { return m_exit; }

 private:
  rcppsw::patterns::state_machine::state* m_state;
  state_guard* m_guard;
  state_entry* m_entry;
  state_exit* m_exit;
};

NS_END(state_machine, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_STATE_MAP_EX_ROW_HPP_ */
