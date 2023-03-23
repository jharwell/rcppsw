/**
 * \file state_entry.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::patterns::fsm {

class base_fsm;
class event_data;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class state_entry
 * \ingroup patterns fsm
 *
 * \brief Abstract entry base class that all entry classes inherit from.
 */
class state_entry {
 public:
  virtual ~state_entry(void) = default;

  /**
   * \brief Called by the state machine engine to execute a state entry
   * action (when entering a state).
   *
   * \param sm A state machine instance.
   * \param data The event data.
   */
  virtual void invoke_entry_action(base_fsm* sm,
                                   const event_data* data) const = 0;
};

} /* namespace rcppsw::patterns::fsm */

