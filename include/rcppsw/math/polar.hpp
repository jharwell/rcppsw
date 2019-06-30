/**
 * @file polar.hpp
 *
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

#ifndef INCLUDE_RCPPSW_MATH_POLAR_HPP_
#define INCLUDE_RCPPSW_MATH_POLAR_HPP_

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
 * @class polar
 * @ingroup math
 *
 * @brief Base template class encapsulating mathematical actions on a distance
 * and angle.
 */
template <typename T>
class polar {
 public:
  /**
   * @brief Computes the square distance between the passed polar coordinates.
   */
  static T square_distance(const polar& p1, const polar& p2) {
    T p1_x = p1.m_length * std::cos(p1.m_angle.value());
    T p1_y = p1.m_length * std::sin(p1.m_angle.value());
    T p2_x = p2.m_length * std::cos(p2.m_angle.value());
    T p2_y = p2.m_length * std::sin(p2.m_angle.value());
    T dif_x = p1_x - p2_x;
    T diff_y = p1_y - p2_y;
    return (diff_x * diff_x) + (diff_y * diff_y);
  }
  
  /**
   * @brief Computes the distance between the passed polar vectors
   *
   */
  static T distance(const polar& p1,  const polar& p2) {
    return std::sqrt(square_distance(p1, p2));
  }
  
  /**
   * @brief A unit polar vector with angle 0
   */
  static const polar zero;
   
  /**
   * @brief A unit polar vector with angle pi / 2
    */
  static const polar pi_over_two;
   
  /**
   * @brief A unit polar vector with angle pi 
   */
  static const polar pi;
  
  /**
   * @brief A unit polar vector with angle 3pi / 2
   */
  static const polar three_pi_over_two;
  
  /**
   * @brief A unit polar vector with angle 2pi
   */
  static const polar two_pi;
  
  /**
   * @brief Initializes polar vector to the origin
   */
  polar(void) noexcept = default;
  
  /**
   * @brief Initializes the polar vector from the polar coordinates.
   *
   * @param length The polar vector length.
   * @param angle The polar vector angle (range [0, 2pi].
   */
  polar(T length, const radians& angle) {
    m_length = length;
    m_angle = angle;
  }
  
  /**
   * @brief Initializes the polar coordinates from Cartesian coordinates.
   *
   * @param x The X coordinate.
   * @param x The Y coordinate.
   */ 
  polar(const T& x, const T&y) {
    m_length = std::sqrt((x * x) + (y * y));
    m_angle = radians(std::atan2(y, x));
  }
  
  /**
   * @brief Sets the polar vector contents from polar coordinates.
   * 
   * @param length The new length of the polar vector.
   * @param angle The new angle of the polar vector.
   */
  void set(const T& length, const radians& angle) {
    m_length = length;
    m_angle = angle;
  }
  
  /**
   * Sets the polar vector contents from Cartesian coordinates.
   *
   * @param x The X coordiante of the polar vector.
   * @param y The Y coordiante of the polar vector.
   */
  void set_from_cartesian(const T& x, const T&y) {
    m_length = std::sqrt((x * x) + (y * y));
    m_angle = radians(std::atan2(y, x));
  }
  
  /**
   * @brief Returns the square length of this vecotr.
   */
  
  T square_length(void) const __rcsw_check_return {
    return (m_length * m_length);
  }
  
  /**
   * @brief Normalizes this polar vector.
   *
   * After this method is called, the polar vector has length 1.
   *
   * @return A reference to the normalized polar vector.
   */
  polar& normalize(void) {
    m_length = 1;
    return *this;
  }
  
  /**
   * @brief Rotate this polar vector by the specified angle.
   *
   * @param angle The rotation angle.
   *
   * @return A reference to the rotated polar vector.
   */
  polar& rotate(const radians& angle) {
    m_angle+= angle;
    return *this;
  }
  
  /**
   * @brief Scales the polar vector by the specified value.
   *
   * @param scale The scale factor.
   *
   * @return A reference to the scaled polar vector.
   */
  polar& scale(const T& scale) {
    m_length *= scale;
    return *this;
  }
  
  /**
   * @breif Returns if this polar vector and the argument are considered
   * equal, determined by polar coordinate comparison.
   *
   */
  bool operator==(const polar& other) const {
    return (m_length == other.m_length && (m_length % radians::kTWO_PI) == (other.m_length % radians::kTWO_PI));
  }
 
 private:
  /* clang-format off */
  T m_length{0};
  radians m_angle{0};
