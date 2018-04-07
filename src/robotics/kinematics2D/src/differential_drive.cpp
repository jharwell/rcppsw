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
#include "rcppsw/robotics/kinematics2D/differential_drive.hpp"
#include "rcsw/common/fpc.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, kinematics2D);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
differential_drive::differential_drive(const std::shared_ptr<er::server>& server,
                                       drive_type type,
                                       double wheel_radius,
                                       double axle_length,
                                       double max_output)
    : er::client(server),
    m_drive_type(type),
    m_wheel_radius(wheel_radius),
    m_axle_length(axle_length),
    m_max_output(max_output) {
  if (ERROR == client::attmod("differential_drive")) {
    client::insmod("differential_drive",
                   rcppsw::er::er_lvl::DIAG,
                   rcppsw::er::er_lvl::VER);
  }
    }

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
status_t differential_drive::actuate(const kinematics::twist& twist) {
    switch (m_drive_type) {
      case kTankDrive:
      ER_ERR("Cannot actuate: Not in curvature drive mode");
      return ERROR;
      break;
    case kCurvatureDrive:
      return curvature_drive(twist, false);
      break;
    default:
      ER_FATAL_SENTINEL("Bad drive type: %d", m_drive_type);
  } /* switch() */
} /* actuate() */

status_t differential_drive::tank_drive(double left_speed,
                                        double right_speed,
                                        bool square_inputs) {
  ER_CHECK(kTankDrive == m_drive_type,
           "Cannot actuate: not in tank drive mode");

  m_left_linspeed = limit(left_speed);
  m_right_linspeed = limit(right_speed);

  if (square_inputs) {
    m_left_linspeed = std::copysign(std::pow(m_left_linspeed, 2), m_left_linspeed);
    m_right_linspeed = std::copysign(std::pow(m_right_linspeed, 2), m_right_linspeed);
  }

  ER_VER("Normalized wheel speeds: (%f, %f)", m_left_linspeed, m_right_linspeed);
  set_linear_velocity(m_left_linspeed * m_max_output,
                      m_right_linspeed * m_max_output);
  return OK;

error:
  return ERROR;
} /* tank_drive() */

status_t differential_drive::curvature_drive(const kinematics::twist& twist,
                                        bool hard_turn) {
  double v_x = limit(twist.linear.x);
  double w_z = limit(twist.angular.z);

  double w = w_z * m_axle_length / 2;
  double v = v_x;

  std::pair<double, double> outputs;

  ER_CHECK(kCurvatureDrive == m_drive_type,
           "Cannot actuate: not in curvature drive mode");
  ER_VER("angular_vel: %f linear_vel: %f", w, v);

  if (hard_turn) {
    if (w_z < 0) {
      outputs = normalize_outputs(std::make_pair(w, -w));
    } else {
      outputs = normalize_outputs(std::make_pair(-w, w));
    }
  } else {
    outputs = normalize_outputs(std::make_pair(v - w, v + w));
  }
  ER_VER("Normalized wheel speeds: (%f, %f)", outputs.first, outputs.second);

  m_left_linspeed = outputs.first;
  m_right_linspeed = outputs.second;
  set_linear_velocity(m_left_linspeed * m_max_output,
                      m_right_linspeed * m_max_output);
  return OK;

error:
  return ERROR;
} /* curvature_drive() */

double differential_drive::limit(double value) const {
  return std::max(std::min(value, 1.0), -1.0);
} /* limit() */

std::pair<double, double> differential_drive::normalize_outputs(
    const std::pair<double, double>& outputs) const {
  double magnitude = std::max(std::abs(outputs.first), std::abs(outputs.second));

  if (magnitude > 1.0) {
    return std::make_pair(outputs.first/magnitude, outputs.second/magnitude);
  }
  return outputs;
} /* normalize_outputs() */

NS_END(kinematics2D, robotics, rcppsw);
