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
namespace rcppsw::math {

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
 /**
   * \brief Initialize the expression with an initial value.
   */
  explicit expression(const T& last) : m_last(last) {}
  virtual ~expression(void) = default;

  expression(const expression&) = default;
  auto operator=(const expression&) -> expression& = default;

  /**
   * \brief Get the last value calculated.
   */
  auto v(void) -> T const { return m_last; }

  /**
   * \brief Evaluate a calculation and set a new value.
   */
  auto eval(const T& val) -> T { return m_last = val; }

  /**
   * @brief Reset the expression to 0. Requires \tparam T to be constructible
   * with an argument of 0.
   */
  auto reset(void) -> void { m_last = T{ 0 }; }

  /**
   * @brief Compare two expressions.
   */
  auto operator<=>(const expression& other) const {
    return v() <=> other.v();
  }

 private:
  /* clang-format off */
  T m_last{};
  /* clang-format on */
};

} /* namespace math::rcppsw */
