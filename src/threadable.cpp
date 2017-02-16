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
#include "rcsw/common/dbg.h"
#include "rcsw/multithread/threadm.h"

/*******************************************************************************
 * Namespace Definitions
 ******************************************************************************/
namespace rcppsw {

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
  thread_run_ = true;

  arg_ = arg;
  CHECK(0 == pthread_create(&thread_, NULL, &threadable::entry_point, this));
  if (-1 != core) {
    CHECK(OK == threadm_core_lock(thread_, core));
  }
  return OK;

error:
  return ERROR;
} /* threadable::start() */

} /* namespace rcppsw */
