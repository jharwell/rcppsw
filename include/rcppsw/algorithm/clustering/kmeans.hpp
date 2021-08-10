/**
 * \file kmeans.hpp
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
#ifndef INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_KMEANS_HPP_
#define INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_KMEANS_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <vector>
#include <random>
#include <functional>
#include <memory>
#include <utility>

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/er/client.hpp"
#include "rcppsw/algorithm/clustering/cluster.hpp"
#include "rcsw/utils/time_utils.h"
#include "rcppsw/algorithm/clustering/kmeans_omp.hpp"
#include "rcppsw/algorithm/clustering/base_clustering_impl.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, algorithm, clustering);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class kmeans
 * \ingroup algorithm clustering
 *
 * \brief Wrapper class for performing kmeans clustering.
 *
 * \tparam T The type of the data that is being clustered. It must support the
 *           following operations: +=, /=, = .
 */
template <typename T>
class kmeans : public er::client<kmeans<T>> {
 public:
  using cluster_vector = typename base_clustering_impl<
   T,
   policy::NC>::cluster_vector;
  using dist_calc_ftype = typename base_clustering_impl<
    T,
    policy::NC>::dist_calc_ftype;

  /**
   * \param data_in Vector of data to cluster.
   * \param impl The method and policy for clustering.
   * \param k The # of clusters.
   * \param max_iter Maximum # of iterations to perform.
   */
  kmeans(const std::vector<T>& data_in,
         std::unique_ptr<base_clustering_impl<T,
         policy::NC>
         > impl,
         size_t k,
         size_t max_iter)
      : ER_CLIENT_INIT("rcppsw.algorithm.clustering.kmeans"),
        mc_max_iter(max_iter),
        mc_k(k),
        m_data_in(data_in),
        m_data(data_in.size()),
        m_membership(data_in.size()),
        m_clusters(),
        m_impl(std::move(impl)) {}

  /**
   * \brief Perform clustering. First the clustering_impl::initialize() method
   * is called. Then, the clustering algorithm is iterated until one of the
   * following is true:
   *
   * - The maximum # of iterations has been reached.
   * - cluster_impl::converged() returns \c TRUE (checked after each iteration).
   *
   * \return A vector where the index corresponds to the index of the data point
   * in the input data, and the value corresponds to the cluster to which the
   * data point belongs.
   */
  membership_type<policy::NC> run(const dist_calc_ftype& dist_func) {
    ER_INFO("Initialize");
    /*
     * First, initialize the buffer that each OpenMP thread will be using. This
     * needs to be done BEFORE copying our data into it, in order to maximize
     * per-thread memory locality.
     */
    m_impl->initialize(&m_data, &m_membership);
    m_data = m_data_in;

    /*
     * Once per-thread memory is initialized, initialize the clusters based on
     * the now-copied data.
     */
    m_clusters = clusters_init();

    ER_INFO("Begin n_clusters=%zu, n_datapoints=%zu",
            m_clusters.size(),
            m_data.size());
    double end = 0.0;
    double start = time_monotonic_sec();

    for (size_t i = 0; i < mc_max_iter; ++i) {
      double iter_start = time_monotonic_sec();
      m_impl->iterate(m_data, dist_func, &m_clusters);
      end = time_monotonic_sec();
      if (m_impl->converged(m_clusters)) {
        ER_INFO("Converged on iter%zu", i);
        break;
      }
      m_impl->post_iter_update(&m_clusters);
      ER_INFO("Iter%zu: time=%.8fms", i, (end - iter_start) * 1000);
    } /* for(i..) */

    ER_INFO("Finish: time=%0.04fs", end - start);
    return m_membership;
  } /* run() */

 private:
  using cluster_type = typename base_clustering_impl<
   T,
   policy::NC>::cluster_type;
  /**
   * \brief Method for derived classes to use to initialize centroids in
   * whatever way they choose, and perform first-touch allocation if they want
   * to.
   */
  cluster_vector clusters_init(void) {
    cluster_vector clusters;
    for (size_t i = 0; i < mc_k; ++i) {
      clusters.emplace_back(cluster_type(i, m_data, m_membership));
    } /* for(i..) */
    return clusters;
  }

  /* clang-format off */
  const size_t                                              mc_max_iter;
  const size_t                                              mc_k;

  std::vector<T>                                            m_data_in;
  std::vector<T>                                            m_data;
  membership_type<policy::NC>                               m_membership;
  cluster_vector                                            m_clusters;
  std::unique_ptr<base_clustering_impl<T,
                                               policy::NC>> m_impl;
  /* clang-format on */
};

NS_END(clustering, algorithm, rcppsw);

#endif /* INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_KMEANS_HPP_ */
