/**
 * \file spatial_dist.cpp
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
#include "rcppsw/types/spatial_dist.hpp"

#include <cmath>

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, types);

/*******************************************************************************
 * Operators
 ******************************************************************************/
spatial_dist operator*(double lhs, const spatial_dist& rhs) {
  return spatial_dist(lhs * rhs.v());
}
spatial_dist operator/(double lhs, const spatial_dist& rhs) {
  return spatial_dist(lhs / rhs.v());
}
spatial_dist operator-(double lhs, const spatial_dist& rhs) {
  return spatial_dist(lhs - rhs.v());
}
spatial_dist operator+(double lhs, const spatial_dist& rhs) {
  return spatial_dist(lhs + rhs.v());
}
bool operator<=(double lhs, const spatial_dist& rhs) { return lhs <= rhs.v(); }

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
spatial_dist spatial_dist::make(const double& value) {
  return spatial_dist(std::fabs(value));
} /* make() */

NS_END(types, rcppsw);
