/**
 * @file differential_drive_actuator.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_HAL_ACTUATORS_DIFFERENTIAL_DRIVE_ACTUATOR_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_HAL_ACTUATORS_DIFFERENTIAL_DRIVE_ACTUATOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"
#include "rcppsw/robotics/hal/hal.hpp"

#if HAL_CONFIG == HAL_CONFIG_ARGOS_FOOTBOT
#include <argos3/plugins/robots/generic/control_interface/ci_differential_steering_actuator.h>
#else
#error "Selected hardware has no differential drive actuator!"
#endif /* HAL_CONFIG */

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, hal, actuators, detail);

/*******************************************************************************
 * Templates
 ******************************************************************************/
template<typename T>
using is_argos_ds_actuator = std::is_same<T,
                                          argos::CCI_DifferentialSteeringActuator>;

NS_END(detail);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class differential_drive_actuator
 * @ingroup robotics hal
 *
 * @brief Differential drive actuator wrapper for the following supported
 * robots:
 *
 * - ARGoS footbot
 */
template <typename T>
class _differential_drive_actuator {
 public:
  explicit _differential_drive_actuator(T* const wheels) : m_wheels(wheels) {}

  /**
   * @brief Set the wheel speeds for the current timestep for a footbot
   * robot. Bounds checking is not performed.
   *
   * @return \ref status_t.
   */
  template <typename U = T,
            RCPPSW_SFINAE_REQUIRE(detail::is_argos_ds_actuator<U>::value)>
  status_t set_wheel_speeds(double left,
                            double right) {
    m_wheels->SetLinearVelocity(left, right);
    return OK;
  }

  /**
   * @brief Stop the wheels of a footbot robot. As far as I know, this is an
   * immediate stop (i.e. no rampdown).
   *
   * @return \ref status_t.
   */
  template <typename U = T,
            RCPPSW_SFINAE_REQUIRE(detail::is_argos_ds_actuator<U>::value)>
  status_t stop_wheels(void) {
    return set_wheel_speeds(0.0, 0.0);
  }

 private:
  T* const m_wheels;
};

#if HAL_CONFIG == HAL_CONFIG_ARGOS_FOOTBOT
using differential_drive_actuator = _differential_drive_actuator<argos::CCI_DifferentialSteeringActuator>;
#endif /* HAL_CONFIG */

NS_END(actuators, hal, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_HAL_ACTUATORS_DIFFERENTIAL_DRIVE_ACTUATOR_HPP_ */
