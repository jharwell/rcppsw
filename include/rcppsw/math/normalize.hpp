/**
 * \file normalize.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

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

