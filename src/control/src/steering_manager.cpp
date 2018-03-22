/**
 * @file steering_manager.cpp
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
#include "rcppsw/control/steering_manager.hpp"
#include "rcppsw/control/force_params.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
steering_manager::steering_manager(boid& entity,
                                   const struct force_params* params)
    : m_entity(entity),
      m_force(),
      m_avoidance_force(&params->avoidance),
      m_arrival_force(&params->arrival),
      m_seek_force(),
      m_wander_force(&params->wander) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void steering_manager::do_seek_through(const argos::CVector2& target) {
  m_force += m_arrival_force(m_entity, target);
} /* do_seek_through() */

void steering_manager::do_seek_to(const argos::CVector2& target) {
  m_force += m_seek_force(m_entity, target);
} /* do_seek_to() */

void steering_manager::do_wander(void) {
  m_force += m_wander_force(m_entity);
} /* do_wander() */

NS_END(control, rcppsw);
