/**
 * \file vector2.cpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/math/vector2.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Template Instantiations
 ******************************************************************************/
template <>
const vector2i vector2i::X(1, 0); // NOLINT
template <>
const vector2z vector2z::X(1, 0); // NOLINT
template <>
const vector2d vector2d::X(1.0, 0.0); // NOLINT

template <>
const vector2i vector2i::Y(0, 1); // NOLINT
template <>
const vector2z vector2z::Y(0, 1); // NOLINT
template <>
const vector2d vector2d::Y(0.0, 1.0); // NOLINT

NS_END(math, rcppsw);
