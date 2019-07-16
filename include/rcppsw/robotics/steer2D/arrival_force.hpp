/**
 * @file arrival_force.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_STEER2D_ARRIVAL_FORCE_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_STEER2D_ARRIVAL_FORCE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"
#include "rcppsw/robotics/steer2D/boid.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, steer2D);
namespace config {
struct arrival_force_config;
} /* namespace config */

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @class arrival_force
 * @ingroup rcppsw robotics steer2D
 *
 * @brief A force pulling the robot to a target (i.e. the robot DOES slow down
 * to "arrive"). Once the robot comes within range of the slowing radius, its
 * speed is ramped down linearly from its current speed to the specified minimal
 * slowing speed.
 */
class arrival_force {
 public:
  explicit arrival_force(const config::arrival_force_config* config);

  math::vector2d operator()(const boid& entity, const math::vector2d& target);
  bool within_slowing_radius(void) const { return m_within_slowing_radius; }

 private:
  /* clang-format off */
  const double mc_max;
  const double mc_slowing_speed_min;
  const double mc_slowing_radius;

  bool         m_within_slowing_radius{false};
  /* clang-format on */
};

NS_END(steer2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_STEER2D_ARRIVAL_FORCE_HPP_ */
