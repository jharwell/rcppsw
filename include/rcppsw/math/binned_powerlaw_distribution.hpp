/**
 * @file binned_powerlaw_distribution.hpp
 * @ingroup math
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

#ifndef INCLUDE_RCPPSW_MATH_BINNED_POWERLAW_DISTRIBUTION_HPP_
#define INCLUDE_RCPPSW_MATH_BINNED_POWERLAW_DISTRIBUTION_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/math/powerlaw_distribution.hpp"
#include "rcppsw/math/rng.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class binned_powerlaw_distribution
 * @ingroup math
 *
 * @brief A power law distribution (duh) of x^pwr where x is in [lb,
 * ub], where the outputs are rounded to the nearest power of pwr. For example,
 * instead of sampling and getting 3.78, with pwr=2 you would get 4.
 */
class binned_powerlaw_distribution : public powerlaw_distribution {
 public:
  /**
   * @brief Initialize distribution.
   *
   * @param lb Lower bound for distribution. Assumed to be a multiple of pwr.
   * @param ub Upper bound for distribution. Assumed to be a multiple of pwr.
   * @param pwr Power for distribution.
   */
  binned_powerlaw_distribution(uint lb, uint ub, uint pwr)
      : powerlaw_distribution(lb, ub, pwr) {}

  double operator()(rng* rng) {
    uint sample = static_cast<uint>(powerlaw_distribution::operator()(rng));
    return std::pow(pwr(), std::ceil(std::log(sample) / std::log(pwr())));
  }
};

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_BINNED_POWERLAW_DISTRIBUTION_HPP_ */
