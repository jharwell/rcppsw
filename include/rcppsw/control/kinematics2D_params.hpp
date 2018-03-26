/**
 * @file kinematics2D_params.hpp
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

#ifndef INCLUDE_RCPPSW_CONTROL_KINEMATICS2D_PARAMS_HPP_
#define INCLUDE_RCPPSW_CONTROL_KINEMATICS2D_PARAMS_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"
#include "rcppsw/control/avoidance_force_params.hpp"
#include "rcppsw/control/arrival_force_params.hpp"
#include "rcppsw/control/wander_force_params.hpp"
#include "rcppsw/control/polar_force_params.hpp"
#include "rcppsw/params/base_params.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @struct kinematics2D_params
 * @ingroup control
 */
struct kinematics2D_params : public params::base_params {
  struct avoidance_force_params avoidance{};
  struct arrival_force_params arrival{};
  struct wander_force_params wander{};
  struct polar_force_params polar{};
};

NS_END(control, rcppsw);

#endif /* INCLUDE_RCPPSW_CONTROL_KINEMATICS2D_PARAMS_HPP_ */
