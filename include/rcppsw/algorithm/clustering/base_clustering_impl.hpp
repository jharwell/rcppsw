/**
 * \file base_clustering_impl.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <functional>

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/algorithm/clustering/cluster.hpp"
#include "rcppsw/algorithm/clustering/membership_policy.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::algorithm::clustering {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \interface base_clustering_impl
 * \ingroup algorithm clustering
 *
 * \brief Templated class interface to guide the implementation of various
 * clustering algorithms by giving them a necessary set of functions to
 * implement so that they can be then run in an implementation agnostic way.
 */
template<typename T, typename Policy>
class base_clustering_impl {
 public:
  using cluster_type = typename cluster::mapping<T, Policy>::type;
  using cluster_vector = std::vector<cluster_type>;
  using dist_calc_ftype = std::function<double(const T&, const T&)>;

  virtual ~base_clustering_impl(void) = default;

   /**
   * \brief Determine if the clusters have converged and the algorithm should be
   * terminated.
   *
   * \return \c TRUE if the algorithm has converged, \c FALSE otherwise.
   */
  virtual bool converged(const cluster_vector& clusters) const = 0;

  /*
   * \brief Perform one iteration the clustering algorithm.
   */
  virtual void iterate(const std::vector<T>& data,
                       const dist_calc_ftype& dist_func,
                       cluster_vector* clusters) = 0;

  /*
   * \brief Update clusters (in some algorithm-specific way) after an iteration.
   */
  virtual void post_iter_update(cluster_vector* clusters) = 0;

  /**
   * \brief Perform algorithm-specific clustering initialization (memory
   * localization, etc.).
   */
  virtual void initialize(std::vector<T>* data,
                          membership_type<Policy>* membership) = 0;
};

} /* namespace rcppsw::algorithm::clustering */

