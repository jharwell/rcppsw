/**
 * @file avoidance_force.hpp
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

#ifndef INCLUDE_RCPPSW_CONTROL_AVOIDANCE_FORCE_HPP_
#define INCLUDE_RCPPSW_CONTROL_AVOIDANCE_FORCE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"
#include "rcppsw/control/boid.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, control);
struct avoidance_force_params;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @class avoidance_force
 * @ingroup control
 *
 * @brief A force pushing the robot away from perceived obstacles. Only active
 * when threatening obstacles are detected.
 */
class avoidance_force {
 public:
  explicit avoidance_force(const struct avoidance_force_params* params);

  argos::CVector2 operator()(const boid& b,
                             bool obs_threat,
                             const argos::CVector2& closest_obstacle);

 private:
  // clang-format off
  double          m_lookahead;
  double          m_max_avoidance;
  // clang-format on
};

NS_END(control, rcppsw);

#endif /* INCLUDE_RCPPSW_CONTROL_AVOIDANCE_FORCE_HPP_ */
