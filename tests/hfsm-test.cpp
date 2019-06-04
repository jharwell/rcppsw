/**
 * @file hfsm-test.cpp
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
#include "rcppsw/patterns/state_machine/hfsm.hpp"
#include <catch.hpp>
#include <memory>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace fsm = rcppsw::patterns::state_machine;
namespace er = rcppsw::er;

/*******************************************************************************
 * Test Classes
 ******************************************************************************/
class test_fsm : public fsm::hfsm {
public:
  enum states { STATE1, STATE2, STATE3, STATE4, STATE5, STATE6, ST_MAX_STATES };

  test_fsm(void)
      : fsm::hfsm(ST_MAX_STATES),
        s1(hfsm::top_state()), s2(hfsm::top_state()), s3(hfsm::top_state()),
        s4(hfsm::top_state()), s5(hfsm::top_state()), s6(hfsm::top_state()) {}

  void event1(void) {
    FSM_DEFINE_TRANSITION_MAP(kMAP){STATE2,
                                    STATE3,
                                    STATE1,
                                    fsm::event_signal::ekFATAL,
                                    fsm::event_signal::ekFATAL,
                                    fsm::event_signal::ekFATAL};
    external_event(kMAP[current_state()],
                   rcppsw::make_unique<fsm::event_data>(1));
  }
  void event2(void) {
    FSM_DEFINE_TRANSITION_MAP(kMAP){fsm::event_signal::ekIGNORED,
                                    STATE4,
                                    fsm::event_signal::ekFATAL,
                                    STATE4,
                                    STATE4,
                                    STATE5};
    external_event(kMAP[current_state()],
                   rcppsw::make_unique<fsm::event_data>(2));
  }

private:
  HFSM_STATE_DECLARE_ND(test_fsm, s1);
  HFSM_STATE_DECLARE_ND(test_fsm, s2);
  HFSM_STATE_DECLARE_ND(test_fsm, s3);
  HFSM_STATE_DECLARE_ND(test_fsm, s4);
  HFSM_STATE_DECLARE_ND(test_fsm, s5);
  HFSM_STATE_DECLARE_ND(test_fsm, s6);

  FSM_DEFINE_STATE_MAP_ACCESSOR(state_map, index) {
    FSM_DEFINE_STATE_MAP(state_map, kMAP){
        FSM_STATE_MAP_ENTRY(&s1), FSM_STATE_MAP_ENTRY(&s2),
        FSM_STATE_MAP_ENTRY(&s3), FSM_STATE_MAP_ENTRY(&s4),
        FSM_STATE_MAP_ENTRY(&s5), FSM_STATE_MAP_ENTRY(&s6)};
    return &kMAP[index];
  }
};

HFSM_STATE_DEFINE_ND(test_fsm, s1) {
  printf("Executing state1\n");
  return fsm::event_signal::ekHANDLED;
}
HFSM_STATE_DEFINE_ND(test_fsm, s2) {
  printf("Executing state2\n");
  return fsm::event_signal::ekHANDLED;
}

HFSM_STATE_DEFINE_ND(test_fsm, s3) {
  printf("Executing state3\n");
  return fsm::event_signal::ekHANDLED;
}

HFSM_STATE_DEFINE_ND(test_fsm, s4) {
  printf("Executing state4\n");
  internal_event(STATE5, rcppsw::make_unique<fsm::event_data>(4));
  return fsm::event_signal::ekHANDLED;
}
HFSM_STATE_DEFINE_ND(test_fsm, s5) {
  printf("Executing state5\n");
  return fsm::event_signal::ekHANDLED;
}

HFSM_STATE_DEFINE_ND(test_fsm, s6) {
  printf("Executing state6\n");
  return fsm::event_signal::ekHANDLED;
}

/*******************************************************************************
 * Test Functions
 ******************************************************************************/
CATCH_TEST_CASE("sanity-test", "[hfsm]") {
  test_fsm fsm;
  fsm.init();
  CATCH_REQUIRE(fsm.current_state() == test_fsm::STATE1);
  fsm.event1();
  CATCH_REQUIRE(fsm.current_state() == test_fsm::STATE2);
  fsm.event1();
  CATCH_REQUIRE(fsm.current_state() == test_fsm::STATE3);
  fsm.init();
  CATCH_REQUIRE(fsm.current_state() == test_fsm::STATE1);
}

CATCH_TEST_CASE("event-test", "[hfsm]") {
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
