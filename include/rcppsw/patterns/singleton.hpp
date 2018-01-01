/**
 * @file singleton.hpp
 * @defgroup patterns
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
#ifndef INCLUDE_RCPPSW_PATTERNS_SINGLETON_HPP_
#define INCLUDE_RCPPSW_PATTERNS_SINGLETON_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class singleton
 *
 * @brief Define a class as in capable of being moved, copied, etc., and that
 * their can only ever be one of them.
 */
template <class T>
class singleton {
 public:
  static T& instance() {
    static T inst;
    return inst;
  }

  singleton(singleton const&) = delete;
  singleton& operator=(singleton const&) = delete;
  singleton(singleton&& other) = delete;
  singleton& operator=(singleton&& other) = delete;

 protected:
  singleton(void) = default;
  ~singleton(void) = default;
};

NS_END(patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_SINGLETON_HPP_ */
