/**
 * \file threadable.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
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

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <pthread.h>
#include <sys/syscall.h>
#include <sys/types.h>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, multithread);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class threadable
 * \ingroup multithread
 *
 * \brief Daemon interface class which can be derived from to indicate that the
 * class can spawn a new thread and jump into the main loop defined for the class.
 */
class threadable {
 public:
  threadable(void) = default;
  virtual ~threadable(void) = default;

  threadable(const threadable&) = delete;
  threadable& operator=(const threadable&) = delete;

  /**
   * \brief The entry point for a thread.
   *
   * \param arg Argument passed to thread (can be NULL).
   * \return The return value of the thread.
   */
  virtual void* thread_main(void* arg) = 0;

  /**
   * \brief Start a thread.
   *
   * \param arg Argument passed to thread (can be NULL).
   * \param core The core to bind the thread to. By default, the thread is
   *             unbound.
   * \return status_t - OK if successful, ERROR otherwise
   */
  status_t start(void* arg, int core = -1);

  /**
   * \brief Signal a thread that it should terminate, from outside the thread.
   */
  virtual void term(void) { m_thread_run = false; }

  /**
   * \brief Join a thread (i.e. wait for it to finish).
   */
  void join(void) { pthread_join(m_thread, nullptr); }

 protected:
  /**
   * \brief Check if a thread object has been told to terminate elsewhere.
   */
  bool terminated(void) const { return m_thread_run; }

  /**
   * \brief Exit a thread from within the thread itself.
   *
   * \param ret If non-NULL, will be filled with the return value of the thread
   * as it exits.
   */
  RCPPSW_DEAD void exit(void* ret = nullptr) {
    m_thread_run = false;
    if (nullptr == ret) {
      int ret2;
      pthread_exit(&ret2);
    } else {
      pthread_exit(ret);
    }
  }

  /**
   * \brief Get the pthread handle for the thread.
   *
   * \return The handle.
   */
  pthread_t thread_handle(void) const { return m_thread; }

  /**
   * \brief Get the ID of the thread within the parent process.
   *
   * \return The thread ID (guaranteed to be unique among threads in a process).
   */
  int64_t thread_id(void) const { return syscall(__NR_gettid); }

 private:
  static void* entry_point(void* this_p) {
    auto* pt = static_cast<threadable*>(this_p);
    return pt->thread_main(pt->m_arg);
  } /* entry_point() */

  /* clancg-format off */
  bool m_thread_run{ false };
  pthread_t m_thread{};
  void* m_arg{ nullptr };
  /* clancg-format on */
};

NS_END(multithread, rcppsw);

