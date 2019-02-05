/**
 * @file clustering_impl.hpp
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

#ifndef INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_CLUSTERING_IMPL_HPP_
#define INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_CLUSTERING_IMPL_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <functional>

#include "rcppsw/common/common.hpp"
#include "rcppsw/algorithm/clustering/cluster.hpp"
#include "rcppsw/algorithm/clustering/membership_policy.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, algorithm, clustering, detail);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template<typename T, typename Policy>
class clustering_impl {
 public:
  using cluster_type = typename cluster::mapping<T, Policy>::type;
  using cluster_vector = std::vector<cluster_type>;
  using dist_calc_ftype = std::function<double(const T&, const T&)>;

  virtual ~clustering_impl(void) = default;

   /**
   * @brief Determine if the clusters have converged and the algorithm should be
   * terminated.
   *
   * @return \c TRUE if the algorithm has converged, \c FALSE otherwise.
   */
  virtual bool converged(const cluster_vector& clusters) const = 0;

  /*
   * @brief Perform one iteration the clustering algorithm.
   */
  virtual void iterate(const std::vector<T>& data,
                       const dist_calc_ftype& dist_func,
                       cluster_vector* const clusters) = 0;

  /*
   * @brief Update clusters (in some algorithm-specific way) after an iteration.
   */
  virtual void post_iter_update(cluster_vector* const clusters) = 0;

  /**
   * @brief Perform algorithm-specific clustering initialization (memory
   * localization, etc.).
   */
  virtual void initialize(std::vector<T>* const data,
                          membership_type<Policy>* const membership) = 0;
};

NS_END(detail, clustering, algorithm, rcppsw);

#endif /* INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_CLUSTERING_IMPL_HPP_ */
