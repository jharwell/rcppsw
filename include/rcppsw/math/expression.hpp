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
#include <vector>
#include <cstddef>
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A base class for easy swapping/manipulating of mathematical expressions.
 */
template<typename T>
class expression {
 public:
  explicit expression(size_t n_vars) :
      m_vars(n_vars) {}

  /**
   * @brief Get the last value calculated
   */
  T last(void) { return m_last; }

  /**
   * @brief Calculate the result of the expression over the variables.
   *
   * @return The new result.
   */
  virtual T calculate(void) = 0;

  /**
   * @brief Update the variable values in the expression and calculate the new
   * value over the updated variables.
   *
   * @param vars The new variables.
   *
   * @return \ref status_t.
   */
  status_t update(const std::vector<T>& vars) {
    FPC_CHECK(ERROR, vars.size() == m_vars.size);
    m_vars = vars;
    m_last = calculate();
    return OK;
  }

 protected:
  std::vector<T>& vars(void) const { return m_vars; }

 private:
               T m_last;
  std::vector<T> m_vars;
};

NS_END(rcppsw, math);

#endif /* INCLUDE_RCPPSW_MATH_EXPRESSION_HPP_ */
