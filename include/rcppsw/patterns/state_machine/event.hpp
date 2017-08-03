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
/// @brief Unique state machine event data must inherit from this class.
class event {
 public:
  enum {
    EVENT_IGNORED = 0xFE,
    EVENT_FATAL   = 0xFF,
    EVENT_HANDLED = 0,
    EVENT_UNHANDLED = 1,
  };
  enum {
    SIG_INIT = 0,
    SIG_CONTINUE = 1,
    SIG_USER = 2
  };

  event(void) : m_signal(SIG_INIT) {}
  virtual ~event() {}
  int signal(void) const { return m_signal; }
  void signal(int signal) { m_signal = signal; }

 private:
  int m_signal;
};

typedef event no_event;

NS_END(state_machine, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_EVENT_HPP_ */
