/*******************************************************************************
 * Name            : kmeans_pthread_cluster.hpp
 * Project         : rcppsw
 * Module          : algorithm
 * Description     : K-means clustering using pthreads
 * Creation Date   : 02/02/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_KMEANS_PTHREAD_CLUSTER_HPP_
#define INCLUDE_KMEANS_PTHREAD_CLUSTER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/kmeans_algorithm.hpp"
#include "include/kmeans_cluster_worker.hpp"
#include "rcsw/include/al/alcsem.h"

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
template <typename T> class kmeans_pthread_cluster : public kmeans_algorithm {
 public:
  /* constructors */
  kmeans_pthread_cluster(int n_threads) :
      n_threads_(n_threads) {}

  void init(void) {
    for (int i = 0; i < n_threads_; ++i) {
      workers_[i].push_back(kmeans_cluster_worker<T>(n_threads_));
    } /* for(i..) */

    kmeans_cluster_worker::clusters(clusters());
    kmeans_cluster_worker::n_threads(n_threads_);
  } /* kmeans_algorithm::init() */

  /* member functions */
  /**
   * kmeans_algorithm::cluster_iterate() - Perform one iteration of the K-means
   * clustering algorithm
   *
   * RETURN:
   *     bool - true if convergence was achieved, false otherwise
   **/
  bool cluster_iterate(void) {

    /*
     * cluster the data via Euclidean distance, putting each matching vector
     * into the queue with the closest centroid.
     */
    for (int i = 0; i < workers_.size(); ++i) {
      workers_[i].start(&data()[i*n_threads_]);
    } /* for(i..) */

    for (int i = 0; i < workers_.size(); ++i) {
      workers_[i].join();
    } /* for(i..) */

    /*
     * Update the center/hash for the queue corresponding to the thread ID
     * of the worker.
     */
    for (int i = 0; i < workers_.size(); ++i) {
      workers_[i].start(NULL);
    } /* for(i..) */

    for (int i = 0; i < workers_.size(); ++i) {
      workers_[i].join();
    } /* for(i..) */

    /* Finally, check for convergence */
    for (int i = 0; i < clusters.size(); ++i) {
      if (!clusters[i].convergence()) {
        return false;
      }
    } /* for(i..) */
    return true;
  } /* kmeans_pthread_cluster::cluster_iterate() */

 private:
  /* member functions */

  /* data members */
  int n_threads_;
  std::vector<kmeans_cluster_worker<T>> workers_;
};

} /* namespace rcppsw */

#endif /* INCLUDE_KMEANS_PTHREAD_CLUSTER_HPP_ */
