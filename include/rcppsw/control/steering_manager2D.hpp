/**
 * @file steering_manager2D.hpp
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

#ifndef INCLUDE_RCPPSW_CONTROL_STEERING_MANAGER2D_HPP_
#define INCLUDE_RCPPSW_CONTROL_STEERING_MANAGER2D_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"
#include "rcppsw/control/avoidance_force.hpp"
#include "rcppsw/control/arrival_force.hpp"
#include "rcppsw/control/seek_force.hpp"
#include "rcppsw/control/wander_force.hpp"
#include "rcppsw/control/polar_force.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @class steering_manager2D
 * @ingroup control
 *
 * @brief Class encapsulating steering of entities through 2D space via summing
 * selectable forces that act on the entity each timestep. To use this class,
 * entities must conform to the \ref boid interface.
 *
 * Once conformant, available behaviors/forces for application are:
 *
 * \ref kSeekThrough
 * \ref kSeekTo
 * \ref kWander
 * \ref kAvoidance
 * \ref kPolar
 */
class steering_manager2D {
 public:
  enum behaviors {
    kSeekThrough, /// Move to and drive through a target
    kSeekTo,      /// Move to and stop at a target
    /**
     * Wander randomly through the environment, changing direction
     * minutely each timestep
     */
    kWander,
    kAvoidance, /// Obstacle avoidance
    /**
     * Apply a constant force radiating from a fixed point in space. Can be used
     * to generate arcing trajectories from linear ones under certain
     * conditions, such as starting from a stopped entities and using one of the
     * seek forces.
     */
    kPolar
  };

  steering_manager2D(boid& entity, const struct force_params* params);

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

  /**
   * @brief Add the \ref kWander force to the sum forces for this timestep.
   */
  void wander(void);

  /**
   * @brief Add the \ref kAvoidance forec to the sum forces for this timestep.
   *
   * If no threatening obstacle exists, this force is 0.
   *
   * @param obs_threat Does a threatening obstacle currently exist?
   * @param closest_obstacle If so, where is it.
   */
  void avoidance(bool obs_threat,
                 const argos::CVector2& closest_obstacle);

  /**
   * @brief Get the steering force the entity, returning the cumulative sum
   * of all forces chosen to act on the entity this timestep.
   *
   * The sum is reset after calling this function.
   */
  argos::CVector2 steering_force(void) { return m_force; }

  /**
   * @brief Reset the sum of forces acting on the entity.
   */
  void reset(void) { m_force.SetX(0); m_force. SetY(0); }

 private:
  void do_seek_through(const argos::CVector2& target);
  void do_seek_to(const argos::CVector2& target);
  void do_wander(void);

  // clang-format off
  boid&           m_entity;
  argos::CVector2 m_force;
  avoidance_force m_avoidance_force;
  arrival_force   m_arrival_force;
  seek_force      m_seek_force;
  wander_force    m_wander_force;
  polar_force     m_polar_force;
  // clang-format on
};

NS_END(control, rcppsw);

#endif /* INCLUDE_RCPPSW_CONTROL_STEERING_MANAGER2D_HPP_ */
