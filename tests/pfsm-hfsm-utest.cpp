/**
 * @file fsm-hfsm-test.cpp
 *
 * @copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_PREFIX_ALL
#include "rcppsw/patterns/fsm/hfsm.hpp"
#include <catch.hpp>
#include <memory>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace fsm = rcppsw::patterns::fsm;
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
      s4(hfsm::top_state()), s5(hfsm::top_state()), s6(hfsm::top_state()),
      RCPPSW_HFSM_DEFINE_STATE_MAP(mc_state_map,
                                   RCPPSW_HFSM_STATE_MAP_ENTRY(&s1), RCPPSW_HFSM_STATE_MAP_ENTRY(&s2),
                           RCPPSW_HFSM_STATE_MAP_ENTRY(&s3), RCPPSW_HFSM_STATE_MAP_ENTRY(&s4),
                           RCPPSW_HFSM_STATE_MAP_ENTRY(&s5), RCPPSW_HFSM_STATE_MAP_ENTRY(&s6)) {}

  void event1(void) {
    RCPPSW_HFSM_DEFINE_TRANSITION_MAP(kMAP){STATE2,
                                    STATE3,
                                    STATE1,
                                    fsm::event_signal::ekFATAL,
                                    fsm::event_signal::ekFATAL,
                                    fsm::event_signal::ekFATAL};
    external_event(kMAP[current_state()],
                   std::make_unique<fsm::event_data>(1));
  }
  void event2(void) {
    RCPPSW_HFSM_DEFINE_TRANSITION_MAP(kMAP){fsm::event_signal::ekIGNORED,
                                    STATE4,
                                    fsm::event_signal::ekFATAL,
                                    STATE4,
                                    STATE4,
                                    STATE5};
    external_event(kMAP[current_state()],
                   std::make_unique<fsm::event_data>(2));
  }

private:
  RCPPSW_HFSM_STATE_DECLARE_ND(test_fsm, s1);
  RCPPSW_HFSM_STATE_DECLARE_ND(test_fsm, s2);
  RCPPSW_HFSM_STATE_DECLARE_ND(test_fsm, s3);
  RCPPSW_HFSM_STATE_DECLARE_ND(test_fsm, s4);
  RCPPSW_HFSM_STATE_DECLARE_ND(test_fsm, s5);
  RCPPSW_HFSM_STATE_DECLARE_ND(test_fsm, s6);

  RCPPSW_HFSM_DEFINE_STATE_MAP_ACCESSOR(state_map, index) {
    return &mc_state_map[index];
  }
  RCPPSW_HFSM_DECLARE_STATE_MAP(state_map, mc_state_map, ST_MAX_STATES);
};

RCPPSW_HFSM_STATE_DEFINE_ND(test_fsm, s1) {
  printf("Executing state1\n");
  return fsm::event_signal::ekHANDLED;
}
RCPPSW_HFSM_STATE_DEFINE_ND(test_fsm, s2) {
  printf("Executing state2\n");
  return fsm::event_signal::ekHANDLED;
}

RCPPSW_HFSM_STATE_DEFINE_ND(test_fsm, s3) {
  printf("Executing state3\n");
  return fsm::event_signal::ekHANDLED;
}

RCPPSW_HFSM_STATE_DEFINE_ND(test_fsm, s4) {
  printf("Executing state4\n");
  internal_event(STATE5, std::make_unique<fsm::event_data>(4));
  return fsm::event_signal::ekHANDLED;
}
RCPPSW_HFSM_STATE_DEFINE_ND(test_fsm, s5) {
  printf("Executing state5\n");
  return fsm::event_signal::ekHANDLED;
}

RCPPSW_HFSM_STATE_DEFINE_ND(test_fsm, s6) {
  printf("Executing state6\n");
  return fsm::event_signal::ekHANDLED;
}

/*******************************************************************************
 * Test Functions
 ******************************************************************************/
CATCH_TEST_CASE("sanity-test", "[rpfsm::hfsm]") {
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

CATCH_TEST_CASE("event-test", "[rpfsm::hfsm]") {
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
