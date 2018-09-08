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
#include "rcppsw/robotics/kinematics2D/differential_drive_fsm.hpp"
#include "rcppsw/robotics/hal/actuators/differential_drive_actuator.hpp"

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
 * \ref kFSMDrive
 */
class differential_drive : public kinematics2D::model,
                           public er::client<differential_drive> {
 public:
  enum drive_type {
    kTankDrive,  /// Controls like those of a tank
    kCurvatureDrive,  /// Control via curving path rather than heading changes
    kFSMDrive  /// Control via soft/hard turn FSM
  };

  /**
   * @brief Initialize differential drive kinematics model.
   *
   * @param type The drive type; see \ref drive_type
   * @param actuator The underlying differential drive actuator via HAL.
   * @param wheel_radius Radius of robot wheels.
   * @param axle_length Lateral distance between wheels.
   * @param max_speed Maximum output of wheels (i.e. max wheel speed).
   * @param soft_turn_max Maximum angle difference between current and new
   *                      heading that will not trigger a hard (in place)
   *                      turn. Only used by \ref kFSMDrive.
   */
  differential_drive(const std::string& er_parent,
                     const hal::actuators::differential_drive_actuator& actuator,
                     drive_type type,
                     double wheel_radius,
                     double axle_length,
                     double max_speed,
                     argos::CRadians soft_turn_max);

  differential_drive(const std::string& er_parent,
                     const hal::actuators::differential_drive_actuator& actuator,
                     drive_type type,
                     double wheel_radius,
                     double axle_length,
                     double max_speed);

  /* kinematics model interface */
  status_t actuate(const kinematics::twist& twist) override;
  void stop(void) override { m_actuator.stop_wheels(); }
  double max_speed(void) const override { return m_max_speed; }

  status_t actuate(const kinematics::twist& twist, bool hard_turn) {
    m_hard_turn = hard_turn;
    return actuate(twist);
  }

  /**
  * @brief Call into low level drivers to do actuation. Note that this is LINEAR
  * velocity, NOT WHEEL velocity.
  */
  void set_wheel_speeds(double left, double right) {
    m_actuator.set_wheel_speeds(left, right);
  }

  /*
   * @brief Gets a new speed/heading angle and transforms it into wheel commands
   * via an FSM.
   *
   * @param speed The new linear speed of the robot.
   * @param angle The difference from the robot's CURRENT heading (i.e."change
   *              this much from the direction you are currently going in").
   *
   * @param force First argument: Whether or not a soft turn should be performed,
   *                              regardless of the angle difference.
   *              Second arguent: Whether or not a hard turn should be
   *                              performed, regardless of angle difference.
   *              If \c {false,false} the parameterized threshold is used
   *              instead.
   *
   *              This parameter is useful for PID-loop like things where you do
   *              NOT want the robot to execute in place turns.
   *
   * @return \ref status_t.
   */
  status_t fsm_drive(double speed,
                     const argos::CRadians& angle,
                     const std::pair<bool, bool>& force = std::make_pair(false,
                                                                         false));
  /**
   * @brief Return the current speed of the robot (average of the 2 wheel
   * speeds).
   */
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

  // clang-format off
  bool                                        m_hard_turn{false};
  enum drive_type                             m_drive_type;
  double                                      m_wheel_radius;
  double                                      m_axle_length;
  double                                      m_max_speed;
  double                                      m_left_linspeed{0.0};
  double                                      m_right_linspeed{0.0};
  differential_drive_fsm                      m_fsm;
  hal::actuators::differential_drive_actuator m_actuator;
  // clang-format on
};

NS_END(kinematics2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_KINEMATICS2D_DIFFERENTIAL_DRIVE_HPP_ */
