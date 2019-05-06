/**
 * @file typelist.hpp
 *
 * @copyright 2019 John Harwell, All rights reserved.
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
#include "rcppsw/common/common.hpp"
#include <boost/mpl/vector.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/joint_view.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/mpl/transform.hpp>

/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * @def RCPPSW_SFINAE_TYPELIST_REQUIRE() Enable the function that this macro is
 * attached to if the specified type is found in the typelist, which must be a
 * \ref typelist compile-time object.
 */
#define RCPPSW_SFINAE_TYPELIST_REQUIRE(Typelist, T)                     \
  typename boost::enable_if<typename boost::mpl::contains<Typelist,     \
                                                          T>::type>::type * = nullptr

/**
 * @def RCPPSW_SFINAE_TYPELIST_REJECT() Disable the function that this macro is
 * attached to if the specified type is found in the Typelist, which must be a
 * \ref typelist compile-time object.
 */
#define RCPPSW_SFINAE_TYPELIST_REJECT(Typelist, T)                     \
  typename boost::disable_if<typename boost::mpl::contains<Typelist,     \
                                                           T>::type>::type * = nullptr

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, mpl);

/**
 * @brief A list of types using boost::mpl::vectors, which enables all sorts of
 * nice operations from the boost MPL library.
 */
template<typename ...Ts>
using typelist = boost::mpl::vector<Ts...>;

/**
 * @brief Wrap a \ref typelist into a container/template class.
 */
template<template<class> class WrapperType>
struct typelist_wrap_into {
  template<class T>
  struct apply {
    using type = WrapperType<T>;
  };
};

/**
 * @brief Apply a functor to each type in the \ref typelist.
 */
template<typename Typelist, template<class> class WrapperType>
using typelist_wrap_apply = typename boost::mpl::transform<Typelist,
                                                           typelist_wrap_into<WrapperType>
                                                           >;
NS_END(mpl, rcppsw);

#endif /* INCLUDE_RCPPSW_INCLUDE_MPL_TYPELIST_HPP_ */
