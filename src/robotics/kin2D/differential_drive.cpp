/**
 * @file differential_drive.cpp
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
#include "rcppsw/robotics/kin2D/differential_drive.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, kin2D);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
differential_drive::differential_drive(
    const hal::actuators::differential_drive_actuator& actuator,
    drive_type type,
    double wheel_radius,
    double axle_length,
    double max_speed,
    const math::radians& soft_turn_max)
    : ER_CLIENT_INIT("rcppsw.robotics.kin2D.differential_drive"),
      m_drive_type(type),
      m_wheel_radius(wheel_radius),
      m_axle_length(axle_length),
      m_max_speed(max_speed),
      m_fsm(max_speed, soft_turn_max),
      m_actuator(actuator) {}

differential_drive::differential_drive(
    const hal::actuators::differential_drive_actuator& actuator,
    drive_type type,
    double wheel_radius,
    double axle_length,
    double max_speed)
    : differential_drive{actuator,
                         type,
                         wheel_radius,
                         axle_length,
                         max_speed,
                         math::radians()} {
  assert(kFSMDrive != type);
}
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
status_t differential_drive::actuate(const kin::twist& twist) {
  switch (m_drive_type) {
    case kTankDrive:
    case kFSMDrive:
      ER_ERR("Cannot actuate: Not in curvature drive mode");
      return ERROR;
      break;
    case kCurvatureDrive:
      return curvature_drive(twist, m_hard_turn);
    default:
      ER_FATAL_SENTINEL("Bad drive type: %d", m_drive_type);
  } /* switch() */
  return ERROR;
} /* actuate() */

status_t differential_drive::fsm_drive(double speed,
                                       const math::radians& angle,
                                       const std::pair<bool, bool>& force) {
  std::pair<double, double> speeds;
  ER_CHECK(kFSMDrive == m_drive_type, "Cannot actuate: not in FSM drive mode");
  m_fsm.change_velocity(speed, angle, force);
  speeds = m_fsm.wheel_speeds();
  speeds = normalize_outputs(speeds);
  m_left_linspeed = speeds.first;
  m_right_linspeed = speeds.second;
  m_actuator.set_wheel_speeds(m_left_linspeed, m_right_linspeed);
  return OK;

error:
  return ERROR;
} /* fsm_drive() */

status_t differential_drive::tank_drive(double left_speed,
                                        double right_speed,
                                        bool square_inputs) {
  ER_CHECK(kTankDrive == m_drive_type, "Cannot actuate: not in tank drive mode");

  m_left_linspeed = limit(left_speed);
  m_right_linspeed = limit(right_speed);

  if (square_inputs) {
    m_left_linspeed =
        std::copysign(std::pow(m_left_linspeed, 2), m_left_linspeed);
    m_right_linspeed =
        std::copysign(std::pow(m_right_linspeed, 2), m_right_linspeed);
  }

  ER_TRACE("Normalized linear wheel speeds: (%f, %f)",
           m_left_linspeed,
           m_right_linspeed);
  m_actuator.set_wheel_speeds(m_left_linspeed, m_right_linspeed);
  return OK;

error:
  return ERROR;
} /* tank_drive() */

status_t differential_drive::curvature_drive(const kin::twist& twist,
                                             bool hard_turn) {
  double w = twist.angular.z;
  double v = twist.linear.x;

  std::pair<double, double> outputs;

  ER_CHECK(kCurvatureDrive == m_drive_type,
           "Cannot actuate: not in curvature drive mode");
  ER_TRACE("Twist.linear.x: %f twist.angular.z: %f",
           twist.linear.x,
           twist.angular.z);

  if (hard_turn) {
    if (w < 0) {
      outputs = normalize_outputs(std::make_pair(m_max_speed, -m_max_speed));
    } else {
      outputs = normalize_outputs(std::make_pair(-m_max_speed, m_max_speed));
    }
  } else {
    outputs = normalize_outputs(std::make_pair((v - w * m_axle_length / 2),
                                               (v + w * m_axle_length / 2)));
  }
  ER_TRACE("Normalized linear wheel speeds: (%f, %f)",
           outputs.first,
           outputs.second);

  m_left_linspeed = outputs.first;
  m_right_linspeed = outputs.second;
  m_actuator.set_wheel_speeds(m_left_linspeed, m_right_linspeed);
  m_hard_turn = false;
  return OK;

error:
  return ERROR;
} /* curvature_drive() */

 double differential_drive::limit(double value) const {
  return std::max(std::min(value, m_max_speed), -m_max_speed);
} /* limit() */

std::pair<double, double> differential_drive::normalize_outputs(
    const std::pair<double, double>& outputs) const {
  return std::make_pair(limit(outputs.first), limit(outputs.second));
} /* normalize_outputs() */

NS_END(kin2D, robotics, rcppsw);
