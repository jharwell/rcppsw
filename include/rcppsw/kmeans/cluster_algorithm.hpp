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
#include <boost/shared_ptr.hpp>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "rcppsw/common/common.hpp"
#include "rcppsw/er/client.hpp"
#include "rcppsw/kmeans/cluster.hpp"
#include "rcsw/utils/time_utils.h"

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
template <typename T>
class cluster_algorithm : public common::er_client {
 public:
  cluster_algorithm(std::size_t n_iterations,
                    std::size_t n_clusters,
                    std::size_t n_threads,
                    std::size_t dimension,
                    std::size_t n_points,
                    const std::string& clusters_fname,
                    const std::string& centroids_fname,
                    common::er_server* const erf)
      : common::er_client(erf),
        m_n_iterations(n_iterations),
        m_n_clusters(n_clusters),
        m_n_threads(n_threads),
        m_dimension(dimension),
        m_n_points(n_points),
        m_data(NULL),
        m_membership(NULL),
        m_clusters_fname(clusters_fname),
        m_centroids_fname(centroids_fname),
        m_clusters(new std::vector<kmeans_cluster<T>*>()) {
    server_handle()->insmod(er_id(), "KMEANS");
    ER_NOM("n_points=%lu, n_clusters=%lu, n_iterations=%lu\n",
           m_n_points,
           m_n_clusters,
           m_n_iterations);
  }

  virtual ~cluster_algorithm(void) {
    for (std::size_t i = 0; i < m_n_clusters; ++i) {
      delete (m_clusters->at(i));
    } /* for(i..) */
    free(m_membership);
  }

  boost::shared_ptr<std::vector<kmeans_cluster<T>*>>& clusters(void) {
    return m_clusters;
  }
  std::size_t n_clusters(void) { return m_n_clusters; }
  std::size_t n_threads(void) { return m_n_threads; }
  T* data(void) { return m_data; }
  void data(T* in) { m_data = in; }
  std::size_t* membership(void) { return m_membership; }
  void membership(std::size_t* in) { m_membership = in; }
  std::size_t n_points(void) { return m_n_points; }
  std::size_t dimension(void) { return m_dimension; }

  virtual void report_clusters(void) {
    std::ofstream ofile(m_clusters_fname);
    for (std::size_t j = 0; j < m_n_points; ++j) {
      ofile << m_membership[j] << std::endl;
    } /* for(j..) */
  }
  virtual void report_centroids(void) {
    std::ofstream ofile(m_centroids_fname);
    ofile << m_clusters->size() << " " << m_dimension << std::endl;
    std::for_each(m_clusters->begin(),
                  m_clusters->end(),
                  [&](const kmeans_cluster<T>* c) { c->report_center(ofile); });
  }
  void cluster(void) {
    ER_NOM("Begin clustering\n");
    double end = 0.0;
    double start = time_monotonic_sec();
    for (std::size_t i = 0; i < m_n_iterations; ++i) {
      double iter_start = time_monotonic_sec();
      if (cluster_iterate()) {
        ER_NOM("Clusters report convergence: terminating\n");
        end = time_monotonic_sec();
        break;
      } else {
        end = time_monotonic_sec();
      }
      ER_DIAG("Iteration %lu time: %.8fms\n", i, (end - iter_start) * 1000);
    } /* for(i..) */

    ER_NOM("k-means clustering time: %0.04fs\n", end - start);
  } /* cluster_algorithm::cluster() */

  virtual void initialize(std::vector<multidim_point<T>>* data_in) {
    /* allocate contiguous memory */
    std::size_t* data_block = (std::size_t*)malloc(
        sizeof(T) * m_n_points * m_dimension + sizeof(std::size_t) * m_n_points);
    assert(NULL != data_block);
    m_data = reinterpret_cast<T*>(data_block + m_n_points);
    m_membership = data_block;

    first_touch_allocation();

    /* Copy data into contiguous chunk */
    for (std::size_t i = 0; i < m_n_points; ++i) {
      std::copy(data_in->at(i).begin(),
                data_in->at(i).end(),
                m_data + (i * m_dimension));
    } /* for(i..) */

    /*
     * Initialize all clusters, including centers
     */
    for (std::size_t i = 0; i < m_n_clusters; ++i) {
      m_clusters->emplace_back(new kmeans_cluster<T>(
          i, m_dimension, m_n_points, m_data, m_membership));
    } /* for(i..) */
  }
  virtual void first_touch_allocation(void) {}

 protected:
  virtual bool cluster_iterate(void) = 0;

 private:
  cluster_algorithm(const cluster_algorithm& other) = delete;
  cluster_algorithm& operator=(const cluster_algorithm& other) = delete;

  std::size_t m_n_iterations;
  std::size_t m_n_clusters;
  std::size_t m_n_threads;

  /*
   * Dimension is 1 more than the actual data dimension, to efficiently store
   * the cluster associated with each data point.
   */
  std::size_t m_dimension;
  std::size_t m_n_points;
  T* m_data;
  std::size_t* m_membership;
  const std::string& m_clusters_fname;
  const std::string& m_centroids_fname;
  boost::shared_ptr<std::vector<kmeans_cluster<T>*>> m_clusters;
};

NS_END(kmeans, rcppsw);

#endif /* INCLUDE_RCPPSW_KMEANS_CLUSTER_ALGORITHM_HPP_ */
