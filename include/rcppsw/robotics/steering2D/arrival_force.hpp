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

#ifndef INCLUDE_RCPPSW_ROBOTICS_STEERING2D_ARRIVAL_FORCE_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_STEERING2D_ARRIVAL_FORCE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"
#include "rcppsw/robotics/steering2D/boid.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, steering2D);
struct arrival_force_params;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @class arrival_force
 * @ingroup robotics steering2D
 *
 * @brief A force pulling the robot to a target (i.e. the robot DOES slow down
 * to "arrive").
 */
class arrival_force {
 public:
  explicit arrival_force(const struct arrival_force_params* params);

  argos::CVector2 operator()(const boid& entity, const argos::CVector2& target);
  bool within_slowing_radius(void) const { return m_within_slowing_radius; }

 private:
  bool   m_within_slowing_radius{false};
  double m_max;
  double m_slowing_speed_min;
  double m_slowing_radius;
};

NS_END(steering2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_STEERING2D_ARRIVAL_FORCE_HPP_ */
