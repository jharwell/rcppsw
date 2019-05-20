/**
 * @file boid.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_STEER2D_BOID_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_STEER2D_BOID_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"
#include "rcppsw/math/vector2.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, steer2D);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class boid
 * @ingroup rcppsw robotics steer2D
 *
 * @brief Interface representing an entity upon which kinematic forces can act
 * (i.e. any class that wants to use the \ref force_calculator must conform to
 * this interface).
 */
class boid {
 public:
  boid(void) = default;
  virtual ~boid(void) = default;

  /**
   * @brief Should return the current linear velocity of the entity.
   */
  virtual math::vector2d linear_velocity(void) const = 0;

  /**
   * @brief Should return the current angular velocity of the entity.
   */
  virtual double angular_velocity(void) const = 0;

  /**
   * @brief Should return the maximum speed of the entity. This can vary in
   * time, if desired.
   */
  virtual double max_speed(void) const = 0;

  /**
   * @brief Return the current position of the entity. Hopefully, this DOES vary
   * with time otherwise your entity is very uninteresting.
   */
  virtual math::vector2d position(void) const = 0;
};

NS_END(steer2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_STEER2D_BOID_HPP_ */
