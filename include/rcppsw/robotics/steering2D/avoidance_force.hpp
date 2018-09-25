/**
 * @file avoidance_force.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_STEERING2D_AVOIDANCE_FORCE_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_STEERING2D_AVOIDANCE_FORCE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"
#include "rcppsw/robotics/steering2D/boid.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, steering2D);
struct avoidance_force_params;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @class avoidance_force
 * @ingroup robotics steering2D
 *
 * @brief A force pushing the robot away from perceived obstacles. Only active
 * when threatening obstacles are detected.
 */
class avoidance_force {
 public:
  explicit avoidance_force(const struct avoidance_force_params* params);

  argos::CVector2 operator()(const boid&,
                             const argos::CVector2& closest_obstacle) const;

 private:
  // clang-format off
  double m_max;
  // clang-format on
};

NS_END(steering2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_STEERING2D_AVOIDANCE_FORCE_HPP_ */
