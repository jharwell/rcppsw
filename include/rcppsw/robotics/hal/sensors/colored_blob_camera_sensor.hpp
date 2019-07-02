/**
 * @file colored_blob_camera_sensor.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_COLORED_BLOB_CAMERA_SENSOR_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_COLORED_BLOB_CAMERA_SENSOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "rcppsw/common/common.hpp"
#include "rcppsw/robotics/hal/hal.hpp"
#include "rcppsw/utils/color.hpp"
#include "rcppsw/math/vector2.hpp"

#if HAL_CONFIG == HAL_CONFIG_ARGOS_FOOTBOT
#include <argos3/plugins/robots/generic/control_interface/ci_colored_blob_omnidirectional_camera_sensor.h>
#else
#error "Selected hardware has no blob camera sensor!"
#endif /* HAL_CONFIG */

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, hal, sensors, detail);

/*******************************************************************************
 * Templates
 ******************************************************************************/
template<typename TSensor>
using is_argos_blob_camera_sensor = std::is_same<
  TSensor,
  argos::CCI_ColoredBlobOmnidirectionalCameraSensor>;

NS_END(detail);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class colored_blob_camera_sensor
 * @ingroup rcppsw robotics hal
 *
 * @brief Omnidirectional colored blob camera sensor wrapper for the following
 * supported robots:
 *
 * - ARGoS footbot
 */
template <typename TSensor>
class _colored_blob_camera_sensor {
 public:
  /**
   * @brief A camera sensor reading (color, distance, angle) tuple.
   */
  struct reading {
    math::vector2d vec;
    utils::color color;
  };

  template <typename U = TSensor,
            RCPPSW_SFINAE_FUNC(detail::is_argos_blob_camera_sensor<U>::value)>
  explicit _colored_blob_camera_sensor(U * const sensor) : m_sensor(sensor) {
    sensor->Enable();
  }

  /**
   * @brief Get the sensor readings for the footbot robot.
   *
   * @return A vector of \ref reading.
   */
  template <typename U = TSensor,
            RCPPSW_SFINAE_FUNC(detail::is_argos_blob_camera_sensor<U>::value)>
  std::vector<reading>  readings(void) const {
    std::vector<reading> ret;
    for (auto &r : m_sensor->GetReadings().BlobList) {
      struct reading s = {
        .vec = {r->Distance, math::radians(r->Angle.GetValue())},
        .color = utils::color(r->Color.GetRed(),
                              r->Color.GetGreen(),
                              r->Color.GetBlue())
      };
      ret.push_back(s);
    } /* for(&r..) */

    return ret;
  }

 private:
  TSensor* const m_sensor;
};

#if HAL_CONFIG == HAL_CONFIG_ARGOS_FOOTBOT
using colored_blob_camera_sensor =
    _colored_blob_camera_sensor<argos::CCI_ColoredBlobOmnidirectionalCameraSensor>;
#endif /* HAL_CONFIG */

NS_END(sensors, hal, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_HAL_SENSORS_BLOB_CAMERA_SENSOR_HPP_ */
