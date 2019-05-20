/**
 * @file differential_drive_config.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_KIN2D_CONFIG_DIFFERENTIAL_DRIVE_CONFIG_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_KIN2D_CONFIG_DIFFERENTIAL_DRIVE_CONFIG_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/config/base_config.hpp"
#include "rcppsw/math/radians.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, kin2D, config);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * @struct differential_drive_config
 * @ingroup rcppsw robotics kin2D config
 */
struct differential_drive_config : public rcppsw::config::base_config {
  math::radians soft_turn_max{};
  double        max_speed{0.0};
};

NS_END(config, kin2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_KIN2D_CONFIG_DIFFERENTIAL_DRIVE_CONFIG_HPP_ */
