/**
 * \file kmeans_omp.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <omp.h>
#include <vector>
#include <limits>

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/algorithm/clustering/base_clustering_impl.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, algorithm, clustering);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class kmeans_omp
 * \ingroup algorithm clustering
 *
 * \brief Parallel clustering using OpenMP using the Nearest Centroid (NC)
 * membership policy. Suitable for kmeans clustering.
 */
template <typename T>
class kmeans_omp : public base_clustering_impl<T, policy::NC> {
 public:
  using typename base_clustering_impl<T, policy::NC>::dist_calc_ftype;
  using typename base_clustering_impl<T, policy::NC>::cluster_vector;

  explicit kmeans_omp(size_t n_threads)
      : m_n_threads(n_threads) {}

  void initialize(std::vector<T>* const data,
                  membership_type<policy::NC>* const membership) override {
    first_touch_allocation(data, membership);
  }

  RCPPSW_PURE bool converged(const cluster_vector& clusters) const override {
    std::size_t sum = 0;
#pragma omp parallel for num_threads(m_n_threads) reduction(+ : sum)
    for (size_t i = 0; i < clusters.size(); ++i) {
      sum += clusters[i].converged();
    } /* for(i..) */
    return sum == clusters.size();
  }

  void post_iter_update(cluster_vector* const clusters) override {
#pragma omp parallel for num_threads(m_n_threads)
    for (size_t i = 0; i < clusters->size(); ++i) {
      (*clusters)[i].update_center();
    } /* for(i..) */
  }

  void iterate(const std::vector<T>& data,
                  const dist_calc_ftype& dist_func,
                  cluster_vector* const clusters) override {
#pragma omp parallel for num_threads(m_n_threads)
    for (size_t i = 0; i < data.size(); ++i) {
      int closest = -1;
      double min_dist = std::numeric_limits<double>::max();
      for (size_t j = 0; j < clusters->size(); ++j) {
        double dist = dist_func(data[i], (*clusters)[j].center());
        if (dist < min_dist) {
          min_dist = dist;
          closest = j;
        }
      } /* for(j..) */
      (*clusters)[closest].add_point(i);
    } /* for(i..) */
  }

 private:
  void first_touch_allocation(std::vector<T>* const data,
                              membership_type<policy::NC>* const membership) {
#pragma omp parallel for num_threads(m_n_threads)
    for (size_t i = 0; i < data->size(); ++i) {
      (*data)[i] = 0;
      (*membership)[i] = -1;
    } /* for(i...) */
  }

  /* clang-format off */
  size_t m_n_threads;
  /* clang-format on */
};

NS_END(clustering, algorithm, rcppsw);

