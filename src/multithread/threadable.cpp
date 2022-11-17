/**
 * \file threadable.cpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/multithread/threadable.hpp"

#include "rcsw/multithread/threadm.h"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, multithread);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
status_t threadable::start(void* arg, int core) {
  /* start main thread */
  m_thread_run = true;

  m_arg = arg;
  RCSW_CHECK(0 ==
             pthread_create(&m_thread, nullptr, &threadable::entry_point, this));
  if (-1 != core) {
    RCSW_CHECK(OK == threadm_core_lock(m_thread, static_cast<size_t>(core)));
  }
  return OK;

error:
  return ERROR;
} /* start() */

NS_END(multithread, rcppsw);
