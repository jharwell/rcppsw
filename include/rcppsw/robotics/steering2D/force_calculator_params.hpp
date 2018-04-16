/**
 * @file force_calculator_params.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_STEERING2D_FORCE_CALCULATOR_PARAMS_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_STEERING2D_FORCE_CALCULATOR_PARAMS_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"
#include "rcppsw/robotics/steering2D/avoidance_force_params.hpp"
#include "rcppsw/robotics/steering2D/arrival_force_params.hpp"
#include "rcppsw/robotics/steering2D/wander_force_params.hpp"
#include "rcppsw/robotics/steering2D/polar_force_params.hpp"
#include "rcppsw/params/base_params.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, steering2D);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @struct force_calculator_params
 * @ingroup robotics steering2D
 */
struct force_calculator_params : public params::base_params {
  struct avoidance_force_params avoidance{};
  struct arrival_force_params arrival{};
  struct wander_force_params wander{};
  struct polar_force_params polar{};
};

NS_END(steering2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_STEERING2D_FORCE_CALCULATOR_PARAMS_HPP_ */
