/**
 * \file radians.cpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
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
RCPPSW_WARNING_DISABLE_PUSH()
RCPPSW_WARNING_DISABLE_GLOBAL_CTOR()

const radians radians::kPI(M_PI); // NOLINT
const radians radians::kTHREE_PI_OVER_TWO(M_PI * 3.0 / 2.0); // NOLINT
const radians radians::kTWO_PI(M_PI * 2.0); // NOLINT
const radians radians::kPI_OVER_TWO(M_PI / 2.0); // NOLINT
const radians radians::kPI_OVER_THREE(M_PI / 3.0); // NOLINT
const radians radians::kPI_OVER_FOUR(M_PI / 4.0); // NOLINT
const radians radians::kZERO(0.0); // NOLINT
const rmath::range<radians> kUNIT_CIRCLE(radians::kZERO,
                                         radians::kTWO_PI); // NOLINT

RCPPSW_WARNING_DISABLE_POP()

const double radians::kRADIANS_TO_DEGREES(180.0 / M_PI); // NOLINT

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
radians::radians(const degrees& d) : m_value(to_radians(d).v()) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
std::string radians::to_str(void) const {
  return "rad(" + rcppsw::to_string(m_value) + ") -> deg(" +
         rcppsw::to_string(m_value * radians::kRADIANS_TO_DEGREES) + ")";
}

/*******************************************************************************
 * Operators Functions
 ******************************************************************************/
std::ostream& operator<<(std::ostream& stream, const radians& r) {
  stream << r.to_str();
  return stream;
} /* operator<<() */

rmath::radians operator*(double lhs, const rmath::radians& rhs) {
  return rhs * lhs;
} /* operator*() */

NS_END(math, rcppsw);
