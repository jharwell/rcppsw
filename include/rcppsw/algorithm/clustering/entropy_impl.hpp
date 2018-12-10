/**
 * @file entropy_impl.hpp
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
#ifndef INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_ENTROPY_IMPL_HPP_
#define INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_ENTROPY_IMPL_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <omp.h>
#include <vector>
#include <limits>

#include "rcppsw/common/common.hpp"
#include "rcppsw/algorithm/clustering/clustering_impl.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, algorithm, clustering);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class entropy_impl
 * @ingroup algorithm clustering
 *
 * @brief Sequential clustering using the Event Horizon (EH) membership
 * policy. Suitable for information entropy calculations.
 */
template <typename T>
class entropy_impl : public clustering_impl<T, policy::EH> {
 public:
  using typename clustering_impl<T, policy::EH>::cluster_vector;
  using typename clustering_impl<T, policy::EH>::dist_calc_ftype;

  explicit entropy_impl(uint n_threads) : m_n_threads(n_threads) {}

  uint n_threads(void) const { return m_n_threads; }

  void initialize(std::vector<T>* const,
                  membership_type<policy::EH>* const) override {
    /* first_touch_allocation(data, membership); */
  }

  void iterate(const std::vector<T>& data,
               const dist_calc_ftype& dist_func,
               cluster_vector* const clusters) override {
    #pragma omp parallel for num_threads(m_n_threads)
    for (size_t i = 0; i < data.size(); ++i) {
      for (size_t j = 0; j < data.size(); ++j) {
        if (dist_func(data[i], data[j]) <= m_horizon) {
          (*clusters)[i].add_point(j);
        }
      } /* for(j..) */
    } /* for(i..) */
  }

  bool converged(const cluster_vector& ) const override { return false; }
  void post_iter_update(cluster_vector* const) override {}

  void horizon(double horizon) { m_horizon = horizon; }

 private:
  void first_touch_allocation(std::vector<T>* const data,
                              membership_type<policy::EH>* const membership) {
    for (size_t i = 0; i < membership->size(); ++i) {
      (*data)[i] = T();
      (*membership)[i].reserve(data->size());
    } /* for(i...) */
  }

  // clang-format off
  uint   m_n_threads;
  double m_horizon{-1};
  // clang-format on
};

NS_END(clustering, algorithm, rcppsw);

#endif /* INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_ENTROPY_IMPL_HPP_ */
