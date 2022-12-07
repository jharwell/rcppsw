/**
 * \file ema.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

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
 * \class ema
 * \ingroup math
 *
 * \brief Calculates an Exponential Moving Average of SOMETHING.
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

  explicit ema(double alpha) : m_alpha(alpha) {}
  ema(double alpha, const T& result) : expression<T>(result), m_alpha(alpha) {}

  double alpha(void) const { return m_alpha; }

  T calc(const T& measure) { return operator()(measure); }
  ema& calc(const ema& other) {
    this->calc(other.v());
    return *this;
  }

  T operator()(const T& measure) {
    /*
     * Cast to T because depending on what the type is, we may get floating
     * point -> integer conversion warnings, so be explicit
     */
    return eval(static_cast<T>((1 - m_alpha) * v() + m_alpha * measure));
  }

  ema& operator()(const ema& other) {
    this->eval(other.v());
    return *this;
  }

  ema& operator+=(const ema& other) {
    this->eval(this->v() + other.v());
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

  ema operator/(const ema& other) const {
    ema r(this->alpha());
    r.eval(this->v() / other.v());
    return r;
  }

  template <typename U = T,
            RCPPSW_SFINAE_DECLDEF(!(std::is_floating_point<T>::value))>
  bool operator==(const ema& other) const {
    return this->v() == other.v();
  }

 private:
  /* clang-formatt off */
  double m_alpha;
  /* clang-formatt on */
};

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
template <typename T, RCPPSW_SFINAE_DECLDEF(!(std::is_floating_point<T>::value))>
bool operator==(const T& v, const ema<T>& rhs) {
  return v == rhs.v();
}

template <class T, class U>
ema<T> operator-(const ema<T>& lhs, const U& rhs) {
  ema<T> r(lhs.alpha());
  r.eval(static_cast<T>(lhs.v() - rhs));
  return r;
}

template <class T, class U>
ema<T> operator-(const U& lhs, const ema<T>& rhs) {
  ema<T> r(rhs.alpha());
  r.eval(static_cast<T>(lhs - rhs.v()));
  return r;
}

template <class T, class U>
ema<T> operator*(const ema<T>& lhs, const U& rhs) {
  ema<T> r(lhs.alpha());
  r.eval(lhs.v() * rhs);
  return r;
}

template <class T, class U>
ema<T> operator*(const U& lhs, const ema<T>& rhs) {
  ema<T> r(rhs.alpha());
  r.eval(rhs.v() * lhs);
  return r;
}

template <class T, class U>
ema<T> operator/(const U& lhs, const ema<T>& rhs) {
  ema<T> r(rhs.alpha());
  r.eval(lhs.v() / rhs);
  return r;
}

/* Always want to make sure we do division with doubles */
template <class T>
ema<T> operator/(const ema<T>& lhs, const double& rhs) {
  ema<T> r(lhs.alpha());
  r.eval(lhs.v() / rhs);
  return r;
}

NS_END(math, rcppsw);

