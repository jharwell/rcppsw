/**
 * \file base_fsm.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_PATTERNS_FSM_BASE_FSM_HPP_
#define INCLUDE_RCPPSW_PATTERNS_FSM_BASE_FSM_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cstdio>
#include <cstddef>
#include <string>
#include <memory>
#include <utility>
#include <array>

#include "rcppsw/common/common.hpp"
#include "rcppsw/er/client.hpp"
#include "rcppsw/patterns/fsm/event.hpp"
#include "rcppsw/patterns/fsm/state_action.hpp"
#include "rcppsw/patterns/fsm/state_entry_action.hpp"
#include "rcppsw/patterns/fsm/state_exit_action.hpp"
#include "rcppsw/patterns/fsm/state_guard_action.hpp"
#include "rcppsw/patterns/fsm/state_map_ex_row.hpp"
#include "rcppsw/patterns/fsm/state_map_row.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, fsm);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class base_fsm
 * \ingroup patterns fsm
 *
 * \brief Implements a software-based state machine.
 *
 ** The FSM paradigm uses *MEMBER* function pointers, so you always need to
 * initialize the state map cleanly WITHOUT copy construction (even inside copy
 * constructors), otherwise all copies of the object will use the other object's
 * state map (default behavior in default copy constructor). If the source
 * object is destructed, then you will get a segfault due to dangling pointers
 * or a "pure virtual function called" error.
 *
 * Thus, all \ref base_fsm derived classes MUST implement the copy constructor,
 * or delete it in order to ensure proper operation in all cases.
 */
class base_fsm : public er::client<base_fsm> {
 public:
  explicit base_fsm(uint8_t max_states, uint8_t initial_state = 0);
  ~base_fsm(void) override = default;

  /**
   * \brief Copy the FSM to initialize another. Event data and whether or not an
   * event is present is not copied.
   */
  base_fsm(const base_fsm& other);

  /**
   * \brief Copy the FSM to initialize another. Event data and whether or not an
   * event is present is not copied.
   */
  base_fsm& operator=(const base_fsm& other);

  /**
   * \brief Get the current state of the state machine.
   */
  uint8_t current_state(void) const { return m_current_state; }

  /**
   * \brief Get the maximum number of states for the state machine.
   */
  uint8_t max_states(void) const { return mc_max_states; }

  /**
   * \brief Get the previous state the the state machine was in that is
   * \a different than the current one.
   *
   * If a state machine has been in state \c A for the last 3 timesteps, and
   * state \c B before that, and the current state is \c A, then this function
   * will return \c B.
   */
  uint8_t previous_state(void) const { return m_previous_state; }

  /**
   * \brief Get the state the the state machine was in the last time the state
   * machine was run.
   *
   * If a state machine has been in state \c A for the last 3 timesteps, and
   * state \c B before that, and the current state is \c A, then this function
   * will return \c A.
   */
  uint8_t last_state(void) const { return m_last_state; }

  /**
   * \brief Injects a signal of the specified type into the state machine,
   * causing the state machine to execute and process the signal in its current
   * state. This is the main means of running an FSM. Suitable for handling
   * signals from within FSM states, and allowing outside classes to send
   * whatever signals they want to the FSM.
   */
  void inject_event(int signal, int type);

  /**
   * \brief Injects the signal of the specified type from the event argument
   * into the state machine. This variant of inject_event() is provided for use
   * with \ref event_data_hold(), to avoid the event data overwrite which occurs
   * with the other version.
   */
  void inject_event(std::unique_ptr<event_data> event);

  /**
   * \brief Initialize/reset the state machine.
   */
  virtual void init(void);

 protected:
  /**
   * \brief Get the data associated with an event injected into the state
   * machine.
   */
  const class event_data* event_data(void) const { return m_event_data.get(); }
  class event_data* event_data(void) { return m_event_data.get(); }
  std::unique_ptr<class event_data> event_data_release(void) {
    return std::move(m_event_data);
  }
  void generated_event(bool b) { m_event_generated = b; }
  bool has_generated_event(void) { return m_event_generated; }

  /**
   * \brief Indicate that the current event data should NOT be reset after \ref
   * state_engine() returns (default).
   */
  void event_data_hold(bool b) { m_event_data_hold = b; }
  bool event_data_hold(void) const { return m_event_data_hold; }

  /**
   * \brief Generates an external event. The data is passed through the event
   * chain without modification. The FSM owns the event data--states should not
   * try to delete it.
   *
   * \param new_state The state machine state to transition to.
   * \param data The event data sent to the state.
   */
  virtual void external_event(uint8_t new_state,
                              std::unique_ptr<class event_data> data);
  void external_event(uint8_t new_state) {
    external_event(new_state, nullptr);
  }

  /**
   * \brief Generates an internal event. These events are generated while
   * executing within a state machine state. Internal states can pass their own
   * data to other states without worrying about deleting the existing data--the
   * FSM owns it and will handle it.
   *
   * \param new_state The state machine state to transition to.
   * \param data The event data sent to the state.
   */
  void internal_event(uint8_t new_state, std::unique_ptr<class event_data> data);
  void internal_event(uint8_t new_state) {
    internal_event(new_state, std::move(m_event_data));
  }

  /*
   * \brief State machine engine that executes the external event and,
   * optionally, all internal events generated during state execution.
   */
  void state_engine(void);

  uint8_t next_state(void) const { return m_next_state; }
  uint8_t initial_state(void) const { return m_initial_state; }
  void next_state(uint8_t next_state) { m_next_state = next_state; }
  void update_state(uint8_t new_state);

  /**
   * \brief Gets the state map as defined in the derived class.
   *
   * A state machine only needs to return a state map using either
   * \ref state_map() or \ref state_map_ex() but not both.
   *
   * \return The row corresponding to the passed in state in the state map.
   */
  virtual const state_map_row* state_map(RCSW_UNUSED size_t) {
    return nullptr;
  }

  /**
   * \brief Gets the extended state map as defined in the derived class.
   *
   * A state machine only needs to return a state map using either
   * \ref state_map() or \ref state_map_ex() but not both.
   *
   * \return The row corresponding to the passed in state in the state map.
   */
  virtual const state_map_ex_row* state_map_ex(RCSW_UNUSED size_t) {
    return nullptr;
  }

  /**
   * \brief Execute one step of the state machine using the simple state
   * definitions.
   */
  virtual void state_engine_step(const state_map_row* c_row);

  /**
   * \brief Execute one step of the state machine using the extended state
   * definitions.
   */
  virtual void state_engine_step(const state_map_ex_row* c_row_ex);

 private:
  void state_engine_map(void);
  void state_engine_map_ex(void);
  void event_data(std::unique_ptr<class event_data> event_data) {
    m_event_data = std::move(event_data);
  }

  const uint8_t                     mc_max_states;
  uint8_t                           m_current_state;
  uint8_t                           m_next_state{0};
  uint8_t                           m_initial_state;
  uint8_t                           m_previous_state{0};
  uint8_t                           m_last_state{0};

  bool                              m_event_generated{false};
  bool                              m_event_data_hold{false};
  std::unique_ptr<class event_data> m_event_data{nullptr};
};

NS_END(fsm, patterns, rcppsw);

/*******************************************************************************
 * State Macros With Data
 ******************************************************************************/
/**
 * \def FSM_STATE_DECLARE(FSM, state_name, event_data)
 *
 * Declare a state \c state_name within the class definition of \c FSM, which
 * requires the input signal of \c event_data each time the state is executed.
 *
 * Should always return \ref event_signal::ekHANDLED for \ref simple_fsm
 * (anything other than that will halt the state machine/crash the program). Can
 * return other signals if the state is part of a \ref hfsm.
 */
#define FSM_STATE_DECLARE(FSM, state_name, event_data)      \
  int ST_##state_name(event_data*);                   \
  rcppsw::patterns::fsm::                         \
      state_action1<FSM, event_data, &FSM::ST_##state_name> \
  state_name{}

/**
 * \def FSM_STATE_DEFINE(FSM, state_name, event_data)
 *
 * Define a state \c state_name for a class \c FSM, which requires the input
 * signal of \c event_data each time the state is executed.
 */
#define FSM_STATE_DEFINE(FSM, state_name, event_data)     \
  int FSM::ST_##state_name(event_data)

/**
 * \def FSM_GUARD_DECLARE(FSM, guard_name, event_data)
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
  rcppsw::patterns::fsm::                                  \
      state_guard_condition1<FSM, event_data, &FSM::GD_##guard_name> \
  guard_name{}

/**
 * \def FSM_GUARD_DEFINE(FSM, guard_name, event_data) Define a guard
 * \c guard_name for a class  \c FSM, which requires the input
 * signal of \c event_data each time the guard is executed.
 */
#define FSM_GUARD_DEFINE(FSM, guard_name, event_data)     \
  bool FSM::GD_##guard_name(const event_data)


/**
 * \def FSM_ENTRY_DECLARE(FSM, entry_name, event_data)
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
  rcppsw::patterns::fsm::                               \
      state_entry_action1<FSM, event_data, &FSM::EN_##entry_name> \
  entry_name{}

/**
 * \def FSM_ENTRY_DEFINE(FSM, entry_name, event_data)
 *
 * Declare an entry \c entry_name for a class \c FSM, which requires the input
 * signal of \c event_data each time the entry is executed.
 */
#define FSM_ENTRY_DEFINE(FSM, entry_name, event_data)  \
  void FSM::EN_##entry_name(const event_data)

/**
 * \def FSM_EXIT_DECLARE(FSM, exit_name)
 *
 * Declare an exit \c exit_name within the class definition of \c FSM.
 *
 * Whenever a state transition occurs in the FSM, if the old state has an exit
 * function defined then it will be run before leaving the state.
 */
#define FSM_EXIT_DECLARE(FSM, exit_name)                                        \
  void EX_##exit_name(void);                                                    \
  rcppsw::patterns::fsm::state_exit_action<FSM, &FSM::EX_##exit_name> \
  exit_name{}

/**
 * \def FSM_EXIT_DEFINE(FSM, exit_name)
 *
 * Define an exit \c exit_name within the a class \c FSM.
 */
#define FSM_EXIT_DEFINE(FSM, exit_name) void FSM::EX_##exit_name(void)

/*******************************************************************************
* State Macros Without Data
******************************************************************************/
/**
 * \def FSM_STATE_DECLARE_ND(FSM, state_name)
 *
 * Same as \ref FSM_STATE_DECLARE(), but without any input data.
 */
#define FSM_STATE_DECLARE_ND(FSM, state_name)                                \
  int ST_##state_name(void);                                                 \
  rcppsw::patterns::fsm::state_action0<FSM, &FSM::ST_##state_name> \
  state_name{}

/**
 * \def FSM_STATE_DEFINE_ND(FSM, state_name)
 *
 * Same as \ref FSM_STATE_DEFINE(), but without any input data.
 */
#define FSM_STATE_DEFINE_ND(FSM, state_name) int FSM::ST_##state_name(void)

/**
 * \def FSM_GUARD_DECLARE_ND(FSM, guard_name)
 *
 * Same as \ref FSM_GUARD_DECLARE(), but without any input data.
 */
#define FSM_GUARD_DECLARE_ND(FSM, guard_name)                                    \
  bool GD_##guard_name(void);                                                    \
  rcppsw::patterns::fsm::state_guard_condition0<FSM,                   \
                                                          &FSM::GD_##guard_name> \
  guard_name{}

/**
 * \def FSM_GUARD_DEFINE_ND(FSM, guard_name)
 *
 * Same as \ref FSM_GUARD_DEFINE(), but without any input data.
 */
#define FSM_GUARD_DEFINE_ND(FSM, guard_name) bool FSM::GD_##guard_name(void)

/**
 * \def FSM_ENTRY_DECLARE_ND(FSM, entry_name)
 *
 * Same as \ref FSM_ENTRY_DECLARE(), but without any input data.
 */
#define FSM_ENTRY_DECLARE_ND(FSM, entry_name)                                      \
  void EN_##entry_name(void);                                                      \
  rcppsw::patterns::fsm::state_entry_action0<FSM, &FSM::EN_##entry_name> \
  entry_name{}

/**
 * \def FSM_ENTRY_DEFINE_ND(FSM, entry_name) Same as \ref FSM_ENTRY_DEFINE(),
 * but without any input data.
 */
#define FSM_ENTRY_DEFINE_ND(FSM, entry_name) void FSM::EN_##entry_name(void)

/*******************************************************************************
 * Transition Map Macros
 ******************************************************************************/
/**
 * \def FSM_DEFINE_TRANSITION_MAP(name)
 *
 * Define the transition map/table for a state machine. Can only be used if \b
 * ALL instances of a class can share the same table, which is true for
 * \ref simple_fsm, but not necessarily for \ref hfsm.
 *
 */
#define FSM_DEFINE_TRANSITION_MAP(name) static const uint8_t name[] =

/**
 * \def FSM_VERIFY_TRANSITION_MAP(name, n_entries)
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
                "Transition map does not cover all states");

/*******************************************************************************
 * State Map Macros
 ******************************************************************************/
/**
 * \def FSM_DECLARE_STATE_MAP(type, name)
 *
 * Declare a state map for an FSM. Note that even for \ref simple_fsm state
 * machines with identical state maps across all class instances, you \b CANNOT
 * use `static` state maps, because state maps contain states, and states use \b
 * MEMBER function pointers, which are necessarily tied to the enclosing
 * object. Using `static` state maps leads to all instances of a class sharing
 * the member function pointers of the *first* instance of the class
 * constructed, and if that object is ever destructed, segfaults will
 * (probably) ensue.
 *
 * \c type must be either "state_map" or "state_map_ex", corresponding to which
 * type of states the state machine is comprised of. \c name can be anything.
 */
#define FSM_DECLARE_STATE_MAP(type, name, n_entries)                    \
  const std::array<rcppsw::patterns::fsm::RCSW_JOIN(type, _row),              \
                   n_entries> name

/**
 * \def FSM_DEFINE_STATE_MAP(name, ...)
 *
 * Define the state map for an FSM.
 */
#define FSM_DEFINE_STATE_MAP(name, ...) name {__VA_ARGS__}

/**
 * \def FSM_DEFINE_STATE_MAP_ACCESSOR(type, index_var)
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
  const rcppsw::patterns::fsm::RCSW_JOIN(type, _row) * \
  type(size_t index_var)

/**
 * \def FSM_STATE_MAP_ENTRY(state_name)
 *
 * Define a state map entry for state \c state_name.
 */
#define FSM_STATE_MAP_ENTRY(state_name) \
  rcppsw::patterns::fsm::state_map_row(state_name)

/**
 * \def FSM_STATE_MAP_ENTRY_EX(state_name)
 *
 * Define an extended state map entry for state \c state_name, where the state
 * does not use any of the entry/exit/guard callbacks. Useful for reducing code
 * clutter.
 */
#define FSM_STATE_MAP_ENTRY_EX(state_name)           \
  rcppsw::patterns::fsm::state_map_ex_row( \
      state_name, NULL, NULL, NULL)

/**
 * \def FSM_STATE_MAP_ENTRY_EX_ALL(state_name, guard_name, entry_name, exit_name)
 *
 * Define an extended state map entry for state \c state_name, along will all
 * callbacks. If entry/exit/guard callbacks are not used for the state,
 * \c nullptr should be passed.
 */
#define FSM_STATE_MAP_ENTRY_EX_ALL(                  \
    state_name, guard_name, entry_name, exit_name)   \
  rcppsw::patterns::fsm::state_map_ex_row( \
      state_name, guard_name, entry_name, exit_name)

#endif /* INCLUDE_RCPPSW_PATTERNS_FSM_BASE_FSM_HPP_ */
