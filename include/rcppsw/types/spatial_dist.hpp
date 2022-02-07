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
#include "rcppsw/types/distance_measure.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, types);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class spatial_dist
 * \ingroup types
 *
 * \brief Specifies a distance in "real" spatial space, and as such is always
 * positive.
 */
class spatial_dist final : public distance_measure<double, struct spatial_dist_tag> {
 public:
  /**
   * Create a \ref spatial_dist from a numeric value, making it positive if
   * necessary. This incurs a higher runtime cost, and so is a separate function
   * from the constructor, which \a assumes the \p value to be positive
   * semi-definite.
   */
  static spatial_dist make(const double& value);

  explicit spatial_dist(const double& v) : distance_measure(v) {}
  ~spatial_dist(void) override = default;
  spatial_dist(const spatial_dist&) = default;

  spatial_dist operator*(double rhs) const {
    return spatial_dist(v() * rhs);
  }
  spatial_dist operator/(double rhs) const {
    return spatial_dist(v() / rhs);
  }
  spatial_dist operator-(double rhs) const {
    return spatial_dist(v() - rhs);
  }
  spatial_dist operator+(double rhs) const {
    return spatial_dist(v() + rhs);
  }


  spatial_dist operator*(const spatial_dist& rhs) const {
    return spatial_dist(v() * rhs.v());
  }
  spatial_dist operator/(const spatial_dist& rhs) const {
    return spatial_dist(v() / rhs.v());
  }
  spatial_dist operator-(const spatial_dist& rhs) const {
    return spatial_dist(v() - rhs.v());
  }
  spatial_dist operator+(const spatial_dist& rhs) const {
    return spatial_dist(v() + rhs.v());
  }

  spatial_dist& operator-=(double rhs) {
    set(v() - rhs);
    return *this;
  }
  spatial_dist& operator=(const spatial_dist& rhs) {
    set(rhs.v());
    return *this;
  }
  spatial_dist& operator+=(const spatial_dist& rhs) {
    set(v() + rhs.v());
    return *this;
  }
};

/*******************************************************************************
 * Operators
 ******************************************************************************/
spatial_dist operator*(double lhs, const spatial_dist& rhs);
spatial_dist operator/(double lhs, const spatial_dist& rhs);
spatial_dist operator-(double lhs, const spatial_dist& rhs);
spatial_dist operator+(double lhs, const spatial_dist& rhs);
bool operator<=(double lhs, const spatial_dist& rhs) RCPPSW_PURE;

NS_END(types, rcppsw);

#endif /* INCLUDE_RCPPSW_TYPES_SPATIAL_DIST_HPP_ */
