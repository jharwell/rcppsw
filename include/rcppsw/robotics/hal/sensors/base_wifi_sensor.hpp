/**
 * @file base_wifi_sensor.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_BASE_WIFI_SENSOR_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_BASE_WIFI_SENSOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, hal, sensors);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class base_wifi_sensor
 * @ingroup robotics hal
 *
 * @brief Base wireless communicatione sensor wrapper containing functionality
 * common to all types of wifi sensors.
 */
class base_wifi_sensor {
 public:
  base_wifi_sensor(void) = default;
  virtual ~base_wifi_sensor(void) = default;

  /**
   * @brief A wireless communication sensor payload.
   */
  struct wifi_packet {
    std::vector<uint8_t> data;

    wifi_packet(void) : data() {}
  };
};

NS_END(sensors, hal, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_BASE_WIFI_SENSOR_HPP_ */
