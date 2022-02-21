/**
 * \file polymorphic_visitable.hpp
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

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * \def RCPPSW_VISITOR_ACCEPT_STUB
 *
 * \brief A stub of a visitor acceptance function necessary to conform to an
 * unspecified interface, with the added benefit that if this stub is ever
 * executed you get an assertion failure rather than a silent error.
 *
 * You can only use this macro in a class which inherits from \ref rer::client.
 */
#define RCPPSW_VISITOR_ACCEPT_STUB(Visitor) \
  void accept(Visitor&) override {                      \
    ER_FATAL_SENTINEL("Stub function %s hit", __FUNCTION__);    \
  }

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, visitor, detail);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \ingroup patterns visitor
 *
 * \brief Helper class to provide the actual implementation of the visitor
 * pattern, receiving end.
 *
 * \tparam T The type to accept.
 */
template <typename T>
class polymorphic_accept_set_helper {
 public:
  virtual void accept(T &visitor) = 0;
  virtual ~polymorphic_accept_set_helper(void) = default;
};

NS_END(detail);

/**
 * \ingroup patterns visitor
 *
 * \brief Allows polymorphic classes (those with a pure virtual member in a base
 * class) to accept visitors of specific types. Allows implicit conversion to
 * base classes if both base/derived types are present in the set.
 *
 * This is more "single dispatch" than "double dispatch", and so is not
 * precisely the visitor pattern, as classes deriving from this class need to
 * implement the second part of the dispatch themselves. However, for situations
 * where you have disparate classes that all share a common interface this is a
 * far more elegant solution than a brittle series of if-else to determine the
 * proper type of the object via dynamic_cast<> before calling a chained visit()
 * function.
 */
template <typename... Ts>
class polymorphic_accept_set {};

/*
 * Middle recursive call for template expansion.
 */
template<typename T, typename... Ts>
class polymorphic_accept_set<T, Ts...>: public detail::polymorphic_accept_set_helper<T>,
                                        public polymorphic_accept_set<Ts...> {
 public:
  using detail::polymorphic_accept_set_helper<T>::accept;
  using polymorphic_accept_set<Ts...>::accept;
};

/*
 * Base case for template expansion.
 */
template<typename T>
class polymorphic_accept_set<T>: public detail::polymorphic_accept_set_helper<T> {
 public:
  using detail::polymorphic_accept_set_helper<T>::accept;
};

NS_END(rcppsw, patterns, visitor);
