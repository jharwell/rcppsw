/**
 * @file visitable.hpp
 * @ingroup patterns visitor
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

#ifndef INCLUDE_RCPPSW_PATTERNS_VISITOR_VISITABLE_HPP_
#define INCLUDE_RCPPSW_PATTERNS_VISITOR_VISITABLE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, visitor);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class visitable_any
 *
 * @brief A class that will accept any kind of visitor.
 *
 * This is suitable for general application of the visitor pattern that does not
 * require polymorphism. The visitor must be derived from \ref visitor()/
 * \ref can_visit() otherwise the static_cast will fail.
 */
template<class V>
class visitable_any {
 public:
  visitable_any(void) = default;

  template <typename T>
  void accept(T &visitor) { visitor.visit(static_cast<V&>(*this)); }
  virtual ~visitable_any(void) = default;
};

/**
 * @class will_accept
 *
 * @brief A class that will accept a specific kind of visitor.
 */
template <class V>
class will_accept {
 public:
  will_accept(void) = default;

  template <class T>
  void accept(const T &visitor) { visitor.visit(static_cast<V&>(*this)); }
  virtual ~will_accept(void) = default;
};

/**
 * @class visitable_set_helper
 *
 * @brief Helper class to provide actual implementation.
 */
template <typename V, typename T>
class visitable_set_helper {
 public:
  virtual ~visitable_set_helper(void) = default;

  void accept(T &visitor) { visitor.visit(static_cast<V&>(*this)); }
};

/**
 * @class visitable_set
 *
 * @brief General case for template expansion. Provides classes the ability to
 * explicitly control what types of visitors they will accept.
 */
template <typename... Ts>
class visitable_set {};

/**
 * @class visitable_set<V,T,..>
 *
 * @brief Middle recursive case for expansion.
 */
template<typename V, typename T, typename... Ts>
class visitable_set<V, T, Ts...>: public visitable_set_helper<V, T>,
                                   public visitable_set<V, Ts...> {
 public:
  using visitable_set_helper<V, T>::accept;
  using visitable_set<V, Ts...>::accept;
};

/**
 * @class visitable_set<V,T>
 *
 * @brief Base case for expansion
 */
template<typename V, typename T>
class visitable_set<V, T>: public visitable_set_helper<V, T> {
 public:
  using visitable_set_helper<V, T>::accept;
};

NS_END(rcppsw, patterns, visitor);

#endif /* INCLUDE_RCPPSW_PATTERNS_VISITOR_VISITABLE_HPP_ */
