/**
 * \file stringizable.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_ER_STRINGIZABLE_HPP_
#define INCLUDE_RCPPSW_ER_STRINGIZABLE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, er);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class stringizable
 * \ingroup er
 *
 * Interface for converting classes to string representations.
 */
class stringizable {
 public:
  stringizable(void) = default;
  virtual ~stringizable(void) = default;

  /**
   * \brief Return a string representation of a class.
   */
  virtual std::string to_str(void) const { return "to_str() not defined"; }
};

NS_END(er, rcppsw);

#endif /* INCLUDE_RCPPSW_ER_STRINGIZABLE_HPP_ */
