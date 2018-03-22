/**
 * @file arrival_force.hpp
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

#ifndef INCLUDE_RCPPSW_CONTROL_ARRIVAL_FORCE_HPP_
#define INCLUDE_RCPPSW_CONTROL_ARRIVAL_FORCE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"
#include "rcppsw/control/boid.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, control);
struct arrival_force_params;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @class arrival_force
 * @ingroup control
 *
 * @brief A force pulling the robot to a target (i.e. the robot DOES slow down
 * to "arrive").
 */
class arrival_force {
 public:
  explicit arrival_force(const struct arrival_force_params* params);

  argos::CVector2 operator()(const boid& entity, const argos::CVector2& target);

 private:
  double m_slowing_radius;
};

NS_END(control, rcppsw);

#endif /* INCLUDE_RCPPSW_CONTROL_ARRIVAL_FORCE_HPP_ */
