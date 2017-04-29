/*******************************************************************************
 * Name            : forkable.hpp
 * Project         : rcppsw
 * Module          : utils
 * Description     : Common threading functionality
 * Creation Date   : 07/18/15
 * Copyright       : Copyright 2015 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_FORKABLE_HPP_
#define INCLUDE_RCPPSW_FORKABLE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <sys/wait.h>
#include <unistd.h>
#include <string>
#include <thread>
#include <vector>
#include "rcsw/common/common.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class forkable {
 public:
  /* member functions */
  forkable(void) : proc_run_(false), pid_(0) {}
  virtual ~forkable(void) {}
  pid_t pid(void) { return pid_; }

  /**
   * @brief Start a process.
   *
   * @param core The core to bind the process (and any threads it might spawn)
   * to. By default, no binding.
   *
   * @return PID of child process in parent
   */
  virtual pid_t start(int core = -1);

  /**
   * @brief Start a process in a new directory.
   * @param core The core to bind the process (and any threads it might spawn)
   * to. By default, no binding.
   *
   * @return PID of child process in parent
   */
  virtual pid_t start(const std::string& new_wd, int core = -1);


  /**
   * @brief Signal a process that it should terminate, from outside the process.
   */
  virtual void term(void) { proc_run_ = false; }

  /**
   * @brief Entry point for the new process.
   */
  virtual void proc_main(void) = 0;

 protected:
  /**
   * @brief Check if a process object has been told to terminate elsewhere.
   */
  bool terminated(void) { return (false == proc_run_); }

 private:
  /* data members */
  bool proc_run_;
  pid_t pid_;

  /* non-member functions */
  static void entry_point(void* this_p) {
    forkable* pt = static_cast<forkable*>(this_p);
    pt->proc_main();
  } /* entry_point() */
};

} /* namespace rcppsw */

#endif /* INCLUDE_RCPPSW_FORKABLE_HPP_ */
