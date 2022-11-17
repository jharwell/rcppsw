/**
 * \file state_map_row.hpp
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

