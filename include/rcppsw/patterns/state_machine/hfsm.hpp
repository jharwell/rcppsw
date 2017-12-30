/**
 * @file hfsm.hpp
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

#ifndef INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_HFSM_HPP_
#define INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_HFSM_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/patterns/state_machine/base_fsm.hpp"
#include "rcppsw/patterns/state_machine/hfsm_state.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, state_machine);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class hfsm Implements a software-based hierarchical state machine.
 */
class hfsm : public base_fsm {
 public:
  /**
   * @param max_states The maximum number of state machine states.
   * @param initial_state Initial state machine state.
   */
  hfsm(const std::shared_ptr<er::server>& server,
       uint8_t max_states,
       uint8_t initial_state = 0)
      : base_fsm(server, max_states, initial_state), m_top_state(nullptr) {}

  ~hfsm() override = default;

  void init(void) override {
    ER_ASSERT(initial_state() < event_signal::IGNORED,
                     "FATAL: Bad initial state");
    base_fsm::init();
  }

  void inject_event(int signal, int type);

  void change_parent(uint8_t state,
                     rcppsw::patterns::state_machine::state* new_parent);

 protected:
  /**
   * @brief The topmost state in the hierarchy, of which all states are
   * children. If an event gets all the way up to here, that's bad, because it
   * should have been handled at a lower layer.
   *
   * @return Does not return.
   */
  int ST_top_state(void) {
    ER_FATAL_SENTINEL("FATAL: Top state in HFSM");
    return 0;
  }
  hfsm_state_action0<hfsm, &hfsm::ST_top_state>* top_state(void) {
    return &m_top_state;
  }

 private:
  void state_engine_step(const state_map_row* c_row) override;
  void state_engine_step(const state_map_ex_row* c_row_ex) override;

  hfsm_state_action0<hfsm, &hfsm::ST_top_state> m_top_state;
};

/*******************************************************************************
 * State Macros With Data
 ******************************************************************************/
/**
 * @brief Declare a state in the current HFSM to be inherited from a parent
 * HFSM.
 *
 * This can be private because it is just a member variable.
 */
#define HFSM_STATE_INHERIT(BASE_FSM, inherited_name, event_data)               \
 private:                                                                      \
  rcppsw::patterns::state_machine::                                            \
      hfsm_state_action1<BASE_FSM, event_data, &BASE_FSM::ST_##inherited_name> \
          inherited_name

/**
 * @brief Declare a state in the current HFSM.
 *
 * The state handler function MUST be public in order for \ref hfsm_state_action
 * templating to work. Apparently when dealing with non-type template arguments,
 * any argument passed that does not EXACTLY match the one in the template will
 * cause a compilation error if the function is protected (i.e. accessible in
 * derived classes). The solution: make it public. Not the best, because it
 * exposes the inner workings of the state machine, but anyone who is using this
 * class should only be manipulating it through the macros anyway.
 */
#define HFSM_STATE_DECLARE(FSM, state_name, event_data)          \
 public:                                                         \
  int ST_##state_name(const event_data*);                        \
                                                                 \
 private:                                                        \
  rcppsw::patterns::state_machine::                              \
      hfsm_state_action1<FSM, event_data, &FSM::ST_##state_name> \
          state_name

#define HFSM_STATE_DEFINE(FSM, state_name, event) \
  FSM_STATE_DEFINE(FSM, state_name, event)

#define HFSM_GUARD_DECLARE(FSM, guard_name, event_data) \
  FSM_GUARD_DECLARE(FSM, guard_name, event_data)
#define HFSM_GUARD_DEFINE(FSM, guard_name, event_data) \
  FSM_GUARD_DEFINE(FSM, guard_name, event_data)

#define HFSM_ENTRY_DECLARE(FSM, entry_name, event_data)           \
 public:                                                          \
  void EN_##entry_name(const event_data*);                        \
                                                                  \
 private:                                                         \
  rcppsw::patterns::state_machine::                               \
      state_entry_action1<FSM, event_data, &FSM::EN_##entry_name> \
          entry_name

#define HFSM_ENTRY_INHERIT(BASE_FSM, inherited_name, event_data)                \
 private:                                                                       \
  rcppsw::patterns::state_machine::                                             \
      state_entry_action1<BASE_FSM, event_data, &BASE_FSM::EN_##inherited_name> \
          inherited_name
#define HFSM_ENTRY_DEFINE(FSM, entry_name, event_data) \
  FSM_ENTRY_DEFINE(FSM, entry_name, event_data)

#define HFSM_EXIT_DECLARE(FSM, exit_name)                                       \
 public:                                                                        \
  void EX_##exit_name(void);                                                    \
                                                                                \
 private:                                                                       \
  rcppsw::patterns::state_machine::state_exit_action<FSM, &FSM::EX_##exit_name> \
      exit_name

#define HFSM_EXIT_INHERIT(BASE_FSM, inherited_name)               \
 private:                                                         \
  rcppsw::patterns::state_machine::                               \
      state_exit_action<BASE_FSM, &BASE_FSM::EX_##inherited_name> \
          inherited_name

#define HFSM_EXIT_DEFINE(FSM, exit_name) FSM_EXIT_DEFINE(FSM, exit_name)

/**
 * @brief Construct a previously declared/inherited state.
 *
 * Should be called in the constructor, and passed the desired parent
 * state. This cannot be done at state declaration (from the compiler's point of
 * view), because of the way templating works.
 */
#define HFSM_CONSTRUCT_STATE(state_name, parent) \
  state_name(static_cast<rcppsw::patterns::state_machine::hfsm_state*>(parent))

/*******************************************************************************
 * State Macros Without Data
 ******************************************************************************/
#define HFSM_STATE_INHERIT_ND(BASE_FSM, inherited_name)            \
 private:                                                          \
  rcppsw::patterns::state_machine::                                \
      hfsm_state_action0<BASE_FSM, &BASE_FSM::ST_##inherited_name> \
          inherited_name

#define HFSM_STATE_DECLARE_ND(FSM, state_name)                                    \
 public:                                                                          \
  int ST_##state_name(void);                                                      \
                                                                                  \
 private:                                                                         \
  rcppsw::patterns::state_machine::hfsm_state_action0<FSM, &FSM::ST_##state_name> \
      state_name

#define HFSM_STATE_DEFINE_ND(FSM, state_name) \
  FSM_STATE_DEFINE_ND(FSM, state_name)

#define HFSM_GUARD_DECLARE_ND(FSM, guard_name) \
  FSM_GUARD_DECLARE_ND(FSM, guard_name)
#define HFSM_GUARD_DEFINE_ND(FSM, guard_name) \
  FSM_GUARD_DEFINE_ND(FSM, guard_name)

#define HFSM_ENTRY_DECLARE_ND(FSM, entry_name)                                     \
 public:                                                                           \
  void EN_##entry_name(void);                                                      \
                                                                                   \
 private:                                                                          \
  rcppsw::patterns::state_machine::state_entry_action0<FSM, &FSM::EN_##entry_name> \
      entry_name

#define HFSM_ENTRY_INHERIT_ND(BASE_FSM, inherited_name)             \
 private:                                                           \
  rcppsw::patterns::state_machine::                                 \
      state_entry_action0<BASE_FSM, &BASE_FSM::EN_##inherited_name> \
          inherited_name
#define HFSM_ENTRY_DEFINE_ND(FSM, entry_name) \
  FSM_ENTRY_DEFINE_ND(FSM, entry_name)

/*******************************************************************************
 * State Map Macros
 ******************************************************************************/
#define HFSM_DEFINE_STATE_MAP_ACCESSOR(type, index_var) \
  FSM_DEFINE_STATE_MAP_ACCESSOR(type, index_var)

/*
 * @def HFSM_DECLARE_STATE_MAP Declare the state map for a state machine.
 *
 * This CANNOT be made a static variable inside a function, because if two or
 * more instances of a state machine derived class have states that do not share
 * the same parent, the global scope for the map will cause updates to the state
 * map (such as changing the parent of a state).
 */
#define HFSM_DECLARE_STATE_MAP(type, name, n_entries) \
    const rcppsw::patterns::state_machine::JOIN(type, _row) (name)[n_entries]

#define HFSM_STATE_MAP_ENTRY_EX(state_name) FSM_STATE_MAP_ENTRY_EX(state_name)

#define HFSM_STATE_MAP_ENTRY_EX_ALL(               \
    state_name, guard_name, entry_name, exit_name) \
  FSM_STATE_MAP_ENTRY_EX_ALL(state_name, guard_name, entry_name, exit_name)

NS_END(state_machine, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_HFSM_HPP_ */
