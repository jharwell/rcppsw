/*******************************************************************************
 * Name            : kmeans_cluster_pthread.hpp
 * Project         : rcppsw
 * Module          : algorithm
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
#include "include/kmeans_cluster_algorithm.hpp"
#include "include/kmeans_cluster_worker.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template <typename T> class kmeans_cluster_pthread : public kmeans_cluster_algorithm<T> {
 public:
  /* constructors */
  kmeans_cluster_pthread(int n_threads,
                         int n_iterations,
                         const std::vector<T>* const data,
                         const std::string& clusters_fname,
                         const std::string& centroids_fname) :
      kmeans_cluster_algorithm<T>(n_iterations, clusters_fname,
                                  centroids_fname, data),
      n_threads_(n_threads), workers_() {
    for (int i = 0; i < n_threads_; ++i) {
      workers_.emplace_back(kmeans_cluster_worker<T>());
    } /* for(i..) */

    kmeans_cluster_worker<T>::clusters(kmeans_cluster_algorithm<T>::clusters());
    kmeans_cluster_worker<T>::n_threads(n_threads_);
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
    /*
     * cluster the data via Euclidean distance, putting each matching vector
     * into the queue with the closest centroid.
     */
    for (std::size_t i = 0; i < workers_.size(); ++i) {
      workers_[i].start((void*)(&kmeans_cluster_algorithm<T>::data()[i*n_threads_]));
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
    for (std::size_t i = 0; i < kmeans_cluster_algorithm<T>::clusters()->size(); ++i) {
      if (!kmeans_cluster_algorithm<T>::clusters()->at(i).convergence()) {
        return false;
      }
    } /* for(i..) */
    return true;
  } /* kmeans_cluster_pthread::cluster_iterate() */

 private:
  /* member functions */

  /* data members */
  int n_threads_;
  std::vector<kmeans_cluster_worker<T>> workers_;
};

} /* namespace rcppsw */

#endif /* INCLUDE_KMEANS_CLUSTER_PTHREAD_HPP_ */
