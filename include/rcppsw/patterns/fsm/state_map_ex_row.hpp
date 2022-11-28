/**
 * \file state_map_ex_row.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/patterns/fsm/state.hpp"
#include "rcppsw/patterns/fsm/state_entry.hpp"
#include "rcppsw/patterns/fsm/state_exit.hpp"
#include "rcppsw/patterns/fsm/state_guard.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, fsm);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class state_map_ex_row
 * \ingroup patterns fsm
 *
 * \brief A structure to hold a single row within the extended state map (a
 * state map which includes entry, exit, and guard hooks).
 */
class state_map_ex_row {
 public:
  state_map_ex_row(rpfsm::state* state,
                   state_guard* guard,
                   state_entry* entry,
                   state_exit* exit)
      : m_state(state), m_guard(guard), m_entry(entry), m_exit(exit) {}

  rpfsm::state* state(void) const { return m_state; }
  state_guard* guard(void) const { return m_guard; }
  state_entry* entry(void) const { return m_entry; }
  state_exit* exit(void) const { return m_exit; }

 private:
  /* clang-format off */
  rpfsm::state* m_state;
  state_guard*  m_guard;
  state_entry*  m_entry;
  state_exit*   m_exit;
  /* clang-format on */
};

NS_END(fsm, patterns, rcppsw);

