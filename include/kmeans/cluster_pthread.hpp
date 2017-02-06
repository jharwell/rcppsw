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
                  const std::vector<T>* const data,
                  const std::string& clusters_fname,
                  const std::string& centroids_fname) :
      cluster_algorithm<T>(n_iterations, n_clusters, clusters_fname,
                           centroids_fname, data),
      n_threads_(n_threads), workers_() {
    for (std::size_t i = 0; i < n_threads_; ++i) {
      workers_.emplace_back(pthread_worker<T>(i, n_threads_,
                                              cluster_algorithm<T>::clusters()));
    } /* for(i..) */
  } /* kmeans_pthreads_cluster::kmeans_cluster_pthread() */

  /* member functions */
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
    for (std::size_t i = 0; i < workers_.size(); ++i) {
      workers_[i].start((void*)(&cluster_algorithm<T>::data()[i*n_threads_]));
    } /* for(i..) */

    for (std::size_t i = 0; i < workers_.size(); ++i) {
      workers_[i].join();
    } /* for(i..) */

    /*
     * Update the center/hash for the queue corresponding to the thread ID
     * of the worker.
     */
    for (std::size_t i = 0; i < workers_.size(); ++i) {
      workers_[i].start(NULL);
    } /* for(i..) */

    for (std::size_t i = 0; i < workers_.size(); ++i) {
      workers_[i].join();
    } /* for(i..) */

    /* Finally, check for convergence */
    for (std::size_t i = 0; i < cluster_algorithm<T>::clusters()->size(); ++i) {
      if (!cluster_algorithm<T>::clusters()->at(i)->convergence()) {
        return false;
      }
      DBGTN("Cluster %lu reports convergence\n", i);
    } /* for(i..) */
    return true;
  } /* cluster_pthread::cluster_iterate() */

 private:
  /* member functions */

  /* data members */
  std::size_t n_threads_;
  std::vector<pthread_worker<T>> workers_;
};

} /* namespace kmeans */
} /* namespace rcppsw */

#endif /* INCLUDE_KMEANS_CLUSTER_PTHREAD_HPP_ */
