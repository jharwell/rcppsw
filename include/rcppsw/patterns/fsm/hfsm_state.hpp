/**
 * \file hfsm_state.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cassert>
#include "rcppsw/rcppsw.hpp"
#include "rcppsw/patterns/fsm/event.hpp"
#include "rcppsw/patterns/fsm/state.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, fsm);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class hfsm_state
 * \ingroup patterns fsm
 *
 * \brief Base class representing a state within a HFSM.
 */
class hfsm_state : public state {
 public:
  explicit hfsm_state(hfsm_state* parent) : m_parent(parent) {}
  ~hfsm_state() override = default;

  rcppsw::patterns::fsm::state* parent(void) const {
    return m_parent;
  }
  void parent(rcppsw::patterns::fsm::state* parent) {
    m_parent = parent;
  }

  hfsm_state(const hfsm_state&) = delete;
  hfsm_state& operator=(const hfsm_state&) = delete;

 private:
  /* clang-format off */
  rcppsw::patterns::fsm::state* m_parent;
  /* clang-format on */
};

/**
 * \tparam FSM The current state machine class.
 * \tparam Handler A state machine member function pointer that takes ZERO
 * arguments.
 */
template <class FSM, int (FSM::*Handler)(void)>
class hfsm_state_action0 : public hfsm_state {
 public:
  explicit hfsm_state_action0(hfsm_state* parent) : hfsm_state(parent) {}
  ~hfsm_state_action0(void) override = default;

  int invoke_state_action(base_fsm* fsm,
                          RCPPSW_UNUSED event_data*) const override {
    auto* derived_fsm = static_cast<FSM*>(fsm);
    return (derived_fsm->*Handler)();
  }
};

/**
 * \tparam FSM The current state machine class.
 * \tparam Event A state function event data type (derived from event).
 * \tparam Handler A state machine member function pointer, that takes ONE
 * argument.
 */
template <class FSM, class Event, int (FSM::*Handler)(Event*)>
class hfsm_state_action1 : public hfsm_state {
 public:
  explicit hfsm_state_action1(hfsm_state* parent) : hfsm_state(parent) {}
  ~hfsm_state_action1() override = default;
  int invoke_state_action(base_fsm* fsm,
                          event_data* event) const override {
    /* Downcast the state machine and event data to the correct derived type */
    auto* derived_fsm = static_cast<FSM*>(fsm);
    Event* derived_event = nullptr;

    /*
     * If this check fails, there is a mismatch between the STATE_DECLARE event
     * data type and the data type being sent to the state function.
     */
    if (nullptr != event) {
      derived_event = dynamic_cast<Event*>(event);
      assert(derived_event);
    }

    return (derived_fsm->*Handler)(derived_event);
  }
};

NS_END(fsm, patterns, rcppsw);

