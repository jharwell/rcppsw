/**
 * @file polymorphic_visitable.hpp
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

#ifndef INCLUDE_RCPPSW_PATTERNS_VISITOR_POLYMORPHIC_VISITABLE_HPP_
#define INCLUDE_RCPPSW_PATTERNS_VISITOR_POLYMORPHIC_VISITABLE_HPP_

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
 * @class polymorphic_visitable_helper
 *
 * @brief Helper class to provide the actual implementation of the visitor
 * pattern, receiving end.
 */
template <typename V, typename T>
class polymorphic_visitable_helper {
 public:
  virtual void accept(T &visitor) = 0;
  virtual ~polymorphic_visitable_helper(void) {}
};

/**
 * @class polymorphic_visitable<...>
 *
 * @brief Allows polymorphic classes (those with a pure virtual member in a base
 * class) to accept visitors of specific types.
 */
template <typename... Ts>
class polymorphic_visitable {};

/**
 * @class polymorphic_visitable<V,T,...>
 *
 * @brief Middle recursive call for template expansion.
 */
template<typename V, typename T, typename... Ts>
class polymorphic_visitable<V, T, Ts...>: public polymorphic_visitable_helper<V, T>,
                                          public polymorphic_visitable<V, Ts...> {
 public:
  using polymorphic_visitable_helper<V, T>::accept;
  using polymorphic_visitable<V, Ts...>::accept;
};

/**
 * @class polymorphic_visitable<V,T>
 *
 * @brief Base case for template expansion.
 */
template<typename V, typename T>
class polymorphic_visitable<V, T>: public polymorphic_visitable_helper<V, T> {
 public:
  using polymorphic_visitable_helper<V, T>::accept;
};

NS_END(rcppsw, patterns, visitor);

#endif /* INCLUDE_RCPPSW_PATTERNS_VISITOR_POLYMORPHIC_VISITABLE_HPP_ */
