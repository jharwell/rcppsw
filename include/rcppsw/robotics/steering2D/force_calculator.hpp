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

#ifndef INCLUDE_RCPPSW_ROBOTICS_STEERING2D_FORCE_CALCULATOR_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_STEERING2D_FORCE_CALCULATOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"
#include "rcppsw/robotics/steering2D/avoidance_force.hpp"
#include "rcppsw/robotics/steering2D/arrival_force.hpp"
#include "rcppsw/robotics/steering2D/seek_force.hpp"
#include "rcppsw/robotics/steering2D/wander_force.hpp"
#include "rcppsw/robotics/steering2D/polar_force.hpp"
#include "rcppsw/robotics/steering2D/force_type.hpp"
#include "rcppsw/er/client.hpp"
#include "rcppsw/robotics/kinematics/twist.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, steering2D);
struct force_calculator_params;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @class force_calculator
 * @ingroup robotics steering2D
 *
 * @brief Class encapsulating steering of entities through 2D space via summing
 * selectable forces that act on the entity each timestep. To use this class,
 * entities must conform to the \ref boid interface.
 *
 * Once conformant, see \ref force_type for available force types.
 */
class force_calculator : public er::client {
 public:
  force_calculator(const std::shared_ptr<er::server>& server,
                   boid& entity,
                   const struct force_calculator_params* params);

  /**
   * @brief Return the current steering force as a velocity vector.
   */
  const argos::CVector2& value(void) const { return m_force_accum; }
  void value(const argos::CVector2& val) { m_force_accum = val; }

  /**
   * @brief Return the current steering force as twist acting on the managed
   * entity.
   */
  kinematics::twist value_as_twist(void) const { return to_twist(m_force_accum); }

  kinematics::twist to_twist(const argos::CVector2& force) const;

  /**
   * @brief Reset the sum of forces acting on the entity.
   */
  void reset(void) { m_force_accum.SetX(0); m_force_accum.SetY(0); }

  /**
   * @brief Add the \ref kSeekThrough force to the sum forces for this timestep.
   *
   * @param target The target to seek to.
   */
  void seek_through(const argos::CVector2& target);

  /**
   * @brief Add the \ref kSeekTo force to the sum forces for this timestep.
   *
   * @param target The target to seek to.
   */
  void seek_to(const argos::CVector2& target);

  bool within_slowing_radius(void) const {
    return m_arrival_force.within_slowing_radius();
  }
  /**
   * @brief Add the \ref kWander force to the sum forces for this timestep.
   */
  void wander(void);

  /**
   * @brief Add the \ref kAvoidance forec to the sum forces for this timestep.
   *
   * If no threatening obstacle exists, this force is 0.
   *
   * @param closest_obstacle Where is the closest obstacle, relative to robot's
   * current position AND heading.
   */
  void avoidance(const argos::CVector2& closest_obstacle);

 protected:
  void accum_force(const argos::CVector2& force) { m_force_accum += force; }
  const boid& entity(void) const { return m_entity; }

 private:
  // clang-format off
  boid&           m_entity;
  argos::CVector2 m_force_accum{};
  avoidance_force m_avoidance_force;
  arrival_force   m_arrival_force;
  seek_force      m_seek_force{};
  wander_force    m_wander_force;
  polar_force     m_polar_force;
  // clang-format on
};

NS_END(steering2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_STEERING2D_FORCE_CALCULATOR_HPP_ */
