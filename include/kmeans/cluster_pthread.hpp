/*******************************************************************************
 * Name            : cluster_pthread.hpp
 * Project         : rcppsw
 * Module          : kmeans
 * Description     : K-means clustering using pthreads
 * Creation Date   : 02/02/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_KMEANS_CLUSTER_PTHREAD_HPP_
#define INCLUDE_KMEANS_CLUSTER_PTHREAD_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <string>
#include "include/kmeans/cluster_algorithm.hpp"
#include "include/kmeans/pthread_worker.hpp"
#include "rcsw/include/common/dbg.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {
namespace kmeans {

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template <typename T> class cluster_pthread : public cluster_algorithm<T> {
 public:
  /* constructors */
  cluster_pthread(std::size_t n_iterations,
                  std::size_t n_clusters,
                  std::size_t n_threads,
                  std::size_t dimension,
                  std::size_t n_points,
                  const std::string& clusters_fname,
                  const std::string& centroids_fname) :
      cluster_algorithm<T>(n_iterations, n_clusters, n_threads, dimension,
                           n_points, clusters_fname, centroids_fname),
      workers_() {
    assert(n_points % n_threads == 0);
    assert(n_clusters % n_threads == 0);
    std::size_t chunk_size = n_points/n_threads;
    for (std::size_t i = 0; i < n_threads; ++i) {
      workers_.emplace_back(pthread_worker<T>(i, n_threads, chunk_size, dimension,
                                              cluster_algorithm<T>::clusters()));
    } /* for(i..) */
  } /* kmeans_cluster_pthread::kmeans_cluster_pthread() */

  /* member functions */
  void initialize(std::vector<multidim_point<T>>* data_in) {
    for (std::size_t i = 0; i < cluster_algorithm<T>::clusters()->size(); ++i) {
      cluster_algorithm<T>::clusters()->at(i)->initialize_center(data_in->at(i).data());
    } /* for(i..) */

    cluster_algorithm<T>::data(new T[data_in->size() * cluster_algorithm<T>::dimension()]);

    /*
     * Perform first touch allocation
     */
    typename pthread_worker<T>::instructions instr = {0, cluster_algorithm<T>::data()};
    for (std::size_t i = 0; i < workers_.size(); ++i) {
      workers_[i].start(&instr);
    } /* for(i..) */

    for (std::size_t i = 0; i < workers_.size(); ++i) {
      workers_[i].join();
    } /* for(i..) */

    for (std::size_t i = 0; i < data_in->size(); ++i) {
      std::copy(data_in->at(i).begin(),
      data_in->at(i).end(),
                cluster_algorithm<T>::data() + i*data_in->at(0).size());
    } /* for(i..) */

  } /* load_data() */

  /**
   * kmeans_cluster_pthread::cluster_iterate() - Perform one iteration of the
   * K-means clustering algorithm
   *
   * RETURN:
   *     bool - true if convergence was achieved, false otherwise
   **/
  bool cluster_iterate(void) {
    for (std::size_t i = 0; i < cluster_algorithm<T>::clusters()->size(); ++i) {
      cluster_algorithm<T>::clusters()->at(i)->reset();
    } /* for(i..) */

    /*
     * cluster the data via Euclidean distance, putting each matching vector
     * into the queue with the closest centroid.
     */
    assert(cluster_algorithm<T>::dimension() % workers_.size() == 0);
    typename pthread_worker<T>::instructions instr1 = {1, cluster_algorithm<T>::data()};
    for (std::size_t i = 0; i < workers_.size(); ++i) {
      workers_[i].start(&instr1);
    } /* for(i..) */

    for (std::size_t i = 0; i < workers_.size(); ++i) {
      workers_[i].join();
    } /* for(i..) */

    /*
     * Update the center for all clusters
     */
    typename pthread_worker<T>::instructions instr2 = {2, NULL};
    for (std::size_t i = 0; i < workers_.size(); ++i) {
      workers_[i].start(&instr2);
    } /* for(i..) */

    for (std::size_t i = 0; i < workers_.size(); ++i) {
      workers_[i].join();
    } /* for(i..) */

    /* Finally, check for convergence */
    bool ret = true;
    for (std::size_t i = 0; i < cluster_algorithm<T>::clusters()->size(); ++i) {
      if (cluster_algorithm<T>::clusters()->at(i)->convergence()) {
        DBGTN("Cluster %lu reports convergence\n", i);
      } else {
        DBGTN("Cluster %lu reports no convergence\n", i);
        ret = false;
      }
    } /* for(i..) */
    return ret;
  } /* cluster_pthread::cluster_iterate() */

 private:
  /* member functions */

  /* data members */
  std::vector<pthread_worker<T>> workers_;
};

} /* namespace kmeans */
} /* namespace rcppsw */

#endif /* INCLUDE_KMEANS_CLUSTER_PTHREAD_HPP_ */
