/**
 * @file differential_drive_fsm.cpp
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
 * Includesp
 ******************************************************************************/
#include "rcppsw/robotics/kin2D/differential_drive_fsm.hpp"
#include "rcppsw/math/range.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, kin2D);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
differential_drive_fsm::differential_drive_fsm(double max_speed,
                                               const math::radians& soft_turn_max)
    : state_machine::simple_fsm(kST_MAX_STATES),
      mc_max_speed(max_speed),
      mc_soft_turn_max(soft_turn_max),
      m_wheel_speeds() {}

/*******************************************************************************
 * Events
 ******************************************************************************/
void differential_drive_fsm::change_velocity(double speed,
                                             const math::radians& angle) {
  FSM_DEFINE_TRANSITION_MAP(kTRANSITIONS){
      kST_SOFT_TURN, /* slow turn */
      kST_HARD_TURN, /* hard turn */
  };
  FSM_VERIFY_TRANSITION_MAP(kTRANSITIONS, kST_MAX_STATES);
  external_event(kTRANSITIONS[current_state()],
                 rcppsw::make_unique<turn_data>(speed, angle));
} /* set_rel_heading() */

/*******************************************************************************
 * States
 ******************************************************************************/

FSM_STATE_DEFINE(differential_drive_fsm, soft_turn, turn_data* data) {
  math::range<math::radians> range(-mc_soft_turn_max, mc_soft_turn_max);
  math::radians angle = data->angle;
  /* too large of a direction change for soft turn--go to hard turn */
  if (!range.contains(angle.signed_normalize())) {
    internal_event(kST_HARD_TURN);
    return state_machine::event_signal::ekHANDLED;
  }

  /* Both wheels go straight, but one is faster than the other */
  double speed_factor = std::fabs((mc_soft_turn_max -
                                   math::radians::abs(data->angle)) /
                                  mc_soft_turn_max);
  double base_speed = std::min(data->speed, mc_max_speed);
  double speed1 = base_speed - base_speed * (1.0 - speed_factor);
  double speed2 = base_speed + base_speed * (1.0 - speed_factor);
  set_wheel_speeds(speed1, speed2, data->angle);
  return state_machine::event_signal::ekHANDLED;
}
FSM_STATE_DEFINE(differential_drive_fsm, hard_turn, turn_data* data) {
  math::range<math::radians> range(-mc_soft_turn_max, mc_soft_turn_max);
  math::radians angle = data->angle;

  /* too little of a direction change for hard turn--go to soft turn */
  if (range.contains(angle.signed_normalize())) {
    internal_event(kST_SOFT_TURN);
    return state_machine::event_signal::ekHANDLED;
  }
  set_wheel_speeds(-mc_max_speed, mc_max_speed, data->angle);
  return state_machine::event_signal::ekHANDLED;
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void differential_drive_fsm::set_wheel_speeds(double speed1,
                                              double speed2,
                                              math::radians heading) {
  if (heading > math::radians::kZERO) {
    /* Turn Left */
    m_wheel_speeds.first = speed1;
    m_wheel_speeds.second = speed2;
  } else {
    /* Turn Right */
    m_wheel_speeds.first = speed2;
    m_wheel_speeds.second = speed1;
  }
}
NS_END(kin2D, robotics, rcppsw);
