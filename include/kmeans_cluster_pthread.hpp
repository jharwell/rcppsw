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
#include <iostream>
#include <fstream>
#include "include/kmeans_algorithm.hpp"
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
template <typename T> class kmeans_cluster_pthread : public kmeans_algorithm<T> {
 public:
  /* constructors */
  explicit kmeans_cluster_pthread(int n_threads,
                                  const std::string& clusters_fname,
                                  const std::string& centroids_fname) :
      n_threads_(n_threads), workers_(), clusters_fname_(clusters_fname),
      centroids_fname_(centroids_fname) {
    for (int i = 0; i < n_threads_; ++i) {
      workers_.emplace_back(kmeans_cluster_worker<T>());
    } /* for(i..) */

    kmeans_cluster_worker<T>::clusters(&kmeans_algorithm<T>::clusters());
    kmeans_cluster_worker<T>::n_threads(n_threads_);
  } /* kmeans_pthreads_cluster::kmeans_cluster_pthread() */

  void report_clusters(void) {
    std::ofstream ofile(clusters_fname_);
    std::for_each(kmeans_algorithm<T>::clusters().begin(),
                  kmeans_algorithm<T>::clusters().end(),
                  [&](const kmeans_cluster<T>& c) {
        ofile << c;
      });
  }
  void report_centroids(void) {
    std::ofstream ofile(centroids_fname_);
    std::for_each(kmeans_algorithm<T>::clusters().begin(),
                  kmeans_algorithm<T>::clusters().end(),
                  [&](const kmeans_cluster<T>& c) {
                    ofile << &c.center();
                  });
  }

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
    for (std::size_t i = 0; i < workers_.size(); ++i) {
      workers_[i].start(&kmeans_algorithm<T>::data()[i*n_threads_]);
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
    for (std::size_t i = 0; i < kmeans_algorithm<T>::clusters().size(); ++i) {
      if (!kmeans_algorithm<T>::clusters()[i].convergence()) {
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
  const std::string& clusters_fname_;
  const std::string& centroids_fname_;
};

} /* namespace rcppsw */

#endif /* INCLUDE_KMEANS_CLUSTER_PTHREAD_HPP_ */
