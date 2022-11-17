/**
 * \file manhattan_dist.cpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/spatial/manhattan_dist.hpp"

#include <cmath>

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::spatial {

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

} /* namespace rcppsw::spatial */
