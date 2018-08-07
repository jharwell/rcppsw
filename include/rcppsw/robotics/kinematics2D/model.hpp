/**
 * @file model.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_KINEMATICS2D_MODEL_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_KINEMATICS2D_MODEL_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <argos3/core/utility/math/vector2.h>
#include "rcppsw/common/common.hpp"
#include "rcppsw/robotics/kinematics/twist.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, kinematics2D);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @class model
 * @ingroup robotics kinematics2D
 *
 * @brief Interface that all 2D kinematics models need to fulfill in order to be
 * used in other components of this module.
 */
class model {
 public:
  model(void) = default;
  virtual ~model(void) = default;

  /**
   * @brief Given a calculated twist acting on the robot, perform actuation
   * (i.e. make the robot move).
   *
   * @param twist The calculated twist.
   *
   * @return \ref status_t.
   */
  virtual status_t actuate(const kinematics::twist& twist) = 0;

  /**
   * @brief Stop the robot.
   */
  virtual void stop(void) = 0;

  /**
   * @brief Get the maximum linear speed of the robot.
   */
  virtual double max_speed(void) const = 0;
};

NS_END(kinematics2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_KINEMATICS2D_MODEL_HPP_ */
