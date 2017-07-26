/**
 * @file state_machine.hpp
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

#ifndef INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_STATE_MACHINE_HPP_
#define INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_STATE_MACHINE_HPP_

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
  const state_base* const State;
};

/**
 * @brief A structure to hold a single row within the extended state map.
 */
struct state_map_row_ex {
  const state_base* const state;
  const state_guard_base* const guard;
  const state_entry_base* const entry;
  const state_exit_base* const exit;
};

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief simple_fsm implements a software-based state machine.
 *
 */
class simple_fsm {
 public:
  enum {
    EVENT_IGNORED = 0xFE,
    CANNOT_HAPPEN
  };

  /**
   * @param max_states The maximum number of state machine states.
   * @param initial_state Initial state machine state.
   */
  explicit simple_fsm(uint8_t max_states, uint8_t initial_state = 0);

  virtual ~simple_fsm() {}

  uint8_t current_state() { return current_state_; }
  uint8_t max_allowed_states() { return MAX_STATES_; }

 protected:
  /**
   * @brief Generates an external event. called once per external event
   * to start the state machine executing
   *
   * @param new_state The state machine state to transition to.
   * @param data The event data sent to the state.
   */
  void external_event(uint8_t new_state, const event_data* data = NULL);

  /**
   * @brief Generates an internal event. These events are generated while executing
   * within a state machine state.
   * @param new_state The state machine state to transition to.
   * @param data The event data sent to the state.
   */
  void internal_event(uint8_t new_state, const event_data* data = NULL);

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
  virtual const state_map_row* state_map() = 0;

  /**
   * @brief Gets the extended state map as defined in the derived class.
   *
   * The BEGIN_STATE_MAP_EX, STATE_MAP_ENTRY_EX, STATE_MAP_ENTRY_ALL_EX, and
   * END_STATE_MAP_EX macros are used to assist in creating the map. A state
   * machine only needs to return a state map using either state_map() or
   * state_map_ex() but not both.
   *
   * @return An array of state_map_row_ex pointers with the array size
   *         max_states or NULL if the state machine uses the state_map().
   */
  virtual const state_map_row_ex* state_map_ex() = 0;

  void current_state(uint8_t new_state) { current_state_ = new_state; }

  /*
   * @brief State machine engine that executes the external event and,
   * optionally, all internal events generated during state execution.
   */
  void state_engine(void);
  void state_engine(const state_map_row* const state_map);
  void state_engine(const state_map_row_ex* const state_map_ex);

  /// The maximum number of state machine states.
  const uint8_t MAX_STATES_;

  /// The current state machine state.
  uint8_t current_state_;

  /// The new state the state machine has yet to transition to.
  uint8_t new_state_;

  /// Set to TRUE when an event is generated.
  bool event_generated_;

  /// The state event data pointer.
  const event_data* event_data_;

  std::mutex mutex_;
};

#define STATE_DECLARE(sm, state_name, event_data)                       \
  void ST_##state_name(const event_data*);                              \
  state_action<sm, event_data, &sm::ST_##state_name> state_name;

#define STATE_DEFINE(sm, state_name, event_data)        \
  void sm::ST_##state_name(const event_data* data)

#define GUARD_DECLARE(sm, guardName, event_data)                        \
  bool GD_##guardName(const event_data*);                               \
  state_guard_condition<sm, event_data, &sm::GD_##guardName> guardName;

#define GUARD_DEFINE(sm, guardName, event_data)         \
  bool sm::GD_##guardName(const event_data* data)

#define ENTRY_DECLARE(sm, entryName, event_data)                        \
  void EN_##entryName(const event_data*);                               \
  state_entry_action<sm, event_data, &sm::EN_##entryName> entryName;

#define ENTRY_DEFINE(sm, entryName, event_data)         \
  void sm::EN_##entryName(const event_data* data)

#define EXIT_DECLARE(sm, exitName)                      \
  void EX_##exitName(void);                             \
  state_exit_action<sm, &sm::EX_##exitName> exitName;

#define EXIT_DEFINE(sm, exitName)               \
  void sm::EX_##exitName(void)

#define BEGIN_TRANSITION_MAP static const uint8_t TRANSITIONS[] = {

#define TRANSITION_MAP_ENTRY(entry) entry,

#define END_TRANSITION_MAP(data)                                        \
    };                                                                  \
  assert(current_state() < ST_MAX_STATES);                         \
  ExternalEvent(TRANSITIONS[current_state()], data);                    \
  STATIC_ASSERT((sizeof(TRANSITIONS)/sizeof(uint8_t)) == ST_MAX_STATES);

#define PARENT_TRANSITION(state)                \
  if (current_state() >= ST_MAX_STATES &&       \
      current_state() < max_allowed_states()) { \
    ExternalEvent(state);                       \
    return; }

#define BEGIN_STATE_MAP                                                 \
  private:                                                              \
  virtual const state_map_row_ex* state_map_ex() { return NULL; }      \
  virtual const state_map_row* state_map() {                          \
    static const state_map_row kSTATE_MAP[] = {

#define STATE_MAP_ENTRY(state_name)             \
      state_name,

#define END_STATE_MAP                                                   \
      };                                                                \
    STATIC_ASSERT((sizeof(kSTATE_MAP)/sizeof(state_map_row)) == ST_MAX_STATES); \
    return &kSTATE_MAP[0]; }

#define BEGIN_STATE_MAP_EX                                              \
      private:                                                          \
      virtual const state_map_row* state_map() { return NULL; }       \
      virtual const state_map_row_ex* state_map_ex() {                 \
        static const state_map_row_ex kSTATE_MAP[] = {

#define STATE_MAP_ENTRY_EX(state_name)          \
          { state_name, 0, 0, 0 },

#define STATE_MAP_ENTRY_ALL_EX(state_name, guard_name, entry_name, exit_name) \
          { state_name, guard_name, entry_name, exit_name },

#define END_STATE_MAP_EX                                                \
          };                                                            \
        STATIC_ASSERT((sizeof(kSTATE_MAP)/sizeof(state_map_row_ex)) == ST_MAX_STATES); \
        return &kSTATE_MAP[0]; }

NS_END(state_machine, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_STATE_MACHINE_HPP_ */
