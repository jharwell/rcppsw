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

#include "rcppsw/math/radians.hpp"
#include "rcppsw/math/sphere_vector.hpp"
#include "rcppsw/math/vector2.hpp"
#include "rcppsw/rcppsw.hpp"
#include "rcppsw/types/discretize_ratio.hpp"
#include "rcppsw/er/stringizable.hpp"

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
 * numbers. Is specialized by  \ref vector3i, \ref vector3d.
 *
 * All operations are performed in whatever the template parameter is, so take
 * care if you are trying to do scaling, trigonometric things with integers...
 */
template <typename T>
class vector3 final : public er::stringizable {
 public:
  using value_type = T;

  /**
 * \brief Needed for using vectors as keys in a map.
 */
  struct key_compare {
    template<typename U,
             RCPPSW_SFINAE_DECLDEF(!std::is_floating_point<U>::value)>
    bool operator()(const vector3<U>& lhs, const vector3<U>& rhs) const {
      /* Order based on X unless X's are equal, if so order on Y, etc. */
      if (lhs.x() != rhs.x()) {
        return lhs.x() < rhs.x();
      }
      if (lhs.y() != rhs.y()) {
        return lhs.y() < rhs.y();
      }
      return lhs.z() < rhs.z();
    }
    template<typename U,
             RCPPSW_SFINAE_DECLDEF(std::is_floating_point<U>::value)>
    bool operator()(const vector3<U>& lhs, const vector3<U>& rhs) const {
      bool equal_x = std::fabs(lhs.x() - rhs.x()) <= kDOUBLE_EPSILON;
      bool equal_y = std::fabs(lhs.y() - rhs.y()) <= kDOUBLE_EPSILON;

      if (!equal_x) {
        return lhs.x() < rhs.x();
      }
      if (!equal_y) {
        return lhs.y() < rhs.y();
      }
      return lhs.z() < rhs.z();
    }
  };

  /**
   * \brief Needed to compare in mathematical contexts.
   */
  struct componentwise_compare {
    template <typename U>
    bool operator()(const vector3<U>& lhs, const vector3<U>& rhs) const {
      return lhs.x() <= rhs.x() && lhs.y() <= rhs.y() && lhs.z() <= rhs.z();
    }
  };

  static constexpr size_t kDIMENSIONALITY = 3;

  /**
   * \brief The positive X axis.
   */
  static const vector3<T> X; // NOLINT

  /**
   * \brief The positive Y axis.
   */
  static const vector3<T> Y; // NOLINT

  /**
   * \brief The positive Z axis.
   */
  static const vector3<T> Z; // NOLINT

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
  explicit vector3<T>(const vector2<T>& v) : vector3{v, T{0}} {}

  /**
   * \brief Initialize the 3D vector from a 2D vector.
   */
  vector3<T>(const vector2<T>& v, const T& z) : vector3(v.x(), v.y(), z) {}

  RCPPSW_NODISCARD T x(void) { return m_x; }
  RCPPSW_NODISCARD T y(void) { return m_y; }
  RCPPSW_NODISCARD T z(void) { return m_z; }

  RCPPSW_NODISCARD const T& x(void) const { return m_x; }
  RCPPSW_NODISCARD const T& y(void) const { return m_y; }
  RCPPSW_NODISCARD const T& z(void) const { return m_z; }

  void x(const T& x) { m_x = x; }
  void y(const T& y) { m_y = y; }
  void z(const T& z) { m_z = z; }

  vector2<T> to_2D(void) const { return vector2<T>(x(), y()); }

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
   * \brief Is the vector is positive definite?
   */
  bool is_pd(void) const { return m_x > 0 && m_y > 0 && m_z > 0; }

  /**
   * \brief Is the vector is positive semi-definite?
   */
  bool is_psd(void) const { return m_x >= 0 && m_y >= 0 && m_z >= 0; }

  /**
   * \brief Returns the square length of this vector.
   */
  RCPPSW_NODISCARD T square_length(void) const {
    return (m_x * m_x) + (m_y * m_y) + (m_z * m_z);
  }

  /**
   * Returns the length of this vector.
   */
  RCPPSW_NODISCARD double length(void) const { return std::sqrt(square_length()); }

  /**
   * \brief Normalizes this vector.
   *
   * After this method is called, the vector has length 1. If the vector
   * is (0,0), this call results in a division by zero error, and your program
   * will probably crash.
   *
   * \return A reference to the normalized vector.
   */
  template <typename U = T,
            RCPPSW_SFINAE_DECLDEF(std::is_floating_point<U>::value)>
  vector3& normalize(void) {
    *this /= this->length();
    return *this;
  }

  /**
   * \brief Mask a vector using another vector, using \p mask as a boolean mask
   * by treating each non-zero entry as a 1. Should only be used if \p mask is a
   * unit vector.
   */
  vector3 mask(const vector3& the_mask) const {
    return vector3(m_x * the_mask.m_x, m_y * the_mask.m_y, m_z * the_mask.m_z);
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
  vector2<T> project_on_xy(void) const { return vector2<T>(m_x, m_y); }

  /**
   * \brief Calculates the projection of this vector onto the YZ plane.
   */
  vector2<T> project_on_yz(void) const { return vector2<T>(m_y, m_z); }

  /**
   * \brief Calculates the projection of this vector onto the XZ plane.
   */
  vector2<T> project_on_xz(void) const { return vector2<T>(m_x, m_z); }

  template <typename U = T, RCPPSW_SFINAE_DECLDEF(std::is_floating_point<U>::value)>
  sphere_vector<T> to_spherical(void) const {
    double radius = length();
    return sphere_vector<T>(
        radius, radians(std::acos(m_z / radius)), radians(std::atan2(m_y, m_x)));
  }

  /**
   * \brief Scales the vector by the specified values.
   *
   * \param scale_x The scale factor for the X coordinate.
   * \param scale_y The scale factor for the Y coordinate.
   * \param scale_z The scale factor for the Z coordinate.
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

  /* Relational operators */

  /**
   * \brief Returns if this vector and the argument are considered equal,
   * determined by coordinate comparison.
   *
   * Only available if the template argument is not floating point.
   */
  template <typename U = T, RCPPSW_SFINAE_DECLDEF(!std::is_floating_point<U>::value)>
  bool operator==(const vector3& other) const {
    return (m_x == other.m_x && m_y == other.m_y && m_z == other.m_z);
  }

  /**
   * \brief Returns if this vector and the argument are considered equal,
   * determined by coordinate comparison.
   *
   * Only available if the template argument is floating point.
   */
  template <typename U = T, RCPPSW_SFINAE_DECLDEF(std::is_floating_point<U>::value)>
  bool operator==(const vector3& other) const {
    return (std::fabs(x() - other.x()) <= kDOUBLE_EPSILON) &&
        (std::fabs(y() - other.y()) <= kDOUBLE_EPSILON) &&
        (std::fabs(z() - other.z()) <= kDOUBLE_EPSILON);
  }

  template <typename U = T, RCPPSW_SFINAE_DECLDEF(!std::is_floating_point<U>::value)>
  bool operator>(const vector3& other) const {
    return (m_x > other.m_x) || ((m_x == other.m_x) && (m_y > other.m_y)) ||
           ((m_x == other.m_x) && (m_y == other.m_y) && (m_z > other.m_z));
  }

  template <typename U = T, RCPPSW_SFINAE_DECLDEF(std::is_floating_point<U>::value)>
  bool operator>(const vector3& other) const {
    bool equal_x = std::fabs(m_x - other.m_x) <= kDOUBLE_EPSILON;
    bool equal_y = std::fabs(m_y - other.m_y) <= kDOUBLE_EPSILON;

    return (m_x > other.m_x) || (equal_x && (m_y > other.m_y)) ||
           (equal_x && equal_y && (m_z > other.m_z));
  }

  /**
   * \brief Returns if this vector and the passed one are not equal by checking
   * coordinates for equality.
   *
   * Should generally not be called if the template parameter type is not an
   * integer, as floating point comparisons in general are unsafe.
   */
  bool operator!=(const vector3& other) const { return !(*this == other); }

  /* modifier operators */
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

  vector3& operator*=(const T& val) {
    m_x *= val;
    m_y *= val;
    m_z *= val;
    return *this;
  }

  vector3& operator/=(const T& val) {
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

  vector3 operator*(const T& val) const {
    vector3 res(*this);
    res *= val;
    return res;
  }

  vector3 operator/(const T& val) const {
    vector3 res(*this);
    res /= val;
    return res;
  }

  vector3 operator-(void) const { return vector3(-m_x, -m_y, -m_z); }

  friend std::ostream& operator<<(std::ostream& stream, const vector3& v) {
    stream << v.to_str();
    return stream;
  }

  /**
   * \brief For parsing a vector from a string in the form of \c "X,Y,Z".
   */
  friend std::istream& operator>>(std::istream& is, vector3<T>& v) {
    T values[3] = { T(), T(), T() };
    utils::parse_values<T>(is, 3, values, ',');
    v.set(values[0], values[1], values[2]);
    return is;
  }

  std::string to_str(void) const override {
    return "(" + rcppsw::to_string(m_x) + "," + rcppsw::to_string(m_y) + "," +
           rcppsw::to_string(m_z) + ")";
  }

 private:
  /* clang-format off */
  T m_x{0};
  T m_y{0};
  T m_z{0};
  /* clang-format on */
};

/*******************************************************************************
 * Template Specializations
 ******************************************************************************/
/**
 * \brief Specialization of \ref vector3 for signed integers.
 */
using vector3i = vector3<int>;

/**
 * \brief Specialization of \ref vector3 for size_t.
 */
using vector3z = vector3<size_t>;

/**
 * \brief Specialization of \ref vector3 for doubles.
 */
using vector3d = vector3<double>;

template<> const vector3i vector3i::X;
template<> const vector3i vector3i::Y;
template<> const vector3i vector3i::Z;

template<> const vector3z vector3z::X;
template<> const vector3z vector3z::Y;
template<> const vector3z vector3z::Z;

template<> const vector3d vector3d::X;
template<> const vector3d vector3d::Y;
template<> const vector3d vector3d::Z;

/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * \brief Convert vector3{i,z} -> vector3d directly, without applying any
 * scaling.
 */
#define RCPPSW_MATH_VEC3_DIRECT_CONV2FLT(prefix)                          \
  static inline vector3d prefix##vec2dvec(const vector3##prefix& other) { \
    return vector3d(other.x(), other.y(), other.z());                     \
  }

/**
 * \brief Convert vector3{i,z} -> vector3d, applying a multiplicative scaling
 * factor.
 */
#define RCPPSW_MATH_VEC3_SCALED_CONV2FLT(prefix)                              \
  static inline vector3d prefix##vec2dvec(const vector3##prefix& other,       \
                                          double scale) {                     \
    return vector3d(other.x() * scale, other.y() * scale, other.z() * scale); \
  }

/**
 * \brief Convert vector3d -> vector3{i,z}, applying a divisive scaling
 * factor.
 */
#define RCPPSW_MATH_VEC3_CONV2DISC(dest_prefix, dest_type)                  \
  static inline vector3##dest_prefix dvec2##dest_prefix##vec(               \
      const vector3d& other, double scale) {                                \
     return vector3##dest_prefix(static_cast<dest_type>(other.x() / scale),  \
                                static_cast<dest_type>(other.y() / scale),  \
                                static_cast<dest_type>(other.z() / scale)); \
  }

/*******************************************************************************
 * Conversion Functions
 ******************************************************************************/
RCPPSW_MATH_VEC3_DIRECT_CONV2FLT(i);
RCPPSW_MATH_VEC3_DIRECT_CONV2FLT(z);
RCPPSW_MATH_VEC3_SCALED_CONV2FLT(i);
RCPPSW_MATH_VEC3_SCALED_CONV2FLT(z);
RCPPSW_MATH_VEC3_CONV2DISC(z, size_t);
RCPPSW_MATH_VEC3_CONV2DISC(i, int);

/*******************************************************************************
 * Free Functions
 ******************************************************************************/
/**
 * \brief Computes the distance between the passed vectors.
 */
template<typename U,
         typename V,
         RCPPSW_SFINAE_DECLDEF(!std::is_floating_point<U>::value),
         RCPPSW_SFINAE_DECLDEF(!std::is_floating_point<V>::value)>
static inline size_t l1norm(const vector3<U>& v1, const vector3<V>& v2) {
  return std::abs(static_cast<int>(v1.x() - v2.x())) +
      std::abs(static_cast<int>(v1.y() - v2.y())) +
      std::abs(static_cast<int>(v1.z() - v2.z()));
}

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_VECTOR3_HPP_ */
