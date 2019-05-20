/**
 * @file range.hpp
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

#ifndef INCLUDE_RCPPSW_MATH_RANGE_HPP_
#define INCLUDE_RCPPSW_MATH_RANGE_HPP_

/*******************************************************************************
 * Includes
******************************************************************************/
#include <iostream>
#include <string>

#include "rcppsw/common/common.hpp"
#include "rcppsw/er/client.hpp"
#include "rcppsw/utils/string_utils.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class range
 * @ingroup rcppsw math
 *
 * @brief Convenience class holding a [min, max] range. Makes comparisons like
 * "is this number in this range" much more intuitive and easy to debug. All
 * ranges must be non-empty sets, meaning that the min must not be equal to the
 * max (if it is an assertion will trigger).
 */
template <typename T>
class range final : public er::client<range<T>> {
 public:
  range(const T& lb, const T& ub) noexcept
      : ER_CLIENT_INIT("rcppsw.math.range"),
        m_lb(lb),
        m_ub(ub),
        m_span(m_ub - m_lb) {}

  T lb(void) const __rcsw_check_return { return m_lb; }
  T ub(void) const __rcsw_check_return { return m_ub; }

  T span(void) const __rcsw_check_return { return m_span; }

  void lb(const T& lb) {
    ER_ASSERT(lb < m_ub, "Lower bound >= upper bound");
    m_lb = lb;
    m_span = m_ub;
    m_span -= m_lb;
  }

  void ub(const T& ub) {
    ER_ASSERT(ub > m_ub, "Lower bound >= upper bound");

    m_ub = ub;
    m_span = m_ub;
    m_span -= m_lb;
  }

  void set(const T& lb, const T& ub) {
    ER_ASSERT(lb < ub, "Lower bound >= upper bound");
    m_lb = lb;
    m_ub = ub;
    m_span = m_ub;
    m_span -= m_lb;
  }

  /**
   * @brief Determine if a value is within the range [lb, ub] (boundary points
   * included).
   *
   * @param value The value to test.
   */
  bool contains(const T& value) const { return value >= m_lb && value <= m_ub; }

  /**
   * @brief Determine if one range completely contains another (boundary points
   * are included with both ranges).
   */
  bool contains(const range<T>& other) const {
    return this->contains(other.m_lb) && this->contains(other.m_ub);
  }

  /**
   * @brief Determine if one range overlaps with another.
   *
   * Overlap is a commutative calculation (i.e. overlap(A,B) <-> overlap(B,A)).
   *
   * To implement this, we need to check if either bound of the argument is
   * contained in our range, AND if either of our bounds are contained in the
   * argument's range. The second part is necessary if A is completely contained
   * inside B in order for the calculation to be commutative.
   */
  bool overlaps_with(const range<T>& other) const {
    return this->contains(other.m_lb) || this->contains(other.m_ub) ||
           other.contains(this->m_lb) || other.contains(this->m_ub);
  }

  /**
   * @brief Wrap the specified value into the range [min, max] using wrap around
   * addition/subtraction.
   *
   * @return The wrapped value.
   */
  __rcsw_pure T wrap_value(T value) const __rcsw_check_return {
    while (value > m_ub) {
      value -= m_span;
    }
    while (value < m_lb) {
      value += m_span;
    }
    return value;
  }

  /**
   * @brief Return a string representation of the range in the form of [lb,ub]
   */
  std::string to_str(void) const {
    return "[" + std::to_string(m_lb) + "-" + std::to_string(m_ub) + "]";
  }

  friend std::ostream& operator<<(std::ostream& stream, const range& c_range) {
    stream << c_range.to_str();
    return stream;
  }
  /**
   * @brief Translate the current range to the specified value, returning a new
   * range centered at that value.
   *
   * @return The new translated range.
   */
  range translate(const T& value) { return range(m_lb - value, m_ub + value); }

  /**
   * @brief For parsing a range from a string in the form of <lb>:<ub>
   */
  friend std::istream& operator>>(std::istream& is, range& r) {
    T values[2] = {T(), T()};
    utils::parse_values<T>(is, 2, values, ':');
    r.set(values[0], values[1]);
    return is;
  }

 private:
  /* clang-format off */
  T m_lb;
  T m_ub;
  T m_span;
  /* clang-format on */
};

using rangei = range<int>;
using ranged = range<double>;
using rangef = range<float>;
using rangeu = range<uint>;

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_RANGE_HPP_ */
