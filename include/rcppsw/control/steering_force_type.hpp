/**
 * @file steering_force_type.hpp
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

#ifndef INCLUDE_RCPPSW_CONTROL_STEERING_FORCE_TYPE_HPP_
#define INCLUDE_RCPPSW_CONTROL_STEERING_FORCE_TYPE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief List of steering forces available within the class
 */
class steering_force_type {
 public:
  enum {
  kSeekThrough,  /// Move to and drive through a target
  kSeekTo,       /// Move to and stop at a target
  /**
   * Wander randomly through the environment, changing direction
   * minutely each timestep
   */
  kWander,
  kAvoidance,  /// Obstacle avoidance
  /**
   * Apply a constant force radiating from a fixed point in space. Can be used
   * to generate arcing trajectories from linear ones under certain
   * conditions, such as starting from a stopped entities and using one of the
   * seek forces.
   */
  kPolar,
  kExternalForces  /// Application defined forces start here
  };
};

NS_END(control, rcppsw);

#endif /* INCLUDE_RCPPSW_CONTROL_STEERING_FORCE_TYPE_HPP_ */
