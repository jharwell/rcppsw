/**
 * \file vector3.cpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/math/vector3.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Class Constants
 ******************************************************************************/
RCPPSW_WARNING_DISABLE_PUSH()
RCPPSW_WARNING_DISABLE_GLOBAL_CTOR()

template <>
const vector3d vector3d::X(1.0, 0.0, 0.0); // NOLINT
template <>
const vector3i vector3i::X(1, 0, 0); // NOLINT

template <>
const vector3d vector3d::Y(0.0, 1.0, 0.0); // NOLINT
template <>
const vector3i vector3i::Y(0, 1, 0); // NOLINT

template <>
const vector3d vector3d::Z(0.0, 0.0, 1.0); // NOLINT
template <>
const vector3i vector3i::Z(0, 0, 1); // NOLINT

RCPPSW_WARNING_DISABLE_POP()

NS_END(math, rcppsw);