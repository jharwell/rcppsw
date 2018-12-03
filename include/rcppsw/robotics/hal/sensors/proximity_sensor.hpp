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
#include <limits>

#include "rcppsw/common/common.hpp"
#include "rcppsw/robotics/hal/hal.hpp"
#include "rcppsw/math/range.hpp"
#include "rcppsw/math/radians.hpp"
#include "rcppsw/math/vector2.hpp"

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
                            std::vector<math::vector2d>>
  readings(void) const {
    std::vector<math::vector2d> ret;
    for (auto &r : m_sensor->GetReadings()) {
      ret.emplace_back(r.Value, math::radians(r.Angle.GetValue()));
    } /* for(&r..) */

    return ret;
  }

  /**
   * @brief Return the closest object within proximity, which is defined as a
   * delta for the proximity sensor + FOV (i.e. prox objects are those within
   * the specified distance to the robot, and those that fall within a specific
   * angle range (e.g. objects behind the robot are ignored). )
   *
   * Should be used in conjunction with \ref prox_obj__exists().
   */
  template <typename U = T>
  typename std::enable_if_t<std::is_same<U,
                                         argos::CCI_FootBotProximitySensor>::value,
                            math::vector2d>
  closest_prox_obj(const math::vector2d& position,
              double obj_delta,
              const math::range<math::radians>& fov) const {
    math::vector2d closest(0, 0);

    for (auto& r : readings()) {
      if (obj_within_prox(r, obj_delta, fov)) {
        if ((position - r).length() < closest.length() ||
            closest.length() <= std::numeric_limits<double>::epsilon()) {
          closest = r;
        }
      }
    } /* for(r..) */
    return closest;
  }

  /**
   * @brief Figure out if an object exists in the robot's proximity
   *
   * A proximity object is defined as one that is closer than the defined
   * object delta to the robot. Note that the object delta is NOT a measure
   * of distance, but a measure [0, 1] indicating how close an objec is which
   * increases exponentially as the object nears.
   *
   * @return \c TRUE if an object is found meeting the stated criteria, \c FALSE
   * otherwise.
   */
  bool prox_obj_exists(const math::vector2d& position,
                            double obj_delta,
                            const math::range<math::radians>& fov) const {
    return closest_prox_obj(position, obj_delta, fov).length() > 0.0;
  }

 private:
  __rcsw_pure bool obj_within_prox(const math::vector2d& obj,
                                   double obj_delta,
                                   const math::range<math::radians>& fov) const {
    return obj.length() >= obj_delta && fov.contains(obj.angle());
  }

  T* m_sensor;
};

#if HAL_CONFIG == HAL_CONFIG_ARGOS_FOOTBOT
using proximity_sensor = _proximity_sensor<argos::CCI_FootBotProximitySensor>;
#endif /* HAL_CONFIG */

NS_END(sensors, hal, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_PROXIMITY_SENSOR_HPP_ */
