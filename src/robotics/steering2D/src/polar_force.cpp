/**
 * @file polar_force.cpp
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
#include "rcppsw/robotics/steering2D/polar_force.hpp"
#include "rcppsw/robotics/steering2D/polar_force_params.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, steering2D);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
polar_force::polar_force(const struct polar_force_params* const params)
    : m_max(params->max) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
argos::CVector2 polar_force::operator()(const boid& entity,
                                        const argos::CVector2& source) const {
  return (entity.position() - source).Normalize() * m_max;
} /* operator()() */

NS_END(steering2D, robotics, rcppsw);
