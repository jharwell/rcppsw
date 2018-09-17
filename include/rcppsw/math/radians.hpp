/**
 * @file radians.hpp
 *
 * @copyright 2018 John Harwell, All rights reserved.
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

#include "rcppsw/common/common.hpp"
#include "rcppsw/math/range.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, math);

class degrees;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class radians
 * @ingroup math
 *
 * @brief Used to store an angle value in radians (duh).
 */
class radians {
 public:
  static const radians kPI;
  static const radians kTWO_PI;
  static const radians kPI_OVER_THREE;
  static const radians kPI_OVER_FOUR;
  static const radians kZERO;
  static const double kRADIANS_TO_DEGREES;

  radians(void) : m_value(0.0) {}

  explicit radians(double value) : m_value(value) {}
  explicit radians(const degrees& d);

  /**
   * @brief Sets the value in radians.
   */
  void set(double value) { m_value = value; }

  /**
   * @brief Sets the value from a value in degrees.
   */
  void set_from_deg(double value) { m_value = value / kRADIANS_TO_DEGREES; }

  double value(void) const { return m_value; }
  double abs_value(void) const { return std::abs(m_value); }

  /**
   * @brief Normalizes the value in the range [-pi, pi].
   */
  radians& signed_normalize(void) {
    kSignedRange.wrap_value(*this);
    return *this;
  }

  /**
   * @brief Normalizes the value in the range [0, 2pi]
   */
  radians& unsigned_normalize(void) {
    kUnsignedRange.wrap_value(*this);
    return *this;
  }

  radians& operator+(void) {
    return *this;
  }

  radians operator-(void) const {
    return radians(-m_value);
  }

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

  double operator/(const radians& other) const {
    return m_value / other.m_value;
  }

  radians operator/(double value) const {
    radians res(*this);
    res /= value;
    return res;
  }

  bool operator<(const radians& other) const {
    return m_value < other.m_value;
  }

  bool operator<=(const radians& other) const {
    return m_value <= other.m_value;
  }

  bool operator>(const radians& other) const {
    return m_value > other.m_value;
  }

  bool operator>=(const radians& other) const {
    return m_value >= other.m_value;
  }

  bool operator==(const radians& other) const {
    return std::fabs(m_value - other.m_value) < std::numeric_limits<double>::epsilon();
  }

  bool operator!=(const radians& other) const {
    return !(*this == other);
  }

 private:
  /**
   * @brief The signed normalization range [-pi, pi]
   */
  static const range<radians> kSignedRange;

  /**
   * The unsigned normalization range [0, 2pi]
   */
  static const range<radians> kUnsignedRange;

  double m_value;
};

/*******************************************************************************
 * Operators
 ******************************************************************************/
std::ostream& operator<<(std::ostream& stream, const radians& r);

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_RADIANS_HPP_ */
