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
#include "rcppsw/control/avoidance_force.hpp"
#include "rcppsw/control/avoidance_force_params.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
avoidance_force::avoidance_force(const struct avoidance_force_params* params)
    : m_lookahead(params->lookahead), m_max(params->max) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
argos::CVector2 avoidance_force::operator()(
    const boid& b,
    bool obs_threat,
    const argos::CVector2& closest_obstacle) {
  argos::CVector2 ahead = b.position() + b.velocity().Normalize() * m_lookahead;
  if (obs_threat) {
    return (ahead - closest_obstacle).Normalize() * m_max;
  } else {
    return argos::CVector2(0, 0); /* no threatening obstacles = no avoidance */
  }
} /* operator()() */

NS_END(control, rcppsw);
