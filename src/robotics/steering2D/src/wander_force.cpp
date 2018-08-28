/**
 * @file wander_force.cpp
 *
 * @copyright 2017 John Harwell, All rights reserved.
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/robotics/steering2D/wander_force.hpp"
#include "rcppsw/robotics/steering2D/wander_force_params.hpp"
#include <cassert>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, steering2D);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
wander_force::wander_force(const struct wander_force_params *const params)
    : m_interval(params->interval),
      m_use_normal(params->normal_dist),
      m_max(params->max),
      m_circle_distance(params->circle_distance),
      m_circle_radius(params->circle_radius),
      m_max_angle_delta(params->max_angle_delta),
      m_angle(0),
      /*
       * Both min and max are 3 std deviations away from the mean of 0, so it is
       * very unlikely that we will get a value outside the max deviation. If we
       * do, just shrink the max angle in the input parameters.
       */
      m_normal_dist(0,  2 * m_max_angle_delta / 6.0) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
argos::CVector2 wander_force::operator()(const boid &entity) {
  /*
   * Only actually apply the wander force at the specified cadence. Otherwise
   * random perturbations between [-n, n] will sum to 0 (no net wandering) over
   * time if the perturbations are applied every timestep.
   */
  ++m_count;
  if (m_count % m_interval != 0) {
    return {0, 0};
  }

  /* calculate circle center */
  argos::CVector2 velocity;
  if (entity.linear_velocity().Length() <= 0) {
    velocity = argos::CVector2(1, 0);
  } else {
    velocity = entity.linear_velocity();
  }

  argos::CVector2 circle_center =
      (velocity).Normalize().Scale(m_circle_distance, m_circle_distance);

  /* calculate displacement force (the actual wandering) */
  argos::CVector2 displacement(
      m_circle_radius * std::cos((m_angle + velocity.Angle()).GetValue()),
      m_circle_radius * std::sin((m_angle + velocity.Angle()).GetValue()));

  /*
   * Update wander angle so it won't have the same value next time with a
   * random pertubation in the range [-max delta, max_delta].
   */

  double val;
  if (m_use_normal) {
    val = m_normal_dist(m_rng);
  } else {
  val = -m_max_angle_delta +
      2 * m_max_angle_delta * (static_cast<double>(std::rand()) / RAND_MAX);
  }
  m_angle.FromValueInDegrees(
      std::fmod(argos::ToDegrees(m_angle).GetValue() + val, m_max_angle_delta));

  /*
   * Wandering is a combination of the current velocity, projected outward a
   * certain distance, and a displacement calculated at that point.
   *
   * There can be discontinuous jumps from a small positive angle for the wander
   * force to a large negative angle between timesteps and vice versa which play
   * havoc with robots' ability to compensate.
   *
   * So, compute the angle indirectly using sine and cosine in order to account
   * for sign differences and ensure continuity.
   */
  double angle = std::atan2(displacement.GetY() - circle_center.GetY(),
                            displacement.GetX() - circle_center.GetX());
  double angle_diff = angle - circle_center.Angle().GetValue();
  angle_diff = std::atan2(std::sin(angle_diff), std::cos(angle_diff));

  if (std::fabs(angle_diff - m_last_angle) > M_PI) {
    angle_diff -= std::copysign(2*M_PI, angle_diff);
  }
  m_last_angle = angle_diff;

  argos::CVector2 wander((circle_center + displacement).Length(),
                         argos::CRadians(angle_diff));
  return wander.Normalize() * m_max;
} /* operator()() */

NS_END(steering2D, robotics, rcppsw);
