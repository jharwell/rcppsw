/**
 * \file forkable.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <sys/wait.h>
#include <unistd.h>

#include <string>
#include <thread>
#include <vector>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, multiprocess);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class forkable
 * \ingroup multiprocess
 *
 * \brief Daemon interface class which can be derived from to indicate that the
 * class can be fork()ed and having each new process jump into the main loop
 * defined for the class.
 */
class forkable {
 public:
  forkable(void) = default;
  virtual ~forkable(void) = default;

  /**
   * \brief Signal a process that it should terminate, from outside the process.
   */
  virtual void term(void) { m_proc_run = false; }

  /**
   * \brief Entry point for the new process.
   */
  virtual void proc_main(void) = 0;

  pid_t pid(void) const { return m_pid; }

  /**
   * \brief Start a process.
   *
   * \param core The core to bind the process (and any threads it might spawn)
   *             to. By default, no binding.
   *
   * \return PID of child process in parent.
   */
  pid_t start(int core = -1);

  /**
   * \brief Start a process in a new directory.
   *
   * \param new_wd The new working directory to start the process in.
   * \param core The core to bind the process (and any threads it might spawn)
   *             to. By default, no binding.
   *
   * \return PID of child process in parent, or -1 if chdir() failed with \p
   *         new_wd.
   */
  pid_t start(const std::string& new_wd, int core = -1);

 protected:
  /**
   * \brief Check if a process object has been told to terminate elsewhere.
   */
  bool terminated(void) const { return !m_proc_run; }

 private:
  static void entry_point(void* this_p) {
    auto pt = static_cast<forkable*>(this_p);
    pt->proc_main();
  }

  /* clang-format off */
  bool  m_proc_run{false};
  pid_t m_pid{0};
  /* clang-format on */
};

NS_END(multiprocess, rcppsw);

