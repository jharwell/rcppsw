/**
 * \file entropy.hpp
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
#ifndef INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_ENTROPY_HPP_
#define INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_ENTROPY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <limits>
#include <map>

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/er/client.hpp"
#include "rcppsw/algorithm/clustering/cluster.hpp"
#include "rcsw/utils/time_utils.h"
#include "rcppsw/algorithm/clustering/eh_clustering_impl.hpp"
#include "rcppsw/math/range.hpp"
#include "rcppsw/math/ientropy.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, algorithm, clustering);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \ingroup algorithm clustering
 *
 * \brief Wrapper class for performing clustering using the event horizon model
 * in which all points within a specified distance (horizon) to a point i are
 * included in its cluster. Implements the following algorithm from Balch2000:
 *
 * For each value of horizon:
 *
 * 1. Initialize N clusters, one for each datapoint in the input vector.
 *
 * 2. For each cluster c_i centered at point p_i, check every point p_j (i !=
 *    j), and if distance(p_i, p_j) <= horizon, add p_j to c_i.
 *
 * 3. Discard redundant clusters.
 *
 * 4. Calculate entropy of remaining non-redundant clusters. Entropy is
 *    accumulated across all values of horizon.
 *
 * \tparam T The type of the data that is being clustered. It must support the
 *           following operations: +=, /=, = .
 */
template <typename T>
class entropy_balch2000 : public er::client<entropy_balch2000<T>> {
 public:
  using cluster_vector = typename base_clustering_impl<
   T,
   policy::EH>::cluster_vector;
  using dist_calc_ftype = typename base_clustering_impl<
    T,
    policy::EH>::dist_calc_ftype;
  using membership_map = std::map<double,
                                  membership_type<policy::EH>>;
  using membership_vector = std::vector<membership_type<policy::EH>>;

  /**
   * \param impl The method and policy for clustering.
   * \param horizon The min and maximum bounds of distances to use when
   *                computing clusters.
   * \param horizon_delta The step size for moving between the min and max
   *                      distance bounds; defines # of overall iterations.
   */
  entropy_balch2000(std::unique_ptr<eh_clustering_impl<T>> impl,
                    const math::ranged& horizon,
                    double horizon_delta)
      : ER_CLIENT_INIT("rcppsw.algorithm.clustering.entropy_balch2000"),
        mc_horizon(horizon),
        mc_horizon_delta(horizon_delta),
        m_impl(std::move(impl)) {}

  /**
   * \brief Perform entropy based clustering, returning the accumulated entropy
   * across all horizons.
   */
  double run(const std::vector<T>& data, const dist_calc_ftype& dist_func) {
    ER_INFO("Initialize");
    m_data = data;

    /*
     * You can't use reserve() here, as that just allocates data without
     * initialization, which is needed to mimic initializing membership arrays
     * in the constructor.
     */
    m_membership.assign(m_data.size(),
                        typename decltype(m_membership)::value_type());
    m_membership_cp.assign(m_data.size(),
                           typename decltype(m_membership_cp)::value_type());

    m_impl->initialize(&m_data, &m_membership);
    m_clusters = clusters_init();

    double t_accum = 0.0;
    double e_accum = 0.0;
    double entropy_h_1 = 0.0;
    size_t n_iter = static_cast<size_t>((mc_horizon.span() / mc_horizon_delta)) + 1;

    ER_INFO("Begin n_datapoints=%zu,horizon=%s,delta=%f,n_iter=%zu",
            m_clusters.size(),
            mc_horizon.to_str().c_str(),
            mc_horizon_delta,
            n_iter);

    /* iterate through all horizons */
    for (size_t i = 0; i < n_iter; ++i) {
      double start = time_monotonic_sec();
      double horizon = mc_horizon.lb() + i* mc_horizon_delta;
      double entropy_h = balch2000_iter(dist_func, horizon);
      double end = time_monotonic_sec();

      if (std::fabs(entropy_h - entropy_h_1) <= rmath::kDOUBLE_EPSILON) {
        ER_WARN("Redundant entropy %f: horizon=%f", entropy_h, horizon);
      } else {
        e_accum += entropy_h;
      }
      ER_DEBUG("Horizon=%f: time=%.8fms,entropy=%f",
              horizon,
              (end - start) * 1000,
              entropy_h);
      entropy_h_1 = entropy_h;
      t_accum += end - start;
    } /* for(i..) */
    ER_INFO("Finish: time=%0.04fs,entropy=%f", t_accum, e_accum);
    return e_accum;
  } /* run() */

 private:
  using cluster_type = typename base_clustering_impl<
   T,
   policy::EH>::cluster_type;
  /**
   * \brief Method for derived classes to use to initialize centroids in
   * whatever way they choose, and perform first-touch allocation if they want
   * to.
   */
  cluster_vector clusters_init(void) {
    cluster_vector clusters;
    for (size_t i = 0; i < m_data.size(); ++i) {
      clusters.emplace_back(cluster_type(i, m_data, m_membership));
    } /* for(i..) */
    return clusters;
  }

  double balch2000_iter(const dist_calc_ftype& dist_func,
                        double horizon) {
    m_impl->horizon(horizon);
    m_impl->iterate(m_data, dist_func, &m_clusters);
    m_impl->post_iter_update(&m_clusters);

    /*
     * Make a copy to prevent permanently deleting clusters that may be
     * duplicates for THIS horizon, but may not for a future horizon value.
     */
    m_membership_cp = m_membership;
    balch2000_rm_dup_clusters(&m_membership_cp);
    std::vector<double> proportions(m_membership_cp.size());
    for (size_t i = 0; i < proportions.size(); ++i) {
      double prop = static_cast<double>(m_membership_cp[i].size()) /
                    m_data.size();
      ER_TRACE("cluster@%zu size=%zu, prop=%f",
               i,
               m_membership_cp[i].size(),
               prop);
      proportions[i] = prop;
    } /* for(i..) */
    return math::ientropy()(proportions);
  }

  void balch2000_rm_dup_clusters(membership_type<policy::EH>* const clusters) {
    ER_TRACE("Removing duplicate clusters");
    /* for each datapoint/cluster in a given iteration */
    for (size_t i = 0; i < clusters->size(); ++i) {
      ER_TRACE("cluster%zu: n_members=%zu", i, (*clusters)[i].size());
      std::unordered_set<size_t>& cluster_i = (*clusters)[i];
      auto comp = [&](const auto& clust) RCPPSW_PURE {
        /*
         * Duplicates are defined as two of the unordered membership sets
         * containing the same points AND the sets not being in the same index
         * in the vector of results (i.e. not self equality).
         */
        return cluster_i == clust &&
        static_cast<size_t>(&clust - &((*clusters)[0])) != i;
      };
      auto rm = std::remove_if(clusters->begin(), clusters->end(), comp);
      clusters->erase(rm, clusters->end());
    } /* for(i..) */
  }

  /* clang-format off */
  const math::ranged                     mc_horizon;
  const double                           mc_horizon_delta;

  std::vector<T>                         m_data{};
  membership_type<policy::EH>            m_membership{};

  /**
   * \brief This is a member variable, rather than a local variable in
   * \ref balch2000_iter, in order to reduce dynamic memory management overhead.
   */

  membership_type<policy::EH>            m_membership_cp{};
  cluster_vector                         m_clusters{};
  std::unique_ptr<eh_clustering_impl<T>> m_impl;
  /* clang-format on */
};

NS_END(clustering, algorithm, rcppsw);

#endif /* INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_ENTROPY_HPP_ */
