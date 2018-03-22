/**
 * @file wander_force.cpp
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
#include "rcppsw/control/wander_force.hpp"
#include "rcppsw/control/force_params.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
wander_force::wander_force(const struct wander_force_params* const params)
    : m_circle_distance(params->circle_distance),
      m_circle_radius(params->circle_radius),
      m_angle(params->angle),
      m_angle_delta(params->angle_delta) {}


/*******************************************************************************
 * Member Functions
 ******************************************************************************/
argos::CVector2 wander_force::operator()(const boid& entity) {
  /* calculate circle center */
  argos::CVector2 circle_center = entity.position().Normalize().Scale(m_circle_distance,
                                                                 m_circle_radius);

  /* calculate displacement force */
  argos::CVector2 displacement(m_circle_radius, m_angle);

  /* update wander angle so it won't have the same value next time */
  m_angle += argos::CRadians(random() * m_angle_delta - m_angle_delta * 0.5);

  return circle_center + displacement;
} /* operator()() */

NS_END(control, rcppsw);
