/**
 * @file force_calculator.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_STEER2D_FORCE_CALCULATOR_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_STEER2D_FORCE_CALCULATOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "rcppsw/common/common.hpp"
#include "rcppsw/robotics/steer2D/avoidance_force.hpp"
#include "rcppsw/robotics/steer2D/arrival_force.hpp"
#include "rcppsw/robotics/steer2D/seek_force.hpp"
#include "rcppsw/robotics/steer2D/wander_force.hpp"
#include "rcppsw/robotics/steer2D/polar_force.hpp"
#include "rcppsw/robotics/steer2D/phototaxis_force.hpp"
#include "rcppsw/er/client.hpp"
#include "rcppsw/robotics/kin/twist.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, steer2D);
namespace config {
struct force_calculator_config;
} /* namespace config */

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @class force_calculator
 * @ingroup rcppsw robotics steer2D
 *
 * @brief Class encapsulating steering of entities through 2D space via summing
 * selectable forces that act on the entity each timestep. To use this class,
 * entities must conform to the \ref boid interface.
 *
 * Once conformant, see \ref force_type for available force types.
 */
class force_calculator : public er::client<force_calculator> {
 public:
  force_calculator(boid& entity,
                   const config::force_calculator_config* config);

  /**
   * @brief Return the current steering force as a velocity vector.
   */
  const math::vector2d& value(void) const { return m_force_accum; }
  void value(const math::vector2d& val) { m_force_accum = val; }

  /**
   * @brief Return the current steering force as twist acting on the managed
   * entity.
   */
  kin::twist value_as_twist(void) const { return to_twist(m_force_accum); }

  kin::twist to_twist(const math::vector2d& force) const;

  /**
   * @brief Reset the sum of forces acting on the entity.
   */
  void reset(void) { m_force_accum.x(0); m_force_accum.y(0); }

  /**
   * @brief Add the \ref arrival_force to the sum forces for this timestep.
   *
   * @param target The target to seek to.
   */
  void seek_through(const math::vector2d& target);

  /**
   * @brief Add the \ref seek_force to the sum forces for this timestep.
   *
   * @param target The target to seek to.
   */
  void seek_to(const math::vector2d& target);

  bool within_slowing_radius(void) const {
    return m_arrival.within_slowing_radius();
  }
  /**
   * @brief Add the \ref wander_force to the sum forces for this timestep.
   */
  void wander(void);

  /**
   * @brief Add the \ref avoidance_force to the sum forces for this timestep.
   *
   * If no threatening obstacle exists, this force is 0.
   *
   * @param closest_obstacle Where is the closest obstacle, relative to robot's
   * current position AND heading.
   */
  void avoidance(const math::vector2d& closest_obstacle);

  /**
   * @brief Add the \ref phototaxis_force to the sum forces for this timestep.
   *
   * @param readings The current light sensor readings.
   */
  void phototaxis(const phototaxis_force::light_sensor_readings& readings);

  /**
   * @brief Add the \ref phototaxis_force to the sum forces for this timestep.
   *
   * @param readings The current camera sensor readings.
   */
  void phototaxis(const phototaxis_force::camera_sensor_readings& readings,
                  const utils::color& color);

  /**
   * @brief Add the negative of the \ref phototaxis_force to the sum forces for
   * this timestep.
   *
   * @param readings The current light sensor readings.
   */
  void anti_phototaxis(
      const phototaxis_force::light_sensor_readings& readings);

  /**
   * @brief Add the negative of the \ref phototaxis_force to the sum forces for
   * this timestep.
   *
   * @param readings The current camera sensor readings.
   */
  void anti_phototaxis(const phototaxis_force::camera_sensor_readings& readings,
                       const utils::color& color);
 private:
  void accum_force(const math::vector2d& force) { m_force_accum += force; }
  const boid& entity(void) const { return m_entity; }

  /* clang-format off */
  boid&            m_entity;
  math::vector2d   m_force_accum{};
  avoidance_force  m_avoidance;
  arrival_force    m_arrival;
  seek_force       m_seek{};
  wander_force     m_wander;
  polar_force      m_polar;
  phototaxis_force m_phototaxis;
  /* clang-format on */
};

NS_END(steer2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_STEER2D_FORCE_CALCULATOR_HPP_ */
