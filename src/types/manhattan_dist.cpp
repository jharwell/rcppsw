/**
 * \file manhattan_dist.cpp
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
#include "rcppsw/types/manhattan_dist.hpp"

#include <cmath>

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, types);

/*******************************************************************************
 * Operators
 ******************************************************************************/
manhattan_dist operator-(int lhs, const manhattan_dist& rhs) {
  return manhattan_dist(lhs - rhs.v());
}
manhattan_dist operator+(int lhs, const manhattan_dist& rhs) {
  return manhattan_dist(lhs + rhs.v());
}
bool operator<=(int lhs, const manhattan_dist& rhs) { return lhs <= rhs.v(); }

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
manhattan_dist manhattan_dist::make(const int& value) {
  return manhattan_dist(std::abs(static_cast<int>(value)));
} /* make() */

NS_END(types, rcppsw);
