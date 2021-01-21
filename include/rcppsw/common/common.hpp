/**
 * \file common.hpp
 * \ingroup common
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

#ifndef INCLUDE_RCPPSW_COMMON_COMMON_HPP_
#define INCLUDE_RCPPSW_COMMON_COMMON_HPP_

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
          RCPPSW_SFINAE_FUNC(!mpl::is_detected<detail::to_str_type, T>::value)>
std::string to_string(const T& obj) {
  return std::to_string(obj);
}

/**
 * @brief For \p T where std::to_string(\p T) does not work, if \p T
 * defines a to_str() method, then it can still use rcppsw::to_string().
 */
template <class T,
          RCPPSW_SFINAE_FUNC(mpl::is_detected<detail::to_str_type, T>::value)>
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

#endif /* INCLUDE_RCPPSW_COMMON_COMMON_HPP_ */
