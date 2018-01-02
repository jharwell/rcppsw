/**
 * @file common.hpp
 * @ingroup common
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

#ifndef INCLUDE_RCPPSW_COMMON_COMMON_HPP_
#define INCLUDE_RCPPSW_COMMON_COMMON_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <memory>
#include "rcsw/common/common.h"

/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * @internal
 *
 * @def NS_START(ns)
 *
 * Callback macro for recursive macro expansion for nested namespace start
 * pasting. \c ns is the namespace to paste.
 */
#define NS_START_(ns) namespace ns {

/*
 * @def NS_START(ns)
 *
 * Callback macro for recursive macro expansion for nested namespace end
 * pasting. \c ns is the namespace to paste. Note that it is not strictly
 * necessary to pass the namespace name to this macro, as it only pastes a
 * single bracket; it is more self documenting to do so, however.
 *
 * @endinternal
 */
#define NS_END_(ns) }

/*
 * @def NS_START(...)
 *
 * Declare a nested namespace, with each successive token in the comma-separated
 * argument list being declared inside the namespace of the previous token.
 */
#define NS_START(...) XFOR_EACH1(NS_START_, __VA_ARGS__)

/*
 * @def NS_END(...)
 *
 * Close a previously declared nested namespace. Tokens should be passed to this
 * macro in the reverse order they were declared in (not actually necessary for
 * valid code, but it is more self documentating to do so).
 */
#define NS_END(...) XFOR_EACH1(NS_END_, __VA_ARGS__)

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw);

/*******************************************************************************
 * Templates
 ******************************************************************************/
#if __cplusplus == 201402L
typedef std::make_unique make_unique;

#elif __cplusplus == 201103L
/**
 * @brief Implementation of std::make_unique which exists in C++14, but not
 * C++11, so if compiling for that standard I have to roll my own.
 */
template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

#endif /* __cplusplus */

NS_END(rcppsw);

#endif /* INCLUDE_RCPPSW_COMMON_COMMON_HPP_ */
