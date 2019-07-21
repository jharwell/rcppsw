/**
 * @file ema.hpp
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

#ifndef INCLUDE_RCPPSW_MATH_EMA_HPP_
#define INCLUDE_RCPPSW_MATH_EMA_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include "rcppsw/math/expression.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class ema
 * @ingroup rcppsw math
 *
 * @brief Calculates an Exponential Moving Average of SOMETHING.
 *
 * Depends on:
 *
 * - Alpha: How much weight to give the past estimate, and how much to give the
 *   new measurement?
 */
template <class T>
class ema final : public expression<T> {
 public:
  using expression<T>::v;
  using expression<T>::eval;

  static ema abs(const ema& e) { return ema(e.alpha(), std::fabs(e.v())); }
  explicit ema(T alpha) : m_alpha(alpha) {}
  ema(T alpha, T result) : expression<T>(result), m_alpha(alpha) {}

  double alpha(void) const { return m_alpha; }

  double calc(double measure) { return operator()(measure); }

  double operator()(double measure) {
    return eval((1 - m_alpha) * v() + m_alpha * measure);
  }

  ema& calc(const ema& measure) {
    this->calc(measure.v());
    return *this;
  }
  ema& operator()(const ema& measure) {
    return eval((1 - m_alpha) * v() + m_alpha * measure.v());
    return *this;
  }

  ema operator+(const ema& other) const {
    ema r(this->alpha());
    r.eval(this->v() + other.v());
    return r;
  }
  ema operator-(const ema& other) const {
    ema r(this->alpha());
    r.eval(this->v() - other.v());
    return r;
  }
  ema operator+=(const ema& other) {
    this->eval(this->v() + other.v());
    return *this;
  }

  ema operator/(const ema& other) const {
    ema r(this->alpha());
    r.eval(this->v() / other.v());
    return r;
  }

 private:
  double m_alpha;
};

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
template <class T>
ema<T> operator-(const ema<T>& lhs, double d) {
  ema<T> r(lhs.alpha());
  r.eval(lhs.v() - d);
  return r;
}

template <class T>
ema<T> operator-(double d, const ema<T>& rhs) {
  ema<T> r(rhs.alpha());
  r.eval(d - rhs.v());
  return r;
}

template <class T>
ema<T> operator*(const ema<T>& lhs, double d) {
  ema<T> r(lhs.alpha());
  r.eval(lhs.v() * d);
  return r;
}

template <class T>
ema<T> operator*(double d, const ema<T>& rhs) {
  ema<T> r(rhs.alpha());
  r.eval(rhs.v() * d);
  return r;
}

template <class T>
ema<T> operator/(double d, const ema<T>& rhs) {
  ema<T> r(rhs.alpha());
  r.eval(rhs.v() / d);
  return r;
}

template <class T>
ema<T> operator/(const ema<T>& lhs, double d) {
  ema<T> r(lhs.alpha());
  r.eval(lhs.v() / d);
  return r;
}

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_EMA_HPP_ */
