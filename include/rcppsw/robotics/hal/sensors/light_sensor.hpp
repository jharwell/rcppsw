/**
 * @file light_sensor.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_LIGHT_SENSOR_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_LIGHT_SENSOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "rcppsw/common/common.hpp"
#include "rcppsw/robotics/hal/hal.hpp"

#if HAL_CONFIG == HAL_CONFIG_ARGOS_FOOTBOT
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_light_sensor.h>
#else
#error "Selected hardware has no light sensor!"
#endif /* HAL_CONFIG */

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, hal, sensors);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class light_sensor
 * @ingroup robotics hal
 *
 * @brief Light sensor wrapper for the following supported robots:
 *
 * - ARGoS footbot
 */
template <typename T>
class _light_sensor {
 public:
  /**
   * @brief A light sensor reading (value, angle) pair.
   *
   * The first argument is the value of the sensor (distance to light), and the
   * second argument is the angle of the sensor on the robot in relation to the
   * positive x axis.
   */
  struct reading {
    double value;
    double angle;

    reading(double _value, double _angle) : value(_value), angle(_angle) {}
  };

  template<typename U = T>
  _light_sensor(typename std::enable_if_t<std::is_same<U,
                      argos::CCI_FootBotLightSensor>::value,
                      argos::CCI_FootBotLightSensor> * sensor)
      : m_sensor(sensor) {}

  /**
   * @brief Get the current light sensor readings for the footbot robot.
   *
   * @return A vector of \ref reading.
   */
  template <typename U = T>
  typename std::enable_if_t<std::is_same<U,
                                         argos::CCI_FootBotLightSensor>::value,
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
using light_sensor = _light_sensor<argos::CCI_FootBotLightSensor>;
#endif /* HAL_CONFIG */

NS_END(sensors, hal, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_LIGHT_SENSOR_HPP_ */
