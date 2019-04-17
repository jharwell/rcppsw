/**
 * @file mt_fsm.cpp
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/multithread/mt_fsm.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, multithread);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void mt_fsm::external_event(uint8_t new_state,
                            std::unique_ptr<sm::event_data> data) {
  m_mutex.lock();
  base_fsm::external_event(new_state, std::move(data));
  m_mutex.unlock();
} /* external_event() */

void mt_fsm::init(void) {
  m_mutex.lock();
  base_fsm::init();
  m_mutex.unlock();
} /* init() */

NS_END(multithread, rcppsw);
