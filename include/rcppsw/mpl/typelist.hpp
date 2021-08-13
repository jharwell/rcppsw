/**
 * \file typelist.hpp
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

#ifndef INCLUDE_RCPPSW_MPL_TYPELIST_HPP_
#define INCLUDE_RCPPSW_MPL_TYPELIST_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/mpl/contains.hpp>
#include <boost/mpl/joint_view.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/set.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/mpl/empty.hpp>

#include <boost/tuple/tuple.hpp>

#include "rcppsw/common/common.hpp"
#include "rcppsw/mpl/mpl.hpp"
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * \def RCPPSW_SFINAE_TYPELIST_REQUIRE() Enable the function that this macro is
 * attached to if the specified type is found in the typelist, which must be a
 * \ref typelist compile-time object.
 */
#define RCPPSW_SFINAE_TYPELIST_REQUIRE(Typelist, T) \
  typename boost::enable_if<                        \
      typename boost::mpl::contains<Typelist, T>::type>::type* = nullptr

/**
 * \def RCPPSW_SFINAE_TYPELIST_REJECT() Disable the function that this macro is
 * attached to if the specified type is found in the typelist, which must be a
 * \ref typelist compile-time object.
 */
#define RCPPSW_SFINAE_TYPELIST_REJECT(Typelist, T) \
  typename boost::disable_if<                      \
      typename boost::mpl::contains<Typelist, T>::type>::type* = nullptr

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, mpl);

/*******************************************************************************
 * Trait Detection Templates
 ******************************************************************************/
/**
 * \typedef typelist
 * \ingroup mpl
 *
 * \brief A list of types using boost::mpl::vectors, which enables all sorts of
 * nice operations from the boost MPL library.
 */
template <typename... Ts>
using typelist = boost::mpl::vector<Ts...>;


/**
 * \typedef empty
 * \ingroup mpl
 *
 * \brief Is the \ref typelist empty ?
 */
template <typename... Ts>
using empty = boost::mpl::empty<Ts...>;

NS_START(detail);

template<class A, template<class...> class B> struct rename_impl;

template<template<class...> class A, class... T, template<class...> class B>
struct rename_impl<A<T...>, B> {
  using type = B<T...>;
};

template <typename TList, typename T> struct ExtendTList;

template<typename T>
struct ExtendTList<std::tuple<void>, T>{
  using type = std::tuple<T>;
};

template<typename T, typename... Ts>
struct ExtendTList<std::tuple<Ts...>, T>{
  using type = std::tuple<Ts..., T>;
};

NS_END(detail);

/**
 * \typedef rename
 * \ingroup mpl
 *
 * \brief Rename a variadic type to another variadic type. E.g., std::tuple<int,
 * float, char> -> typelist<int, float, char>.
 */

template<class A, template<class...> class B>
using rename = typename detail::rename_impl<A, B>;

/**
 * \struct typelist_wrap_into
 * \ingroup mpl
 *
 * \brief Wrap a \ref typelist into a container/template class.
 *
 * \tparam WrapperType The container class each of the types in the \ref
 *                     typelist will be wrapped into. It takes the wrapped type,
 *                     as well as additional template arguments for the wrapped
 *                     type, as arguments.
 *
 * \tparam WrapperTypeArgs Additional template paramaters for the WrapperType.
 */
template <template <class WrappedType, class...> class WrapperType,
          class... WrapperTypeArgs>
struct typelist_wrap_into {
  /**
   * \brief Perform the wrap.
   *
   * \tparam ApplyArgs The *single* wrapped type from above. Must be a parameter
   * pack, so that it can be concatenated with the WrapperType parameter
   * pack (which may be empty); making it a normal template argument throws
   * errors on WrapperTypes that only take a single argument.
   */
  template <class... ApplyArgs>
  struct apply {
    using type = WrapperType<ApplyArgs..., WrapperTypeArgs...>;
  };
};


/**
 * \typedef typelist_wrap_apply
 * \ingroup mpl
 *
 * \brief Apply a functor to each type in the \ref typelist. The functor can
 * itself take as many template parameters as needed.
 */
template <typename Typelist,
          template <class WrappedType, class...> class WrapperType,
          class... Args>
using typelist_wrap_apply =
    typename boost::mpl::transform<Typelist,
                                   typelist_wrap_into<WrapperType, Args...> >;

template<class Seq>
using make_tuple_type = typename boost::mpl::fold<
  typename boost::mpl::fold<
  Seq,
    boost::mpl::set<>,
    boost::mpl::insert<boost::mpl::_1, boost::mpl::_2>
    >::type,
  boost::tuple<void>,
  detail::ExtendTList<boost::mpl::_1, boost::mpl::_2>
  >;

NS_END(mpl, rcppsw);

#endif /* INCLUDE_RCPPSW_INCLUDE_MPL_TYPELIST_HPP_ */
