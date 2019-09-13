/**
 * @file rng.hpp
 *
 * @copyright 2019 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_MATH_RNG_HPP_
#define INCLUDE_RCPPSW_MATH_RNG_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"
#include "rcppsw/math/range.hpp"
#include "rcppsw/patterns/pimpl/impl_ptr.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class rng
 * @ingroup rcppsw math
 *
 * @brief Random number generator class using the PIMPL pattern in order to not
 * include <random> in the header file.
 */
class rng : public patterns::pimpl::impl_ptr<rng>::unique {
 public:
  explicit rng(uint seed);
  ~rng(void);

  uint seed(void) const { return m_seed; }
  void seed(uint seed) { m_seed = seed; }

  double uniform(double lb, double ub);
  double uniform(const ranged& c_range) {
    return uniform(c_range.lb(), c_range.ub());
  }

  uint uniform(uint lb, uint ub);
  uint uniform(const rangeu& c_range) {
    return uniform(c_range.lb(), c_range.ub());
  }

  int uniform(int lb, int ub);
  int uniform(const rangei& c_range) {
    return uniform(c_range.lb(), c_range.ub());
  }

  double gaussian(double mean, double std_dev);

  /* clang-format off */
  uint m_seed;
  /* clang-format on */
};

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_RNG_HPP_ */
