/*******************************************************************************
 * Name            : threadable.cpp
 * Project         : rcppsw
 * Module          : multithread
 * Description     : Threadable base class
 * Creation Date   : 11/16/15
 * Copyright       : Copyright 2015 John Harwell, All rights reserved
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/multithread/threadable.hpp"
#include "rcsw/multithread/threadm.h"

/*******************************************************************************
 * Namespace Definitions
 ******************************************************************************/
NS_START(rcppsw, multithread);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
/**
 * threadable::start() - Start a thread
 *
 * RETURN:
 *     status_t - OK if successful, ERROR otherwise
 *
 **/
status_t threadable::start(void* arg, int core) {
  /* start main thread */
  m_thread_run = true;

  m_arg = arg;
  CHECK(0 == pthread_create(&m_thread, NULL, &threadable::entry_point, this));
  if (-1 != core) {
    CHECK(OK == threadm_core_lock(m_thread, core));
  }
  return OK;

error:
  return ERROR;
} /* start() */

NS_END(multithread, rcppsw);
