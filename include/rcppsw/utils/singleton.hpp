/*******************************************************************************
 * Name            : singleton.hpp
 * Project         : rcppsw
 * Module          : common
 * Description     : Singleton design pattern implementation
 * Creation Date   : 06/26/15
 * Copyright       : Copyright 2015 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_SINGLETON_HPP_
#define INCLUDE_RCPPSW_SINGLETON_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stddef.h>  // defines NULL

/*******************************************************************************
 * Namespace Definitions
 ******************************************************************************/

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template <class T>
class singleton {
 public:
  static T& instance() {
    static T inst;
    return inst;
  }

 protected:
  /* constructor */
  singleton(void) {}

  /* destructor */
  ~singleton(void) {}

 private:
  singleton(singleton const&) = delete;
  singleton& operator=(singleton const&) = delete;
};

#endif /* INCLUDE_RCPPSW_SINGLETON_HPP_ */
