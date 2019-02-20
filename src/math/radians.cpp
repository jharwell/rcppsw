/**
 * @file radians.cpp
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
#include "rcppsw/math/radians.hpp"
#include <iostream>
#include "rcppsw/math/angles.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Class Constants
 ******************************************************************************/
/* These are just mathematical constants, so global constructors are OK */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
const radians radians::kPI(M_PI);
const radians radians::kTWO_PI(M_PI * 2.0);
const radians radians::kPI_OVER_THREE(M_PI / 3.0);
const radians radians::kPI_OVER_FOUR(M_PI / 4.0);
const radians radians::kZERO(0.0);

const double radians::kRADIANS_TO_DEGREES(180.0 / M_PI);
const range<radians> radians::kSignedRange(-radians(M_PI), radians(M_PI));
const range<radians> radians::kUnsignedRange(radians(0), radians(2 * M_PI));
#pragma clang diagnostic pop

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
radians::radians(const degrees& r) : m_value(to_radians(r).value()) {}

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
std::ostream& operator<<(std::ostream& stream, const radians& r) {
  stream << "radians(" << r.value() << " -> "
         << r.value() * radians::kRADIANS_TO_DEGREES << " degrees"
         << ")";
  return stream;
} /* operator<<() */

NS_END(math, rcppsw);
