/**
 * @file fsm-simple_fsm-test.cpp
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
#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_PREFIX_ALL
#include "rcppsw/patterns/fsm/event.hpp"
#include "rcppsw/patterns/fsm/simple_fsm.hpp"
#include <catch.hpp>
#include <memory>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace fsm = rcppsw::patterns::fsm;
namespace er = rcppsw::er;

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
class test_fsm : public fsm::simple_fsm {
public:
  enum states { STATE1, STATE2, STATE3, STATE4, STATE5, STATE6, ST_MAX_STATES };

  explicit test_fsm(void)
      : fsm::simple_fsm(ST_MAX_STATES),
      RCPPSW_FSM_DEFINE_STATE_MAP(mc_state_map,
                           RCPPSW_FSM_STATE_MAP_ENTRY(&s1), RCPPSW_FSM_STATE_MAP_ENTRY(&s2),
                           RCPPSW_FSM_STATE_MAP_ENTRY(&s3), RCPPSW_FSM_STATE_MAP_ENTRY(&s4),
                           RCPPSW_FSM_STATE_MAP_ENTRY(&s5), RCPPSW_FSM_STATE_MAP_ENTRY(&s6)) {}

  RCPPSW_FSM_STATE_DECLARE_ND(test_fsm, s1);
  RCPPSW_FSM_STATE_DECLARE_ND(test_fsm, s2);
  RCPPSW_FSM_STATE_DECLARE_ND(test_fsm, s3);
  RCPPSW_FSM_STATE_DECLARE_ND(test_fsm, s4);
  RCPPSW_FSM_STATE_DECLARE_ND(test_fsm, s5);
  RCPPSW_FSM_STATE_DECLARE_ND(test_fsm, s6);
  void event1(void) {
    RCPPSW_FSM_DEFINE_TRANSITION_MAP(kMAP){STATE2,
                                    STATE3,
                                    STATE1,
                                    fsm::event_signal::ekFATAL,
                                    fsm::event_signal::ekFATAL,
                                    fsm::event_signal::ekFATAL};
    external_event(kMAP[current_state()], nullptr);
  }
  void event2(void) {
    RCPPSW_FSM_DEFINE_TRANSITION_MAP(kMAP){fsm::event_signal::ekIGNORED,
                                    STATE4,
                                    fsm::event_signal::ekFATAL,
                                    STATE4,
                                    STATE4,
                                    STATE5};
    external_event(kMAP[current_state()], nullptr);
  }

  RCPPSW_FSM_DECLARE_STATE_MAP(state_map, mc_state_map, ST_MAX_STATES);
  RCPPSW_FSM_DEFINE_STATE_MAP_ACCESSOR(state_map, index) override {
    return &mc_state_map[index];
  }
};

RCPPSW_FSM_STATE_DEFINE_ND(test_fsm, s1) {
  printf("Executing state1\n");
  return fsm::event_signal::ekHANDLED;
}
RCPPSW_FSM_STATE_DEFINE_ND(test_fsm, s2) {
  printf("Executing state2\n");
  return fsm::event_signal::ekHANDLED;
}

RCPPSW_FSM_STATE_DEFINE_ND(test_fsm, s3) {
  printf("Executing state3\n");
  return fsm::event_signal::ekHANDLED;
}

RCPPSW_FSM_STATE_DEFINE_ND(test_fsm, s4) {
  printf("Executing state4\n");
  internal_event(STATE5);
  return fsm::event_signal::ekHANDLED;
}
RCPPSW_FSM_STATE_DEFINE_ND(test_fsm, s5) {
  printf("Executing state5\n");
  return fsm::event_signal::ekHANDLED;
}

RCPPSW_FSM_STATE_DEFINE_ND(test_fsm, s6) {
  printf("Executing state6\n");
  return fsm::event_signal::ekHANDLED;
}
/*******************************************************************************
 * Test Functions
 ******************************************************************************/
CATCH_TEST_CASE("sanity-test", "[rpfsm::simple_fsm]") {
  test_fsm fsm;

  CATCH_REQUIRE(fsm.current_state() == test_fsm::STATE1);
  fsm.event1();
  CATCH_REQUIRE(fsm.current_state() == test_fsm::STATE2);
  fsm.event1();
  CATCH_REQUIRE(fsm.current_state() == test_fsm::STATE3);
  fsm.init();
  CATCH_REQUIRE(fsm.current_state() == test_fsm::STATE1);
}

CATCH_TEST_CASE("event-test", "[rpfsm::simple_fsm]") {
  test_fsm fsm;
  fsm.init();
  CATCH_REQUIRE(fsm.current_state() == test_fsm::STATE1);
  fsm.event2();
  CATCH_REQUIRE(fsm.current_state() == test_fsm::STATE1);
  fsm.event1();
  CATCH_REQUIRE(fsm.current_state() == test_fsm::STATE2);
  fsm.event2();
  CATCH_REQUIRE(fsm.current_state() == test_fsm::STATE5);
}
