/**
 * \file manhattan_dist.hpp
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

#ifndef INCLUDE_RCPPSW_TYPES_MANHATTAN_DIST_HPP_
#define INCLUDE_RCPPSW_TYPES_MANHATTAN_DIST_HPP_

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
 * \class manhattan_dist
 * \ingroup types
 *
 * \brief Specifies a distance between two points in manhattan distance, and as
 * such is always positive.
 */
class manhattan_dist final : public distance_measure<int,
                                                     struct manhattan_dist_tag> {
 public:
  /**
   * Create a \ref manhattan_dist from a numeric value, making it positive if
   * necessary. This incurs a higher runtime cost, and so is a separate function
   * from the constructor, which \a assumes the \p value to be positive
   * semi-definite.
   */
  static manhattan_dist make(const int& value);

  explicit manhattan_dist(const int& v, bool check_psd = true)
      : distance_measure(v, check_psd) {}

  ~manhattan_dist(void) override = default;
  manhattan_dist(const manhattan_dist&) = default;

  manhattan_dist operator*(int rhs) const {
    return manhattan_dist(v() * rhs);
  }
  manhattan_dist operator/(int rhs) const {
    return manhattan_dist(v() / rhs);
  }
  manhattan_dist operator-(int rhs) const {
    return manhattan_dist(v() - rhs);
  }
  manhattan_dist operator+(int rhs) const {
    return manhattan_dist(v() + rhs);
  }


  manhattan_dist operator*(const manhattan_dist& rhs) const {
    return manhattan_dist(v() * rhs.v());
  }
  manhattan_dist operator/(const manhattan_dist& rhs) const {
    return manhattan_dist(v() / rhs.v());
  }
  manhattan_dist operator-(const manhattan_dist& rhs) const {
    return manhattan_dist(v() - rhs.v());
  }
  manhattan_dist operator+(const manhattan_dist& rhs) const {
    return manhattan_dist(v() + rhs.v());
  }

  manhattan_dist& operator-=(int rhs) {
    set(v() - rhs);
    return *this;
  }
  manhattan_dist& operator=(const manhattan_dist& rhs) {
    set(rhs.v());
    return *this;
  }
  manhattan_dist& operator+=(const manhattan_dist& rhs) {
    set(v() + rhs.v());
    return *this;
  }
};

/*******************************************************************************
 * Operators
 ******************************************************************************/
manhattan_dist operator-(int lhs, const manhattan_dist& rhs);
manhattan_dist operator+(int lhs, const manhattan_dist& rhs);
bool operator<=(int lhs, const manhattan_dist& rhs) RCPPSW_PURE;

NS_END(types, rcppsw);

#endif /* INCLUDE_RCPPSW_TYPES_MANHATTAN_DIST_HPP_ */
