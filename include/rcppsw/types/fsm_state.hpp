/**
 * \file fsm_state.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_TYPES_FSM_STATE_HPP_
#define INCLUDE_RCPPSW_TYPES_FSM_STATE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"
#include "rcppsw/types/named_type.hpp"
#include "rcppsw/patterns/fsm/event.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, types);

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
/**
 * \class fsm_state
 * \ingroup types
 *
 * \brief A class for representing the state a given FSM is currently in, in
 * order to reduce the probability of strange behaviors that can occur if the
 * FSM state is tracked using a regular integer and compared with any other
 * integer. By using a strong type, you force comparisons to ONLY other
 * instances of this type to work without an explicit cast, which is generally a
 * good thing.
 */
class fsm_state : public rtypes::named_type<uint8_t, struct fsm_state_tag> {
 public:
  using named_type<uint8_t, fsm_state_tag>::named_type;

  fsm_state(const fsm_state&) = default;
  fsm_state& operator=(const fsm_state& other) {
    set(other.v());
    return *this;
  }

  bool operator<(const fsm_state& other) const { return v() < other.v(); }
  bool operator==(const fsm_state& other) const { return v() == other.v(); }
  bool operator!=(const fsm_state& other) const { return v() != other.v(); }

  bool operator<(const patterns::fsm::event_signal::type& other) const {
    return v() < other; }
  bool operator==(const patterns::fsm::event_signal::type& other) const {
    return v() == other;
  }
  bool operator!=(const patterns::fsm::event_signal::type& other) const {
    return v() != other;
  }
};

template <typename TEnumType, TEnumType Length>
class fsm_state_array {
 public:
  using value_type = typename std::underlying_type<TEnumType>::type;
  using array_type = std::array<TEnumType, static_cast<value_type>(Length)>;
  template<value_type... Indices>
  using sequence_type = std::integer_sequence<value_type, Indices...>;
  using make_sequence = std::make_integer_sequence<value_type,
                                                   static_cast<value_type>(Length)>;

  static array_type create(void) { return do_create(make_sequence{}); }

 private:
  template <value_type... Indices>
  static constexpr array_type do_create(sequence_type<Indices...>) {
    return {(static_cast<TEnumType>(Indices))...};
  }
};

NS_START(constants);

/** \brief Default starting state is 0 */
static fsm_state kDefaultStartState = fsm_state(0);

NS_END(constants, types, rcppsw);

#endif /* INCLUDE_RCPPSW_TYPES_FSM_STATE_HPP_ */
