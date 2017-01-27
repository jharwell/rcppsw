/*******************************************************************************
 * Name            : singleton.hpp
 * Project         : rcppsw
 * Module          : rcppsw
 * Description     : Singleton design pattern implementation
 * Creation Date   : Fri Jun 26 10:56:54 2015
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef INCLUDE_SINGLETON_HPP_
#define INCLUDE_SINGLETON_HPP_

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
template <class T> class singleton
{
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

#endif /* INCLUDE_SINGLETON_HPP_ */
