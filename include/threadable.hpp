/*******************************************************************************
 * Name            : threadable.hpp
 * Project         : rcppsw
 * Module          : utils
 * Description     : Common threading functionality
 * Creation Date   : Sat Jul 18 14:33:49 2015
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef THREADABLE_HPP_
#define THREADABLE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/al/altypes.h"
#include <thread>

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
  static void entry_point(void* this_p) { threadable *pt = static_cast<threadable*>(this_p); pt->thread_main(); }
  /* operators */
};

} /* namespace rcppsw */

/*******************************************************************************
 * Operater Definitions
 ******************************************************************************/

#endif /* THREADABLE_HPP_ */
