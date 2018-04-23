/**
 * @file avoidance_force.cpp
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/robotics/steering2D/avoidance_force.hpp"
#include "rcppsw/robotics/steering2D/avoidance_force_params.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, steering2D);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
avoidance_force::avoidance_force(const struct avoidance_force_params* params)
    : m_lookahead(params->lookahead), m_max(params->max) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
argos::CVector2 avoidance_force::operator()(
    __unused const boid& b,
    const argos::CVector2& closest_obstacle) const {
  if (closest_obstacle.Length() > 0) {
    argos::CVector2 avoidance = -closest_obstacle;
    return avoidance.Normalize() * m_max;
  } else {
    return {0, 0}; /* no threatening obstacles = no avoidance */
  }
} /* operator()() */

NS_END(steering2D, robotics, rcppsw);
