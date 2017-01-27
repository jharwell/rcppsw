/*******************************************************************************
 * Name            : threadable.hpp
 * Project         : rcppsw
 * Module          : multithread
 * Description     : Common threading functionality
 * Creation Date   : 06/18/15
 * Copyright       : Copyright 2015 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_THREADABLE_HPP_
#define INCLUDE_THREADABLE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <thread>
#include "include/al/altypes.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class threadable
{
 public:
  /* data members */

  /* member functions */
  threadable(void) : thread_run(false),
                     internal_thread() {}
  virtual ~threadable(void) {}

  virtual void start(
      int core = -1);

  virtual void term(void)
  {
    thread_run = false;
    internal_thread.join();
  }
  bool terminated(void) { return (false == thread_run); }
  virtual void join(void) { internal_thread.join(); }
  virtual void thread_main(void) = 0;
  status_t thread_core_lock(
      pthread_t thread,
      int core);

 protected:
  pthread_t thread_handle(void) { return internal_thread.native_handle(); }

 private:
  /* data members */
  bool thread_run;
  std::thread internal_thread;

  /* non-member functions */
  static void entry_point(void* this_p) {
    threadable *pt = static_cast<threadable*>(this_p);
    pt->thread_main();
  } /* entry_point() */
  /* operators */
};

} /* namespace rcppsw */

/*******************************************************************************
 * Operater Definitions
 ******************************************************************************/

#endif /* INCLUDE_THREADABLE_HPP_ */
