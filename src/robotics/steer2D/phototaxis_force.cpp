/**
 * @file phototaxis_force.cpp
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
#include "rcppsw/robotics/steer2D/phototaxis_force.hpp"
#include <numeric>

#include "rcppsw/robotics/steer2D/config/phototaxis_force_config.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, steer2D);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
phototaxis_force::phototaxis_force(
    const config::phototaxis_force_config* config)
    : mc_max(config->max) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
math::vector2d phototaxis_force::operator()(
    const light_sensor_readings& readings) const {

  auto accum = std::accumulate(readings.begin(),
                               readings.end(),
                               math::vector2d(),
                               [&](const math::vector2d& v,
                                   const auto& r){
                                 return v + math::vector2d(r.value,
                                                           math::radians(r.angle));
                               });

  return math::vector2d(1.0, accum.angle()) * mc_max;
} /* operator()() */

math::vector2d phototaxis_force::operator()(
    const camera_sensor_readings& readings,
    const utils::color& color) const {

  auto accum = std::accumulate(readings.begin(),
                               readings.end(),
                               math::vector2d(),
                               [&](const math::vector2d& v,
                                   const auto& r){
                                 return (r.color == color) ? v + r.vec: v;
                               });

  return math::vector2d(1.0, accum.angle()) * mc_max;
} /* operator()() */

NS_END(steer2D, robotics, rcppsw);
