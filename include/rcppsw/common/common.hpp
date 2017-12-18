/**
 * @file common.hpp
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
#define NS_START_(ns) namespace ns {
#define NS_END_(ns) }
#define NS_START(...) XFOR_EACH1(NS_START_, __VA_ARGS__)
#define NS_END(...) XFOR_EACH1(NS_END_, __VA_ARGS__)

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw);

/*******************************************************************************
 * Templates
 ******************************************************************************/
/* C++11 does not have std::make_unique, so I have to create my own...  */
template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

NS_END(rcppsw);

#endif /* INCLUDE_RCPPSW_COMMON_COMMON_HPP_ */
