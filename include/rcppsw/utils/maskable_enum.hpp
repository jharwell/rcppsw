/**
 * \file maskable_enum.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/

/*******************************************************************************
 * Templates
 ******************************************************************************/
template <typename TEnum, RCPPSW_SFINAE_DECLDEF(std::is_enum<TEnum>::value)>
RCPPSW_PURE TEnum operator|(const TEnum& lhs, const TEnum& rhs) {
  using T = std::underlying_type_t<TEnum>;
  return static_cast<TEnum>(static_cast<T>(lhs) | static_cast<T>(rhs));
}

template <typename TEnum, RCPPSW_SFINAE_DECLDEF(std::is_enum<TEnum>::value)>
RCPPSW_PURE bool operator&(const TEnum& lhs, const TEnum& rhs) {
  using T = std::underlying_type_t<TEnum>;
  return static_cast<T>(lhs) & static_cast<T>(rhs);
}

template <typename TEnum, RCPPSW_SFINAE_DECLDEF(std::is_enum<TEnum>::value)>
TEnum operator|=(TEnum& lhs, const TEnum& rhs) {
  return lhs = lhs | rhs;
}
