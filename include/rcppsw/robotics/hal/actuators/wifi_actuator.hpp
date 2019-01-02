/**
 * @file wifi_actuator.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_HAL_ACTUATORS_WIFI_ACTUATOR_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_HAL_ACTUATORS_WIFI_ACTUATOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"
#include "rcppsw/utils/color.hpp"
#include "rcppsw/robotics/hal/hal.hpp"
#include "rcppsw/robotics/hal/wifi_packet.hpp"

#if HAL_CONFIG == HAL_CONFIG_ARGOS_FOOTBOT
#include <argos3/plugins/robots/generic/control_interface/ci_range_and_bearing_actuator.h>
#else
#error "Selected component has no RAB actuator!"
#endif /* HAL_CONFIG */

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, hal, actuators, detail);

/*******************************************************************************
 * Templates
 ******************************************************************************/
template<typename Actuator>
using is_argos_rab_actuator = std::is_same<Actuator,
                                           argos::CCI_RangeAndBearingActuator>;
NS_END(detail);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class wifi_actuator_
 * @ingroup robotics hal
 *
 * @brief WIFI actuator wrapper for the following supported robots:
 *
 * - ARGoS footbot. These robots will use wifi to broadcast data every timestep
 *   to all robots in range until told to do otherwise.
 */
template<typename T>
class _wifi_actuator {
 public:

  explicit _wifi_actuator(T* const wifi) : m_wifi(wifi) {}


  /**
   * @brief Start broadcasting the specified data to all footbots within range.
   */
  template <typename U = T,
            RCPPSW_SFINAE_REQUIRE(detail::is_argos_rab_actuator<U>::value)>
  void broadcast_start(const struct wifi_packet& packet) {
    for (size_t i = 0; i < packet.data.size(); ++i) {
      m_wifi->SetData(i, packet.data[i]);
    } /* for(i..) */
  }

  /**
   * @brief Stop broadcasting the previously specified data to all footbots
   * within range.
   */
  template <typename U = T,
            RCPPSW_SFINAE_REQUIRE(detail::is_argos_rab_actuator<U>::value)>
  void broadcast_stop(void) {
    m_wifi->ClearData();
  }

  /**
   * @brief Reset the wifi device.
   */
  template <typename U = T,
            RCPPSW_SFINAE_REQUIRE(detail::is_argos_rab_actuator<U>::value)>
  void reset(void) {
    m_wifi->ClearData();
  }

 private:
  T* const m_wifi;
};

#if HAL_CONFIG == HAL_CONFIG_ARGOS_FOOTBOT
using wifi_actuator = _wifi_actuator<argos::CCI_RangeAndBearingActuator>;
#endif /* HAL_CONFIG */

NS_END(actuators, hal, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_HAL_ACTUATORS_WIFI_ACTUATOR_HPP_ */
