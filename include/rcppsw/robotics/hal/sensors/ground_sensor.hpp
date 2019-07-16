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
#include <vector>
#include "rcppsw/common/common.hpp"
#include "rcppsw/robotics/hal/hal.hpp"

#if HAL_CONFIG == HAL_CONFIG_ARGOS_FOOTBOT
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_motor_ground_sensor.h>
#else
#error "Selected hardware has no ground sensor!"
#endif /* HAL_CONFIG */

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, hal, sensors, detail);

/*******************************************************************************
 * Templates
 ******************************************************************************/
template<typename TSensor>
using is_argos_ground_sensor = std::is_same<TSensor,
                                            argos::CCI_FootBotMotorGroundSensor>;

NS_END(detail);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class ground_sensor
 * @ingroup rcppsw robotics hal sensors
 *
 * @brief Ground sensor wrapper for the following supported robots:
 *
 * - ARGoS footbot
 */
template <typename TSensor>
class _ground_sensor {
 public:
  /**
   * @brief A ground sensor reading (value, distance) pair.
   *
   * The first argument is the value of the sensor (a robot can have a variable
   * number of sensors), and the second
   * argument is the distance from the sensor on the robot to the robot's center
   * (this may not be used, depending on the actual hardware mapped to).
   */
  struct reading {
    reading(double v, double d) noexcept : value(v), distance(d) {}

    double value;
    double distance;
  };

  explicit _ground_sensor(TSensor * const sensor) : m_sensor(sensor) {}

  /**
   * @brief Get the current ground sensor readings for the footbot robot.
   *
   * @return A vector of \ref reading.
   */
  template <typename U = TSensor,
            RCPPSW_SFINAE_FUNC(detail::is_argos_ground_sensor<U>::value)>
  std::vector<reading> readings(void) const {
    std::vector<reading> ret;
    for (auto &r : m_sensor->GetReadings()) {
      ret.emplace_back(r.Value, -1.0);    } /* for(&r..) */

    return ret;
  }

  /**
   * @brief Detect if a certain condition is met by examining footbot ground
   * sensor readings
   *
   * @param target The target threshold value for the condition to detect.
   * @param tol The tolerance from the target that is acceptable for a reading
   *            to be counted as part of the consensus.
   * @param consensus The # of sensors of the 4 on the footbot that have to
   *                  agree for the condition to successfully be detected.
   *
   * @return \c TRUE iff the condition was detected by the specified # readings.
   */
  template <typename U = TSensor,
            RCPPSW_SFINAE_FUNC(detail::is_argos_ground_sensor<U>::value)>
  bool detect(double target, double tol, uint consensus) const {
    std::vector<reading> r = readings();

    uint sum = 0;
    sum += static_cast<uint>(r[0].value >= target - tol &&
                             r[0].value <= target + tol);
    sum += static_cast<uint>(r[1].value >= target - tol &&
                             r[1].value <= target + tol);
    sum += static_cast<uint>(r[2].value >= target - tol &&
                             r[2].value <= target + tol);
    sum += static_cast<uint>(r[3].value >= target - tol &&
                             r[3].value <= target + tol);
    return sum >= consensus;
  }

 private:
  TSensor* const m_sensor;
};

#if HAL_CONFIG == HAL_CONFIG_ARGOS_FOOTBOT
using ground_sensor = _ground_sensor<argos::CCI_FootBotMotorGroundSensor>;
#endif /* HAL_CONFIG */

NS_END(sensors, hal, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_GROUND_SENSOR_HPP_ */
