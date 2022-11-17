/**
 * \file singleton.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, singleton);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class singleton
 * \ingroup patterns singleton
 *
 * \brief Define a class as incapable of being moved, copied, etc., and that
 * there can only ever be one of. The only restriction on derived classes is
 * that the must have a zero parameter constructor available.
 */
template <class T>
class singleton {
 public:

  /**
   * \brief Get the instance of the singleton
   */
  static T& instance() {
    static T inst;
    return inst;
  }

  singleton(singleton const&) = delete;
  singleton& operator=(singleton const&) = delete;
  singleton(singleton&&) = delete;
  singleton& operator=(singleton&&) = delete;

 protected:
  singleton(void) = default;
  ~singleton(void) = default;
};

NS_END(singleton, patterns, rcppsw);

