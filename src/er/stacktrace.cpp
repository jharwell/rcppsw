/**
 * \file stacktrace.cpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/er/stacktrace.hpp"

#include <csignal>
#include <fstream>
#include <iostream>
#include <cxxabi.h>

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, er);

static void stacktrace_to_file(int pid);

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
void sigsegv_sighandler(int signum) {
  /* trigger a core dump if we get a segfault or other signal */
  std::signal(signum, SIG_DFL);

  /*
   * Write stacktrace to a file named uniquely based on process PID
   * to help with debugging if a core dump is not created (for whatever
   * reason).
   */
  stacktrace_to_file(getpid());

  /* rethrow signal and terminate */
  ::kill(getpid(), signum);
} /* sigsegv_sighandler() */

void terminate_handler(void) {
  auto const ep = std::current_exception();
  if (ep) {
    try {
      int status;
      auto const etype = abi::__cxa_demangle(abi::__cxa_current_exception_type()->name(),
                                             nullptr,
                                             nullptr,
                                             &status);
      std::cerr << "Terminating: uncaught exception of type `" << etype << "`";
      std::rethrow_exception(ep);
    } catch(const std::exception& e) {
      std::cerr << " with `what()` = \"" << e.what() << "\"";
    } catch(...) {}
    std::cerr << std::endl;
  }
  /*
   * Write stacktrace to a file named uniquely based on process PID
   * to help with debugging if a core dump is not created (for whatever
   * reason).
   */
  stacktrace_to_file(getpid());

  std::abort();
} /* terminate_handler() */

void stacktrace_to_file(int pid) {
  char fname[50];
  snprintf(fname, sizeof(fname), "backtrace-%d", pid);

  /*
   * Can't safely create strings, allocate memory, etc., in signal handlers, so
   * this is all we get.
   */
  boost::stacktrace::safe_dump_to(fname);
} /* stacktrace_to_file() */

NS_END(er, rcppsw);
