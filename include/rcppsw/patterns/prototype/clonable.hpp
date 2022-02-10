/**
 * \file clonable.hpp
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
#include <memory>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, prototype);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class clonable
 * \ingroup patterns prototype
 *
 * \brief Define a class as being capable of being cloned (i.e. a deep copy). I
 * generally prefer this approach when copying objects, because it is explicit
 * and not subject to compiler/language standards around operator=(), AND
 * because the use of std::unique_ptr makes it clear the returned object has
 * nothing to do with the source object.
 *
 * \tparam T The type of the class to mark as clonable.
 */
template<typename T>
class clonable {
 public:
  clonable(void) = default;
  virtual ~clonable(void) = default;
  clonable(const clonable&) = default;
  clonable& operator=(const clonable&) = default;

  /**
   * \brief Clone the calling object, transfering ownership of the copy
   * explicitly to the calling context.
   */
  virtual std::unique_ptr<T> clone(void) const = 0;
};

NS_END(rcppsw, patterns, prototype);

