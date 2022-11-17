/**
 * \file angles.cpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/math/angles.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
degrees to_degrees(const radians& r) {
  return degrees(r.v() * radians::kRADIANS_TO_DEGREES);
} /* to_degrees() */

/**
 * \brief Converts \ref degrees to \ref radians
 */
radians to_radians(const degrees& d) {
  return radians(d.v() * degrees::kDEGREES_TO_RADIANS);
} /* to_radians() */

radians normalized_diff(const radians& angle1, const radians& angle2) {
  radians res;
  res.set(std::fmod(angle1.v() - angle2.v() + radians::kPI.v(),
                    radians::kTWO_PI.v()));
  if (res.v() < 0.0) {
    res += radians::kTWO_PI;
  }
  res -= radians::kPI;
  return res;
} /* normalized_diff() */

degrees normalized_diff(const degrees& angle1, const degrees& angle2) {
  degrees res;
  res.set(std::fmod(angle1.v() - angle2.v() + 180.0, 360.0));

  if (res.v() < 0.0) {
    res += 360.0;
  }
  res -= 180.0;
  return res;
} /* normalized_diff() */

NS_END(math, rcppsw);
