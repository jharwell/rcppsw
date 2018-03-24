/**
 * @file kinematics2D.cpp
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
#include "rcppsw/control/kinematics2D.hpp"
#include "rcppsw/control/kinematics2D_params.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
kinematics2D::kinematics2D(boid& entity,
                           const struct kinematics2D_params* params)
    : m_entity(entity),
      m_force(),
      m_avoidance_force(&params->avoidance),
      m_arrival_force(&params->arrival),
      m_seek_force(),
      m_wander_force(&params->wander),
      m_polar_force(&params->polar) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void kinematics2D::do_seek_through(const argos::CVector2& target) {
  m_force += m_arrival_force(m_entity, target);
} /* do_seek_through() */

void kinematics2D::do_seek_to(const argos::CVector2& target) {
  m_force += m_seek_force(m_entity, target);
} /* do_seek_to() */

void kinematics2D::do_wander(void) {
  m_force += m_wander_force(m_entity);
} /* do_wander() */

NS_END(control, rcppsw);
