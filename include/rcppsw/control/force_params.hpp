/**
 * @file force_params.hpp
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

#ifndef INCLUDE_RCPPSW_CONTROL_FORCE_PARAMS_HPP_
#define INCLUDE_RCPPSW_CONTROL_FORCE_PARAMS_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <argos3/core/utility/math/angles.h>
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
struct avoidance_force_params {
  double lookahead{0};
  double max_avoidance{0};
};

struct arrival_force_params {
  /**
   * The radius around the object inside which the entity should begin to slow
   * down, so as to not overshoot the target.
   */
  double slowing_radius{0};
};

struct wander_force_params {
  double circle_distance{0};
  double circle_radius{0};
  argos::CRadians angle;
  double angle_delta{0};
};
struct force_params {
  struct avoidance_force_params avoidance;
  struct arrival_force_params arrival;
  struct wander_force_params wander;
};

NS_END(control, rcppsw);

#endif /* INCLUDE_RCPPSW_CONTROL_FORCE_PARAMS_HPP_ */
