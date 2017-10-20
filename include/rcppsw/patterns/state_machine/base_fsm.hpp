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
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A structure to hold a single row within the state map.
 */
class state_map_row {
 public:
  explicit state_map_row(rcppsw::patterns::state_machine::state* state) :
      m_state(state) {}

  rcppsw::patterns::state_machine::state* state(void) const { return m_state; }

 private:
  rcppsw::patterns::state_machine::state* m_state;
};

/**
 * @brief A structure to hold a single row within the extended state map.
 */
class state_map_ex_row {
 public:
  state_map_ex_row(rcppsw::patterns::state_machine::state* state,
                   state_guard* guard,
                   state_entry* entry, state_exit* exit) :
      m_state(state), m_guard(guard), m_entry(entry), m_exit(exit) {}
  rcppsw::patterns::state_machine::state* state(void) const { return m_state; }
  state_guard* guard(void) const { return m_guard; }
  state_entry* entry(void) const { return m_entry; }
  state_exit* exit(void) const { return m_exit; }

 private:
  rcppsw::patterns::state_machine::state* m_state;
  state_guard* m_guard;
  state_entry* m_entry;
  state_exit* m_exit;
};

/**
 * @brief base_fsm implements a software-based state machine.
 *
 */
class base_fsm: public common::er_client {
 public:
  base_fsm(const std::shared_ptr<common::er_server>& server,
             uint8_t max_states,
             uint8_t initial_state = 0);

  virtual ~base_fsm() {}

  virtual uint8_t current_state(void) const { return m_current_state; }
  virtual uint8_t max_states(void) const { return mc_max_states; }
  virtual uint8_t previous_state(void) const { return m_previous_state; }
  virtual uint8_t last_state(void) const { return m_last_state; }
  virtual void init(void);

 protected:
  const event_data* event_data_get(void) { return m_event_data.get(); }

  void generated_event(bool b) { m_event_generated = b; }
  bool has_generated_event(void) { return m_event_generated; }

  /**
   * @brief Generates an external event. Called once per external event
   * to start the state machine executing. The data is passed through the event
   * chain without modification. The FSM owns the event data--states should try
   * to delete it.
   *
   * @param new_state The state machine state to transition to.
   * @param data The event data sent to the state.
   */
  void external_event(uint8_t new_state,
                      std::unique_ptr<const event_data> data);
  void external_event(uint8_t new_state) {
    internal_event(new_state, std::move(nullptr));
  }
  /**
   * @brief Generates an internal event. These events are generated while executing
   * within a state machine state. Internal states can pass their own data to
   * other states without worrying about deleting the existing data--the FSM
   * owns it and will handle it.
   *
   * @param new_state The state machine state to transition to.
   * @param data The event data sent to the state.
   */
  void internal_event(uint8_t new_state,
                              std::unique_ptr<const event_data> data);
  void internal_event(uint8_t new_state) {
    internal_event(new_state, std::move(m_event_data));
  }

  /*
   * @brief State machine engine that executes the external event and,
   * optionally, all internal events generated during state execution.
   */
  void state_engine(void);

  virtual uint8_t next_state(void) const { return m_next_state; }
  virtual uint8_t initial_state(void) const { return m_initial_state; }
  virtual void next_state(uint8_t next_state) { m_next_state = next_state; }
  virtual void update_state(uint8_t new_state);

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
  virtual const state_map_row* state_map(__unused size_t index) { return NULL; }


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
  virtual const state_map_ex_row* state_map_ex(__unused size_t index) { return NULL; }

  virtual void state_engine_step(const state_map_row* const row);
  virtual void state_engine_step(const state_map_ex_row* const row_ex);

  base_fsm(const base_fsm& fsm);

 private:
  void state_engine_map(void);
  void state_engine_map_ex(void);
  base_fsm& operator=(const base_fsm& fsm) = delete;

  const uint8_t     mc_max_states;      /// The maximum # of fsm states.
  uint8_t           m_current_state;    /// The current state machine state.
  uint8_t           m_next_state;        /// The next state to transition to.
  uint8_t           m_initial_state;
  uint8_t           m_previous_state;
  uint8_t           m_last_state;
  bool              m_event_generated;  /// Set to TRUE on event generation.
  std::unique_ptr<const event_data> m_event_data;  /// The state event data pointer.
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

#define FSM_GUARD_DECLARE(FSM, guard_name, event_data)                    \
  bool GD_##guard_name(__unused const event_data*);                      \
  rcppsw::patterns::state_machine::state_guard_condition<FSM,            \
                                                         event_data,    \
                                                         &FSM::GD_##guard_name> guard_name;

#define FSM_GUARD_DEFINE(FSM, guard_name, event_data)             \
  bool FSM::GD_##guard_name(__unused const event_data* data)

#define FSM_ENTRY_DECLARE(FSM, entry_name, event_data)                    \
  void EN_##entry_name(__unused const event_data*);                      \
  rcppsw::patterns::state_machine::state_entry_action<FSM,               \
                                                      event_data,       \
                                                      &FSM::EN_##entry_name> entry_name;

#define FSM_ENTRY_DEFINE(FSM, entry_name, event_data)             \
  void FSM::EN_##entry_name(__unused const event_data* data)

#define FSM_EXIT_DECLARE(FSM, exit_name)                                  \
  void EX_##exit_name(void);                                             \
  rcppsw::patterns::state_machine::state_exit_action<FSM,                \
                                                     &FSM::EX_##exit_name> exit_name;

#define FSM_EXIT_DEFINE(FSM, exit_name)           \
  void FSM::EX_##exit_name(void)

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
#define FSM_DEFINE_STATE_MAP(type, name)                                \
    static const rcppsw::patterns::state_machine::JOIN(type, _row) name[] =

#define FSM_DEFINE_STATE_MAP_ACCESSOR(type, index_var)                  \
  const rcppsw::patterns::state_machine::JOIN(type, _row)* JOIN(type, )(size_t index_var)

#define FSM_STATE_MAP_ENTRY(state_name)     \
  rcppsw::patterns::state_machine::state_map_row(state_name)

#define FSM_STATE_MAP_ENTRY_EX(state_name) \
  rcppsw::patterns::state_machine::state_map_ex_row(state_name, NULL, NULL, NULL)

#define FSM_STATE_MAP_ENTRY_EX_ALL(state_name, guard_name, entry_name, exit_name) \
  rcppsw::patterns::state_machine::state_map_ex_row(state_name, guard_name, entry_name, exit_name)

#define FSM_VERIFY_STATE_MAP(type, name)                                \
  static_assert((sizeof(name)/sizeof(rcppsw::patterns::state_machine::JOIN(type, _row))) == ST_MAX_STATES, \
                "state map does not cover all states");

#endif /* INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_BASE_FSM_HPP_ */
