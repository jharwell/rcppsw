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
};

/**
 * @brief A structure to hold a single row within the extended state map.
 */
struct state_map_ex_row {
  const rcppsw::patterns::state_machine::state* const state;
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
  explicit base_fsm(std::shared_ptr<common::er_server> server);

  virtual ~base_fsm() {}

  virtual uint8_t current_state(void) const = 0;
  virtual uint8_t max_states(void) const = 0;
  virtual void init(void);

 protected:
  const event* event_data(void) { return m_event_data.get(); }
  void generated_event(bool b) { m_event_generated = b; }
  bool has_generated_event(void) { return m_event_generated; }

  /**
   * @brief Generates an external event. Called once per external event
   * to start the state machine executing.
   *
   * @param new_state The state machine state to transition to.
   * @param data The event data sent to the state.
   */
  void external_event(uint8_t new_state, const event* data = NULL);

  /**
   * @brief Generates an internal event. These events are generated while executing
   * within a state machine state.
   * @param new_state The state machine state to transition to.
   * @param data The event data sent to the state.
   */
  void internal_event(uint8_t new_state, const event* data = NULL);

  /*
   * @brief State machine engine that executes the external event and,
   * optionally, all internal events generated during state execution.
   */
  void state_engine(void);

  virtual void next_state(uint8_t next_state) = 0;
  virtual void update_state(uint8_t new_state) = 0;
  virtual uint8_t next_state(void) const = 0;
  virtual uint8_t initial_state(void) const = 0;

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

 private:
  void state_engine_step(const state_map_row* const map);
  void state_engine_step(const state_map_ex_row* const map_ex);
  void state_engine(const state_map_row* const state_map);
  void state_engine(const state_map_ex_row* const state_map_ex);

  base_fsm(const base_fsm& fsm) = delete;
  base_fsm& operator=(const base_fsm& fsm) = delete;

  bool              m_event_generated;  /// Set to TRUE on event generation.
  std::unique_ptr<const event> m_event_data;  /// The state event data pointer.
  std::mutex        m_mutex;            /// Lock for thread safety.
};

NS_END(state_machine, patterns, rcppsw);

/*******************************************************************************
 * State Macros
 ******************************************************************************/
#define FSM_STATE_DECLARE(FSM, state_name, event_data)                   \
  int ST_##state_name(__unused const event_data*);                     \
  rcppsw::patterns::state_machine::state_action<FSM,                     \
                                                event_data,             \
                                                &FSM::ST_##state_name> state_name;

#define FSM_STATE_DEFINE(FSM, state_name, event_data)            \
  int FSM::ST_##state_name(__unused const event_data* data)

#define FSM_GUARD_DECLARE(FSM, guardName, event_data)                    \
  bool GD_##guardName(__unused const event_data*);                      \
  rcppsw::patterns::state_machine::state_guard_condition<FSM,            \
                                                         event_data,    \
                                                         &FSM::GD_##guardName> guardName;

#define FSM_GUARD_DEFINE(FSM, guardName, event_data)             \
  bool FSM::GD_##guardName(__unused const event_data* data)

#define FSM_ENTRY_DECLARE(FSM, entryName, event_data)                    \
  void EN_##entryName(__unused const event_data*);                      \
  rcppsw::patterns::state_machine::state_entry_action<FSM,               \
                                                      event_data,       \
                                                      &FSM::EN_##entryName> entryName;

#define FSM_ENTRY_DEFINE(FSM, entryName, event_data)             \
  void FSM::EN_##entryName(__unused const event_data* data)

#define FSM_EXIT_DECLARE(FSM, exitName)                                  \
  void EX_##exitName(void);                                             \
  rcppsw::patterns::state_machine::state_exit_action<FSM,                \
                                                     &FSM::EX_##exitName> exitName;

#define FSM_EXIT_DEFINE(FSM, exitName)           \
  void FSM::EX_##exitName(void)

/*******************************************************************************
 * Transition Map Macros
 ******************************************************************************/
#define FSM_DEFINE_TRANSITION_MAP(name) static const uint8_t name[] =
#define FSM_TRANSITION_MAP_ENTRY(entry) entry,
#define FSM_VERIFY_TRANSITION_MAP(name)                                 \
  assert(current_state() < ST_MAX_STATES);                              \
  static_assert((sizeof(name)/sizeof(uint8_t)) == ST_MAX_STATES,        \
                "transition map does not cover all states");

/*******************************************************************************
 * State Map Macros
 ******************************************************************************/
#define FSM_DEFINE_STATE_MAP_EX(type, name) FSM_DEFINE_STATE_MAP(state_map_ex, name)
#define FSM_DEFINE_STATE_MAP(type, name)                                \
    static const rcppsw::patterns::state_machine::JOIN(type, _row) name[] =

#define FSM_DEFINE_STATE_MAP_ACCESSOR(type)                             \
  virtual const rcppsw::patterns::state_machine::JOIN(type, _row)* JOIN(type, )(void)

#define FSM_STATE_MAP_ENTRY(state_name)     \
  {state_name}

#define FSM_STATE_MAP_ENTRY_EX(state_name) { state_name, NULL, NULL, NULL}
#define FSM_STATE_MAP_ENTRY_EX_ALL(state_name, guard_name, entry_name, exit_name) \
  {state_name, guard_name, entry_name, exit_name}

#define FSM_VERIFY_STATE_MAP(type, name)                                \
  static_assert((sizeof(name)/sizeof(struct FSM::JOIN(type, _row))) == ST_MAX_STATES, \
                "state map does not cover all states");

#endif /* INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_BASE_FSM_HPP_ */
