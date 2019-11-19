/**
 * @file ientropy.hpp
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

#ifndef INCLUDE_RCPPSW_MATH_IENTROPY_HPP_
#define INCLUDE_RCPPSW_MATH_IENTROPY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <vector>

#include "rcppsw/common/common.hpp"
#include "rcppsw/math/expression.hpp"
#include "rcppsw/math/radians.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class ientropy
 * @ingroup math
 *
 * @brief Calculates the informational entropy of a cluster (Shannon's
 * definition).
 *
 * Uses the formula:
 *
 * H(S) = - SUM( p_i * log2(p_i)) over all i in m.
 */
class ientropy : public math::expression<double> {
 public:
  /**
   * @brief Calculate the informational entropy.
   *
   * @param groups A vector of the proportional representation of each group
   *               within the cluster. Should sum to 1, though this is not
   *               checked.
   */
  double operator()(const std::vector<double>& groups) {
    double entropy = 0.0;
    std::for_each(groups.begin(), groups.end(), [&](const auto& prop) {
      entropy += prop * std::log2(prop);
    });
    return eval(-entropy);
  }
};

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_IENTROPY_HPP_ */
