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
#include <catch.hpp>
#include <memory>
#include "rcppsw/patterns/state_machine/hfsm.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
using namespace rcppsw::common;
namespace fsm = rcppsw::patterns::state_machine;

/*******************************************************************************
 * Constant Definitions
 ******************************************************************************/

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/

/*******************************************************************************
 * Global Variables
 ******************************************************************************/

/*******************************************************************************
 * Forward Declarations
 ******************************************************************************/

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
class  test_fsm : public fsm::hfsm {
 public:
  enum states {
    STATE1,
    STATE2,
    STATE3,
    STATE4,
    STATE5,
    STATE6,
    ST_MAX_STATES
  };

  explicit test_fsm(std::shared_ptr<er_server> server) :
      hfsm(server) {}

  HFSM_STATE_DECLARE(test_fsm, hfsm, base_state, s1, fsm::no_event);
  HFSM_STATE_DECLARE(test_fsm, hfsm, base_state, s2, fsm::no_event);
  HFSM_STATE_DECLARE(test_fsm, hfsm, base_state, s3, fsm::no_event);
  HFSM_STATE_DECLARE(test_fsm, hfsm, base_state, s4, fsm::no_event);
  HFSM_STATE_DECLARE(test_fsm, hfsm, base_state, s5, fsm::no_event);
  HFSM_STATE_DECLARE(test_fsm, hfsm, base_state, s6, fsm::no_event);
  void event1(void) {
    FSM_DEFINE_TRANSITION_MAP(kMAP) {
      STATE2,
          STATE3,
          STATE1,
          fsm::event::EVENT_FATAL,
          fsm::event::EVENT_FATAL,
          fsm::event::EVENT_FATAL
          };
    external_event(kMAP[current_state()], nullptr);
  }
  void event2(void) {
    FSM_DEFINE_TRANSITION_MAP(kMAP) {
          fsm::event::EVENT_IGNORED,
              STATE4,
              fsm::event::EVENT_FATAL,
          STATE4,
          STATE4,
          STATE5
          };
    external_event(kMAP[current_state()], nullptr);
  }

  FSM_DEFINE_STATE_MAP_ACCESSOR(state_map) {
    FSM_DEFINE_STATE_MAP(state_map, kMAP) {
      FSM_STATE_MAP_ENTRY(&s1),
          FSM_STATE_MAP_ENTRY(&s2),
          FSM_STATE_MAP_ENTRY(&s3),
          FSM_STATE_MAP_ENTRY(&s4),
          FSM_STATE_MAP_ENTRY(&s5),
          FSM_STATE_MAP_ENTRY(&s6)
          };
    return &kMAP[0];
  }
  uint8_t current_state(void) const { return m_current_state; }
  uint8_t max_states(void) const { return ST_MAX_STATES; }
  uint8_t next_state(void) const { return m_next_state; }
  void next_state(uint8_t next_state) { m_next_state = next_state; }
  void update_state(uint8_t new_state) { m_current_state = new_state; }
  uint8_t initial_state(void) const { return m_initial_state; }

 private:
  uint8_t m_current_state;
  uint8_t m_initial_state;
  uint8_t m_next_state;
};

HFSM_STATE_DEFINE(test_fsm, s1, fsm::no_event) {
  printf("Executing state1\n");
  return fsm::event::EVENT_HANDLED;
}
HFSM_STATE_DEFINE(test_fsm, s2, fsm::no_event) {
  printf("Executing state2\n");
  return fsm::event::EVENT_HANDLED;
}

HFSM_STATE_DEFINE(test_fsm, s3, fsm::no_event) {
  printf("Executing state3\n");
  return fsm::event::EVENT_HANDLED;
}

HFSM_STATE_DEFINE(test_fsm, s4, fsm::no_event) {
  printf("Executing state4\n");
  internal_event(STATE5);
  return fsm::event::EVENT_HANDLED;
}
HFSM_STATE_DEFINE(test_fsm, s5, fsm::no_event) {
  printf("Executing state5\n");
  return fsm::event::EVENT_HANDLED;
}

HFSM_STATE_DEFINE(test_fsm, s6, fsm::no_event) {
  printf("Executing state6\n");
  return fsm::event::EVENT_HANDLED;
}

/*******************************************************************************
 * Test Functions
 ******************************************************************************/
CATCH_TEST_CASE("sanity-test", "[hfsm]") {
  test_fsm fsm(std::make_shared<er_server>("logfile"));
  fsm.init();
  CATCH_REQUIRE(fsm.current_state() == test_fsm::STATE1);
  fsm.event1();
  CATCH_REQUIRE(fsm.current_state() == test_fsm::STATE2);
  fsm.event1();
  CATCH_REQUIRE(fsm.current_state() == test_fsm::STATE3);
  fsm.init();
  CATCH_REQUIRE(fsm.current_state() == test_fsm::STATE1);
}

/* CATCH_TEST_CASE("event-test", "[hfsm]") { */
/*   test_fsm fsm(std::make_shared<er_server>("logfile")); */
/*   CATCH_REQUIRE(fsm.current_state() == test_fsm::STATE1); */
/*   fsm.event2(); */
/*   CATCH_REQUIRE(fsm.current_state() == test_fsm::STATE1); */
/*   fsm.event1(); */
/*   CATCH_REQUIRE(fsm.current_state() == test_fsm::STATE2); */
/*   fsm.event2(); */
/*   CATCH_REQUIRE(fsm.current_state() == test_fsm::STATE5); */
/* } */
