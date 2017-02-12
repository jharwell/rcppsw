/*******************************************************************************
 * Name            : threadable.hpp
 * Project         : rcppsw
 * Module          : multithread
 * Description     : Common threading functionality
 * Creation Date   : 06/18/15
 * Copyright       : Copyright 2015 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_THREADABLE_HPP_
#define INCLUDE_RCPPSW_THREADABLE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include "rcsw/al/altypes.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class threadable {
 public:
  /* data members */

  /* member functions */
  threadable(void) : thread_run_(false), thread_(), arg_(NULL) {}
  virtual ~threadable(void) {}

  virtual void* thread_main(void* arg) = 0;
  virtual status_t start(void* arg, int core = -1);
  virtual void exit(void* ret = NULL) {
    thread_run_ = false;
    if (!ret) {
      int ret2;
      pthread_exit(&ret2);
    } else {
      pthread_exit(ret);
    }
  }
  virtual void term(void) { thread_run_ = false; }
  bool terminated(void) { return (false == thread_run_); }
  virtual void join(void) { pthread_join(thread_, NULL); }

 protected:
  pthread_t thread_handle(void) { return thread_; }
  int thread_id(void) { return syscall(__NR_gettid); }
  /* operators */
  threadable(const threadable&& other) : thread_run_(other.thread_run_),
                                         thread_(other.thread_),
                                         arg_(other.arg_) {}

 private:
  /* non-member functions */
  static void* entry_point(void* this_p) {
    threadable* pt = static_cast<threadable*>(this_p);
    return pt->thread_main(pt->arg_);
  } /* entry_point() */

  /* operators */
  const threadable& operator=(const threadable& rhs) = delete;
  threadable(const threadable& other) = delete;

  /* data members */
  bool thread_run_;
  pthread_t thread_;
  void *arg_;
};

} /* namespace rcppsw */

/*******************************************************************************
 * Operater Definitions
 ******************************************************************************/

#endif /* INCLUDE_RCPPSW_THREADABLE_HPP_ */
