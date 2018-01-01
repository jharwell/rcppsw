/**
 * @file expression.hpp
 * @ingroup math
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
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class expression
 *
 * @brief A base class for easy swapping/manipulating of mathematical
 * expressions.
 */
template <typename T>
class expression {
 public:
  expression(void) : m_last() {}

  /**
   * @brief Get the last value calculated.
   */
  T last_result(void) const { return m_last; }

  /**
   * @brief Calculate a new value.
   */
  T set_result(T val) {
    m_last = val;
    return m_last;
  }

  bool operator==(const expression& other) const {
    return this->last_result() == other.last_result();
  }
  bool operator>(const expression& other) const {
    return this->last_result() > other.last_result();
  }
  bool operator<(const expression& other) const {
    return this->last_result() < other.last_result();
  }

 private:
  T m_last;
};

NS_END(rcppsw, math);

#endif /* INCLUDE_RCPPSW_MATH_EXPRESSION_HPP_ */
