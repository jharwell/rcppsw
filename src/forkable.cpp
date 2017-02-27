/*******************************************************************************
 * Name            : forkable.cpp
 * Project         : rcppsw
 * Module          : multithread
 * Description     : Common fork()/exec() wrappers
 * Creation Date   : 08/16/15
 * Copyright       : Copyright 2015 John Harwell, All rights reserved
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/forkable.hpp"
#include <assert.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string>
#include <vector>
#include "rcsw/multiprocess/procm.h"
#include "rcsw/common/dbg.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
/**
 * forkable::start() - Start a process
 *
 * RETURN:
 *     pid_t - PID of child process
 *
 **/
pid_t forkable::start(int core) {
  proc_run_ = true;
  pid_ = fork();
  if (pid_ == 0) {
    if (-1 != core) {
      procm_socket_lock(core);
    }
    entry_point(this);
  }
  return pid_;
} /* forkable::start() */

/**
 * forkable::start() - Change cwd and Start a process
 *
 * RETURN:
 *     pid_t - PID of child process
 *
 **/
pid_t forkable::start(const std::string& new_wd, int core) {
  proc_run_ = true;
  pid_ = fork();
  if (pid_ == 0) {
    CHECK(0 == chdir(new_wd.c_str()));
    if (-1 != core) {
      procm_socket_lock(core);
    }
    entry_point(this);
  }
  return pid_;
error:
  return -1;
} /* forkable::start() */

} /* namespace rcppsw */
