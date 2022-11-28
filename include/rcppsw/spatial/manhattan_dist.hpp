/**
 * \file manhattan_dist.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/spatial/measurement.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::spatial {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class manhattan_dist
 * \ingroup spatial
 *
 * \brief Specifies a distance between two points in manhattan distance, and as
 * such is always positive.
 */
class manhattan_dist final : public measurement<int,
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
      : measurement(v, check_psd) {}

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

} /* namespace rcppsw::spatial */
