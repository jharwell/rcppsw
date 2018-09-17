/**
 * @file battery_sensor.hpp
 *
 * @copyright 2018 The Nimer Inc., All rights reserved.
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

 #ifndef INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_BATTERY_SENSOR_HPP_
 #define INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_BATTERY_SENSOR_HPP_

 /******************************************************************************
  * Includes
  ******************************************************************************/
 #include <vector>
 #include "rcppsw/common/common.hpp"
 #include "rcppsw/robotics/hal/hal.hpp"

 #if HAL_CONFIG == HAL_CONFIG_ARGOS_FOOTBOT
 #include <argos3/plugins/robots/generic/control_interface/ci_battery_sensor.h>
 #else
 #error "Selected hardware has no battery sensor!"
 #endif /* HAL_CONFIG */

 /******************************************************************************
  * Namespaces
  ******************************************************************************
*/
NS_START(rcppsw, robotics, hal, sensors);

 /******************************************************************************
  * Class Definitions
  ******************************************************************************/
  /**
   * @class battery_sensor
   * @ingroup robotics hal
   *
   * @brief Battery sensor wrapper for the following supported robots:
   *
   * - ARGoS footbot
   */
template <typename T>
class _battery_sensor {
public:
  /**
   * @brief A battery sensor reading (value, angle) pair.
   *
   * The first argument is the amount of battery left (1 meaning 100% and 0
   * being 0%), and the second argument is the amount of time left for the robot
   * (there is an "infinite" time option to essentially diable the battery for
   * the simulation).
   */
   typedef struct reading {
     double availible_charge;
     double time_left;

     reading(double _availible_charge, double _time_left) : availible_charge(_availible_charge), time_left(_time_left) {}
   }reading;

   template<typename U = T>
   explicit _battery_sensor(typename std::enable_if_t<std::is_same<U,
                            argos::CCI_BatterySensor>::value,
                            argos::CCI_BatterySensor> * sensor)
       : m_sensor(sensor) {}

    /**
    * @brief Get the current battery sensor readings for
    * the footbot robot.
    * @return A vector of \ref reading.
    */
    template <typename U = T>
    typename std::enable_if_t<std::is_same<U, argos::CCI_BatterySensor>::value, reading>

    readings(void) const {
      argos::CCI_BatterySensor::SReading temp = m_sensor->GetReading();
      reading ret(temp.AvailableCharge, temp.TimeLeft);


      return ret;
    }

   private:
    T* m_sensor;
  };

  #if HAL_CONFIG == HAL_CONFIG_ARGOS_FOOTBOT
  using battery_sensor = _battery_sensor<argos::CCI_BatterySensor>;
  #endif /* HAL_CONFIG */

  NS_END(sensors, hal, robotics, rcppsw);

  #endif /* INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_BATTERY_SENSOR_HPP_ */
