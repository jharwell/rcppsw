/**
 * \file angles.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_MATH_ANGLES_HPP_
#define INCLUDE_RCPPSW_MATH_ANGLES_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcsw/common/compilers.h"

#include "rcppsw/math/degrees.hpp"
#include "rcppsw/math/radians.hpp"
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Free Functions
 ******************************************************************************/
/**
 * \brief Converts \ref radians to \ref degrees,
 */
degrees to_degrees(const radians& r) RCPPSW_PURE;

/**
 * \brief Converts \ref degrees to \ref radians.
 */
radians to_radians(const degrees& d) RCPPSW_PURE;

/**
 * \brief Calculates the normalized difference between the given angles.
 *
 * The difference is calculated as (angle1 - angle2) and then normalized
 * in [-pi,pi].
 *
 * \return The difference between the two angles.
 */
radians normalized_diff(const radians& angle1, const radians& angle2);

/**
 * \brief Calculates the normalized difference between the given angles.
 *
 * The difference is calculated as (angle1 - angle2) and then normalized
 * in [-180,180].
 *
 * \return The difference between the two angles.
 */
degrees normalized_diff(const degrees& angle1, const degrees& angle2);

/**
 * \brief Calculate the absolute value of a \ref radians or \ref degrees
 * value. This does not perform any wrapping/normalizing.
 */
template<typename TAngleType>
 TAngleType abs(const TAngleType& angle) {
  return TAngleType(std::fabs(angle.v()));
}

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_ANGLES_HPP_ */
