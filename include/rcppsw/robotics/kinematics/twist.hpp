/**
 * @file twist.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_KINEMATICS_TWIST_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_KINEMATICS_TWIST_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, kinematics);

/*******************************************************************************
 * Struct Definitions
 ******************************************************************************/

/**
 * @struct twist
 * @ingroup robotics kinematics
 *
 * @brief Representation of the twist of a  robot. ROS already has this, but
 * does not work with all robotic simulators (such as ARGoS)/models, hence the
 * need for me to implement this.
 */
struct twist {
  struct {
    double x{};
    double y{};
    double z{};
  } linear{};
  struct {
    double x{};
    double y{};
    double z{};
  } angular{};
};

NS_END(kinematics, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_KINEMATICS_TWIST_HPP_ */
