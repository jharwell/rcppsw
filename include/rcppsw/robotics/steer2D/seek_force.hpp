/**
 * @file seek_force.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_STEER2D_SEEK_FORCE_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_STEER2D_SEEK_FORCE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"
#include "rcppsw/robotics/steer2D/boid.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, steer2D);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @class seek_force
 * @ingroup rcppsw robotics steer2D
 *
 * @brief A force pulling the robot to a target and then through the target
 * (i.e. the robot does not slow down to "arrive").
 */
class seek_force {
 public:
  seek_force(void) = default;

  math::vector2d operator()(const boid& entity,
                            const math::vector2d& target) const;
};

NS_END(steer2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_STEER2D_SEEK_FORCE_HPP_ */