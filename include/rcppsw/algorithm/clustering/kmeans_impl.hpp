/**
 * \file kmeans_impl.hpp
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
#ifndef INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_KMEANS_IMPL_HPP_
#define INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_KMEANS_IMPL_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <omp.h>
#include <vector>
#include <limits>

#include "rcppsw/common/common.hpp"
#include "rcppsw/algorithm/clustering/clustering_impl.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, algorithm, clustering, detail);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class kmeans_impl
 * \ingroup algorithm clustering
 *
 * \brief Parallel clustering using OpenMP using the Nearest Centroid (NC)
 * membership policy. Suitable for kmeans clustering.
 */
template <typename T>
class kmeans_impl : public clustering_impl<T, policy::NC> {
 public:
  using typename clustering_impl<T, policy::NC>::dist_calc_ftype;
  using typename clustering_impl<T, policy::NC>::cluster_vector;

  explicit kmeans_impl(uint n_threads)
      : m_n_threads(n_threads) {}

  void initialize(std::vector<T>* const data,
                  membership_type<policy::NC>* const membership) override {
    first_touch_allocation(data, membership);
  }

  RCSW_PURE bool converged(const cluster_vector& clusters) const override {
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
  uint m_n_threads;
  /* clang-format on */
};

NS_END(detail, clustering, algorithm, rcppsw);

#endif /* INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_KMEANS_IMPL_HPP_ */
