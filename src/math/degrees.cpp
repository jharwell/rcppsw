/**
 * @file degrees.cpp
 *
 * @copyright 2018 John Harwell, All rights reserved.
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/math/degrees.hpp"
#include <iostream>
#include "rcppsw/math/angles.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Class Constants
 ******************************************************************************/
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
const range<degrees> degrees::kSignedRange(degrees(-180.0), degrees(180.0));
const range<degrees> degrees::kUnsignedRange(degrees(0.0), degrees(360.0));
const double degrees::kDEGREES_TO_RADIANS(M_PI / 180.0);
#pragma clang diagnostic pop

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
degrees::degrees(const radians& r) : m_value(to_degrees(r).value()) {}

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
std::ostream& operator<<(std::ostream& stream, const degrees& d) {
  stream << d.to_str();
  return stream;
} /* operator<<() */

NS_END(math, rcppsw);
