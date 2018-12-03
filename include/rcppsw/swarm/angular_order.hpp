/**
 * @file angular_order.hpp
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

#ifndef INCLUDE_RCPPSW_SWARM_ANGULAR_ORDER_HPP_
#define INCLUDE_RCPPSW_SWARM_ANGULAR_ORDER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <algorithm>
#include <limits>

#include "rcppsw/common/common.hpp"
#include "rcppsw/math/radians.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, swarm);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class angular_order
 * @ingroup swarm
 *
 * @brief Calculates the angular order within a swarm for a given instant. From
 * Turgut2008.
 */
class angular_order {
 public:
  double operator()(const std::vector<math::radians>& headings) {
    double y = 0.0;
    std::for_each(headings.begin(),
                  headings.end(),
                  [&](const auto& r) {
                    y += std::sin(r.value());
                  });

    double x = 0.0;
    std::for_each(headings.begin(),
                  headings.end(),
                  [&](const auto& r) {
                    x += std::cos(r.value());
                  });

    return std::fabs(std::atan2(y, x)) / headings.size();
  }
};

NS_END(swarm, rcppsw);

#endif /* INCLUDE_RCPPSW_SWARM_ANGULAR_ORDER_HPP_ */
