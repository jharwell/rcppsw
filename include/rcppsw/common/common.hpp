/**
 * \file common.hpp
 * \ingroup common
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "rcsw/common/common.h"

#include "rcppsw/common/macros.hpp"
#include "rcppsw/mpl/mpl.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw);

/*******************************************************************************
 * String Conversion Templates
 ******************************************************************************/
NS_START(detail);

/**
 * \brief Predicate for detecting if a type \p T defines `to_str()`.
 *
 * \tparam T The type to check.
 */
template <class T>
using to_str_type = decltype(std::declval<T>().to_str());

NS_END(detail);

/**
 * @brief For \p T where std::to_string(\p T) works let the stdandard library to
 * the conversion.
 */
template <typename T,
          RCPPSW_SFINAE_DECLDEF(!mpl::is_detected<detail::to_str_type, T>::value)>
std::string to_string(const T& obj) {
  return std::to_string(obj);
}

/**
 * @brief For \p T where std::to_string(\p T) does not work, if \p T
 * defines a to_str() method, then it can still use rcppsw::to_string().
 */
template <class T,
          RCPPSW_SFINAE_DECLDEF(mpl::is_detected<detail::to_str_type, T>::value)>
std::string to_string(const T& obj) {
  return obj.to_str();
}

/*******************************************************************************
 * Misc. Templates
 ******************************************************************************/
/**
 * \brief Get the value of a strongly typed enum as its underlying type.
 */
template <typename TEnum>
constexpr typename std::underlying_type<TEnum>::type
as_underlying(const TEnum& e) noexcept {
  return static_cast<typename std::underlying_type<TEnum>::type>(e);
}

NS_END(rcppsw);

