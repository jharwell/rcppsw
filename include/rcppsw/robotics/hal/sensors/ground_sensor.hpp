/**
 * @file ground_sensor.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_GROUND_SENSOR_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_GROUND_SENSOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"
#include "rcppsw/robotics/hal/hal.hpp"

#if HAL_CONFIG == HAL_CONFIG_ARGOS_FOOTBOT
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_motor_ground_sensor.h>
#else
#error "Selected hardware has no ground sensor!"
#endif /* HAL_CONFIG */

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, hal, sensors);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class ground_sensor
 * @ingroup robotics hal
 *
 * @brief Ground sensor wrapper for the following supported robots:
 *
 * - ARGoS footbot
 */
template <typename T>
class _ground_sensor {
 public:
  /**
   * @brief A ground sensor reading (value, distance) pair.
   *
   * The first argument is the value of the sensor (a robot can have a variable
   * number of sensors), and the second
   * argument is the distance from the sensor on the robot to the robot's center
   * (this may not be used, depending on the actual hardware mapped to).
   *
   * @todo: Make this use the new rcppsw math vector I am eventually going to
   * implement.
   */
  struct reading {
    double value;
    double distance;

    reading(double _value, double _distance) : value(_value), distance(_distance) {}
  };

  template<typename U = T>
  _ground_sensor(typename std::enable_if_t<std::is_same<U,
                      argos::CCI_FootBotMotorGroundSensor>::value,
                      argos::CCI_FootBotMotorGroundSensor> * sensor)
      : m_sensor(sensor) {}

  /**
   * @brief Get the current ground sensor readings for the footbot robot.
   *
   * @return A vector of \ref reading.
   */
  template <typename U = T>
  typename std::enable_if_t<std::is_same<U,
                                         argos::CCI_FootBotMotorGroundSensor>::value,
                            std::vector<reading>>
  readings(void) const {
    std::vector<reading> ret;
    for (auto &r : m_sensor->GetReadings()) {
      ret.push_back({r.Value, -1.0});
    } /* for(&r..) */

    return ret;
  }

 private:
  T* m_sensor;
};

#if HAL_CONFIG == HAL_CONFIG_ARGOS_FOOTBOT
using ground_sensor = _ground_sensor<argos::CCI_FootBotMotorGroundSensor>;
#endif /* HAL_CONFIG */

NS_END(sensors, hal, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_GROUND_SENSOR_HPP_ */
