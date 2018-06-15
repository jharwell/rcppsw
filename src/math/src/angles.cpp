/**
 * @file angles.cpp
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
#include "rcppsw/math/angles.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
degrees to_degrees(const radians& r) {
  return degrees(r.value() * radians::kRADIANS_TO_DEGREES);
} /* to_degrees() */

/**
 * @brief Converts \ref degrees to \ref radians
 */
radians to_radians(const degrees& d) {
  return radians(d.value() * degrees::kDEGREES_TO_RADIANS);
} /* to_radians() */

radians normalized_diff(const radians& angle1, const radians& angle2) {
  radians res;
  res.set(std::fmod(angle1.value() - angle2.value() + radians::kPI.value(),
                    radians::kTWO_PI.value()));
  if (res.value() < 0.0) {
    res += radians::kTWO_PI;
  }
  res -= radians::kPI;
  return res;
} /* normalized_diff() */

degrees normalized_diff(const degrees& angle1, const degrees& angle2) {
  degrees res;
  res.set(std::fmod(angle1.value() - angle2.value() + 180.0f, 360.0f));

  if (res.value() < 0.0f) {
    res += 360.0;
  }
  res -= 180.0;
  return res;
} /* normalized_diff() */

NS_END(math, rcppsw);
