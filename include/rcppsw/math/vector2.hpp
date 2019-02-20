/**
 * @file vector2.hpp
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

#ifndef INCLUDE_RCPPSW_MATH_VECTOR2_HPP_
#define INCLUDE_RCPPSW_MATH_VECTOR2_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include <limits>
#include <string>

#include "rcppsw/common/common.hpp"
#include "rcppsw/math/radians.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class vector2
 * @ingroup math
 *
 * @brief Base template class encapsulating mathematical actions on a pair of
 * numbers. Is specialized by \ref vector2d, \ref vector2i, \ref vector2f.
 *
 * All operations are performed in whatever the template parameter is, so take
 * care if you are trying to do scaling, trigonometric things with integers...
 */
template <typename T>
class vector2 {
 public:
  /**
   * @brief Computes the square distance between the passed vectors.
   */
  static T square_distance(const vector2& v1, const vector2& v2) {
    return (v1 - v2).square_length();
  }

  /**
   * @brief Computes the distance between the passed vectors.
   */
  static T distance(const vector2& v1, const vector2& v2) {
    return (v1 - v2).length();
  }

  /**
   * @brief The positive X axis.
   */
  static const vector2 X;

  /**
   * @brief The positive Y axis.
   */
  static const vector2 Y;

  /**
   * @brief Initializes vector to (0,0)
   */
  vector2(void) : m_x(0), m_y(0) {}

  /**
   * @brief Initializes the vector from Cartesian coordinates.
   *
   * @param x The X coordinate.
   * @param y The Y coordinate.
   */
  vector2(const T& x, const T& y) : m_x(x), m_y(y) {}

  /**
   * @brief Initializes the vector coordinates from polar coordinates.
   *
   * @param length The vector length.
   * @param angle The vector angle.
   */
  vector2(T length, const radians& angle)
      : m_x(std::cos(angle.value()) * length),
        m_y(std::sin(angle.value()) * length) {}

  T x(void) const __rcsw_check_return { return m_x; }
  T y(void) const __rcsw_check_return { return m_y; }
  void x(const T& x) { m_x = x; }
  void y(const T& y) { m_y = y; }

  /**
   * @brief Sets the vector contents from Cartesian coordinates.
   *
   * @param x The new X coordinate.
   * @param y The new Y coordinate.
   */
  void set(const T& x, const T& y) {
    m_x = x;
    m_y = y;
  }

  /**
   * Sets the vector contents from polar coordinates.
   *
   * @param length The length of the vector.
   * @param angle The angle of the vector (range [0,2pi)
   */
  void set_from_polar(const T& length, const radians& angle) {
    m_x = std::cos(angle.value()) * length;
    m_y = std::sin(angle.value()) * length;
  }

  /**
   * @brief Returns the square length of this vector.
   */
  T square_length(void) const __rcsw_check_return {
    return (m_x * m_x) + (m_y * m_y);
  }

  /**
   * Returns the length of this vector.
   */
  T length(void) const __rcsw_check_return {
    return std::sqrt(square_length());
  }

  /**
   * @brief Normalizes this vector.
   *
   * After this method is called, the vector has length 1. If the vector
   * is (0,0), this call results in a division by zero error, and your program
   * will probably crash.
   *
   * @return A reference to the normalized vector.
   */
  vector2& normalize(void) {
    *this /= this->length();
    return *this;
  }

  /**
   * @brief Return the angle of this vector.
   */
  radians angle(void) const { return radians(std::atan2(m_y, m_x)); }

  /**
   * @brief Rotate this vector by the specified angle.
   *
   * This is only available if the template parameter is not an integer.
   *
   * @param angle The rotation angle.
   *p
   * @return A reference to the rotated vector.
   */
  template <typename U = T, RCPPSW_SFINAE_REQUIRE(std::is_floating_point<U>::value)>
  vector2& rotate(const radians& angle) {
    T sin_val = std::sin(angle.value());
    T cos_val = std::cos(angle.value());
    m_x = m_x * cos_val - m_y * sin_val;
    m_y = m_x * sin_val + m_y * cos_val;
    return *this;
  }

  /**
   * @brief Scales the vector by the specified values.
   *
   * @param scale_x the scale factor for the X coordinate.
   * @param scale_y the scale factor for the Y coordinate.
   *
   * @return A reference to the scaled vector.
   */
  vector2& scale(const T& scale_x, const T& scale_y) {
    m_x *= scale_x;
    m_y *= scale_y;
    return *this;
  }

  /**
   * @brief Scales the vector by the specified values.
   *
   * @param factor The scaling factor applied to both X and Y.
   *
   * @return A reference to the scaled vector.
   */
  vector2& scale(const T& factor) { return scale(factor, factor); }

  /**
   * @brief Returns if this vector and the argument are considered equal,
   * determined by coordinate comparison.
   *
   * Only available if the template argument is not floating point.
   */
  template <typename U = T,
            RCPPSW_SFINAE_REQUIRE(!std::is_floating_point<U>::value)>
  bool operator==(const vector2& other) const {
    return (m_x == other.m_x && m_y == other.m_y);
  }

  /**
   * @brief Returns if this vector and the argument are considered equal,
   * determined by coordinate comparison.
   *
   * Only available if the template argument is floating point.
   */
  template <typename U = T, RCPPSW_SFINAE_REQUIRE(std::is_floating_point<U>::value)>
  bool operator==(const vector2& other) const {
    return (std::fabs(x() - other.x()) <= std::numeric_limits<T>::epsilon() &&
            (std::fabs(y() - other.y()) <= std::numeric_limits<T>::epsilon()));
  }

  /**
   * @brief Needed for using vectors as keys in a map.
   */
  bool operator<(const vector2& other) const {
    return m_x < other.m_x && m_y < other.m_y;
  }
  /**
   * @brief Returns if this vector and the passed one are not equal by checking
   * coordinates for equality.
   *
   * Should generally not be called if the template parameter type is not an
   * integer, as floating point comparisons in general are unsafe.
   */
  bool operator!=(const vector2& other) const { return !(*this == other); }

  vector2& operator+=(const vector2& other) {
    m_x += other.m_x;
    m_y += other.m_y;
    return *this;
  }

  vector2& operator-=(const vector2& other) {
    m_x -= other.m_x;
    m_y -= other.m_y;
    return *this;
  }

  vector2& operator*=(T val) {
    m_x *= val;
    m_y *= val;
    return *this;
  }

  vector2& operator/=(T val) {
    m_x /= val;
    m_y /= val;
    return *this;
  }

  vector2 operator+(const vector2& other) const {
    vector2 res(*this);
    res += other;
    return res;
  }

  vector2<T> operator-(const vector2& other) const {
    vector2<T> res(*this);
    res -= other;
    return res;
  }

  vector2 operator*(T val) const {
    vector2 res(*this);
    res *= val;
    return res;
  }

  vector2 operator/(T val) const {
    vector2 res(*this);
    res /= val;
    return res;
  }

  vector2 operator-(void) const { return vector2(-m_x, -m_y); }

  friend std::ostream& operator<<(std::ostream& stream, const vector2& v) {
    stream << "(" << v.m_x << "," << v.m_y << ")";
    return stream;
  }

  std::string to_str(void) const {
    return "(" + std::to_string(m_x) + "," + std::to_string(m_y) + ")";
  }

 private:
  T m_x;
  T m_y;
};

using vector2i = vector2<int>;
using vector2u = vector2<uint>;
using vector2d = vector2<double>;

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define DIRECT_CONV2D(prefix)                                             \
  static inline vector2d prefix##vec2dvec(const vector2##prefix& other) { \
    return vector2d(other.x(), other.y());                                \
  }

#define SCALED_CONV2D(prefix)                                           \
  static inline vector2d prefix##vec2dvec(const vector2##prefix& other, \
                                          double scale) {               \
    return vector2d(other.x() * scale, other.y() * scale);              \
  }

#define CONV2U(prefix)                                                  \
  static inline vector2u prefix##vec2uvec(const vector2##prefix& other, \
                                          double scale) {               \
    return vector2u(static_cast<uint>(std::round(other.x() / scale)),   \
                    static_cast<uint>(std::round(other.y() / scale)));  \
  }

/*******************************************************************************
 * Free Functions
 ******************************************************************************/
DIRECT_CONV2D(u);
DIRECT_CONV2D(i);
SCALED_CONV2D(u);
SCALED_CONV2D(i);
CONV2U(d);

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_VECTOR2_HPP_ */
