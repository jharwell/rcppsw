/**
 * @file event.hpp
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

#ifndef INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_EVENT_HPP_
#define INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_EVENT_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, state_machine);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class event_signal
 *
 * @brief A class representing the different signals that can be passed between
 * states in an FSM, and/or between FSMs.
 */
class event_signal {
 public:
  enum {
    IGNORED = 0xFE, /// A signal that can be ignored
                    /**
                     * @brief A signal indicating that something VERY BAD has
                     * happened. Will cause the parent FSM to halt the program.
                     */
    FATAL = 0xFF,

    /**
     * @brief A signal indicating that all signals input into a given state have
     * been handled successfully. All states should return this signal in the
     * nomitive case.
     */
    HANDLED = 0,

    /**
     * @brief A signal from a lower/child state that could not be handled
     * by a lower state, OR a signal that a lower state sent to
     * indicate that it encountered a situation that it does not
     * know how to handle in the normal turn of events.
     */
    UNHANDLED = 1,

    /**
     * @brief Applications wishing to defined their own event signals
     * should start here.
     */
    EXTERNAL_SIGNALS,
  };
};

/**
 * @class event_type
 *
 * @brief A class representing the types of signals that can be passed between
 * states in an FSM, and/or between FSMs.
 */
class event_type {
 public:
  enum {
    NORMAL = 0, /// A normal, external state machine event

    /**
     * @brief A signal from a child state, conveying something that it couldn't
     * handle or that something important happened that it felt a parent FSM
     * should know about.
     */
    CHILD = 1,

    /**
     * @brief Applications wishing to defined their own event types
     * should start here.
     */
    EXTERNAL_TYPES,
  };
};

/**
 * @class event_data
 *
 * @brief Unique state machine event data must inherit from this class.
 */
class event_data {
 public:
  event_data(void) = default;
  explicit event_data(int signal, int type = event_type::NORMAL)
      : m_signal(signal), m_type(type) {}
  virtual ~event_data(void) = default;

  int signal(void) const { return m_signal; }
  void signal(int signal) { m_signal = signal; }
  int type(void) const { return m_type; }
  void type(int type) { m_type = type; }
  void reset(void) {
    signal(event_signal::IGNORED);
    type(event_type::NORMAL);
  }

 private:
  int m_signal{event_signal::IGNORED};
  int m_type{event_type::NORMAL};
};

/**
 * @class no_event_data
 *
 * @brief This class does NOT derived from \ref event_data so that compiler
 * errors are generated if you attempt to use it outside of its intent to
 * indicate that a state does not take any data as input.
 */
class no_event_data {};

NS_END(state_machine, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_EVENT_HPP_ */
