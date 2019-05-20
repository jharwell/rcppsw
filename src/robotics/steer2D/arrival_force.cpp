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
#include "rcppsw/robotics/steer2D/arrival_force.hpp"
#include "rcppsw/robotics/steer2D/config/arrival_force_config.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, steer2D);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
arrival_force::arrival_force(const config::arrival_force_config* const config)
    : mc_max(config->max),
      mc_slowing_speed_min(config->slowing_speed_min),
      mc_slowing_radius(config->slowing_radius) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
math::vector2d arrival_force::operator()(const boid& entity,
                                         const math::vector2d& target) {
  math::vector2d desired = target - entity.position();
  double distance = desired.length();

  desired.normalize();
  if (distance <= mc_slowing_radius) {
    m_within_slowing_radius = true;
    desired.scale(
        std::max(mc_slowing_speed_min, mc_max * distance / mc_slowing_radius));
  } else {
    m_within_slowing_radius = false;
    desired.scale(mc_max);
  }
  /*
   * Handle atan2() being discontinuous at angles ~pi.
   */
  double angle_to_target = std::atan2(target.y() - entity.position().y(),
                                      target.x() - entity.position().x());
  double angle_diff = angle_to_target - entity.linear_velocity().angle().value();
  angle_diff = std::atan2(std::sin(angle_diff), std::cos(angle_diff));

  if (std::fabs(angle_diff - m_last_angle) > M_PI) {
    angle_diff -= std::copysign(2 * M_PI, angle_diff);
  }
  m_last_angle = angle_diff;
  math::vector2d arrival(desired.length(), angle_diff);
  return arrival;
} /* operator()() */

NS_END(steer2D, robotics, rcppsw);
