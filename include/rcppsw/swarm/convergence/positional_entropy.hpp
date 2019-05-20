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
#include <memory>

#include "rcppsw/common/common.hpp"
#include "rcppsw/algorithm/clustering/entropy.hpp"
#include "rcppsw/math/vector2.hpp"
#include "rcppsw/swarm/convergence/convergence_measure.hpp"
#include "rcppsw/er/client.hpp"
#include "rcppsw/swarm/convergence/config/positional_entropy_config.hpp"

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
 * @ingroup rcppsw swarm convergence
 *
 * @brief Calculate the positional entropy of the swarm, using the methods
 * outlined in Balch2000 and Turgut2008.
 */
class positional_entropy final : public convergence_measure,
                           public algclust::entropy_balch2000<math::vector2d> {
 public:
  positional_entropy(double epsilon,
                     std::unique_ptr<algclust::detail::entropy_impl<math::vector2d>> impl,
                     const config::positional_entropy_config* const config)
      : convergence_measure(epsilon),
        entropy_balch2000(std::move(impl),
                          config->horizon,
                          config->horizon_delta) {}

  using entropy_balch2000::entropy_balch2000;

  /**
   * @brief Calculate the positional entropy in 2D space of a swarm.
   */
  bool operator()(const std::vector<math::vector2d>& data) {
    auto dist_func = [](const math::vector2d& v1,
                        const math::vector2d& v2) {
      return (v1 - v2).length();
    };
    update_raw(run(data, dist_func));
    set_norm(math::normalize(raw_min(), raw_max(), raw()));
    return update_convergence_state();
  }
};

NS_END(convergence, swarm, rcppsw);

#endif /* INCLUDE_RCPPSW_SWARM_CONVERGENCE_POSITIONAL_ENTROPY_HPP_ */
