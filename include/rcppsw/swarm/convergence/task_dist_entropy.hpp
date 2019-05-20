/**
 * @file task_dist_entropy.hpp
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

#ifndef INCLUDE_RCPPSW_SWARM_CONVERGENCE_TASK_DIST_ENTROPY_HPP_
#define INCLUDE_RCPPSW_SWARM_CONVERGENCE_TASK_DIST_ENTROPY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <algorithm>

#include "rcppsw/common/common.hpp"
#include "rcppsw/math/ientropy.hpp"
#include "rcppsw/swarm/convergence/convergence_measure.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, swarm, convergence);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class task_dist_entropy
 * @ingroup rcppsw swarm convergence
 *
 * @brief Calculate the task_dist entropy of the swarm, using the methods
 * outlined in Balch2000 and Turgut2008.
 */
class task_dist_entropy final : public convergence_measure {
 public:
  explicit task_dist_entropy(double epsilon) : convergence_measure(epsilon) {}


  /**
   * @brief Calculate the task distribution entropy of the swarm.
   *
   * @param tasks The current task distribution (each task is a unique
   *              non-negative integer).
   */
  bool operator()(const std::vector<int>& tasks) {
    int n_tasks = *std::max_element(tasks.begin(),
                                    tasks.end()) + 1; /* 0-based indexing */

    if (-1 == n_tasks) { /* no robots have active tasks */
      return false;
    }
    /* Count occurences of each task to obtain a discretized distribution */
    std::vector<int> accum(n_tasks);
    for (auto &t : tasks) {
      if (-1 != t) { /* -1 indicates no active task */
        accum[t]++;
      }
    } /* for(&t..) */

    /*
     * Divide the # of occurrencies of each task by the total # of elements in
     * the distribution in order to obtain the proportional representation
     * needed as input into the informational entropy calculation.
     */
    std::vector<double> dist(n_tasks);
    for (size_t i = 0; i < dist.size(); ++i) {
      dist[i] = static_cast<double>(accum[i]) / tasks.size();
    } /* for(i..) */

    update_raw(math::ientropy()(dist));
    set_norm(math::normalize(raw_min(), raw_max(), raw()));
    return update_convergence_state();
  }
};

NS_END(convergence, swarm, rcppsw);

#endif /* INCLUDE_RCPPSW_SWARM_CONVERGENCE_TASK_DIST_ENTROPY_HPP_ */
