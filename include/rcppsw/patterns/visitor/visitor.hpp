/**
 * \file visitor.hpp
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
#include <utility>

#include <boost/variant/static_visitor.hpp>

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/mpl/typelist.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, patterns, visitor, detail);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * \class visit_set_helper
 * \ingroup patterns visitor
 *
 * \brief Helper class to provide actual implementation.
 *
 * \tparam T A type to visit.
 */
template <typename T>
class visit_set_helper {
 public:
  virtual void visit(T& visitee) = 0;
  virtual ~visit_set_helper(void) = default;
};

NS_END(detail);

/**
 * \ingroup patterns visitor
 *
 * \brief General case for template expansion. Provides classes the ability to
 * explicitly control what types of classes they can visit (limited to the
 * specified types AND their parent classes).
 */
template <typename... Ts>
class visit_set {};

/**
 * \ingroup patterns visitor
 *
 * \brief Middle recursive case for expansion.
 *
 * \tparam T A type to visit.
 * \tparam Ts The rest of the to-be-processed types to visit.
 */
template<typename T, typename... Ts>
class visit_set<T, Ts...>: public detail::visit_set_helper<T>,
                           public visit_set<Ts...> {
 public:
  using detail::visit_set_helper<T>::visit;
  using visit_set<Ts...>::visit;
};

/**
 * \ingroup patterns visitor
 *
 * \brief Base case for expansion.
 *
 */
template<typename T>
class visit_set<T>: public detail::visit_set_helper<T> {
 public:
  using detail::visit_set_helper<T>::visit;
};

/**
 * \ingroup patterns visitor
 *
 * \brief List of types specifying the set of visitors that a \ref
 * precise_visitor will be able to visit.
 */
template<typename ...Args>
using precise_visit_set = mpl::typelist<Args...>;

/**
 * \class precise_visitor
 * \ingroup patterns visitor
 *
 * \brief Visitor that will only visit precisely with types that exactly match
 * one of the types in its type list (i.e. no implicit upcasting is
 * allowed). SFINAE FTW!
 *
 * \tparam VisitorImpl The name of the class containing the actual
 *                     implementation of the visit functions.
 * \tparam TypeList List of types that the class will be able to visit. Must be
 * a \ref rmpl::typelist.
 *
 * For each visitee type you want to be able to visit, you must (1) include it
 * in the type list for the list, (2) define a function with the following exact
 * signature:
 *
 * void visit(<vistee_type>&)
 *
 * If these conditions are not meant, then trying to call visit() will result in
 * a compiler error.
 *
 * \note Non-static methods from \p VisitorImpl will be available in the
 * derived class (in contrast to \ref precise_visitor).
 */
template <typename VisitorImpl, typename TypeList>
class precise_visitor : public VisitorImpl,
                        protected boost::static_visitor<void> {
 public:
  using VisitorImpl::VisitorImpl;
  template <typename... Args>
  explicit precise_visitor(Args&&... args)
      : VisitorImpl(std::forward<Args>(args)...) {}

  template <typename T,
            RCPPSW_SFINAE_TYPELIST_REQUIRE(TypeList, T),
            typename ...Args>
  /**
   * The visit template, which can take additional arguments besides the
   * visitee.
   */
  void visit(T& visitee, Args&&... args) {
    VisitorImpl::visit(visitee, std::forward<Args>(args)...);
  }
};

/**
 * \class filtered_visitor
 * \ingroup patterns visitor
 *
 * \brief Convenience wrapper allowing generic visits to ANY type, but filtering
 * them on the \ref rmpl::typelist passed to the \ref
 * rpvisitor::precise_visitor.
 *
 * \tparam TVisitor The name of the visitor class, which must be capable of
 *                  being used with \ref precise_visitor, and define \p
 *                  visit_typelist.
 *
 * \note This class is appropriate if no non-static methods from \p TVisitor are
 * needed (they will not be accessible, because inheritance is not used).
 *
 */
template<typename TVisitor>
class filtered_visitor {
 public:
  using visitor_type = TVisitor;
  template<typename...Args>
  explicit filtered_visitor(Args&& ...args)
      : m_impl(std::forward<Args>(args)...) {}

  template<typename TAny, typename ...Args>
  void visit(TAny& obj, Args&&... args) {
    m_impl.visit(obj, std::forward<Args>(args)...);
  }

 private:
  /**
   * \brief We use the precise visitor in order to force compile errors if a
   * call to a visitor is made that involves a visitee that is not in our visit
   * set (i.e. remove the possibility of implicit upcasting performed by the
   * compiler).
   */
  precise_visitor<TVisitor, typename TVisitor::visit_typelist> m_impl;
};

NS_END(rcppsw, patterns, visitor);

