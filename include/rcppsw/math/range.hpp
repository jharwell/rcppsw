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
#include <assert.h>

#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template<typename T>
class range {
 public:
  range(const T& min, const T& max)
      : m_min(min),
        m_max(max),
        m_span(m_max - m_min) {
    assert(min <= max);
  }

  T get_min(void) const { return m_min; }
  T get_max(void) const { return m_max; }

  void set_min(const T& min) {
    assert(min <= m_max);
    m_min = min;
    m_span = m_max;
    m_span -= m_min;
  }

  void set_max(const T& max) {
    assert(m_min <= max);
    m_max = max;
    m_span = m_max;
    m_span -= m_min;
  }

  T span(void) const { return m_span; }

  void set(const T& min, const T& max) {
    assert(min <= max);
    m_min = min;
    m_max = max;
    m_span = m_max;
    m_span -= m_min;
  }

  /**
   * @brief Determine if a value is within the range [min, max] (boundary points
   * included).
   *
   * @param value The value to test.
   */
  bool is_within(const T& value) const {
    return value >= m_min && value <= m_max;
  }

  void wrap_value(T& value) const {
    while (value > m_max) { value -= m_span; }
    while (value < m_min) { value += m_span; }
  }

  friend std::ostream& operator<<(std::ostream& stream, const range& c_range) {
    stream << c_range.m_min << ":"
       << c_range.m_max;
    return stream;
  }

 private:
  T m_min;
  T m_max;
  T m_span;
};

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_RANGE_HPP_ */
