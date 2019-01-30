/**
 * @file positional_entropy.hpp
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

#ifndef INCLUDE_RCPPSW_SWARM_CONVERGENCE_POSITIONAL_ENTROPY_HPP_
#define INCLUDE_RCPPSW_SWARM_CONVERGENCE_POSITIONAL_ENTROPY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <algorithm>

#include "rcppsw/common/common.hpp"
#include "rcppsw/algorithm/clustering/entropy.hpp"
#include "rcppsw/math/vector2.hpp"
#include "rcppsw/math/expression.hpp"
#include "rcppsw/er/client.hpp"
#include "rcppsw/swarm/convergence/positional_entropy_params.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, swarm, convergence);
namespace algclust = algorithm::clustering;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class positional_entropy
 * @ingroup swarm
 *
 * @brief Calculate the positional entropy of the swarm, using the methods
 * outlined in Balch2000 and Turgut2008.
 */
class positional_entropy : public math::expression<double>,
                           public algclust::entropy_balch2000<math::vector2d> {
 public:
  positional_entropy(const std::vector<math::vector2d>& data,
                     std::unique_ptr<algclust::detail::entropy_impl<math::vector2d>> impl,
                     const struct positional_entropy_params* const params)
      : entropy_balch2000(data,
                          std::move(impl),
                          params->horizon,
                          params->horizon_delta) {}

  using entropy_balch2000::entropy_balch2000;

  /**
   * @brief Calculate the positional entropy in 2D space of a swarm.
   */
  double operator()(void) {
    return set_result(run([](const math::vector2d& v1,
                             const math::vector2d& v2) {
                            return (v1 - v2).length();
                          }));
  }
};

NS_END(convergence, swarm, rcppsw);

#endif /* INCLUDE_RCPPSW_SWARM_CONVERGENCE_POSITIONAL_ENTROPY_HPP_ */
