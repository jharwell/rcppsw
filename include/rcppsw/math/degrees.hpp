/**
 * \file degrees.hpp
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

#ifndef INCLUDE_RCPPSW_MATH_DEGREES_HPP_
#define INCLUDE_RCPPSW_MATH_DEGREES_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include <limits>
#include <string>

#include "rcppsw/math/range.hpp"
#include "rcppsw/rcppsw.hpp"
#include "rcppsw/math/math.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

class radians;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class degrees
 * \ingroup math
 *
 * \brief Used to store an angle value in degrees (duh).
 */
class degrees final : public er::stringizable {
 public:
  /*
   * These are MATHEMATICAL constants, so they get UPPER_CASE naming convention
   * to emphasize that fact.
   */
  static const double kDEGREES_TO_RADIANS; // NOLINT

  degrees(void) = default;

  /**
   * \brief Initialize from the specified value in DEGREES.
   */
  explicit degrees(double value) : m_value(value) {}

  /**
   * \brief Initialize from the specified value in RADIANS.
   */
  explicit degrees(const radians& r);

  /**
   * \brief Get the raw value of the angle.
   */
  double v(void) const { return m_value; }

  double operator()(void) const { return v(); }

  /**
   * \brief Set the current value in degrees.
   *
   * \param value In DEGREES.
   */
  void set(double value) { m_value = value; }

  /**
   * \brief Normalizes the value in the range [-180, 180]
   */
  degrees& signed_normalize(void) {
    return *this = kSignedRange.wrap_value(*this);
  }

  /**
   * \brief Normalizes the value in the range [0, 360].
   */
  degrees& unsigned_normalize(void) {
    return *this = kUnsignedRange.wrap_value(*this);
  }

  /**
   * \brief Return a string representation of the degrees object of the form
   * 'deg(XX) -> rad(YY)'.
   */
  std::string to_str(void) const override;

  degrees& operator+(void) { return *this; }

  degrees operator-(void) const { return degrees(-m_value); }

  degrees& operator+=(const degrees& other) {
    m_value += other.m_value;
    return *this;
  }

  degrees& operator+=(double value) {
    m_value += value;
    return *this;
  }

  degrees& operator-=(const degrees& other) {
    m_value -= other.m_value;
    return *this;
  }
  degrees& operator-=(double value) {
    m_value -= value;
    return *this;
  }
  degrees& operator*=(double value) {
    m_value *= value;
    return *this;
  }

  degrees& operator/=(double value) {
    m_value /= value;
    return *this;
  }

  degrees operator+(const degrees& other) const {
    degrees res(*this);
    res += other;
    return res;
  }

  degrees operator-(const degrees& other) const {
    degrees res(*this);
    res -= other;
    return res;
  }

  degrees operator*(double value) const {
    degrees res(*this);
    res *= value;
    return res;
  }

  double operator/(const degrees& other) const { return m_value / other.m_value; }

  degrees operator/(double value) const {
    degrees res(*this);
    res /= value;
    return res;
  }

  bool operator<(const degrees& other) const { return m_value < other.m_value; }

  bool operator<=(const degrees& other) const { return m_value <= other.m_value; }

  bool operator>(const degrees& other) const { return m_value > other.m_value; }

  bool operator>=(const degrees& other) const { return m_value >= other.m_value; }

  bool operator==(const degrees& other) const {
    return std::fabs(m_value - other.m_value) <= kDOUBLE_EPSILON;
  }

  bool operator!=(const degrees& other) const { return !(*this == other); }

  friend std::istream& operator>>(std::istream& is, degrees& d) {
    is >> d.m_value;
    return is;
  }

 private:
  /**
   * \brief The signed normalization range [-180, 180]
   */
  static const range<degrees> kSignedRange;

  /**
   * \brief The unsigned normalization range [0, 360]
   */
  static const range<degrees> kUnsignedRange;

  double m_value{ 0.0 };
};

/*******************************************************************************
 * Operators
 ******************************************************************************/
std::ostream& operator<<(std::ostream& stream, const degrees& d);

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_DEGREES_HPP_ */
