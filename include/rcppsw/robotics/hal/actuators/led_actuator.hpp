/**
 * @file led_actuator.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_HAL_ACTUATORS_LED_ACTUATOR_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_HAL_ACTUATORS_LED_ACTUATOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"
#include "rcppsw/utils/color.hpp"
#include "rcppsw/robotics/hal/hal.hpp"

#if HAL_CONFIG == HAL_CONFIG_ARGOS_FOOTBOT
#include <argos3/plugins/robots/generic/control_interface/ci_leds_actuator.h>
#else
#error "Selected component has no LEDs!"
#endif /* HAL_CONFIG */

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, hal, actuators);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class led_actuator_
 * @ingroup robotics hal
 *
 * @brief LED actuator wrapper for the following supported robots:
 *
 * - ARGoS footbot
 */
template<typename T>
class _led_actuator {
 public:
  template<typename U = T>
  _led_actuator(typename std::enable_if_t<std::is_same<U,
               argos::CCI_LEDsActuator>::value,
               argos::CCI_LEDsActuator> * leds)
      : m_leds(leds) {}

  /**
   * @brief Set a single LED on the footbot robot to a specific color (or set
   * all LEDs to a specific color).
   *
   * @param id Which LED to change color. This is application defined. However,
   * the reserved value of -1 should be interpreted to mean set the color of
   * \c ALL LEDs on the robot.
   *
   * @param color The color to change the LED to. This is application defined.
   *
   * @return \ref status_t.
   */
  template <typename U = T>
  typename std::enable_if_t<std::is_same<U,
                                         argos::CCI_LEDsActuator>::value,
                            status_t>
  set_color(int id, utils::color color) {
    if (-1 == id) {
      m_leds->SetAllColors(argos::CColor(color.red(),
                                         color.green(),
                                         color.blue(),
                                         color.alpha()));
    } else {
      m_leds->SetSingleColor(id, argos::CColor(color.red(),
                                               color.green(),
                                               color.blue(),
                                               color.alpha()));
    }
    return OK;
  }


  /**
   * @brief Set intensity for a single LED on the footbot robot (or set
   * intensity of all LEDs).
   *
   * @param id Which LED to set intensity for. This is application
   * defined. However, the reserved value of -1 should be interpreted to mean
   * set the intensity of \c ALL LEDs on the robot.
   *
   * @param intensity In the range [0,255]. Application defined meaning.
   *
   * @return \ref status_t.
   */
  template <typename U = T>
  typename std::enable_if_t<std::is_same<U,
                                         argos::CCI_LEDsActuator>::value,
                            status_t>
  set_intensity(int id, uint8_t intensity) {
    if (-1 == id) {
      m_leds->SetAllIntensities(intensity);
    } else {
      m_leds->SetSingleIntensity(id, intensity);
    }
    return OK;
  }

 private:
  T* m_leds;
};

#if HAL_CONFIG == HAL_CONFIG_ARGOS_FOOTBOT
using led_actuator = _led_actuator<argos::CCI_LEDsActuator>;
#endif /* HAL_CONFIG */

NS_END(actuators, hal, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_HAL_ACTUATORS_LED_ACTUATOR_HPP_ */
