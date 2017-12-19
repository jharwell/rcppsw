/**
 * @file threadable.cpp
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
#include "rcppsw/multithread/threadable.hpp"
#include "rcsw/multithread/threadm.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, multithread);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
status_t threadable::start(void* arg, int core) {
  /* start main thread */
  m_thread_run = true;

  m_arg = arg;
  CHECK(0 == pthread_create(&m_thread, nullptr, &threadable::entry_point, this));
  if (-1 != core) {
    CHECK(OK == threadm_core_lock(m_thread, core));
  }
  return OK;

error:
  return ERROR;
} /* start() */

NS_END(multithread, rcppsw);
