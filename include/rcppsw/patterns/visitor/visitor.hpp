/**
 * @file visitor.hpp
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
#include "rcppsw/mpl/typelist.hpp"
#include <boost/variant/static_visitor.hpp>
#include <boost/mpl/back_inserter.hpp>
#include <boost/mpl/copy.hpp>
#include <boost/mpl/joint_view.hpp>

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, visitor);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class visit_set_helper
 *
 * @brief Helper class to provide actual implementation.
 */
template <typename T>
class visit_set_helper {
 public:
  virtual void visit(T& visitee) = 0;
  virtual ~visit_set_helper(void) = default;
};

/**
 * @class visit_set
 * @ingroup patterns visitor
 *
 * @brief General case for template expansion. Provides classes the ability to
 * explicitly control what types of classes they can visit (limited to the
 * specified types AND their parent classes).
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
 * @brief Base case for expansion.
 */
template<typename T>
class visit_set<T>: public visit_set_helper<T> {
 public:
  using visit_set_helper<T>::visit;
};

/**
 * @brief List of types specifying the set of visitors that a @ref
 * precise_visitor will be able to visit.
 */
template<typename ...Args>
using precise_visit_set = mpl::typelist<Args...>;

/**
 * @brief Visitor that will only visit precisely with types that exactly match
 * one of the types in its type list (i.e. no implicit upcasting is
 * allowed). SFINAE FTW!
 *
 * @tparam VisitorImpl The name of the class containing the actual
 *                     implementation of the visit functions.
 * @tparam TypeList List of types that the class will be able to visit. Must be
 * a @ref precise_visit_set.
 *
 * For each visitee type you want to be able to visit, you must (1) include it
 * in the type list for the list, (2) define a function with the following exact
 * signature:
 *
 * void visit(<vistee_type>&)
 *
 * If these conditions are not meant, then trying to call visit() will result in
 * a compiler error.
 */
template <typename VisitorImpl, typename TypeList>
struct precise_visitor : public VisitorImpl,
                         public boost::static_visitor<void> {
  using VisitorImpl::VisitorImpl;
  template <typename... Args>
  explicit precise_visitor(Args&&... args)
      : VisitorImpl(std::forward<Args>(args)...) {}

  template <typename T, RCPPSW_SFINAE_TYPELIST_REQUIRE(TypeList, T)>
  void visit(T& visitee) {
    VisitorImpl::visit(visitee);
  }
};

NS_END(rcppsw, patterns, visitor);

#endif /* INCLUDE_RCPPSW_PATTERNS_VISITOR_VISITOR_HPP_ */
