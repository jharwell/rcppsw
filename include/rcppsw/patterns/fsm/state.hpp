/**
 * \file state.hpp
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

} /* namespace rcppsw::patterns::fsm */

