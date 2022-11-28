/**
 * \file powerlaw_distribution.hpp
 * \ingroup math
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/math/rng.hpp"
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class powerlaw_distribution
 * \ingroup math
 *
 * \brief Represents a power law distribution (duh) of x^pwr where x is in [lb,
 * ub]. Constructed from a uniform distribution on [0, 1].
 */
class powerlaw_distribution {
 public:
  /**
   * \brief Initialize distribution.
   *
   * \param lb Lower bound for distribution. Assumed to be a multiple of pwr.
   * \param ub Upper bound for distribution. Assumed to be a multiple of pwr.
   * \param pwr Power for distribution.
   */
  powerlaw_distribution(size_t lb, size_t ub, size_t pwr)
      : m_lb(lb), m_ub(ub), m_pwr(pwr) {}
  virtual ~powerlaw_distribution(void) = default;

  double operator()(rng* rng) {
    double v = rng->uniform(0.0, 1.0);
    double pmax = std::pow(m_ub, m_pwr + 1);
    double pmin = std::pow(m_lb, m_pwr + 1);
    double tmp = pmin + (pmax - pmin) * v;
    return std::pow(tmp, 1.0 / (m_pwr + 1));
  }
  size_t pwr(void) const { return m_pwr; }
  size_t lb(void) const { return m_lb; }
  size_t ub(void) const { return m_ub; }

 private:
  /* clang-format off */
  size_t m_lb;
  size_t m_ub;
  size_t m_pwr;
  /* clang-format on */
};
NS_END(math, rcppsw);

