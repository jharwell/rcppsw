/**
 * \file vector3.cpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/math/vector3.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Template Instantiations
 ******************************************************************************/

template <>
const vector3i vector3i::X(1, 0, 0); // NOLINT
template <>
const vector3z vector3z::X(1, 0, 0); // NOLINT
template <>
const vector3d vector3d::X(1.0, 0.0, 0.0); // NOLINT

template <>
const vector3i vector3i::Y(0, 1, 0); // NOLINT
template <>
const vector3z vector3z::Y(0, 1, 0); // NOLINT
template <>
const vector3d vector3d::Y(0.0, 1.0, 0.0); // NOLINT

template <>
const vector3i vector3i::Z(0, 0, 1); // NOLINT
template <>
const vector3z vector3z::Z(0, 0, 1); // NOLINT
template <>
const vector3d vector3d::Z(0.0, 0.0, 1.0); // NOLINT

NS_END(math, rcppsw);
