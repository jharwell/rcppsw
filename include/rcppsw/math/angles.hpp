/**
 * \file angles.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

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

