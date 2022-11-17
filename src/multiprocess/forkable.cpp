/**
 * \file forkable.cpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/multiprocess/forkable.hpp"

#include <filesystem>

#include "rcsw/multiprocess/procm.h"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, multiprocess);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
pid_t forkable::start(int core) {
  return start(std::filesystem::current_path(), core);
} /* forkable::start() */

pid_t forkable::start(const std::string& new_wd, int core) {
  m_proc_run = true;
  m_pid = fork();
  if (m_pid == 0) {
    RCSW_CHECK(0 == chdir(new_wd.c_str()));
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
