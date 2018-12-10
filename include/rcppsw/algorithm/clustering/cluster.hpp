/**
 * @file cluster.hpp
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
#ifndef INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_CLUSTER_HPP_
#define INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_CLUSTER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <type_traits>
#include <limits>
#include <cmath>

#include "rcppsw/common/common.hpp"
#include "rcppsw/algorithm/clustering/membership_policy.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, algorithm, clustering);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class nc_cluster
 * @ingroup algorithm clustering
 *
 * @brief A policy based cluster for a Nearest Centroid (NC) cluster during the
 * execution of the NC clustering algorithm.
*/
template <typename T, typename Policy>
class nc_cluster {
 public:
  nc_cluster(uint id,
             const std::vector<T>& data,
             membership_type<Policy>* const membership)
      : mc_data(data),
        m_id(id),
        m_membership(membership),
        m_center(mc_data[m_id]) {}

  nc_cluster& operator=(const nc_cluster&) = delete;

  void add_point(size_t idx) { (*m_membership)[idx] = m_id; }

  /*
   * Determine if the cluster has converged, by checking if the center of the
   * cluster has changed.
   */
  template<typename U = T,
           typename = typename std::enable_if<!std::is_floating_point<U>::value>::type>
  __rcsw_pure bool converged(void) const { return (m_prev_center == m_center); }

  template<typename U = T,
           typename = typename std::enable_if<std::is_floating_point<U>::value>::type>
  __rcsw_pure bool converged(int = 0) const {
    return std::fabs(m_prev_center - m_center) <= std::numeric_limits<U>::epsilon();
  }

  /**
   * @brief Update the center (mean) of the points in the cluster after an
   * iteration is finished.
   **/
  void update_center(void) {
    T accum{};
    m_prev_center = m_center;

    uint n_points = 0;
    for (size_t i = 0; i < mc_data.size(); ++i) {
      if ((*m_membership)[i] == m_id) {
        accum += mc_data[i];
        ++n_points;
      }
    } /* for(i..) */

    accum /= n_points;
    m_center = accum;
  }

  const T& center(void) const { return m_center; }

 private:
  // clang-format off
  const std::vector<T>&          mc_data;

  size_t                         m_id;
  membership_type<Policy>* const m_membership;
  T                              m_center;
  T                              m_prev_center{};
  // clang-format on
};

/**
 * @class eh_cluster
 * @ingroup algorithm clustering
 *
 * @brief A policy based cluster for an Event Horizon (EH) cluster during the
 * execution of the EH clustering algorithm.
*/
template <typename T, typename Policy>
class eh_cluster {
 public:
  eh_cluster(uint id,
             const std::vector<T>& data,
             membership_type<Policy>* const membership)
      : mc_data(data),
        m_id(id),
        m_membership(membership),
        m_center(mc_data[m_id]) {}

  eh_cluster& operator=(const eh_cluster&) = delete;

  void add_point(size_t point_idx) {
    (*m_membership)[m_id].insert(point_idx);
  }

  /*
   * Determine if the cluster has converged, by checking if the center of the
   * cluster has changed.
   */
  bool converged(void) const { return m_prev_size == size(); }
  size_t size(void) const { return m_membership->size(); }

  /**
   * @brief Update the size of the cluster after an iteration has finished.
   **/
  void update_size(void) { m_prev_size = size(); }

  const T& center(void) const { return m_center; }

 private:
  // clang-format off
  const std::vector<T>&          mc_data;

  size_t                         m_id;
  membership_type<Policy>* const m_membership;
  T                              m_center;
  size_t                         m_prev_size{0};
  // clang-format on
};

/*******************************************************************************
 * SFINAE Templates
 ******************************************************************************/
namespace cluster {

template<typename T, typename Policy, typename Enable = void>
struct mapping;

template<typename T, typename Policy>
struct mapping<T, Policy, policy::is_nc<Policy>> {
  using type = nc_cluster<T, Policy>;
};

template<typename T, typename Policy>
struct mapping<T, Policy, policy::is_eh<Policy>> {
  using type = eh_cluster<T, Policy>;
};
}  // namespace cluster

NS_END(clustering, algorithm, rcppsw);

#endif /* INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_CLUSTER_HPP_ */
