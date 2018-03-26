/**
 * @file wander_force.hpp
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

#ifndef INCLUDE_RCPPSW_CONTROL_WANDER_FORCE_HPP_
#define INCLUDE_RCPPSW_CONTROL_WANDER_FORCE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <argos3/core/utility/math/angles.h>

#include "rcppsw/common/common.hpp"
#include "rcppsw/control/boid.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, control);
struct wander_force_params;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @class wander_force
 * @ingroup control
 *
 * @brief A small random perturbation that can be added to a robot's current
 * velocity in order to make it move randomly throughout the environment
 */
class wander_force {
 public:
  explicit wander_force(const struct wander_force_params* params);

  argos::CVector2 operator()(const boid& entity);

 private:
  // clang-format off
  double          m_circle_distance;
  double          m_circle_radius;
  argos::CRadians m_angle{};
  double          m_max_angle_delta;
  // clang-format on
};

NS_END(control, rcppsw);

#endif /* INCLUDE_RCPPSW_CONTROL_WANDER_FORCE_HPP_ */
