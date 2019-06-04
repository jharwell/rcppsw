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
#include "rcppsw/robotics/steer2D/force_calculator.hpp"
#include "rcppsw/robotics/steer2D/config/force_calculator_config.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, steer2D);

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
force_calculator::force_calculator(boid& entity,
                                   const config::force_calculator_config* config)
    : ER_CLIENT_INIT("rcppsw.robotics.steer2D.force_calculate"),
      m_entity(entity),
      m_avoidance(&config->avoidance),
      m_arrival(&config->arrival),
      m_wander(&config->wander),
      m_polar(&config->polar),
      m_phototaxis(&config->phototaxis){}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
kin::twist force_calculator::to_twist(const math::vector2d& force) const {
  kin::twist twist;
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

void force_calculator::seek_through(const math::vector2d& target) {
  math::vector2d force = m_seek(m_entity, target);
  ER_DEBUG("Seek force: (%f, %f)@%f [%f]",
           force.x(),
           force.y(),
           force.angle().value(),
           force.length());
  accum_force(force);
} /* seek_through() */

void force_calculator::seek_to(const math::vector2d& target) {
  math::vector2d force = m_arrival(m_entity, target);
  ER_DEBUG("Arrival force: (%f, %f)@%f [%f]",
           force.x(),
           force.y(),
           force.angle().value(),
           force.length());
  accum_force(force);
} /* seek_to() */

void force_calculator::wander(void) {
  math::vector2d force = m_wander(m_entity);
  ER_DEBUG("Wander force: (%f, %f)@%f [%f]",
           force.x(),
           force.y(),
           force.angle().value(),
           force.length());
  accum_force(force);
} /* wander() */

void force_calculator::avoidance(const math::vector2d& closest_obstacle) {
  math::vector2d force = m_avoidance(m_entity, closest_obstacle);
  ER_DEBUG("Avoidance force: (%f, %f)@%f [%f]",
           force.x(),
           force.y(),
           force.angle().value(),
           force.length());
  accum_force(force);
} /* avoidance() */

void force_calculator::phototaxis(
    const phototaxis_force::light_sensor_readings& readings) {
  math::vector2d force = m_phototaxis(readings);
  ER_DEBUG("Phototaxis force: (%f, %f)@%f [%f]",
           force.x(),
           force.y(),
           force.angle().value(),
           force.length());
  accum_force(force);
} /* phototaxis() */

void force_calculator::phototaxis(
    const phototaxis_force::camera_sensor_readings& readings,
    const utils::color& color) {
  math::vector2d force = m_phototaxis(readings, color);
  ER_DEBUG("Phototaxis force: (%f, %f)@%f [%f]",
           force.x(),
           force.y(),
           force.angle().value(),
           force.length());
  accum_force(force);
} /* phototaxis() */

void force_calculator::anti_phototaxis(
    const phototaxis_force::light_sensor_readings& readings) {
  math::vector2d force = -m_phototaxis(readings);
  ER_DEBUG("Anti-phototaxis force: (%f, %f)@%f [%f]",
           force.x(),
           force.y(),
           force.angle().value(),
           force.length());
  accum_force(force);
} /* anti_phototaxis() */

void force_calculator::anti_phototaxis(
    const phototaxis_force::camera_sensor_readings& readings,
    const utils::color& color) {
  math::vector2d force = -m_phototaxis(readings, color);
  ER_DEBUG("Anti-phototaxis force: (%f, %f)@%f [%f]",
           force.x(),
           force.y(),
           force.angle().value(),
           force.length());
  accum_force(force);
} /* anti_phototaxis() */

NS_END(steer2D, robotics, rcppsw);
