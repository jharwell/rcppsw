/**
 * @file phototaxis_force.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_STEER2D_PHOTOTAXIS_FORCE_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_STEER2D_PHOTOTAXIS_FORCE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "rcppsw/robotics/steer2D/boid.hpp"
#include "rcppsw/robotics/hal/sensors/light_sensor.hpp"
#include "rcppsw/robotics/hal/sensors/colored_blob_camera_sensor.hpp"

/*******************************************************************************
 * namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, steer2D);
namespace config {
struct phototaxis_force_config;
}

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @class phototaxis_force
 * @ingroup rcppsw robotics steer2D
 *
 * @brief A force pushing the robot away from light sources.
 */
class phototaxis_force {
 public:
  using light_sensor_readings = std::vector<hal::sensors::light_sensor::reading>;
  using camera_sensor_readings =
      std::vector<hal::sensors::colored_blob_camera_sensor::reading>;
  explicit phototaxis_force(const config::phototaxis_force_config* config);

  math::vector2d operator()(const light_sensor_readings& readings) const;

  /**
   * @brief Calculate force vector to the average location of objects of the
   * specified color.
   */
  math::vector2d operator()(const camera_sensor_readings& readings,
                            const utils::color& color) const;

  /* clang-format off */
  const double mc_max;
  /* clang-format on */
};

NS_END(steer2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_STEER2D_PHOTOTAXIS_FORCE_HPP_ */
