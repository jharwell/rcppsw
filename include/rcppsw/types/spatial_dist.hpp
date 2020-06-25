/**
 * \file spatial_dist.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_TYPES_SPATIAL_DIST_HPP_
#define INCLUDE_RCPPSW_TYPES_SPATIAL_DIST_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/types/named_type.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, types);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \brief Specifies a distance in "real" spatial space, and as such is always
 * positive.
 */
class spatial_dist : public named_type<double, struct spatial_dist_tag> {
 public:
  explicit spatial_dist(const double& value);
  spatial_dist(const spatial_dist&) = default;

  spatial_dist& operator=(const spatial_dist& other) {
    set(other.v());
    return *this;
  }
  spatial_dist& operator+=(const spatial_dist& other) {
    set(v() + other.v());
    return *this;
  }
  bool operator<(const spatial_dist& other) const { return v() < other.v(); }
  bool operator>(const spatial_dist& other) const { return v() > other.v(); }
  bool operator>=(const spatial_dist& other) const { return v() >= other.v(); }
  bool operator>=(double other) const { return v() >= other; }
  bool operator<=(const spatial_dist& other) const { return v() <= other.v(); }
  bool operator<=(double other) const { return v() <= other; }
  bool operator>(double other) const { return v() > other; }
  spatial_dist operator*(double other) const {
    spatial_dist res(v());
    res.set(res.v() * other);
    return res;
  }

  spatial_dist& operator-=(double other) {
    set(v() - other);
    return *this;
  }

  spatial_dist operator-(double other) const {
    spatial_dist res(v());
    res.set(res.v() - other);
    return res;
  }
  spatial_dist operator-(const spatial_dist& rhs) const {
    return spatial_dist(v() - rhs.v());
  }
  spatial_dist operator+(const spatial_dist& rhs) const {
    return spatial_dist(v() + rhs.v());
  }
};

/*******************************************************************************
 * Operators
 ******************************************************************************/
spatial_dist operator*(double lhs, const spatial_dist& rhs);
spatial_dist operator-(double lhs, const spatial_dist& rhs);
spatial_dist operator+(double lhs, const spatial_dist& rhs);

NS_END(types, rcppsw);

#endif /* INCLUDE_RCPPSW_TYPES_SPATIAL_DIST_HPP_ */
