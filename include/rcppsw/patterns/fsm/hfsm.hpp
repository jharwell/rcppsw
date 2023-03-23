/**
 * \file hfsm.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "rcppsw/patterns/fsm/base_fsm.hpp"
#include "rcppsw/patterns/fsm/hfsm_state.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::patterns::fsm {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class hfsm
 * \ingroup patterns fsm
 *
 * \brief Implements a software-based hierarchical state machine (states can
 * contain other states).
 */
class hfsm : public base_fsm, public er::client<hfsm> {
 public:
  /**
   * \param max_states The maximum number of state machine states.
   * \param initial_state Initial state machine state.
   */
  explicit hfsm(uint8_t max_states,
                uint8_t initial_state = 0)
      : base_fsm(max_states, initial_state),
        ER_CLIENT_INIT("rcppsw.patterns.fsm.hfsm"),
        m_top_state(nullptr) {}

  ~hfsm() override = default;

  void init(void) override {
    ER_ASSERT(initial_state() < event_signal::ekIGNORED,
                     "Bad initial state");
    base_fsm::init();
  }

  /**
   * \brief Change the parent state of the specified state to a new state.
   *
   * \param state The state within THIS state machine to change the parent of.
   * \param new_parent A new parent state, which can be from ANOTHER \ref hfsm.
   */
  void change_parent(uint8_t state,
                     rcppsw::patterns::fsm::state* new_parent);

 protected:
  /**
   * \brief The topmost state in the hierarchy, of which all states are
   * children. If an event gets all the way up to here, that's bad, because it
   * should have been handled at a lower layer.
   *
   * \return Does not return.
   */
  int ST_top_state(void) {
    ER_FATAL_SENTINEL("Top state in HFSM");
    return 0;
  }
  hfsm_state_action0<hfsm, &hfsm::ST_top_state>* top_state(void) {
    return &m_top_state;
  }

 private:
  void state_engine_step(const state_map_row* c_row) override;
  void state_engine_step(const state_map_ex_row* c_row_ex) override;

  /* clang-format off */
  hfsm_state_action0<hfsm, &hfsm::ST_top_state> m_top_state;
  /* clang-format on */
};

/*******************************************************************************
 * State Macros With Data
 ******************************************************************************/
/**
 * \def RCPPSW_HFSM_STATE_INHERIT(BASE_FSM, inherited_name, event_data)
 *
 * Declare a state in the current HFSM to be inherited from a parent HFSM.
 *
 * This can be private because it is just a member variable.
 */
#define RCPPSW_HFSM_STATE_INHERIT(BASE_FSM, inherited_name, event_data)               \
 private:                                                                      \
  rcppsw::patterns::fsm::                                            \
      hfsm_state_action1<BASE_FSM, event_data, &BASE_FSM::ST_##inherited_name> \
          inherited_name

/**
 * \def RCPPSW_HFSM_STATE_DECLARE(FSM, state_name, event_data)
 *
 * Declare a state in the current HFSM.
 *
 * The state handler function MUST be public in order for \ref hfsm_state_action1
 * templating to work. Apparently when dealing with non-type template arguments,
 * any argument passed that does not EXACTLY match the one in the template will
 * cause a compilation error if the function is protected (i.e. accessible in
 * derived classes). The solution: make it public. Not the best, because it
 * exposes the inner workings of the state machine, but anyone who is using this
 * class should only be manipulating it through the macros anyway.
 */
#define RCPPSW_HFSM_STATE_DECLARE(FSM, state_name, event_data)          \
 public:                                                         \
  int ST_##state_name(event_data*);                        \
                                                                 \
 private:                                                        \
  rcppsw::patterns::fsm::                              \
      hfsm_state_action1<FSM, event_data, &FSM::ST_##state_name> \
          state_name

#define RCPPSW_HFSM_STATE_DEFINE(FSM, state_name, event_data)    \
  RCPPSW_FSM_STATE_DEFINE(FSM, state_name, event_data)

#define RCPPSW_HFSM_GUARD_DECLARE(FSM, guard_name, event_data) \
  RCPPSW_FSM_GUARD_DECLARE(FSM, guard_name, event_data)
#define RCPPSW_HFSM_GUARD_DEFINE(FSM, guard_name, event_data)    \
  RCPPSW_FSM_GUARD_DEFINE(FSM, guard_name, event_data)

/**
 * \def RCPPSW_HFSM_ENTRY_DECLARE(FSM, entry_name, event_data)
 *
 * Declare a state in the current HFSM.
 *
 * The entry handler function MUST be public in order for templating to
 * work. Apparently when dealing with non-type template arguments, any argument
 * passed that does not EXACTLY match the one in the template will cause a
 * compilation error if the function is protected (i.e. accessible in derived
 * classes). The solution: make it public. Not the best, because it exposes the
 * inner workings of the state machine, but anyone who is using this class
 * should only be manipulating it through the macros anyway.
 */
#define RCPPSW_HFSM_ENTRY_DECLARE(FSM, entry_name, event_data)           \
 public:                                                          \
  void EN_##entry_name(const event_data*);                        \
                                                                  \
 private:                                                         \
  rcppsw::patterns::fsm::                               \
      state_entry_action1<FSM, event_data, &FSM::EN_##entry_name> \
          entry_name

/**
 * \def RCPPSW_HFSM_ENTRY_INHERIT(BASE_FSM, inherited_name, event_data)
 *
 * Declare a entry callback in the current HFSM to be inherited from a parent
 * HFSM.
 *
 * This can be private because it is just a member variable.
 */
#define RCPPSW_HFSM_ENTRY_INHERIT(BASE_FSM, inherited_name, event_data)                \
 private:                                                                       \
  rcppsw::patterns::fsm::                                             \
      state_entry_action1<BASE_FSM, event_data, &BASE_FSM::EN_##inherited_name> \
          inherited_name

#define RCPPSW_HFSM_ENTRY_DEFINE(FSM, entry_name, event_data)   \
  RCPPSW_FSM_ENTRY_DEFINE(FSM, entry_name, event_data)

/**
 * \def RCPPSW_HFSM_EXIT_INHERIT(BASE_FSM, inherited_name, event_data)
 *
 * Declare an exit callback in the current HFSM to be inherited from a parent
 * HFSM.
 *
 * This can be private because it is just a member variable.
 */
#define RCPPSW_HFSM_EXIT_INHERIT(BASE_FSM, inherited_name)               \
 private:                                                         \
  rcppsw::patterns::fsm::                               \
      state_exit_action<BASE_FSM, &BASE_FSM::EX_##inherited_name> \
 inherited_name{}

/**
 * \def RCPPSW_HFSM_EXIT_DECLARE(FSM, exit_name)
 *
 * Declare an exit callback in the current HFSM.
 */
#define RCPPSW_HFSM_EXIT_DECLARE(FSM, exit_name)                        \
  public:                                                               \
  void EX_##exit_name(void);                                            \
                                                                        \
private:                                                                \
rcppsw::patterns::fsm::state_exit_action<FSM, &FSM::EX_##exit_name>     \
exit_name{}

#define RCPPSW_HFSM_EXIT_DEFINE(FSM, exit_name) RCPPSW_FSM_EXIT_DEFINE(FSM, exit_name)

/**
 * \brief Construct a previously declared/inherited state.
 *
 * Should be called in the constructor, and passed the desired parent
 * state. This cannot be done at state declaration (from the compiler's point of
 * view), because of the way templating works (I think).
 */
#define RCPPSW_HFSM_CONSTRUCT_STATE(state_name, parent)                        \
  state_name(static_cast<rcppsw::patterns::fsm::hfsm_state*>(parent))

/*******************************************************************************
 * State Macros Without Data
 ******************************************************************************/
/**
 * \def RCPPSW_HFSM_STATE_INHERIT_ND(FSM, inherited_name)
 *
 * Same as \ref RCPPSW_HFSM_STATE_INHERIT(), but with no data.
 */
#define RCPPSW_HFSM_STATE_INHERIT_ND(BASE_FSM, inherited_name)            \
 private:                                                          \
  rcppsw::patterns::fsm::                                \
      hfsm_state_action0<BASE_FSM, &BASE_FSM::ST_##inherited_name> \
          inherited_name

/**
 * \def RCPPSW_HFSM_STATE_DECLARE_ND(FSM, state_name)
 *
 * Same as \ref RCPPSW_HFSM_STATE_DECLARE(), but with no data.
 */
#define RCPPSW_HFSM_STATE_DECLARE_ND(FSM, state_name, ...)                     \
  public:                                                               \
  int ST_##state_name(void) __VA_ARGS__;                                \
                                                                        \
private:                                                                \
rcppsw::patterns::fsm::hfsm_state_action0<FSM, &FSM::ST_##state_name> \
state_name

#define RCPPSW_HFSM_STATE_DEFINE_ND(FSM, state_name) \
  RCPPSW_FSM_STATE_DEFINE_ND(FSM, state_name)

#define RCPPSW_HFSM_GUARD_DECLARE_ND(FSM, guard_name) \
  RCPPSW_FSM_GUARD_DECLARE_ND(FSM, guard_name)
#define RCPPSW_HFSM_GUARD_DEFINE_ND(FSM, guard_name) \
  RCPPSW_FSM_GUARD_DEFINE_ND(FSM, guard_name)

/**
 * \def RCPPSW_HFSM_ENTRY_DECLARE_ND(FSM, entry_name)
 *
 * Same as \ref RCPPSW_HFSM_ENTRY_DECLARE(), but with no data.
 */
#define RCPPSW_HFSM_ENTRY_DECLARE_ND(FSM, entry_name)                          \
  public:                                                               \
  void EN_##entry_name(void);                                           \
                                                                        \
private:                                                                \
rcppsw::patterns::fsm::state_entry_action0<FSM, &FSM::EN_##entry_name> \
entry_name{}

/**
 * \def RCPPSW_HFSM_ENTRY_INHERIT_ND(FSM, inherited_name)
 *
 * Same as \ref RCPPSW_HFSM_ENTRY_INHERIT(), but with no data.
 */
#define RCPPSW_HFSM_ENTRY_INHERIT_ND(BASE_FSM, inherited_name)             \
 private:                                                           \
  rcppsw::patterns::fsm::                                 \
      state_entry_action0<BASE_FSM, &BASE_FSM::EN_##inherited_name> \
 inherited_name{}

#define RCPPSW_HFSM_ENTRY_DEFINE_ND(FSM, entry_name) \
  RCPPSW_FSM_ENTRY_DEFINE_ND(FSM, entry_name)

/*******************************************************************************
 * Transition Map Macros
 ******************************************************************************/
#define RCPPSW_HFSM_DEFINE_TRANSITION_MAP(name)        \
  RCPPSW_FSM_DEFINE_TRANSITION_MAP(name)

#define RCPPSW_HFSM_VERIFY_TRANSITION_MAP(name, n_entries)      \
  RCPPSW_FSM_VERIFY_TRANSITION_MAP(name, n_entries)

/*******************************************************************************
 * State Map Macros
 ******************************************************************************/
#define RCPPSW_HFSM_DEFINE_STATE_MAP_ACCESSOR(type, index_var) \
  RCPPSW_FSM_DEFINE_STATE_MAP_ACCESSOR(type, index_var)

#define RCPPSW_HFSM_DECLARE_STATE_MAP(type, name, n_entries)   \
  RCPPSW_FSM_DECLARE_STATE_MAP(type, name, n_entries)

#define RCPPSW_HFSM_DEFINE_STATE_MAP(name, ...) RCPPSW_FSM_DEFINE_STATE_MAP(name, __VA_ARGS__)

#define RCPPSW_HFSM_STATE_MAP_ENTRY_EX(state_name) RCPPSW_FSM_STATE_MAP_ENTRY_EX(state_name)
#define RCPPSW_HFSM_STATE_MAP_ENTRY(state_name) RCPPSW_FSM_STATE_MAP_ENTRY(state_name)

#define RCPPSW_HFSM_STATE_MAP_ENTRY_EX_ALL(               \
    state_name, guard_name, entry_name, exit_name) \
  RCPPSW_FSM_STATE_MAP_ENTRY_EX_ALL(state_name, guard_name, entry_name, exit_name)

} /* namespace rcppsw::patterns::fsm */

