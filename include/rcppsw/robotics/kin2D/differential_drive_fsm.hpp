/**
 * @file differential_drive_fsm.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_KIN2D_DIFFERENTIAL_DRIVE_FSM_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_KIN2D_DIFFERENTIAL_DRIVE_FSM_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <utility>
#include <string>

#include "rcppsw/patterns/state_machine/simple_fsm.hpp"
#include "rcppsw/math/radians.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, kin2D);

namespace state_machine = rcppsw::patterns::state_machine;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class differential_drive_fsm
 * @ingroup rcppsw robotics kin2D
 *
 * @brief Handles the control of the differential drive for the robot, in terms
 * of how quickly/how much to change wheel speeds. Does NOT actually change the
 * wheel speeds.
 */
class differential_drive_fsm final : public state_machine::simple_fsm {
 public:
  /**
   * @brief Initialize the FSM.
   *
   * @param max_speed Maximum wheel velocity.
   * @param soft_turn_max Maximum angle difference between current and new
   *                      heading that will not trigger a hard (in place) turn.
   */
  differential_drive_fsm(double max_speed,
                         const math::radians& soft_turn_max);

  /*
   * @brief Gets a direction vector as input and transforms it into wheel
   * speeds internally.
   *
   * @param speed The new linear speed of the robot.
   * @param angle The difference from the robot's CURRENT heading (i.e."change
   *              this much from the direction you are currently going in").
   */
  void change_velocity(double speed, const math::radians& angle);

  std::pair<double, double> wheel_speeds(void) const { return m_wheel_speeds; }

 private:
  /**
   * @brief Set the wheel speeds according to the heading.
   *
   * @param speed1 Speed of left wheel.
   * @param speed2 Speed of right wheel.
   * @param heading Robot heading, which is used to determine which speed to
   *                apply to which wheel, so that the proper turn direction is
   *                executed.
   */
  void set_wheel_speeds(double speed1, double speed2, math::radians heading);

  /**
   * @brief Clamp the desired speed to a maximum (maximum will be either the
   * global maximum or the throttled maximum).
   *
   * @param desired The desired wheel speed.
   *
   * @return The clamped speed.
   */
  double clamp_wheel_speed(double desired);

  /*
   * @enum The robot can be in three different turning states.
   */
  enum fsm_states {
    kST_SOFT_TURN,  /// Both wheels rotating forward at slightly different speeds
    kST_HARD_TURN,  /// Wheels are turning with opposite & max speeds
    kST_MAX_STATES
  };

  /**
   * @brief Turning data for input into the state machine, to translate the
   * desired heading change into wheel speeds.
   */
  struct turn_data final : public state_machine::event_data {
    turn_data(double speed_in,
              math::radians angle_in)
        : speed(speed_in), angle(angle_in) {}

    double speed;
    math::radians angle;
  };

  /**
   * @brief Robots in this state will execute a gradual turn in the desired
   * heading direction. Threshold for this type of turn is controlled by
   * parameters.
   */
  FSM_STATE_DECLARE(differential_drive_fsm, soft_turn, turn_data);

  /**
   * @brief Robots in this state will execute an in-place turn (a spin really)
   * in the direction of the desired heading. Threshold for this type of turn
   * is controlled by parameters.
   */
  FSM_STATE_DECLARE(differential_drive_fsm, hard_turn, turn_data);

  FSM_DEFINE_STATE_MAP_ACCESSOR(state_map, index) override {
    FSM_DEFINE_STATE_MAP(state_map, kSTATE_MAP){
        FSM_STATE_MAP_ENTRY(&soft_turn),
        FSM_STATE_MAP_ENTRY(&hard_turn),
    };
    FSM_VERIFY_STATE_MAP(state_map, kSTATE_MAP, kST_MAX_STATES);
    return &kSTATE_MAP[index];
  }
  /* clang-format off */
  const double              mc_max_speed;
  const math::radians       mc_soft_turn_max;
  std::pair<double, double> m_wheel_speeds;
  /* clang-format on */
};

NS_END(kin2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_KIN2D_DIFFERENTIAL_DRIVE_FSM_HPP_ */
