/**
 * \file vector2.hpp
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

#ifndef INCLUDE_RCPPSW_MATH_VECTOR2_HPP_
#define INCLUDE_RCPPSW_MATH_VECTOR2_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include <limits>
#include <string>

#include "rcppsw/math/radians.hpp"
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
 * \class vector2
 * \ingroup math
 *
 * \brief Base template class encapsulating mathematical actions on a pair of
 * numbers. Is specialized by \ref vector2i, \ref vector2d.
 *
 * All operations are performed in whatever the template parameter is, so take
 * care if you are trying to do scaling, trigonometric things with integers...
 */
template <typename T>
class vector2 final : public er::stringizable {
 public:
  using value_type = T;

  /**
 * \brief Needed for using vectors as keys in a map.
 */
  struct key_compare {
    template<typename U = T,
             RCPPSW_SFINAE_DECLDEF(!std::is_floating_point<U>::value)>
    bool operator()(const vector2<U>& lhs, const vector2<U>& rhs) const {
      /* Order based on X unless X's are equal, if so order on Y, etc. */
      if (lhs.x() != rhs.x()) {
        return lhs.x() < rhs.x();
      }
      return lhs.y() < rhs.y();
    }
    template<typename U = T,
             RCPPSW_SFINAE_DECLDEF(std::is_floating_point<U>::value)>
    bool operator()(const vector2<U>& lhs, const vector2<U>& rhs) const {
      bool equal_x = std::fabs(lhs.x() - rhs.x()) <= kDOUBLE_EPSILON;

      if (!equal_x) {
        return lhs.x() < rhs.x();
      }
      return lhs.y() < rhs.y();
    }
  };

  /**
   * \brief Needed to compare in mathematical contexts.
   */
  struct componentwise_compare {
    bool operator()(const vector2<T>& lhs, const vector2<T>& rhs) const {
      return lhs.x() <= rhs.x() && lhs.y() <= rhs.y();
    }
  };

  static constexpr size_t kDIMENSIONALITY = 2;

  /**
   * \brief The positive X axis.
   */
  static const vector2<T> X; // NOLINT

  /**
   * \brief The positive Y axis.
   */
  static const vector2<T> Y; // NOLINT

  /**
   * \brief Computes the manhattan distance between the passed vectors.
   */
  template<typename U,
           typename V,
           RCPPSW_SFINAE_DECLDEF(!std::is_floating_point<U>::value),
           RCPPSW_SFINAE_DECLDEF(!std::is_floating_point<V>::value)>
  static size_t l1norm(const vector2<U>& v1, const vector2<V>& v2) {
    return std::abs(static_cast<int>(v1.x() - v2.x())) +
        std::abs(static_cast<int>(v1.y() - v2.y()));
  }

  /**
   * \brief Initializes vector to (0,0)
   */
  vector2(void) noexcept = default;

  /**
   * \brief Initializes the vector from Cartesian coordinates.
   *
   * \param x The X coordinate.
   * \param y The Y coordinate.
   */
  constexpr vector2(const T& x, const T& y) noexcept : m_x(x), m_y(y) {}

  /**
   * \brief Initializes the vector coordinates from polar coordinates.
   *
   * \param length The vector length.
   * \param angle The vector angle.
   */
  template <typename U = T, RCPPSW_SFINAE_DECLDEF(std::is_floating_point<U>::value)>
  vector2(const T& length, const radians& angle) noexcept
      : m_x(std::cos(angle.v()) * length),
        m_y(std::sin(angle.v()) * length) {}

  RCPPSW_NODISCARD T x(void)  { return m_x; }
  RCPPSW_NODISCARD T y(void)  { return m_y; }
  RCPPSW_NODISCARD const T& x(void) const { return m_x; }
  RCPPSW_NODISCARD const T& y(void) const { return m_y; }
  void x(const T& x) { m_x = x; }
  void y(const T& y) { m_y = y; }

  /**
   * \brief Is the vector is positive definite?
   */
  bool is_pd(void) const { return m_x > 0 && m_y > 0; }

  /**
   * \brief Is the vector is positive semi-definite?
   */
  bool is_psd(void) const { return m_x >= 0 && m_y >= 0; }

  /**
   * \brief Sets the vector contents from Cartesian coordinates.
   *
   * \param x The new X coordinate.
   * \param y The new Y coordinate.
   */
  void set(const T& x, const T& y) {
    m_x = x;
    m_y = y;
  }

  /**
   * Sets the vector contents from polar coordinates.
   *
   * \param length The length of the vector.
   * \param angle The angle of the vector (range [0,2pi)
   */
  template <typename U = T, RCPPSW_SFINAE_DECLDEF(std::is_floating_point<U>::value)>
  void set_from_polar(const T& length, const radians& angle) {
    m_x = std::cos(angle.v()) * length;
    m_y = std::sin(angle.v()) * length;
  }

  /**
   * \brief Returns the square length of this vector.
   */
  RCPPSW_NODISCARD T square_length(void) const { return (m_x * m_x) + (m_y * m_y); }

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
  template <typename U = T, RCPPSW_SFINAE_DECLDEF(std::is_floating_point<U>::value)>
  vector2& normalize(void) {
    *this /= this->length();
    return *this;
  }

  /**
   * \brief Return the angle of this vector.
   */
  radians angle(void) const { return radians(std::atan2(m_y, m_x)); }

  /**
   * \brief Rotate this vector by the specified angle.
   *
   * This is only available if the template parameter is not an integer.
   *
   * \param angle The rotation angle.
   *
   * \return A reference to the rotated vector.
   */
  template <typename U = T, RCPPSW_SFINAE_DECLDEF(std::is_floating_point<U>::value)>
  vector2& rotate(const radians& angle) {
    T sin_val, cos_val;
    ::sincos(angle.v(), &sin_val, &cos_val);
    m_x = m_x * cos_val - m_y * sin_val;
    m_y = m_x * sin_val + m_y * cos_val;
    return *this;
  }

  /**
   * \brief Scales the vector by the specified values.
   *
   * \param scale_x the scale factor for the X coordinate.
   * \param scale_y the scale factor for the Y coordinate.
   *
   * \return A reference to the scaled vector.
   */
  vector2& scale(const T& scale_x, const T& scale_y) {
    m_x *= scale_x;
    m_y *= scale_y;
    return *this;
  }

  /**
   * \brief Scales the vector by the specified values.
   *
   * \param factor The scaling factor applied to both X and Y.
   *
   * \return A reference to the scaled vector.
   */
  vector2& scale(const T& factor) { return scale(factor, factor); }

  /* relational operators */
  /**
   * \brief Returns if this vector and the argument are considered equal,
   * determined by coordinate comparison.
   *
   * Only available if the template argument is not floating point.
   */
  template <typename U = T, RCPPSW_SFINAE_DECLDEF(!std::is_floating_point<U>::value)>
  bool operator==(const vector2& other) const {
    return (m_x == other.m_x && m_y == other.m_y);
  }

  /**
   * \brief Returns if this vector and the argument are considered equal,
   * determined by coordinate comparison.
   *
   * Only available if the template argument is floating point.
   */
  template <typename U = T, RCPPSW_SFINAE_DECLDEF(std::is_floating_point<U>::value)>
  bool operator==(const vector2& other) const {
    return (std::fabs(x() - other.x()) <= kDOUBLE_EPSILON) &&
        (std::fabs(y() - other.y()) <= kDOUBLE_EPSILON);
  }

  /**
   * \brief Needed for using vectors as keys in a map.
   */
  template <typename U = T, RCPPSW_SFINAE_DECLDEF(!std::is_floating_point<U>::value)>
  bool operator<(const vector2& other) const {
    return (m_x < other.m_x) || ((m_x == other.m_x) && (m_y < other.m_y));
  }

  template <typename U = T, RCPPSW_SFINAE_DECLDEF(!std::is_floating_point<U>::value)>
  bool operator>(const vector2& other) const {
    return (m_x > other.m_x) || ((m_x == other.m_x) && (m_y > other.m_y));
  }

  bool operator<=(const vector2& other) const {
    return *this < other || *this == other;
  }

  bool operator>=(const vector2& other) const {
    return *this > other || *this == other;
  }
  /**
   * \brief Returns if this vector and the passed one are not equal by checking
   * coordinates for equality.
   *
   * Should generally not be called if the template parameter type is not an
   * integer, as floating point comparisons in general are unsafe.
   */
  bool operator!=(const vector2& other) const { return !(*this == other); }

  /* modifier operators */
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
    stream << v.to_str();
    return stream;
  }

  /**
   * \brief For parsing a vector from a string in the form of \c "X,Y".
   */
  friend std::istream& operator>>(std::istream& is, vector2<T>& v) {
    T values[2] = { T(), T() };
    utils::parse_values<T>(is, 2, values, ',');
    v.set(values[0], values[1]);
    return is;
  }

  std::string to_str(void) const override {
    return "(" + rcppsw::to_string(m_x) + "," + rcppsw::to_string(m_y) + ")";
  }

 private:
  /* clang-format off */
  T m_x{0};
  T m_y{0};
  /* clang-format on */
};

/*******************************************************************************
 * Template Specializations
 ******************************************************************************/
/**
 * \brief Specialization of \ref vector2 for signed integers.
 */
using vector2i = vector2<int>;

/**
 * \brief Specialization of \ref vector2 for size_t.
 */
using vector2z = vector2<size_t>;

/**
 * \brief Specialization of \ref vector2 for doubles.
 */
using vector2d = vector2<double>;

template<> const vector2i vector2i::X;
template<> const vector2i vector2i::Y;

template<> const vector2z vector2z::X;
template<> const vector2z vector2z::Y;

template<> const vector2d vector2d::X;
template<> const vector2d vector2d::Y;

/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * \brief Convert vector2{i,u,z} -> vector2d directly, without applying any
 * scaling.
 */
#define RCPPSW_MATH_VEC2_DIRECT_CONVF(prefix)                             \
  static inline vector2d prefix##vec2dvec(const vector2##prefix& other) { \
    return vector2d(other.x(), other.y());                                \
  }

/**
 * \brief Convert vector2{i,u,z} -> vector2d, applying a multiplicative scaling
 * factor.
 */
#define RCPPSW_MATH_VEC2_SCALED_CONVF(prefix)                           \
  static inline vector2d prefix##vec2dvec(const vector2##prefix& other, \
                                          double scale) {               \
    return vector2d(other.x() * scale, other.y() * scale);              \
  }

/**
 * \brief Convert vector2d -> vector2{i,u,z}, applying a divisive scaling
 * factor.
 */
#define RCPPSW_MATH_VEC2_CONV2DISC(dest_prefix, dest_type)                      \
  static inline vector2##dest_prefix dvec2##dest_prefix##vec(               \
      const vector2d& other, double scale) {                                \
    return vector2##dest_prefix(static_cast<dest_type>(other.x() / scale),  \
                                static_cast<dest_type>(other.y() / scale)); \
  }

/*******************************************************************************
 * Conversion Functions
 ******************************************************************************/
RCPPSW_MATH_VEC2_DIRECT_CONVF(i);
RCPPSW_MATH_VEC2_DIRECT_CONVF(z);
RCPPSW_MATH_VEC2_SCALED_CONVF(i);
RCPPSW_MATH_VEC2_SCALED_CONVF(z);
RCPPSW_MATH_VEC2_CONV2DISC(z, size_t);
RCPPSW_MATH_VEC2_CONV2DISC(i, int);

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_VECTOR2_HPP_ */
