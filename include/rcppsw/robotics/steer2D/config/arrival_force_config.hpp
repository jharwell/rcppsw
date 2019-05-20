/**
 * @file arrival_force_config.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_STEER2D_CONFIG_ARRIVAL_FORCE_CONFIG_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_STEER2D_CONFIG_ARRIVAL_FORCE_CONFIG_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"
#include "rcppsw/config/base_config.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, steer2D, config);

/*******************************************************************************
 * Struct Definitions
 ******************************************************************************/

/**
 * @struct arrival_force_config
 * @ingroup rcppsw robotics steer2D config
 */
struct arrival_force_config : rcppsw::config::base_config {
  /**
   * Maximum value for the force.
   */
  double max{0};

  /**
   * The speed that entities entering the slowing radius will slow down to
   * (linear ramp down).
   */
  double slowing_speed_min{0};

  /**
   * The radius around the object inside which the entity should begin to slow
   * down, so as to not overshoot the target.
   */
  double slowing_radius{0};
};

NS_END(config, steer2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_STEER2D_CONFIG_ARRIVAL_FORCE_CONFIG_HPP_ */