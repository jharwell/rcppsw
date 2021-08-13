/**
 * \file normalize.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_MATH_NORMALIZE_HPP_
#define INCLUDE_RCPPSW_MATH_NORMALIZE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"
#include "rcppsw/math/math.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Free Functions
 ******************************************************************************/
/*
 * \brief Normalize a value in the range [min, max] to [0, 1].
 *
 * If the max and min measurements are the same, then the normalized value is
 * 0.5.o
 */
static inline double normalize(double min, double max, double val) {
  if (max - min <= rmath::kDOUBLE_EPSILON) {
    return 0.5;
  } else {
    return (val - min) / (max - min);
  }
} /* normalize() */

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_NORMALIZE_HPP_ */
