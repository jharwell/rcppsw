/**
 * \file euclidean_dist.cpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/spatial/euclidean_dist.hpp"

#include <cmath>

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::spatial {

/*******************************************************************************
 * Operators
 ******************************************************************************/
euclidean_dist operator*(double lhs, const euclidean_dist& rhs) {
  return euclidean_dist(lhs * rhs.v());
}
euclidean_dist operator/(double lhs, const euclidean_dist& rhs) {
  return euclidean_dist(lhs / rhs.v());
}
euclidean_dist operator-(double lhs, const euclidean_dist& rhs) {
  return euclidean_dist(lhs - rhs.v());
}
euclidean_dist operator+(double lhs, const euclidean_dist& rhs) {
  return euclidean_dist(lhs + rhs.v());
}
bool operator<=(double lhs, const euclidean_dist& rhs) { return lhs <= rhs.v(); }
bool operator<(double lhs, const euclidean_dist& rhs) { return lhs < rhs.v(); }

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
euclidean_dist euclidean_dist::make(const double& value) {
  return euclidean_dist(std::fabs(value));
} /* make() */

} /* namespace rcppsw::spatial */
