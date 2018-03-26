/**
 * @file arrival_force_params.hpp
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

#ifndef INCLUDE_RCPPSW_CONTROL_ARRIVAL_FORCE_PARAMS_HPP_
#define INCLUDE_RCPPSW_CONTROL_ARRIVAL_FORCE_PARAMS_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"
#include "rcppsw/params/base_params.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Struct Definitions
 ******************************************************************************/

/**
 * @struct arrival_force_params
 * @ingroup control
 */
struct arrival_force_params : params::base_params {
  /**
   * The radius around the object inside which the entity should begin to slow
   * down, so as to not overshoot the target.
   */
  double slowing_radius{0};
};

NS_END(control, rcppsw);

#endif /* INCLUDE_RCPPSW_CONTROL_ARRIVAL_FORCE_PARAMS_HPP_ */
