/**
 * \file euclidean_dist.hpp
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
 * \class euclidean_dist
 * \ingroup spatial
 *
 * \brief Specifies a distance in "real" spatial space, and as such is always
 * positive.
 */
class euclidean_dist final : public measurement<double, struct euclidean_dist_tag> {
 public:
  /**
   * Create a \ref euclidean_dist from a numeric value, making it positive if
   * necessary. This incurs a higher runtime cost, and so is a separate function
   * from the constructor, which \a assumes the \p value to be positive
   * semi-definite.
   */
  static euclidean_dist make(const double& value);

  explicit euclidean_dist(const double& v) : measurement(v) {}
  ~euclidean_dist(void) override = default;
  euclidean_dist(const euclidean_dist&) = default;

  euclidean_dist operator*(double rhs) const {
    return euclidean_dist(v() * rhs);
  }
  euclidean_dist operator/(double rhs) const {
    return euclidean_dist(v() / rhs);
  }
  euclidean_dist operator-(double rhs) const {
    return euclidean_dist(v() - rhs);
  }
  euclidean_dist operator+(double rhs) const {
    return euclidean_dist(v() + rhs);
  }


  euclidean_dist operator*(const euclidean_dist& rhs) const {
    return euclidean_dist(v() * rhs.v());
  }
  euclidean_dist operator/(const euclidean_dist& rhs) const {
    return euclidean_dist(v() / rhs.v());
  }
  euclidean_dist operator-(const euclidean_dist& rhs) const {
    return euclidean_dist(v() - rhs.v());
  }
  euclidean_dist operator+(const euclidean_dist& rhs) const {
    return euclidean_dist(v() + rhs.v());
  }

  euclidean_dist& operator-=(double rhs) {
    set(v() - rhs);
    return *this;
  }
  euclidean_dist& operator+=(double rhs) {
    set(v() + rhs);
    return *this;
  }
  euclidean_dist& operator=(const euclidean_dist& rhs) {
    set(rhs.v());
    return *this;
  }
  euclidean_dist& operator+=(const euclidean_dist& rhs) {
    set(v() + rhs.v());
    return *this;
  }
};

/*******************************************************************************
 * Operators
 ******************************************************************************/
euclidean_dist operator*(double lhs, const euclidean_dist& rhs);
euclidean_dist operator/(double lhs, const euclidean_dist& rhs);
euclidean_dist operator-(double lhs, const euclidean_dist& rhs);
euclidean_dist operator+(double lhs, const euclidean_dist& rhs);
bool operator<=(double lhs, const euclidean_dist& rhs) RCPPSW_PURE;

} /* namespace rcppsw::spatial */
