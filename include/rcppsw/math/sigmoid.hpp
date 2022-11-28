/**
 * \file sigmoid.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/math/config/sigmoid_config.hpp"
#include "rcppsw/math/expression.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * \class sigmoid
 * \ingroup math
 *
 * \brief Encapsulates base aspects common to all sigmoid functions; does not
 * calculate anything itself, as derived sigmoids each have different input
 * parameter requirements to calculate the value of the function at a point in
 * space.
 */
class sigmoid : public expression<double> {
 public:
  sigmoid(void) = default;

  /**
   * \brief Construct the sigmoid using parameters.
   */
  explicit sigmoid(const config::sigmoid_config* const config)
      : sigmoid{ config->reactivity, config->offset, config->gamma } {}

  /**
   * \brief Construct the sigmoid by passing each parameter explicitly. Note
   * that they are all of the same type, and therefore ordering is important.
   */
  sigmoid(double reactivity, double offset, double gamma)
      : m_reactivity(reactivity), m_offset(offset), m_gamma(gamma) {}

  /**
   * \brief Initialize the sigmoid after construction. Needed if the sigmoid is
   * just one of many functions a class may use during its internal operations,
   * and the selection must be performed after construction of the enclosing class.
   */
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
  /* clang-format off */
  double m_reactivity{0.0};
  double m_offset{0.0};
  double m_gamma{0.0};
  /* clang-format on */
};

NS_END(math, rcppsw);

