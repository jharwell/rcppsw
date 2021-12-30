/**
 * \file radians.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_MATH_RADIANS_HPP_
#define INCLUDE_RCPPSW_MATH_RADIANS_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include <limits>
#include <string>

#include "rcppsw/math/range.hpp"
#include "rcppsw/rcppsw.hpp"
#include "rcppsw/math/math.hpp"
#include "rcppsw/er/stringizable.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

class degrees;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class radians
 * \ingroup math
 *
 * \brief Used to store an angle value in radians (duh).
 *
 * When comparing instances for approxmate equality, they are compared to 6
 * decimal places, by default; this can be overriden on a per-comparison basis
 * if desired, or set class-wide via \ref kAPPROX_EQUALITY_TOL.
 */
class radians final : public er::stringizable {
 public:
  /*
   * These are MATHEMATICAL constants, so they get UPPER_CASE naming convention
   * to emphasize that fact.
   */
  static const radians kPI; // NOLINT
  static const radians kTWO_PI; // NOLINT
  static const radians kTHREE_PI_OVER_TWO; // NOLINT
  static const radians kPI_OVER_TWO; // NOLINT
  static const radians kPI_OVER_THREE; // NOLINT
  static const radians kPI_OVER_FOUR; // NOLINT
  static const radians kZERO; // NOLINT
  static const double kRADIANS_TO_DEGREES; // NOLINT

  radians(void) = default;
  explicit radians(double value) noexcept : m_value(value) {}
  explicit radians(const degrees& d);

  /**
   * \brief Sets the value in radians.
   */
  void set(double value) { m_value = value; }

  /**
   * \brief Get the raw value in radians.
   */
  double v(void) const { return m_value; }

  /**
   * \brief Normalizes the value in the range [-pi, pi].
   */
  radians& signed_normalize(void) {
    static range<radians> signed_range(-kPI, kPI);
    return *this = signed_range.wrap_value(*this);
  }

  /**
   * \brief Normalizes the value in the range [0, 2pi].
   */
  radians& unsigned_normalize(void) {
    static range<radians> unsigned_range(kZERO, kTWO_PI);
    return *this = unsigned_range.wrap_value(*this);
  }

  /**
   * \brief Return a string representation of the radians object of the form
   * 'rad(XX) -> deg(YY)'.
   */
  std::string to_str(void) const override;

  friend std::istream& operator>>(std::istream& is, radians& r) {
    is >> r.m_value;
    return is;
  }

  radians& operator+(void) { return *this; }

  radians operator-(void) const { return radians(-m_value); }

  radians& operator+=(const radians& other) {
    m_value += other.m_value;
    return *this;
  }

  radians& operator-=(const radians& other) {
    m_value -= other.m_value;
    return *this;
  }

  radians& operator*=(double value) {
    m_value *= value;
    return *this;
  }

  radians& operator/=(double value) {
    m_value /= value;
    return *this;
  }

  radians operator+(const radians& other) const {
    radians res(*this);
    res += other;
    return res;
  }

  radians operator-(const radians& other) const {
    radians res(*this);
    res -= other;
    return res;
  }

  radians operator*(double value) const {
    radians res(*this);
    res *= value;
    return res;
  }

  double operator/(const radians& other) const { return m_value / other.m_value; }

  radians operator/(double value) const {
    radians res(*this);
    res /= value;
    return res;
  }

  bool operator<(const radians& other) const { return m_value < other.m_value; }

  bool operator<=(const radians& other) const { return m_value <= other.m_value; }

  bool operator>(const radians& other) const { return m_value > other.m_value; }

  bool operator>=(const radians& other) const { return m_value >= other.m_value; }

  /**
   * \brief Compare two radian values for equality, using the tolerance
   * specified during construction.
   */
  bool operator==(const radians& other) const {
    return std::fabs(m_value - other.m_value) < kDOUBLE_EPSILON;
  }

  bool operator!=(const radians& other) const { return !(*this == other); }

  /**
   * \brief Determine if two instances are equal within the specified
   * tolerance.
   *
   * This cannot be made part of \ref operator==(), because those functions
   * cannot have default arguments.
   */
  bool is_equal(const radians& other, double tol = kDOUBLE_EPSILON) const {
    return rmath::is_equal(m_value, other.m_value, tol);
  }

 private:
  /* clang-format off */
  double m_value{0.0};
  /* clang-format on */
};

/*******************************************************************************
 * Operators
 ******************************************************************************/
std::ostream& operator<<(std::ostream& stream, const radians& r);

rmath::radians operator*(double lhs, const rmath::radians& rhs);

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_RADIANS_HPP_ */
