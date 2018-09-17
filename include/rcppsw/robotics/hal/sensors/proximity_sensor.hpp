/**
 * @file proximity_sensor.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_PROXIMITY_SENSOR_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_PROXIMITY_SENSOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>

#include "rcppsw/common/common.hpp"
#include "rcppsw/robotics/hal/hal.hpp"

#if HAL_CONFIG == HAL_CONFIG_ARGOS_FOOTBOT
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_proximity_sensor.h>
#else
#error "Selected hardware has no proximity sensor!"
#endif /* HAL_CONFIG */

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, hal, sensors);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class proximity_sensor
 * @ingroup robotics hal
 *
 * @brief Proxmity sensor wrapper for the following supported robots:
 *
 * - ARGoS footbot
 */
template <typename T>
class _proximity_sensor {
 public:
  /**
   * @brief A proximity sensor reading (value, angle) pair.
   *
   * The first argument is the value of the sensor at an angle, and the second
   * argument is the angle in radians. Note that the "value" in this case does
   * NOT have to be distance, but could be something else like exponential [0,1]
   * that is computed from the distance measured.
   */
  struct reading {
    double value;
    double angle;

    reading(double _value, double _angle) : value(_value), angle(_angle) {}
  };

  template<typename U = T>
  explicit _proximity_sensor(typename std::enable_if_t<std::is_same<U,
                             argos::CCI_FootBotProximitySensor>::value,
                      argos::CCI_FootBotProximitySensor> * sensor)
      : m_sensor(sensor) {}

  /**
   * @brief Get the current proximity sensor readings for the footbot robot.
   *
   * @return A vector of \ref reading.
   */
  template <typename U = T>
  typename std::enable_if_t<std::is_same<U,
                                         argos::CCI_FootBotProximitySensor>::value,
                            std::vector<reading>>
  readings(void) const {
    std::vector<reading> ret;
    for (auto &r : m_sensor->GetReadings()) {
      ret.push_back({r.Value, r.Angle.GetValue()});
    } /* for(&r..) */

    return ret;
  }

 private:
  T* m_sensor;
};

#if HAL_CONFIG == HAL_CONFIG_ARGOS_FOOTBOT
using proximity_sensor = _proximity_sensor<argos::CCI_FootBotProximitySensor>;
#endif /* HAL_CONFIG */

NS_END(sensors, hal, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_PROXIMITY_SENSOR_HPP_ */
