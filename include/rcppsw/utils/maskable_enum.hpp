/**
 * @file maskable_enum.hpp
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

#ifndef INCLUDE_RCPPSW_UTILS_MASKABLE_ENUM_HPP_
#define INCLUDE_RCPPSW_UTILS_MASKABLE_ENUM_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <type_traits>

#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Templates
 ******************************************************************************/
template <typename TEnum, RCPPSW_SFINAE_FUNC(std::is_enum<TEnum>::value)>
RCSW_PURE TEnum operator|(const TEnum& lhs, const TEnum& rhs) {
  using T = std::underlying_type_t<TEnum>;
  return static_cast<TEnum>(static_cast<T>(lhs) | static_cast<T>(rhs));
}

template <typename TEnum, RCPPSW_SFINAE_FUNC(std::is_enum<TEnum>::value)>
RCSW_PURE bool operator&(const TEnum& lhs, const TEnum& rhs) {
  using T = std::underlying_type_t<TEnum>;
  return static_cast<T>(lhs) & static_cast<T>(rhs);
}

template <typename TEnum, RCPPSW_SFINAE_FUNC(std::is_enum<TEnum>::value)>
TEnum operator|=(TEnum& lhs, const TEnum& rhs) {
  return lhs = lhs | rhs;
}

#endif /* INCLUDE_RCPPSW_COMMON_MASKABLE_ENUM_HPP_ */
