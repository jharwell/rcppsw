/**
 * @file differential_drive.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_KINEMATICS2D_DIFFERENTIAL_DRIVE_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_KINEMATICS2D_DIFFERENTIAL_DRIVE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"
#include "rcppsw/robotics/kinematics2D/model.hpp"
#include "rcppsw/er/client.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, kinematics2D);

/*******************************************************************************
 * Struct Definitions
 ******************************************************************************/

/**
 * @class differential_drive
 * @ingroup robotics kinematics2D
 *
 * @brief Model for a TWO wheel differential drive robot, providing a number of
 * operating modes:
 *
 * \ref kTankDrive
 * \ref kCurvatureDrive
 */
class differential_drive : public kinematics2D::model, public er::client {
 public:
  enum drive_type {
    kTankDrive,  /// Controls like those of a tank
    kCurvatureDrive  /// Control via curving path rather than heading changes
  };

  /**
   * @brief Initialize differential drive kinematics model.
   *
   * @param type The drive type; see \ref drive_type
   * @param wheel_radius Radius of robot wheels.
   * @param axle_length Lateral distance between wheels
   * @param max_output Maximum output of wheels (i.e. max wheel speed).
   */
  differential_drive(const std::shared_ptr<er::server>& server,
                     drive_type type,
                     double wheel_radius,
                     double axle_length,
                     double max_output);

  /* kinematics model interface */
  status_t actuate(const kinematics::twist& twist) override;
  void stop(void) override { set_linear_velocity(0, 0); }
  double max_speed(void) const override { return m_max_output * m_wheel_radius; }

  /**
   * @brief Hook for derived classes to actually call into low level drivers to
   * do actuation. Note that this is LINEAR velocity, NOT WHEEL velocity.
   */
  virtual void set_linear_velocity(double left, double right) = 0;

  double current_speed(void) const {
    return (m_left_linspeed + m_right_linspeed) / 2;
  }
  double left_linspeed(void) const { return m_left_linspeed; }
  double right_linspeed(void) const { return m_right_linspeed; }
  double axle_length(void) const { return m_axle_length; }

  /**
   * Curvature drive method. This is the most common differential drive method,
   * and the one that ROS generally has for differential drive robots.
   *
   * Basically, you control the curvature of the robot's path with the twist,
   * rather than the rate of its heading change via wheel speed changes. This
   * makes the robot better behaved when moving quickly. Also provides an
   * override for "hard" turns (i.e. turning in place).
   *
   * @param twist The calculated twist for the robot. Only the linear.x and
   *                    angular.z components are used. Both values are
   *                    [-1.0..1.0]. Clockwise is positive in z, and forward is
   *                    positive in x.
   * @param hard_turn If set, the robot will turn in place instead of following
   *                    a curved trajectory.
   *
   * @return \ref status_t.
   */
  status_t curvature_drive(const kinematics::twist& twist, bool hard_turn);

  /**
   * Tank drive method (i.e. how a tank moves.)
   *
   * @param left_speed The robot left side's speed along the X axis
   *                   [-1.0..1.0]. Forward is positive.
   * @param right_speed The robot right side's speed along the X axis
   *                    [-1.0..1.0]. Forward is positive.
   * @param square_inputs If set, decreases the input sensitivity at low
   *                      speeds.
   * @return \ref status_t.
   */
  status_t tank_drive(double left_speed, double right_speed, bool square_inputs);

 private:
  /**
   * @brief Normalize all wheel outputs to within the [-1.0, 1.0] range.
   */
  std::pair<double, double> normalize_outputs(const std::pair<double, double>& outputs) const;

  /**
   * @brief Limit the value to [-1, 1].
   */
  double limit(double value) const;

  enum drive_type m_drive_type;
  double m_wheel_radius;
  double m_axle_length;
  double m_max_output;
  double m_left_linspeed{0.0};
  double m_right_linspeed{0.0};
};

NS_END(kinematics2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_KINEMATICS2D_DIFFERENTIAL_DRIVE_HPP_ */
