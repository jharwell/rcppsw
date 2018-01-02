/**
 * @file base_fsm.hpp
 * @ingroup patterns state_machine
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
#include <cstdio>
#include <cstddef>
#include <mutex>
#include "rcppsw/common/common.hpp"
#include "rcppsw/er/client.hpp"
#include "rcppsw/patterns/state_machine/event.hpp"
#include "rcppsw/patterns/state_machine/state_action.hpp"
#include "rcppsw/patterns/state_machine/state_entry_action.hpp"
#include "rcppsw/patterns/state_machine/state_exit_action.hpp"
#include "rcppsw/patterns/state_machine/state_guard_action.hpp"
#include "rcppsw/patterns/state_machine/state_map_ex_row.hpp"
#include "rcppsw/patterns/state_machine/state_map_row.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, state_machine);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class base_fsm
 *
 * @brief Implements a software-based state machine.
 */
class base_fsm : public er::client {
 public:
  base_fsm(const std::shared_ptr<er::server>& server,
           uint8_t max_states,
           uint8_t initial_state = 0);

  virtual ~base_fsm() = default;

  /**
   * @brief Get the current state of the state machine.
   */
  virtual uint8_t current_state(void) const { return m_current_state; }

  /**
   * @brief Get the maximum number of states for the state machine.
   */
  virtual uint8_t max_states(void) const { return mc_max_states; }

  /**
   * @brief Get the previous state the the state machine was in that is
   * \a different than the current one.
   *
   * If a state machine has been in state \c A for the last 3 timesteps, and
   * state \c B before that, and the current state is \c A, then this function
   * will return \c B.
   */
  virtual uint8_t previous_state(void) const { return m_previous_state; }

  /**
   * @brief Get the state the the state machine was in the last time the state
   * machine was run.
   *
   * If a state machine has been in state \c A for the last 3 timesteps, and
   * state \c B before that, and the current state is \c A, then this function
   * will return \c A.
   */
  virtual uint8_t last_state(void) const { return m_last_state; }

  /**
   * @brief Initialize/reset the state machine.
   */
  virtual void init(void);

 protected:
  /**
   * @brief Get the data associated with an event injected into the state machine.
   */
  const event_data* event_data_get(void) const { return m_event_data.get(); }
  event_data* event_data_get(void) { return const_cast<event_data*>(m_event_data.get()); }

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
  void external_event(uint8_t new_state, std::unique_ptr<const event_data> data);
  void external_event(uint8_t new_state) {
    internal_event(new_state, nullptr);
  }

  /**
   * @brief Generates an internal event. These events are generated while
   * executing
   * within a state machine state. Internal states can pass their own data to
   * other states without worrying about deleting the existing data--the FSM
   * owns it and will handle it.
   *
   * @param new_state The state machine state to transition to.
   * @param data The event data sent to the state.
   */
  void internal_event(uint8_t new_state, std::unique_ptr<const event_data> data);
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
  virtual const state_map_row* state_map(__unused size_t) { return nullptr; }

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
  virtual const state_map_ex_row* state_map_ex(__unused size_t) {
    return nullptr;
  }

  /**
   * @brief Execute one step of the state machine using the simple state
   * definitions.
   */
  virtual void state_engine_step(const state_map_row* c_row);

  /**
   * @brief Execute one step of the state machine using the extended state
   * definitions.
   */
virtual void state_engine_step(const state_map_ex_row* c_row_ex);

 private:
  void state_engine_map(void);
  void state_engine_map_ex(void);

  const uint8_t mc_max_states; /// The maximum # of fsm states.
  uint8_t m_current_state;     /// The current state machine state.
  uint8_t m_next_state;        /// The next state to transition to.
  uint8_t m_initial_state;
  uint8_t m_previous_state;
  uint8_t m_last_state;
  bool m_event_generated; /// Set to TRUE on event generation.
  std::unique_ptr<const event_data> m_event_data;
  std::mutex m_mutex;
};

NS_END(state_machine, patterns, rcppsw);

/*******************************************************************************
 * State Macros With Data
 ******************************************************************************/
/**
 * @def FSM_STATE_DECLARE(FSM, state_name, event_data)
 *
 * Declare a state \c state_name within the class definition of \c FSM, which
 * requires the input signal of \c event_data each time the state is executed.
 *
 * Should always return \ref event_signal::HANDLED for \ref simple_fsm (anything
 * other than that will halt the state machine/crash the program). Can return
 * other signals if the state is part of a \ref hfsm.
 */
#define FSM_STATE_DECLARE(FSM, state_name, event_data)      \
  int ST_##state_name(const event_data*);                   \
  rcppsw::patterns::state_machine::                         \
      state_action1<FSM, event_data, &FSM::ST_##state_name> \
          state_name

/**
 * @def FSM_STATE_DEFINE(FSM, state_name, event_data)
 *
 * Define a state \c state_name for a class \c FSM, which requires the input
 * signal of \c event_data each time the state is executed.
 */
#define FSM_STATE_DEFINE(FSM, state_name, event_data)   \
  int FSM::ST_##state_name(const event_data* data)

/**
 * @def FSM_GUARD_DECLARE(FSM, guard_name, event_data)
 *
 * Declare a guard \c guard_name within the class definition of \c FSM, which
 * requires the input signal of \c event_data each time the guard is executed.
 *
 * Guards are executed each time the state machine is in an extended state that
 * has a guard defined. If the guard returns \c FALSE, then the state function
 * for the state will not be executed. If the guard returns \c TRUE, then it
 * will.
 */
#define FSM_GUARD_DECLARE(FSM, guard_name, event_data)               \
  bool GD_##guard_name(const event_data*);                           \
  rcppsw::patterns::state_machine::                                  \
      state_guard_condition1<FSM, event_data, &FSM::GD_##guard_name> \
          guard_name

/**
 * @def FSM_GUARD_DEFINE(FSM, guard_name, event_data) Define a guard
 * \c guard_name for a class  \c FSM, which requires the input
 * signal of \c event_data each time the guard is executed.
 */
#define FSM_GUARD_DEFINE(FSM, guard_name, event_data) \
  bool FSM::GD_##guard_name(const event_data* data)


/**
 * @def FSM_ENTRY_DECLARE(FSM, entry_name, event_data)
 *
 * Declare an entry \c entry_name within the class definition of \c FSM, which
 * requires the input signal of \c event_data each time the entry is executed.
 *
 * Whenever the state function for a state in the state machine is executed
 * (possibly by passing a guard condition), if it is a state transition (last
 * state different than current one), then the entry function for that state
 * will be executed.
 */
#define FSM_ENTRY_DECLARE(FSM, entry_name, event_data)            \
  void EN_##entry_name(const event_data*);                        \
  rcppsw::patterns::state_machine::                               \
      state_entry_action1<FSM, event_data, &FSM::EN_##entry_name> \
          entry_name

/**
 * @def FSM_ENTRY_DEFINE(FSM, entry_name, event_data)
 *
 * Declare an entry \c entry_name for a class \c FSM, which requires the input
 * signal of \c event_data each time the entry is executed.
 */
#define FSM_ENTRY_DEFINE(FSM, entry_name, event_data) \
  void FSM::EN_##entry_name(const event_data* data)

/**
 * @def FSM_EXIT_DECLARE(FSM, exit_name)
 *
 * Declare an exit \c exit_name within the class definition of \c FSM.
 *
 * Whenever a state transition occurs in the FSM, if the old state has an exit
 * function defined then it will be run before leaving the state.
 */
#define FSM_EXIT_DECLARE(FSM, exit_name)                                        \
  void EX_##exit_name(void);                                                    \
  rcppsw::patterns::state_machine::state_exit_action<FSM, &FSM::EX_##exit_name> \
      exit_name

/**
 * @def FSM_EXIT_DEFINE(FSM, exit_name)
 *
 * Define an exit \c exit_name within the a class \c FSM.
 */
#define FSM_EXIT_DEFINE(FSM, exit_name) void FSM::EX_##exit_name(void)

/*******************************************************************************
* State Macros Without Data
******************************************************************************/
/**
 * @def FSM_STATE_DECLARE_ND(FSM, state_name)
 *
 * Same as \ref FSM_STATE_DECLARE(), but without any input data.
 */
#define FSM_STATE_DECLARE_ND(FSM, state_name)                                \
  int ST_##state_name(void);                                                 \
  rcppsw::patterns::state_machine::state_action0<FSM, &FSM::ST_##state_name> \
      state_name

/**
 * @def FSM_STATE_DEFINE_ND(FSM, state_name)
 *
 * Same as \ref FSM_STATE_DEFINE(), but without any input data.
 */
#define FSM_STATE_DEFINE_ND(FSM, state_name) int FSM::ST_##state_name(void)

/**
 * @def FSM_GUARD_DECLARE_ND(FSM, guard_name)
 *
 * Same as \ref FSM_GUARD_DECLARE(), but without any input data.
 */
#define FSM_GUARD_DECLARE_ND(FSM, guard_name)                                    \
  bool GD_##guard_name(void);                                                    \
  rcppsw::patterns::state_machine::state_guard_condition0<FSM,                   \
                                                          &FSM::GD_##guard_name> \
      guard_name

/**
 * @def FSM_GUARD_DEFINE_ND(FSM, guard_name)
 *
 * Same as \ref FSM_GUARD_DEFINE(), but without any input data.
 */
#define FSM_GUARD_DEFINE_ND(FSM, guard_name) bool FSM::GD_##guard_name(void)

/**
 * @def FSM_ENTRY_DECLARE_ND(FSM, entry_name)
 *
 * Same as \ref FSM_ENTRY_DECLARE(), but without any input data.
 */
#define FSM_ENTRY_DECLARE_ND(FSM, entry_name)                                      \
  void EN_##entry_name(void);                                                      \
  rcppsw::patterns::state_machine::state_entry_action0<FSM, &FSM::EN_##entry_name> \
      entry_name

/**
 * @def FSM_ENTRY_DEFINE_ND(FSM, entry_name) Same as \ref FSM_ENTRY_DEFINE(),
 * but without any input data.
 */
#define FSM_ENTRY_DEFINE_ND(FSM, entry_name) void FSM::EN_##entry_name(void)

/*******************************************************************************
 * Transition Map Macros
 ******************************************************************************/
/**
 * @def FSM_DEFINE_TRANSITION_MAP(name)
 *
 * Define the transition map/table for a state machine. Can only be used if \b
 * ALL instances of a class can share the same table, which is true for
 * \ref simple_fsm, but not necessarily for \ref hfsm.
 *
 */
#define FSM_DEFINE_TRANSITION_MAP(name) static const uint8_t name[] =

/**
 * @def FSM_VERIFY_TRANSITION_MAP(name, n_entries)
 *
 * Verify that all states have been covered in the defined transition map. Can
 * only be used in conjunction with the \ref FSM_DEFINE_TRANSITION_MAP() macro
 * (i.e. not with \ref hfsm maps--compiler error will result if the map is not
 * fully filled out regardless of any checking).
 *
 * \c name is the name of the map in the class, and \c n_entries is the number
 * of entries the map should have.
 */
#define FSM_VERIFY_TRANSITION_MAP(name, n_entries)                     \
    static_assert((sizeof(name) / sizeof(uint8_t)) == (n_entries),     \
                "transition map does not cover all states");

/*******************************************************************************
 * State Map Macros
 ******************************************************************************/
/**
 * @def FSM_DEFINE_STATE_MAP(type, name)
 *
 * Define a state map for an FSM at \b GLOBAL scope. All instances of a class
 * will share the same state map, which will not be a problem for
 * \ref simple_fsm state machines; it is only for \ref hfsm state machines that
 * you really really don't want to do this. Use \ref HFSM_DECLARE_STATE_MAP()
 * instead.
 *
 * \c type must be either "state_map" or "state_map_ex", corresponding to which
 * type of states the state machine is comprised of. \c name can be anything.
 */
#define FSM_DEFINE_STATE_MAP(type, name) \
  static const rcppsw::patterns::state_machine::JOIN(type, _row) (name)[]

/**
 * @def FSM_DEFINE_STATE_MAP_ACCESSOR(type, index_var)
 *
 * Define the function that will be used by all \ref simple_fsm state machines
 * to process events (i.e. given that a machine is in state X and event Y
 * occurs, what state should it transition to next).
 *
 * \c type must be either "state_map" or "state_map_ex", corresponding to which
 * type of states the state machine is comprised of. \c index_var can be
 * anything, and will have the value of the current state.
 */

#define FSM_DEFINE_STATE_MAP_ACCESSOR(type, index_var)      \
  const rcppsw::patterns::state_machine::JOIN(type, _row) * \
      JOIN(type, )(size_t index_var)

/**
 * @def FSM_STATE_MAP_ENTRY(state_name)
 *
 * Define a state map entry for state \c state_name.
 */
#define FSM_STATE_MAP_ENTRY(state_name) \
  rcppsw::patterns::state_machine::state_map_row(state_name)

/**
 * @def FSM_STATE_MAP_ENTRY_EX(state_name)
 *
 * Define an extended state map entry for state \c state_name, where the state
 * does not use any of the entry/exit/guard callbacks. Useful for reducing code
 * clutter.
 */
#define FSM_STATE_MAP_ENTRY_EX(state_name)           \
  rcppsw::patterns::state_machine::state_map_ex_row( \
      state_name, NULL, NULL, NULL)

/**
 * @def FSM_STATE_MAP_ENTRY_EX_ALL(state_name, guard_name, entry_name, exit_name)
 *
 * Define an extended state map entry for state \c state_name, along will all
 * callbacks. If entry/exit/guard callbacks are not used for the state,
 * \c nullptr should be passed.
 */
#define FSM_STATE_MAP_ENTRY_EX_ALL(                  \
    state_name, guard_name, entry_name, exit_name)   \
  rcppsw::patterns::state_machine::state_map_ex_row( \
      state_name, guard_name, entry_name, exit_name)

/**
 * @def FSM_VERIFY_STATE_MAP(type, name n_entries)
 *
 * Verifies that the state map \c name of type \c type (must be "state_map" or
 * "state_map_ex") contains \c n_entries using a static assert.
 */
#define FSM_VERIFY_STATE_MAP(type, name, n_entries)                            \
  static_assert((sizeof(name) /                                                \
                 sizeof(rcppsw::patterns::state_machine::JOIN(type, _row))) == \
                (n_entries),                                            \
                "state map does not cover all states");

#endif /* INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_BASE_FSM_HPP_ */
