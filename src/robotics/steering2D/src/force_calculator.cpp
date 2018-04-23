/**
 * @file force_calculator.cpp
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/robotics/steering2D/force_calculator.hpp"
#include "rcppsw/robotics/steering2D/force_calculator_params.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, steering2D);

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
force_calculator::force_calculator(const std::shared_ptr<er::server>& server,
                                   boid& entity,
                                   const struct force_calculator_params* params)
    : er::client(server),
      m_entity(entity),
      m_avoidance_force(&params->avoidance),
      m_arrival_force(&params->arrival),
      m_wander_force(&params->wander),
      m_polar_force(&params->polar) {
  if (ERROR == client::attmod("force_calculator")) {
    client::insmod("force_calculator",
                   rcppsw::er::er_lvl::DIAG,
                   rcppsw::er::er_lvl::NOM);
  }
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
kinematics::twist force_calculator::to_twist(const argos::CVector2& force) const {
  kinematics::twist twist;
  twist.linear.x = force.Length();
  twist.angular.z =
      (force - m_entity.linear_velocity()).Length() *
      std::sin((force - m_entity.linear_velocity()).Angle().GetValue());
  if (m_entity.linear_velocity().Length() > 0) {
    twist.angular.z /= m_entity.linear_velocity().Length();
  } else {
    twist.angular.z = 0;
  }
  return twist;
} /* to_twist() */

void force_calculator::seek_through(const argos::CVector2& target) {
  argos::CVector2 force = m_seek_force(m_entity, target);
  ER_DIAG("Seek force: (%f, %f)@%f [%f]",
          force.GetX(),
          force.GetY(),
          force.Angle().GetValue(),
          force.Length());
  accum_force(force);
} /* seek_through() */

void force_calculator::seek_to(const argos::CVector2& target) {
  argos::CVector2 force = m_arrival_force(m_entity, target);
  ER_DIAG("Arrival force: (%f, %f)@%f [%f]",
          force.GetX(),
          force.GetY(),
          force.Angle().GetValue(),
          force.Length());
  accum_force(force);
} /* seek_to() */

void force_calculator::wander(void) {
  argos::CVector2 force = m_wander_force(m_entity);
  ER_DIAG("Wander force: (%f, %f)@%f [%f]",
          force.GetX(),
          force.GetY(),
          force.Angle().GetValue(),
          force.Length());
  accum_force(force);
} /* wander() */

void force_calculator::avoidance(const argos::CVector2& closest_obstacle) {
  argos::CVector2 force = m_avoidance_force(m_entity, closest_obstacle);
  ER_DIAG("Avoidance force: (%f, %f)@%f [%f]",
          force.GetX(),
          force.GetY(),
          force.Angle().GetValue(),
          force.Length());
  accum_force(force);
} /* avoidance() */

NS_END(steering2D, robotics, rcppsw);
