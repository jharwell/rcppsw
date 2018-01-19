/**
 * @file forkable.cpp
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
#include "rcppsw/common/common.hpp"
#include "rcsw/common/dbg.h"
#include "rcsw/multiprocess/procm.h"

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
