/*******************************************************************************
 * Name            : forkable.hpp
 * Project         : rcppsw
 * Module          : utils
 * Description     : Common threading functionality
 * Creation Date   : 07/18/15
 * Copyright       : Copyright 2015 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_FORKABLE_HPP_
#define INCLUDE_FORKABLE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <sys/wait.h>
#include <unistd.h>
#include <string>
#include <thread>
#include <vector>
#include "rcsw/include/al/altypes.h"

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
  virtual pid_t start(int core = -1);

  virtual pid_t start(const std::string& new_wd, int core = -1);

  virtual void term(void) { proc_run_ = false; }
  bool terminated(void) { return (false == proc_run_); }
  virtual void proc_main(void) = 0;

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

/*******************************************************************************
 * Non-member Functions
 ******************************************************************************/
pid_t fork_exec(const std::vector<std::string>& cmd, const std::string& new_wd,
                bool stdout_sup, int* pipefd);
status_t proc_socket_lock(int core);

#endif /* INCLUDE_FORKABLE_HPP_ */
