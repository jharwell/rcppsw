/**
 * @file polar_force.cpp
 *
 * @copyright 2017 John Harwell, All rights reserved.
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/robotics/steer2D/polar_force.hpp"
#include "rcppsw/robotics/steer2D/config/polar_force_config.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, steer2D);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
polar_force::polar_force(const config::polar_force_config* const config)
    : mc_max(config->max) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
math::vector2d polar_force::operator()(const boid& entity,
                                       const math::vector2d& source) const {
  return (entity.position() - source).normalize() * mc_max;
} /* operator()() */

NS_END(steer2D, robotics, rcppsw);
