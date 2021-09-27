/**
 * \file math.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_MATH_MATH_HPP_
#define INCLUDE_RCPPSW_MATH_MATH_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include <utility>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Constant Definitions
 ******************************************************************************/
/**
 * \brief For comparing floating point numbers within a given tolerance when
 * std::numeric_limits<double>::epsilon() won't work.
 */
static constexpr double kDOUBLE_EPSILON = RCSW_DOUBLE_EPSILON;

/*******************************************************************************
 * Free-Functions
 ******************************************************************************/
/**
 * \brief Determine if two floating point values are equal, using the specified
 * tolerance. You can't always use std::numeric_limits<double>::epsilon()
 * because of floating point representation errors.
 */

static inline bool is_equal(double lhs,
                            double rhs,
                            double tol = kDOUBLE_EPSILON) {
  return std::fabs(lhs - rhs) < tol;
}

/**
 * \brief Determine if \p x is a multiple \p y within \p tol tolerance.
 */
static inline bool is_multiple_of(double x,
                                  double y,
                                  double tol = kDOUBLE_EPSILON) {
  return std::fabs(std::remainder(x, y)) < tol;
}

NS_START(detail);

template <class T>
using length_func_decltype = decltype(std::declval<T>().length());

NS_END(detail);

/**
 * \brief Computes the euclidean distance between the passed vectors.
 */
template<typename T,
         RCPPSW_SFINAE_DECLDEF(rmpl::is_detected<detail::length_func_decltype, T>::value)>
static inline double l2norm(const T& lhs, const T& rhs) {
  return (lhs - rhs).length();
}

/**
 * \brief Computes the square of the euclidean distance between the passed
 * vectors.
 */
template<typename T,
         RCPPSW_SFINAE_DECLDEF(rmpl::is_detected<detail::length_func_decltype, T>::value)>

static inline double l2norm_squared(const T& lhs, const T& rhs) {
  return (lhs - rhs).squared_length();
}

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_MATH_HPP_ */
