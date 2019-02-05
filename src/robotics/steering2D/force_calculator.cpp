/**
 * @file force_calculator.cpp
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
#include "rcppsw/robotics/steering2D/force_calculator.hpp"
#include "rcppsw/robotics/steering2D/force_calculator_params.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, steering2D);

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
force_calculator::force_calculator(boid &entity,
                                   const struct force_calculator_params *params)
    : ER_CLIENT_INIT("rcppsw.robotics.steering2D.force_calculate"),
      m_entity(entity), m_avoidance_force(&params->avoidance),
      m_arrival_force(&params->arrival), m_wander_force(&params->wander),
      m_polar_force(&params->polar) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
kinematics::twist
force_calculator::to_twist(const math::vector2d &force) const {
  kinematics::twist twist;
  twist.linear.x = force.length();
  twist.angular.z =
      (force - m_entity.linear_velocity()).length() *
      std::sin((force - m_entity.linear_velocity()).angle().value());
  if (m_entity.linear_velocity().length() > 0) {
    twist.angular.z /= m_entity.linear_velocity().length();
  } else {
    twist.angular.z = 0;
  }
  return twist;
} /* to_twist() */

void force_calculator::seek_through(const math::vector2d &target) {
  math::vector2d force = m_seek_force(m_entity, target);
  ER_DEBUG("Seek force: (%f, %f)@%f [%f]", force.x(), force.y(),
           force.angle().value(), force.length());
  accum_force(force);
} /* seek_through() */

void force_calculator::seek_to(const math::vector2d &target) {
  math::vector2d force = m_arrival_force(m_entity, target);
  ER_DEBUG("Arrival force: (%f, %f)@%f [%f]", force.x(), force.y(),
           force.angle().value(), force.length());
  accum_force(force);
} /* seek_to() */

void force_calculator::wander(void) {
  math::vector2d force = m_wander_force(m_entity);
  ER_DEBUG("Wander force: (%f, %f)@%f [%f]", force.x(), force.y(),
           force.angle().value(), force.length());
  accum_force(force);
} /* wander() */

void force_calculator::avoidance(const math::vector2d &closest_obstacle) {
  math::vector2d force = m_avoidance_force(m_entity, closest_obstacle);
  ER_DEBUG("Avoidance force: (%f, %f)@%f [%f]", force.x(), force.y(),
           force.angle().value(), force.length());
  accum_force(force);
} /* avoidance() */

NS_END(steering2D, robotics, rcppsw);
