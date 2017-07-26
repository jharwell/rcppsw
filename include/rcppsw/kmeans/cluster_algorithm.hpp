/**
 * @file cluster_algorithm.hpp
 *
 * @copyright 2017 John Harwell, All rights reserved.
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
#ifndef INCLUDE_RCPPSW_KMEANS_CLUSTER_ALGORITHM_HPP_
#define INCLUDE_RCPPSW_KMEANS_CLUSTER_ALGORITHM_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <time.h>
#include <algorithm>
#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include "rcppsw/common/common.hpp"
#include "rcppsw/kmeans/cluster.hpp"
#include "rcppsw/erf_client.hpp"
#include "rcsw/utils/utils.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, kmeans);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Base class implementation of k-means clustering algorithm.
 */
template <typename T> class cluster_algorithm: public erf_client {
 public:
  cluster_algorithm(std::size_t n_iterations,
                    std::size_t n_clusters,
                    std::size_t n_threads,
                    std::size_t dimension,
                    std::size_t n_points,
                    const std::string& clusters_fname,
                    const std::string& centroids_fname,
                    er_server *const erf) :
      erf_client(erf),
      n_iterations_(n_iterations), n_clusters_(n_clusters),
      n_threads_(n_threads),
      dimension_(dimension), n_points_(n_points),
      data_(NULL),
      membership_(NULL),
      clusters_fname_(clusters_fname),
      centroids_fname_(centroids_fname),
      clusters_(new std::vector<kmeans_cluster<T>*>()) {
    erf_handle()->insmod(erf_id(), "KMEANS");
    ER_REPORT(er_lvl::NOM, "n_points=%lu, n_clusters=%lu, n_iterations=%lu\n",
              n_points_, n_clusters_, n_iterations_);
  }

  virtual ~cluster_algorithm(void) {
    for (std::size_t i = 0; i < n_clusters_; ++i) {
      delete(clusters_->at(i));
    } /* for(i..) */
    free(membership_);
  }

  boost::shared_ptr<std::vector<kmeans_cluster<T>*>>& clusters(void) {
    return clusters_;
  }
  std::size_t n_clusters(void) { return n_clusters_; }
  std::size_t n_threads(void) { return n_threads_; }
  T* data(void) { return data_; }
  void data(T* in) { data_ = in; }
  std::size_t* membership(void) { return membership_; }
  void membership(std::size_t* in) { membership_ = in; }
  std::size_t n_points(void) { return n_points_; }
  std::size_t dimension(void) { return dimension_; }

  virtual void report_clusters(void) {
    std::ofstream ofile(clusters_fname_);
    for (std::size_t j = 0; j < n_points_; ++j) {
      ofile << membership_[j] << std::endl;
    } /* for(j..) */
  }
  virtual void report_centroids(void) {
    std::ofstream ofile(centroids_fname_);
    ofile << clusters_->size() << " " << dimension_ << std::endl;
    std::for_each(clusters_->begin(), clusters_->end(),
                  [&](const kmeans_cluster<T>* c) {
                    c->report_center(ofile);
                  });
  }
  void cluster(void) {
    ER_REPORT(er_lvl::NOM, "Begin clustering\n");
    double end = 0.0;
    double start = utils_monotonic_sec();
    for (std::size_t i = 0; i < n_iterations_; ++i) {
      double iter_start = utils_monotonic_sec();
      if (cluster_iterate()) {
        ER_REPORT(er_lvl::NOM, "Clusters report convergence: terminating\n");
        end = utils_monotonic_sec();
        break;
      } else {
        end = utils_monotonic_sec();
      }
      ER_REPORT(er_lvl::DIAG, "Iteration %lu time: %.8fms\n", i, (end - iter_start)*1000);
    } /* for(i..) */

    ER_REPORT(er_lvl::NOM,"k-means clustering time: %0.04fs\n", end-start);
  } /* cluster_algorithm::cluster() */

  virtual void initialize(std::vector<multidim_point<T>>* data_in)  {
    /* allocate contiguous memory */
    std::size_t* data_block = (std::size_t*)malloc(sizeof(T) * n_points_ * dimension_
                                                   + sizeof(std::size_t) * n_points_);
    assert(NULL != data_block);
    data_ = reinterpret_cast<T*>(data_block + n_points_);
    membership_ = data_block;

    first_touch_allocation();

    /* Copy data into contiguous chunk */
    for (std::size_t i = 0; i < n_points_; ++i) {
      std::copy(data_in->at(i).begin(), data_in->at(i).end(),
                data_ + (i * dimension_));
    } /* for(i..) */

    /*
     * Initialize all clusters, including centers
     */
    for (std::size_t i = 0; i < n_clusters_; ++i) {
      clusters_->emplace_back(new kmeans_cluster<T>(i, dimension_, n_points_,
                                                    data_, membership_));
    } /* for(i..) */
  }
  virtual void first_touch_allocation(void) {}

 protected:
  virtual bool cluster_iterate(void) = 0;

 private:
  cluster_algorithm(const cluster_algorithm& other) = delete;
  cluster_algorithm& operator=(const cluster_algorithm& other) = delete;

  std::size_t n_iterations_;
  std::size_t n_clusters_;
  std::size_t n_threads_;

  /*
   * Dimension is 1 more than the actual data dimension, to efficiently store
   * the cluster associated with each data point.
   */
  std::size_t dimension_;
  std::size_t n_points_;
  T* data_;
  std::size_t* membership_;
  const std::string& clusters_fname_;
  const std::string& centroids_fname_;
  boost::shared_ptr<std::vector<kmeans_cluster<T>*>> clusters_;
};

NS_END(kmeans, rcppsw);

#endif /* INCLUDE_RCPPSW_KMEANS_CLUSTER_ALGORITHM_HPP_ */
