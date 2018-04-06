/**
 * @file arrival_force.cpp
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
#include "rcppsw/robotics/steering2D/arrival_force.hpp"
#include "rcppsw/robotics/steering2D/arrival_force_params.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, steering2D);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
arrival_force::arrival_force(const struct arrival_force_params* const params)
    : m_slowing_radius(params->slowing_radius) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
argos::CVector2 arrival_force::operator()(const boid& entity,
                                          const argos::CVector2& target) {
  argos::CVector2 desired = target - entity.position();
  double distance = desired.Length();

  desired.Normalize();
  if (distance <= m_slowing_radius) {
    desired.Scale(entity.max_speed() * distance / m_slowing_radius,
                  entity.max_speed() * distance / m_slowing_radius);
  } else {
    desired.Scale(entity.max_speed(), entity.max_speed());
  }
  return desired - entity.velocity();
} /* operator()() */

NS_END(steering2D, robotics, rcppsw);
