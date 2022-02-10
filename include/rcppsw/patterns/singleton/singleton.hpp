/**
 * \file singleton.hpp
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

