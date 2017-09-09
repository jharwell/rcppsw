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
#include <stdio.h>
#include <typeinfo>
#include <cstddef>
#include <mutex>
#include "rcppsw/patterns/state_machine/hfsm_state.hpp"
#include "rcppsw/patterns/state_machine/base_fsm.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, state_machine);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * @brief A structure to hold a single row within the state map.
 */
class hfsm_state_map_row : public state_map_row {
 public:
  hfsm_state_map_row(rcppsw::patterns::state_machine::state* state,
                     rcppsw::patterns::state_machine::state* parent) :
      state_map_row(state), m_parent(parent) {}

  rcppsw::patterns::state_machine::state* parent(void) const { return m_parent; }

 private:
  rcppsw::patterns::state_machine::state* m_parent;
};

/**
 * @brief A structure to hold a single row within the extended state map.
 */
class hfsm_state_map_ex_row : public state_map_ex_row {
 public:
  hfsm_state_map_ex_row(rcppsw::patterns::state_machine::state* state,
                        rcppsw::patterns::state_machine::state* parent,
                        state_guard* guard,
                        state_entry* entry, state_exit* exit) :
      state_map_ex_row(state, guard, entry, exit), m_parent(parent) {}

  rcppsw::patterns::state_machine::state* parent(void) const { return m_parent; }

 private:
  rcppsw::patterns::state_machine::state* m_parent;
};

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief hfsm implements a software-based state machine.
 */
class hfsm: public base_fsm {
 public:
  /**
   * @param max_states The maximum number of state machine states.
   * @param initial_state Initial state machine state.
   */
  explicit hfsm(std::shared_ptr<common::er_server> server) :
      base_fsm(server), m_top_state(nullptr) {}

  virtual ~hfsm() {}

  virtual void init(void) {
    assert(initial_state() < event_signal::IGNORED);
    base_fsm::init();
  }

  void inject_event(int signal, int type);

 protected:
  /**
   * @brief The topmost state in the hierarchy, of which all states are
   * children. If an event gets all the way up to here, that's bad, because it
   * should have been handled at a lower layer.
   *
   * @return Does not return.
   */
  int ST_top_state(__unused const no_event_data* data) { assert(0); }
  hfsm_state_action<hfsm,
                    no_event_data,
                    &hfsm::ST_top_state>* top_state(void) {
    return &m_top_state;
  }

 private:
  void state_engine_step(const state_map_row* const map);
  void state_engine_step(const state_map_ex_row* const map_ex);

  hfsm(const hfsm& fsm) = delete;
  hfsm& operator=(const hfsm& fsm) = delete;

  hfsm_state_action<hfsm, no_event_data, &hfsm::ST_top_state> m_top_state;
};

/*******************************************************************************
 * State Macros
 ******************************************************************************/
#define HFSM_STATE_INHERIT(BASE_FSM, \
                           inherited_name, \
                           state_data)                                  \
  private:                                                              \
  rcppsw::patterns::state_machine::hfsm_state_action<BASE_FSM,          \
                                                     state_data,        \
                                                     &BASE_FSM::ST_##inherited_name> inherited_name;
#define HFSM_STATE_DECLARE(FSM, state_name, state_data)              \
  public:                                                            \
  int ST_##state_name(__unused const state_data*);                      \
private:                                                                \
rcppsw::patterns::state_machine::hfsm_state_action<FSM,                 \
                                                   state_data,          \
                                                   &FSM::ST_##state_name> state_name; \


#define HFSM_STATE_DEFINE(FSM, state_name, event) \
  FSM_STATE_DEFINE(FSM, state_name, event)

#define HFSM_GUARD_DECLARE(FSM, guard_name, event_data) \
  FSM_GUARD_DECLARE(FSM, guard_name, event_data)
#define HFSM_GUARD_DEFINE(FSM, guard_name, event_data) \
  FSM_GUARD_DEFINE(FSM, guard_name, event_data)

#define HFSM_ENTRY_DECLARE(FSM, entry_name, event_data)                 \
  public:                                                               \
  void EN_##entry_name(__unused const event_data*);                      \
private:                                                                \
rcppsw::patterns::state_machine::state_entry_action<FSM,                \
                                                    event_data,         \
                                                    &FSM::EN_##entry_name> entry_name;

#define HFSM_ENTRY_INHERIT(BASE_FSM, inherited_name, event_data)        \
  private:                                                              \
  rcppsw::patterns::state_machine::state_entry_action<BASE_FSM,         \
                                                      event_data,       \
                                                      &BASE_FSM::EN_##inherited_name> inherited_name;
#define HFSM_ENTRY_DEFINE(FSM, entry_name, event_data) \
  FSM_ENTRY_DEFINE(FSM, entry_name, event_data)

#define HFSM_EXIT_DECLARE(FSM, exit_name)                               \
  public:                                                               \
  void EX_##exit_name(void);                                            \
private:                                                                \
rcppsw::patterns::state_machine::state_exit_action<FSM,                 \
                                                   &FSM::EX_##exit_name> exit_name;

#define HFSM_EXIT_INHERIT(BASE_FSM, inherited_name)                     \
  private:                                                              \
  rcppsw::patterns::state_machine::state_exit_action<BASE_FSM,          \
                                                     &BASE_FSM::EX_##inherited_name> inherited_name;

#define HFSM_EXIT_DEFINE(FSM, exit_name) FSM_EXIT_DEFINE(FSM, exit_name)

#define HFSM_CONSTRUCT_STATE(state_name, \
                             parent) state_name(static_cast<fsm::hfsm_state*>(parent))

/*******************************************************************************
 * State Map Macros
 ******************************************************************************/
#define HFSM_DEFINE_STATE_MAP_ACCESSOR(type, index_var)   \
  FSM_DEFINE_STATE_MAP_ACCESSOR(type, index_var)
#define HFSM_DEFINE_STATE_MAP(type, name) \
  static const rcppsw::patterns::state_machine::JOIN(JOIN(hfsm_, type), _row) name[] =
#define HFSM_STATE_MAP_ENTRY_EX(state_name, parent) \
  rcppsw::patterns::state_machine::hfsm_state_map_ex_row(state_name, parent, \
                                                    NULL, \
                                                    NULL, NULL)

#define HFSM_STATE_MAP_ENTRY_EX_ALL(state_name,                 \
                                    parent,                     \
                                    guard_name,                 \
                                    entry_name,                 \
                                    exit_name)                  \
  rcppsw::patterns::state_machine::hfsm_state_map_ex_row(state_name, parent, \
                                                    guard_name, \
                                                    entry_name, exit_name)
#define HFSM_VERIFY_STATE_MAP(type, name) FSM_VERIFY_STATE_MAP(JOIN(hfsm_, type), name)

/*******************************************************************************
 * Transition Map Macros
 ******************************************************************************/
#define HFSM_DEFINE_TRANSITION_MAP(name) FSM_DEFINE_TRANSITION_MAP(name)
#define HFSM_TRANSITION_MAP_ENTRY(entry) FSM_TRANSITION_MAP_ENTRY(entry)
#define HFSM_VERIFY_TRANSITION_MAP(name) FSM_VERIFY_TRANSITION_MAP(name)

NS_END(state_machine, patterns, rcppsw);

#endif /* INCLUDE_RCPPSW_PATTERNS_STATE_MACHINE_HFSM_HPP_ */
