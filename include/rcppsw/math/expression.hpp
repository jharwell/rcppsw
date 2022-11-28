/**
 * \file expression.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class expression
 * \ingroup math
 *
 * \brief A base class for easy swapping/manipulating of mathematical
 * expressions.
 */
template <class T>
class expression {
 public:
  expression(void) = default;
  explicit expression(const T& last) : m_last(last) {}
  virtual ~expression(void) = default;

  expression(const expression&) = default;
  expression& operator=(const expression&) = default;

  /**
   * \brief Get the last value calculated.
   */
  T v(void) const { return m_last; }

  /**
   * \brief Evaluate a calculation and set a new value.
   */
  T eval(const T& val) { return m_last = val; }

  void reset(void) { m_last = T{ 0 }; }

  bool operator==(const expression& other) const {
    return this->v() == other.v();
  }
  bool operator>(const expression& other) const { return this->v() > other.v(); }
  bool operator<(const expression& other) const { return this->v() < other.v(); }

 private:
  /* clang-format off */
  T m_last{};
  /* clang-format on */
};

NS_END(rcppsw, math);
