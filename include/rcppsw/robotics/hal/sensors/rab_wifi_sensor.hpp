/**
 * @file rab_wifi_sensor.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_RAB_WIFI_SENSOR_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_RAB_WIFI_SENSOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "rcppsw/robotics/hal/wifi_packet.hpp"

#if HAL_CONFIG == HAL_CONFIG_ARGOS_FOOTBOT
#include <argos3/plugins/robots/generic/control_interface/ci_range_and_bearing_sensor.h>
#else
#error "Selected hardware has no RAB wireless communication sensor!"
#endif /* HAL_CONFIG */

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, hal, sensors);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class rab_wifi_sensor
 * @ingroup robotics hal
 *
 * @brief Wireless communication sensor with range and bearing information for
 * the following supported robots:
 *
 * - ARGoS footbot
 */
template <typename T>
class _rab_wifi_sensor  {
  struct rab_wifi_packet : public wifi_packet {
    /**
     * @brief How far the source is from the receiver?
     */
    double                   range;

    /**
     * @brief Angle between source and receiver.
     */
    argos::CRadians          hor_bearing;

    /**
     * @brief Angle between robot XY plane and source.
     */
    argos::CRadians          vert_bearing;

    rab_wifi_packet(double _range,
                    const argos::CRadians& _hor_bearing,
                    const argos::CRadians& _vert_bearing) :
        wifi_packet(),
        range(_range),
        hor_bearing(_hor_bearing),
        vert_bearing(_vert_bearing) {}
  };

 public:
  template<typename U = T>
  explicit _rab_wifi_sensor(typename std::enable_if_t<std::is_same<U,
                            argos::CCI_RangeAndBearingSensor>::value,
                            argos::CCI_RangeAndBearingSensor> * sensor)
      : m_sensor(sensor) {}

  /**
   * @brief Get the current rab wifi sensor readings for the footbot robot.
   *
   * @return A vector of \ref rab_wifi_packet.
   */
  template <typename U = T>
  typename std::enable_if_t<std::is_same<U,
                                         argos::CCI_RangeAndBearingSensor>::value,
                            std::vector<rab_wifi_packet>>
  readings(void) const {
    std::vector<rab_wifi_packet> ret;
    for (auto &r : m_sensor->GetReadings()) {
      rab_wifi_packet d(r.Range,
                r.HorizontalBearing,
                r.VerticalBearing);
      for (size_t i = 0; i < r.Data.Size(); ++i) {
        d.data.push_back(r.Data[i]);
      } /* for(i..) */
      ret.push_back(d);
    } /* for(&r..) */
    return ret;
  }

 private:
  T* m_sensor;
};

#if HAL_CONFIG == HAL_CONFIG_ARGOS_FOOTBOT
using rab_wifi_sensor = _rab_wifi_sensor<argos::CCI_RangeAndBearingSensor>;
#endif /* HAL_CONFIG */

NS_END(sensors, hal, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_RAB_WIFI_SENSOR_HPP_ */
