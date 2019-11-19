/**
 * \file powerlaw_distribution.hpp
 * \ingroup math
 *
 * \copyright 2018 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_MATH_POWERLAW_DISTRIBUTION_HPP_
#define INCLUDE_RCPPSW_MATH_POWERLAW_DISTRIBUTION_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"
#include "rcppsw/math/rng.hpp"

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
  powerlaw_distribution(uint lb, uint ub, uint pwr)
      : m_lb(lb), m_ub(ub), m_pwr(pwr) {}
  virtual ~powerlaw_distribution(void) = default;

  double operator()(rng* rng) {
    double y = rng->uniform(0.0, 1.0);
    double tmp = (std::pow(m_ub, m_pwr + 1) - std::pow(m_lb, m_pwr + 1)) * y +
                 std::pow(m_lb, m_pwr + 1);
    return std::pow(tmp, 1.0 / (m_pwr + 1));
  }
  uint pwr(void) const { return m_pwr; }
  uint lb(void) const { return m_lb; }
  uint ub(void) const { return m_ub; }

 private:
  /* clang-format off */
  uint m_lb;
  uint m_ub;
  uint m_pwr;
  /* clang-format on */
};
NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_POWERLAW_DISTRIBUTION_HPP_ */
