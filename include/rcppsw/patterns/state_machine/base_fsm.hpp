/**
 * @file base_fsm.hpp
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

#ifndef INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_BASE_FSM_HPP_
#define INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_BASE_FSM_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include <typeinfo>
#include <cstddef>
#include <mutex>
#include "rcppsw/common/common.hpp"
#include "rcppsw/patterns/state_machine/event.hpp"
#include "rcppsw/patterns/state_machine/state.hpp"
#include "rcppsw/common/er_client.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, state_machine);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * @brief A structure to hold a single row within the state map.
 */
struct state_map_row {
  const rcppsw::patterns::state_machine::state* const state;
  const rcppsw::patterns::state_machine::state* const parent_state;
};

/**
 * @brief A structure to hold a single row within the extended state map.
 */
struct state_map_ex_row {
  const rcppsw::patterns::state_machine::state* const state;
  const rcppsw::patterns::state_machine::state* const parent_state;
  const state_guard* const guard;
  const state_entry* const entry;
  const state_exit* const exit;
};

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief base_fsm implements a software-based state machine.
 */
class base_fsm: public common::er_client {
 public:
  /**
   * @param max_states The maximum number of state machine states.
   * @param initial_state Initial state machine state.
   */
  base_fsm(std::shared_ptr<common::er_server> server,
           uint8_t max_states,
           uint8_t initial_state = 0);

  virtual ~base_fsm() {}

  uint8_t current_state(void) { return m_current_state; }
  uint8_t max_states(void) { return mc_max_states; }
  virtual void reset(void);

 protected:
  /**
   * @brief Generates an external event. Called once per external event
   * to start the state machine executing.
   *
   * @param new_state The state machine state to transition to.
   * @param data The event data sent to the state.
   */
  virtual void external_event(uint8_t new_state, const event* data = NULL);

  /**
   * @brief Generates an internal event. These events are generated while executing
   * within a state machine state.
   * @param new_state The state machine state to transition to.
   * @param data The event data sent to the state.
   */
  virtual void internal_event(uint8_t new_state, const event* data = NULL);

  virtual void state_engine_step(const state_map_row* const map);
  virtual void state_engine_step(const state_map_ex_row* const map_ex);

  /*
   * @brief State machine engine that executes the external event and,
   * optionally, all internal events generated during state execution.
   */
  virtual void state_engine(void);

  void next_state(uint8_t next_state) { m_next_state = next_state; }
  uint8_t next_state(void) { return m_next_state; }

  std::unique_ptr<const event>& event_data(void) { return m_event_data; }
  void generated_event(bool b) { m_event_generated = b; }
  bool has_generated_event(void) { return m_event_generated; }

 private:
  /**
   * @brief Gets the state map as defined in the derived class.
   *
   * The BEGIN_STATE_MAP, STATE_MAP_ENTRY and END_STATE_MAP macros are used to
   * assist in creating the map. A state machine only needs to return a state
   * map using either state_map() or state_map_ex() but not both.
   *
   * @return An array of state_map_row pointers with the array size MAX_STATES
   *         or NULL if the state machine uses the state_map_ex().
   */
  virtual const state_map_row* state_map() { return NULL; }

  /**
   * @brief Gets the extended state map as defined in the derived class.
   *
   * The BEGIN_STATE_MAP_EX, STATE_MAP_ENTRY_EX, STATE_MAP_ENTRY_ALL_EX, and
   * END_STATE_MAP_EX macros are used to assist in creating the map. A state
   * machine only needs to return a state map using either state_map() or
   * state_map_ex() but not both.
   *
   * @return An array of state_map_ex_row pointers with the array size
   *         max_states or NULL if the state machine uses the state_map().
   */
  virtual const state_map_ex_row* state_map_ex() { return NULL; }

  void update_state(uint8_t new_state) { m_current_state = new_state; }

  void state_engine(const state_map_row* const state_map);
  void state_engine(const state_map_ex_row* const state_map_ex);

  base_fsm(const base_fsm& fsm) = delete;
  base_fsm& operator=(const base_fsm& fsm) = delete;

  const uint8_t     mc_max_states;      /// The maximum # of fsm states.
  uint8_t           m_current_state;    /// The current state machine state.
  uint8_t           m_next_state;        /// The next state to transition to.
  uint8_t           m_initial_state;
  bool              m_event_generated;  /// Set to TRUE on event generation.
  std::unique_ptr<const event> m_event_data;  /// The state event data pointer.
  std::mutex        m_mutex;            /// Lock for thread safety.
};

NS_END(state_machine, patterns, rcppsw);

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define STATE_DECLARE(sm, state_name, event_data)                       \
  void ST_##state_name(__unused const event_data*);              \
  rcppsw::patterns::state_machine::state_action<sm, \
                                                event_data, \
                                                &sm::ST_##state_name> state_name;

#define STATE_DEFINE(sm, state_name, event_data)        \
  void sm::ST_##state_name(__unused const event_data* data)

#define GUARD_DECLARE(sm, guardName, event_data)                        \
  bool GD_##guardName(__unused const event_data*);                               \
  rcppsw::patterns::state_machine::state_guard_condition<sm, \
                                                         event_data, \
                                                         &sm::GD_##guardName> guardName;

#define GUARD_DEFINE(sm, guardName, event_data)         \
  bool sm::GD_##guardName(__unused const event_data* data)

#define ENTRY_DECLARE(sm, entryName, event_data)                        \
  void EN_##entryName(__unused const event_data*);                               \
  rcppsw::patterns::state_machine::state_entry_action<sm,\
                                                      event_data, \
                                                      &sm::EN_##entryName> entryName;

#define ENTRY_DEFINE(sm, entryName, event_data)         \
  void sm::EN_##entryName(__unused const event_data* data)

#define EXIT_DECLARE(sm, exitName)                      \
  void EX_##exitName(void);                             \
  rcppsw::patterns::state_machine::state_exit_action<sm,\
                                                     &sm::EX_##exitName> exitName;

#define EXIT_DEFINE(sm, exitName)               \
  void sm::EX_##exitName(void)

#define DEFINE_TRANSITION_MAP(name) static const uint8_t name[] =
#define TRANSITION_MAP_ENTRY(entry) entry,

#define VERIFY_TRANSITION_MAP(name)                                     \
  assert(current_state() < ST_MAX_STATES);                              \
  static_assert((sizeof(name)/sizeof(uint8_t)) == ST_MAX_STATES, \
                "transition map does not cover all states");



#define PARENT_TRANSITION(state)                \
  if (current_state() >= ST_MAX_STATES &&       \
      current_state() < max_allowed_states()) { \
    ExternalEvent(state);                       \
    return; }

#define VERIFY_STATE_MAP(type, name)                                         \
  static_assert((sizeof(name)/sizeof(struct fsm::JOIN(type, _row))) == ST_MAX_STATES, \
                "state map does not cover all states");

#define DEFINE_STATE_MAP_ACCESSOR(type) \
  virtual const rcppsw::patterns::state_machine::JOIN(type, _row)* JOIN(type, )(void)

#define DEFINE_STATE_MAP_EX(type, name) DEFINE_STATE_MAP(state_map_ex, name)
#define DEFINE_STATE_MAP(type, name)                                           \
  static const rcppsw::patterns::state_machine::JOIN(type, _row) name[] =

#define STATE_MAP_ENTRY(state_name)             \
  {&state_name, NULL}

#define STATE_MAP_ENTRY_EX(state_name) { state_name, NULL, NULL, NULL, NULL}

#define STATE_MAP_ENTRY_EX_ALL(state_name, guard_name, entry_name, exit_name) \
  { state_name, NULL, guard_name, entry_name, exit_name}

#endif /* INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_BASE_FSM_HPP_ */
