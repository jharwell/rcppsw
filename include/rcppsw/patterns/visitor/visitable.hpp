/**
 * @file visitable.hpp
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
#include <boost/variant/static_visitor.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/utility/enable_if.hpp>
#include "rcppsw/common/common.hpp"


/*******************************************************************************
 * Macros
 ******************************************************************************/
#define RCPPSW_SFINAE_TYPELIST_REQUIRE(Typelist, T)                     \
  typename boost::enable_if<typename boost::mpl::contains<TypeList,     \
                                                          T>::type>::type * = nullptr
#define RCPPSW_SFINAE_TYPELIST_REJECT(Typelist, T)                      \
  typename boost::disable_if<typename boost::mpl::contains<TypeList,    \
                                                           T>::type>::type * = nullptr

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, patterns, visitor);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class visitable_any
 * @ingroup patterns visitor
 *
 * @brief A class that will accept any kind of visitor.
 *
 * This is suitable for general application of the visitor pattern that does not
 * require polymorphism. The visitor must be derived from \ref visitor()/
 * \ref visit_set() otherwise the static_cast will fail.
 */
template<class V>
class visitable_any {
 public:
  visitable_any(void) = default;
  virtual ~visitable_any(void) = default;
  visitable_any(const visitable_any&) = default;
  visitable_any& operator=(const visitable_any&) = default;

  template <typename T>
  void accept(T &visitor) { visitor.visit(static_cast<V&>(*this)); }
};

/**
 * @class accept_set_helper
 *
 * @brief Helper class to provide actual implementation.
 *
 */
template <typename V, typename T>
class accept_set_helper {
 public:
  virtual ~accept_set_helper(void) = default;

  /**
   * @brief Accept a visitor of the specified type.
   *
   * @tparam U Forwarded template type parameter that is 100% necessary to get
   * this design pattern to work.
   */
  template<typename U = T>
  void accept(std::enable_if_t<std::is_same<U, T>::value, T>& visitor) {
    visitor.visit(static_cast<V&>(*this)); }
};

/**
 * @class accept_set
 * @ingroup patterns visitor
 *
 * @brief General case for template expansion. Provides classes the ability to
 * explicitly control what types of visitors they will accept.
 */
template <typename... Ts>
class accept_set {};

/**
 * @class accept_set<V,T,..>
 *
 * @brief Middle recursive case for expansion.
 */
template<typename V, typename T, typename... Ts>
class accept_set<V, T, Ts...>: public accept_set_helper<V, T>,
                               public accept_set<V, Ts...> {
 public:
  using accept_set_helper<V, T>::accept;
  using accept_set<V, Ts...>::accept;
};

/**
 * @class accept_set<V,T>
 *
 * @brief Base case for expansion
 */
template<typename V, typename T>
class accept_set<V, T>: public accept_set_helper<V, T> {
 public:
  using accept_set_helper<V, T>::accept;
};

template<typename V, typename T>
using will_accept = accept_set_helper<V, T>;

/**
 * @class variant_accept_set
 * @ingroup patterns visitor
 *
 * @brief General case for template expansion. Provides classes the ability to
 * explicitly control what types of visitors they will accept. A
 */
template <typename VisitorBase, typename TypeList>
class variant_accept_set : public boost::static_visitor<void>,
                   public VisitorBase {
  using VisitorBase::VisitorBase;

  template<typename T,
           RCPPSW_SFINAE_TYPELIST_REQUIRE(Typelist, T)>
  void operator()(T& visitor) {
    VisitorBase::operator()(visitor);
  }

  template<typename T,
           RCPPSW_SFINAE_TYPELIST_REJECT(Typelist, T)>
  void operator()(T&) {}
};


NS_END(rcppsw, patterns, visitor);

#endif /* INCLUDE_RCPPSW_PATTERNS_VISITOR_VISITABLE_HPP_ */
