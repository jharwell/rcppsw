/**
 * @file clonable.hpp
 * @ingroup patterns prototype
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

#ifndef INCLUDE_RCPPSW_PATTERNS_PROTOTYPE_CLONABLE_HPP_
#define INCLUDE_RCPPSW_PATTERNS_PROTOTYPE_CLONABLE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, prototype);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class clonable
 *
 * @brief Define a class as being capable of being cloned (i.e. a deep copy).
 */
template<typename T>
class clonable {
 public:
  clonable(void) {}
  virtual ~clonable(void) {}

  /**
   * @brief Clone the calling object, transfering ownership of the copy
   * explicitly to the calling context.
   */
  virtual std::unique_ptr<T> clone(void) const = 0;
};

NS_END(rcppsw, patterns, prototype);

#endif /* INCLUDE_RCPPSW_PATTERNS_PROTOTYPE_CLONABLE_HPP_ */
