/**
 * \file vector3.hpp
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

#ifndef INCLUDE_RCPPSW_MATH_VECTOR3_HPP_
#define INCLUDE_RCPPSW_MATH_VECTOR3_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include <limits>
#include <string>

#include "rcppsw/common/common.hpp"
#include "rcppsw/math/radians.hpp"
#include "rcppsw/types/discretize_ratio.hpp"
#include "rcppsw/math/vector2.hpp"
#include "rcppsw/math/sphere_vector.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class vector3
 * \ingroup math
 *
 * \brief Base template class encapsulating mathematical actions on a pair of
 * numbers. Is specialized by \ref vector3u, \ref vector3i, \ref vector3d.
 *
 * All operations are performed in whatever the template parameter is, so take
 * care if you are trying to do scaling, trigonometric things with integers...
 */
template <typename T>
class vector3 {
 public:
  /**
   * \brief Computes the square distance between the passed vectors.
   */
  static T square_distance(const vector3& v1, const vector3& v2) {
    return (v1 - v2).square_length();
  }

  /**
   * \brief Computes the distance between the passed vectors.
   */
  static T distance(const vector3& v1, const vector3& v2) {
    return (v1 - v2).length();
  }

  /**
   * \brief The positive X axis.
   */
  static const vector3 X; // NOLINT

  /**
   * \brief The positive Y axis.
   */
  static const vector3 Y; // NOLINT


  /**
   * \brief The positive Z axis.
   */
  static const vector3 Z; // NOLINT

  /**
   * \brief Initializes vector to (0,0,0)
   */
  vector3(void) noexcept = default;

  /**
   * \brief Initializes the vector from Cartesian coordinates.
   *
   * \param x The X coordinate.
   * \param y The Y coordinate.
   * \param z The Z coordinate.
   */
  constexpr vector3(const T& x, const T& y, const T& z)
  : m_x(x), m_y(y), m_z(z) {}

  /**
   * \brief Initializes the 3D vector from a 2D vector, setting the Z value to
   * 0.0.
   */
  explicit vector3<T>(const vector2<T>& v) : vector3(v.x(), v.y(), 0.0) {}

  T x(void) RCSW_CHECK_RET { return m_x; }
  T y(void) RCSW_CHECK_RET { return m_y; }
  T z(void) RCSW_CHECK_RET { return m_z; }

  const T& x(void) const RCSW_CHECK_RET { return m_x; }
  const T& y(void) const RCSW_CHECK_RET { return m_y; }
  const T& z(void) const RCSW_CHECK_RET { return m_z; }

  void x(const T& x) { m_x = x; }
  void y(const T& y) { m_y = y; }
  void z(const T& z) { m_z = z; }

  /**
   * \brief Is the vector is positive definite?
   */
  bool is_pd(void) const { return m_x > 0 && m_y > 0 && m_z > 0; }

  /**
   * \brief Sets the vector contents from Cartesian coordinates.
   *
   * \param x The new X coordinate.
   * \param y The new Y coordinate.
   */
  void set(const T& x, const T& y, const T& z) {
    m_x = x;
    m_y = y;
    m_z = z;
  }

  /**
   * \brief Returns the square length of this vector.
   */
  T square_length(void) const RCSW_CHECK_RET {
    return (m_x * m_x) + (m_y * m_y) + (m_z * m_z);
  }

  /**
   * Returns the length of this vector.
   */
  double length(void) const RCSW_CHECK_RET { return std::sqrt(square_length()); }

  /**
   * \brief Normalizes this vector.
   *
   * After this method is called, the vector has length 1. If the vector
   * is (0,0), this call results in a division by zero error, and your program
   * will probably crash.
   *
   * \return A reference to the normalized vector.
   */
  vector3& normalize(void) {
    *this /= this->length();
    return *this;
  }

  /**
   * \brief Return angle between this vector and the X axis.
   */
  radians xangle(void) const { return radians(std::atan2(m_z, m_y)); }

  /**
   * \brief Return the angle between this vector and the Y axis.
   */
  radians yangle(void) const { return radians(std::atan2(m_x, m_z)); }

  /**
   * \brief Return the angle between this vector and the Z axis.
   */
  radians zangle(void) const { return radians(std::atan2(m_y, m_x)); }

  /**
   * \brief Calculates the projection of this vector onto the XY plane.
   */
  vector2<T> project_on_xy(void) const { return vector2(m_x, m_y); }

  /**
   * \brief Calculates the projection of this vector onto the YZ plane.
   */
  vector2<T> project_on_yz(void) const { return vector2(m_y, m_z); }

  /**
   * \brief Calculates the projection of this vector onto the XZ plane.
   */
  vector2<T> project_on_xz(void) const { return vector2(m_x, m_z); }

  sphere_vector<T> to_spherical(void) const {
    double radius = length();
    return sphere_vector<T>(radius,
                            radians(std::acos(m_z / radius)),
                            radians(std::atan2(m_y, m_x)));
  }

  /**
   * \brief Scales the vector by the specified values.
   *
   * \param scale_x the scale factor for the X coordinate.
   * \param scale_y the scale factor for the Y coordinate.
   * \param scale_z the scale factor for the Z coordinate.
   *
   * \return A reference to the scaled vector.
   */
  vector3& scale(const T& scale_x, const T& scale_y, const T& scale_z) {
    m_x *= scale_x;
    m_y *= scale_y;
    m_z *= scale_z;
    return *this;
  }

  /**
   * \brief Scales the vector by the specified values.
   *
   * \param factor The scaling factor applied to X,Y,Z.
   *
   * \return A reference to the scaled vector.
   */
  vector3& scale(const T& factor) { return scale(factor, factor, factor); }

  /**
   * \brief Returns if this vector and the argument are considered equal,
   * determined by coordinate comparison.
   *
   * Only available if the template argument is not floating point.
   */
  template <typename U = T, RCPPSW_SFINAE_FUNC(!std::is_floating_point<U>::value)>
  bool operator==(const vector3& other) const {
    return (m_x == other.m_x && m_y == other.m_y && m_z == other.m_z);
  }

  /**
   * \brief Returns if this vector and the argument are considered equal,
   * determined by coordinate comparison.
   *
   * Only available if the template argument is floating point.
   */
  template <typename U = T, RCPPSW_SFINAE_FUNC(std::is_floating_point<U>::value)>
  bool operator==(const vector3& other) const {
    return (std::fabs(x() - other.x()) <= std::numeric_limits<T>::epsilon() &&
            (std::fabs(y() - other.y()) <= std::numeric_limits<T>::epsilon()) &&
            (std::fabs(z() - other.z()) <= std::numeric_limits<T>::epsilon()));
  }

  /**
   * \brief Needed for using vectors as keys in a map.
   */
  bool operator<(const vector3& other) const {
    return (m_x < other.m_x) || ((m_x == other.m_x) && (m_y < other.m_y));
  }

  /**
   * \brief Returns if this vector and the passed one are not equal by checking
   * coordinates for equality.
   *
   * Should generally not be called if the template parameter type is not an
   * integer, as floating point comparisons in general are unsafe.
   */
  bool operator!=(const vector3& other) const { return !(*this == other); }

  vector3& operator+=(const vector3& other) {
    m_x += other.m_x;
    m_y += other.m_y;
    m_z += other.m_z;
    return *this;
  }

  vector3& operator-=(const vector3& other) {
    m_x -= other.m_x;
    m_y -= other.m_y;
    m_z -= other.m_z;
    return *this;
  }

  vector3& operator*=(T val) {
    m_x *= val;
    m_y *= val;
    m_z *= val;
    return *this;
  }

  vector3& operator/=(T val) {
    m_x /= val;
    m_y /= val;
    m_z /= val;
    return *this;
  }

  vector3 operator+(const vector3& other) const {
    vector3 res(*this);
    res += other;
    return res;
  }

  vector3<T> operator-(const vector3& other) const {
    vector3<T> res(*this);
    res -= other;
    return res;
  }

  vector3 operator*(T val) const {
    vector3 res(*this);
    res *= val;
    return res;
  }

  vector3 operator/(T val) const {
    vector3 res(*this);
    res /= val;
    return res;
  }

  vector3 operator-(void) const { return vector3(-m_x, -m_y); }

  friend std::ostream& operator<<(std::ostream& stream, const vector3& v) {
    stream << "(" << v.m_x << "," << v.m_y << "," << v.m_z << ")";
    return stream;
  }

  std::string to_str(void) const {
    return "(" +
        rcppsw::to_string(m_x) + "," +
        rcppsw::to_string(m_y) + "," +
        rcppsw::to_string(m_z) +
        ")";
  }

 private:
  /* clang-format off */
  T m_x{0};
  T m_y{0};
  T m_z{0};
  /* clang-format on */
};

/**
 * \brief Specialization of \ref vector3 for signed integers.
 */
using vector3i = vector3<int>;

/**
 * \brief Specialization of \ref vector3 for unsigned integers.
 */
using vector3u = vector3<uint>;

/**
 * \brief Specialization of \ref vector3 for doubles.
 */
using vector3d = vector3<double>;

/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * \brief Convert vector3{i,u} -> vector3d directly, without applying any
 * scaling.
 */
#define RCPPSW_MATH_VEC_DIRECT_CONV3D(prefix)                             \
  static inline vector3d prefix##vec2dvec(const vector3##prefix& other) { \
    return vector3d(other.x(), other.y(), other.z());                   \
  }

/**
 * \brief Convert vector3{i,u} -> vector3d, applying a multiplicative scaling
 * factor.
 */
#define RCPPSW_MATH_VEC_SCALED_CONV3D(prefix)                           \
  static inline vector3d prefix##vec2dvec(const vector3##prefix& other, \
                                          double scale) {               \
    return vector3d(other.x() * scale, other.y() * scale, other.z() * scale); \
  }

/**
 * \brief Convert vector3d -> vector3u, applying a divisive scaling factor.
 */
#define RCPPSW_MATH_VEC_CONV3U(prefix)                                  \
  static inline vector3u prefix##vec2uvec(const vector3##prefix& other, \
                                          double scale) {               \
    return vector3u(static_cast<uint>(std::round(other.x() / scale)),   \
                    static_cast<uint>(std::round(other.y() / scale)),   \
                    static_cast<uint>(std::round(other.z() / scale)));  \
  }

/*******************************************************************************
 * Free Functions
 ******************************************************************************/
RCPPSW_MATH_VEC_DIRECT_CONV3D(u);
RCPPSW_MATH_VEC_DIRECT_CONV3D(i);
RCPPSW_MATH_VEC_SCALED_CONV3D(u);
RCPPSW_MATH_VEC_SCALED_CONV3D(i);
RCPPSW_MATH_VEC_CONV3U(d);

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_VECTOR3_HPP_ */
