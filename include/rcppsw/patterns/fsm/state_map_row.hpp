/**
 * \file state_map_row.hpp
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
#include "rcppsw/patterns/fsm/state.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, fsm);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class state_map_row
 * \ingroup patterns fsm
 *
 * \brief A structure to hold a single row within the state map.
 */
class state_map_row {
 public:
  explicit state_map_row(rcppsw::patterns::fsm::state* state)
      : m_state(state) {}

  rcppsw::patterns::fsm::state* state(void) const { return m_state; }

 private:
  /* clang-format off */
  rpfsm::state* m_state;
  /* clang-format on */
};

NS_END(fsm, patterns, rcppsw);

