/**
 * \file mt_fsm.cpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
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
