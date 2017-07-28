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
#include "rcppsw/multiprocess/forkable.hpp"
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
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, multiprocess);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
pid_t forkable::start(int core) {
  m_proc_run = true;
  m_pid = fork();
  if (m_pid == 0) {
    if (-1 != core) {
      procm_socket_lock(core);
    }
    entry_point(this);
  }
  return m_pid;
} /* forkable::start() */

pid_t forkable::start(const std::string& new_wd, int core) {
  m_proc_run = true;
  m_pid = fork();
  if (m_pid == 0) {
    CHECK(0 == chdir(new_wd.c_str()));
    if (-1 != core) {
      procm_socket_lock(core);
    }
    entry_point(this);
  }
  return m_pid;

error:
  return -1;
} /* forkable::start() */

NS_END(multiprocess, rcppsw);
