/**
 * @file expression.hpp
 *
 * @copyright 2017 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_MATH_EXPRESSION_HPP_
#define INCLUDE_RCPPSW_MATH_EXPRESSION_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class expression
 * @ingroup rcppsw math
 *
 * @brief A base class for easy swapping/manipulating of mathematical
 * expressions.
 */
template <class T>
class expression {
 public:
  expression(void) : m_last() {}
  explicit expression(const T& last) : m_last(last) {}
  virtual ~expression(void) = default;
  expression(const expression&) = default;
  expression& operator=(const expression&) = default;

  /**
   * @brief Get the last value calculated.
   */
  T v(void) const { return m_last; }

  /**
   * @brief Evaluate a calculation and set a new value.
   */
  T eval(const T& val) { return m_last = val; }

  void reset(void) { m_last = T{0}; }

  bool operator==(const expression& other) const {
    return this->v() == other.v();
  }
  bool operator>(const expression& other) const {
    return this->v() > other.v();
  }
  bool operator<(const expression& other) const {
    return this->v() < other.v();
  }

 private:
  /* clang-format off */
  T m_last;
  /* clang-format on */
};

NS_END(rcppsw, math);

#endif /* INCLUDE_RCPPSW_MATH_EXPRESSION_HPP_ */
