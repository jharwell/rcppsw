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
#include "rcppsw/robotics/steering2D/wander_force.hpp"
#include "rcppsw/robotics/steering2D/wander_force_params.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, steering2D);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
wander_force::wander_force(const struct wander_force_params* const params)
    : m_circle_distance(params->circle_distance),
      m_circle_radius(params->circle_radius),
      m_angle(0),
      m_max_angle_delta(params->max_angle_delta) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
argos::CVector2 wander_force::operator()(const boid& entity) {
  /* calculate circle center */
    argos::CVector2 velocity;
  if (entity.linear_velocity().Length() <= 0) {
    velocity = argos::CVector2(1, 0);
  } else {
    velocity = entity.linear_velocity();
  }
  std::cout << "velocity: "<< velocity << std::endl;
  std::cout << "angle: " << m_angle << std::endl;
  argos::CVector2 circle_center =
      (velocity).Normalize().Scale(m_circle_distance, m_circle_distance);

  /* calculate displacement force */
  argos::CVector2 displacement(0, m_circle_radius);
  double angle_tmp = std::atan2(std::cos(m_angle.GetValue()),
                                std::sin(m_angle.GetValue()));
  displacement.SetX(displacement.Length() * std::cos(angle_tmp));
  displacement.SetY(displacement.Length() * std::sin(angle_tmp));

  /* update wander angle so it won't have the same value next time */
  double val = -m_max_angle_delta + (random() / (RAND_MAX / (2 * m_max_angle_delta)));
  std::cout << "displacement: "<< displacement << std::endl;
  std::cout << "circle_center: "<< circle_center << std::endl;
  argos::CRadians update(val * M_PI/180);

  m_angle += update;
  return (circle_center + displacement);
} /* operator()() */

NS_END(steering2D, robotics, rcppsw);
