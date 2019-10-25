/**
 * @file hfsm_state.hpp
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

#ifndef INCLUDE_RCPPSW_PATTERNS_FSM_HFSM_STATE_HPP_
#define INCLUDE_RCPPSW_PATTERNS_FSM_HFSM_STATE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cassert>
#include "rcppsw/common/common.hpp"
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
 * @class hfsm_state
 * @ingroup rcppsw patterns fsm
 *
 * @brief Base class representing a state within a HFSM.
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

  hfsm_state(const hfsm_state& other) = delete;
  hfsm_state& operator=(const hfsm_state& other) = delete;

 private:
  rcppsw::patterns::fsm::state* m_parent;
};

/**
 * @tparam FSM The current state machine class.
 * @tparam Handler A state machine member function pointer that takes ZERO
 * arguments.
 */
template <class FSM, int (FSM::*Handler)(void)>
class hfsm_state_action0 : public hfsm_state {
 public:
  explicit hfsm_state_action0(hfsm_state* parent) : hfsm_state(parent) {}
  ~hfsm_state_action0(void) override = default;

  int invoke_state_action(base_fsm* fsm,
                          RCSW_UNUSED const event_data*) const override {
    auto* derived_fsm = static_cast<FSM*>(fsm);
    return (derived_fsm->*Handler)();
  }
};

/**
 * @tparam FSM The current state machine class.
 * @tparam Event A state function event data type (derived from event).
 * @tparam Handler A state machine member function pointer, that takes ONE
 * argument.
 */
template <class FSM, class Event, int (FSM::*Handler)(const Event*)>
class hfsm_state_action1 : public hfsm_state {
 public:
  explicit hfsm_state_action1(hfsm_state* parent) : hfsm_state(parent) {}
  ~hfsm_state_action1() override = default;
  int invoke_state_action(base_fsm* fsm,
                          const event_data* event) const override {
    /* Downcast the state machine and event data to the correct derived type */
    auto* derived_fsm = static_cast<FSM*>(fsm);
    const Event* derived_event = nullptr;

    /*
     * If this check fails, there is a mismatch between the STATE_DECLARE event
     * data type and the data type being sent to the state function.
     */
    if (nullptr != event) {
      derived_event = dynamic_cast<const Event*>(event);
      assert(derived_event);
    }

    return (derived_fsm->*Handler)(derived_event);
  }
};

NS_END(fsm, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_FSM_HFSM_STATE_HPP_ */