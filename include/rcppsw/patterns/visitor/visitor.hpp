/**
 * @file visitor.hpp
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

#ifndef INCLUDE_RCPPSW_PATTERNS_VISITOR_VISITOR_HPP_
#define INCLUDE_RCPPSW_PATTERNS_VISITOR_VISITOR_HPP_

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
 * @class visitor
 *
 * @brief The base visitor class from which all other classes wishing to employ
 * the visit()/accept() paradigm inherit.
 */
class visitor {
 public:
  virtual ~visitor(void) {}
};

/**
 * @class can_visit
 *
 * @brief Visitor classes should also derive from can_visit<T> for each derived
 * visitable type they want to visit.
 */
template<class T, typename R = void>
class can_visit {
 public:
  virtual R visit(T& visitee) = 0;
  virtual ~can_visit(void) {}
};

/**
 * @class visitor_set_helper
 *
 * @brief Helper class to provide actual implementation.
 */
template <typename T>
class visit_set_helper {
 public:
  virtual void visit(T& visitee) = 0;
  virtual ~visit_set_helper(void) {}
};

/**
 * @class visit_set
 *
 * @brief General case for template expansion.
 */
template <typename... Ts>
class visit_set {};

/**
 * @class visit_set<T,R,..>
 *
 * @brief Middle recursive case for expansion.
 */
template<typename T, typename... Ts>
class visit_set<T, Ts...>: public visit_set_helper<T>,
                             public visit_set<Ts...> {
 public:
  using visit_set_helper<T>::visit;
  using visit_set<Ts...>::visit;
};

/**
 * @class visit_set<T>
 *
 * @brief Base case for expansion. Provides classes the ability to explicitly
 * control what types of classes they can visit.
 */
template<typename T>
class visit_set<T>: public visit_set_helper<T> {
 public:
  using visit_set_helper<T>::visit;
};

NS_END(rcppsw, patterns, visitor);

#endif /* INCLUDE_RCPPSW_PATTERNS_VISITOR_VISITOR_HPP_ */
