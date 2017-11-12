/**
 * @file threadable.hpp
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

#ifndef INCLUDE_RCPPSW_MULTITHREAD_THREADABLE_HPP_
#define INCLUDE_RCPPSW_MULTITHREAD_THREADABLE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, multithread);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class threadable {
 public:
  threadable(void) : m_thread_run(false), m_thread(), m_arg(NULL) {}
  virtual ~threadable(void) {}

  /**
   * @brief The entry point for a thread.
   *
   * @param arg Argument passed to thread (can be NULL).
   * @return The return value of the thread.
   */
  virtual void* thread_main(void* arg) = 0;

  /**
   * @brief Start a thread.
   *
   * @param arg Argument passed to thread (can be NULL).
   * @param core The core to bind the thread to. By default, the thread is
   *             unbound.
   * @return status_t - OK if successful, ERROR otherwise
   */
  virtual status_t start(void* arg, int core = -1);


  /**
   * @brief Signal a thread that it should terminate, from outside the thread.
   */
  virtual void term(void) { m_thread_run = false; }

  /**
   * @brief Join a thread (i.e. wait for it to finish)
   */
  virtual void join(void) { pthread_join(m_thread, NULL); }

 protected:
  /**
   * @brief Check if a thread object has been told to terminate elsewhere.
   */
  bool terminated(void) { return (false == m_thread_run); }

  /**
   * @brief Exit a thread from within the thread itself.
   *
   * @param ret If non-NULL, will be filled with the return value of the thread
   * as it exits.
   */
  virtual void exit(void* ret = NULL) {
    m_thread_run = false;
    if (!ret) {
      int ret2;
      pthread_exit(&ret2);
    } else {
      pthread_exit(ret);
    }
  }

  /**
   * @brief Get the pthread handle for the thread.
   *
   * @return The handle.
   */
  pthread_t thread_handle(void) { return m_thread; }

  /**
   * @brief Get the ID of the thread within the parent process.
   *
   * @return The thread ID (guaranteed to be unique among threads in a process).
   */
  int64_t thread_id(void) { return syscall(__NR_gettid); }

  threadable(const threadable&& other) : m_thread_run(other.m_thread_run),
                                         m_thread(other.m_thread),
                                         m_arg(other.m_arg) {}

 private:
  static void* entry_point(void* this_p) {
    threadable* pt = static_cast<threadable*>(this_p);
    return pt->thread_main(pt->m_arg);
  } /* entry_point() */

  const threadable& operator=(const threadable& rhs) = delete;
  threadable(const threadable& other) = delete;

  bool      m_thread_run;
  pthread_t m_thread;
  void      *m_arg;
};

NS_END(multithread, rcppsw);

#endif /* INCLUDE_RCPPSW_MULTITHREAD_THREADABLE_HPP_ */
