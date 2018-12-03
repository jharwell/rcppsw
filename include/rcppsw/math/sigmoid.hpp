/**
 * @file sigmoid.hpp
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

#ifndef INCLUDE_RCPPSW_MATH_SIGMOID_HPP_
#define INCLUDE_RCPPSW_MATH_SIGMOID_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>

#include "rcppsw/math/sigmoid_params.hpp"
#include "rcppsw/math/expression.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, math);


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class sigmoid : public expression<double> {
 public:
  sigmoid(void) = default;
  explicit sigmoid(const sigmoid_params* const params) :
      sigmoid{params->reactivity, params->offset, params->gamma} {}

  sigmoid(double reactivity, double offset, double gamma) :
      m_reactivity(reactivity),
      m_offset(offset),
      m_gamma(gamma) {}

  void init(double reactivity, double offset, double gamma) {
    m_reactivity = reactivity;
    m_offset = offset;
    m_gamma = gamma;
  }

 protected:
  double reactivity(void) const { return m_reactivity; }
  double offset(void) const { return m_offset; }
  double gamma(void) const { return m_gamma; }

 private:
  // clang-format off
  double m_reactivity{0.0};
  double m_offset{0.0};
  double m_gamma{0.0};
  // clang-format on
};

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_SIGMOID_HPP_ */
