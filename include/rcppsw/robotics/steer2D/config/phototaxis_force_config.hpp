/**
 * @file phototaxis_force_config.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_STEER2D_CONFIG_PHOTOTAXIS_FORCE_CONFIG_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_STEER2D_CONFIG_PHOTOTAXIS_FORCE_CONFIG_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/config/base_config.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, steer2D, config);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * @struct phototaxis_force_config
 * @ingroup rcppsw robotics steer2D config
 */
struct phototaxis_force_config : public rcppsw::config::base_config {
  double max;
};

NS_END(config, steer2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_STEER2D_CONFIG_PHOTOTAXIS_FORCE_CONFIG_HPP_ */
