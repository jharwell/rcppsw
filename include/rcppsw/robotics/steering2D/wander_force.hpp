/**
 * @file wander_force.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_STEERING2D_WANDER_FORCE_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_STEERING2D_WANDER_FORCE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <random>
#include "rcppsw/common/common.hpp"
#include "rcppsw/robotics/steering2D/boid.hpp"
#include "rcppsw/math/radians.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, steering2D);
struct wander_force_params;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @class wander_force
 * @ingroup control
 *
 * @brief A small random perturbation that can be added to a robot's current
 * velocity in order to make it move randomly throughout the environment. This
 * can be thought of as a directed random walk.
 */
class wander_force {
 public:
  explicit wander_force(const struct wander_force_params* params);

  math::vector2d operator()(const boid& entity);

 private:
  /* clang-format off */
  uint                             m_interval;
  int                              m_count{-1};
  bool                             m_use_normal;
  double                           m_max;
  double                           m_circle_distance;
  double                           m_circle_radius;
  double                           m_max_angle_delta;
  double                           m_last_angle{0.0};
  math::radians                    m_angle;
  std::random_device               m_rng{};
  std::normal_distribution<double> m_normal_dist;
  /* clang-format on */
};

NS_END(steering2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_STEERING2D_WANDER_FORCE_HPP_ */
