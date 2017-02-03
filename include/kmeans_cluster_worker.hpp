n/*******************************************************************************
 * Name            : kmeans_cluster_worker.hpp
 * Project         : rcsw
 * Module          : algorithm
 * Description     : Workers for pthread-based implementation of K-means
 *                   clustering
 * Creation Date   : 02/02/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_KMEANS_CLUSTER_WORKER_HPP_
#define INCLUDE_KMEANS_CLUSTER_WORKER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <limits>
#include "include/threadable.hpp"
#include "include/kmeans_cluster.hpp"

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
template <typename T> class kmeans_cluster_worker: public threadable {
 public:
  /* constructors */
  kmeans_cluster_worker(void);

  /* member functions */
  static void clusters(const std::vector<kmeans_cluster<T>>& c) { clusters_ = c; }
  static void n_trheads(int n) { n_threads_ = n; }

  /**
   * kmeans_cluster_worker::thread_main() - Main worker function
   *
   * RETURN:
   *     void* - N/A (must be void* to satisfy pthread_create())
   **/
  void* thread_main(void* arg) {
    if (NULL == arg) {
          clusters_->at(self()).update_center();
          return NULL;
    }
    std::vector<std::vector<T>>* data = arg;
    for (int i = data->size()/n_threads_; i < data->size()/n_threads_ + n_threads_; ++i) {
      int min_queue;
      T min_dist = std::numeric_limits<T>::max();
      for (int j = 0; j < clusters_[j].size(); ++j) {
        T dist = euclidean_dist(clusters_[j].center(), data[i]);
        if (dist < min_dist) {
          min_dist = dist;
          min_queue = j;
        }
      } /* for(j..) */
      clusters_[min_queue].add(data[i]);
    } /* for(i..) */
    return NULL;
  } /* kmeans_cluster_worker::thread_main() */

 private:
  /* member functions */
  /**
   * kmeans_cluster_worker::euclidean_dist() - Calculate the Euclidean
   * dist between two vectors
   *
   * RETURN:
   *     float - The dist
   **/
  T (euclidean_dist)(const std::vector<T>& p1,
                             const std::vector<T>& p2) {
    T dist = -1;
    std::for_each(p1.begin(), p1.end(), [&](const T& e1) {
        std::for_each(p2.begin(), p2.end(), [&](const T& e2) {
            dist += std::pow(e1 - e2, 2);
          });
            });
    return dist;
  } /* kmeans_cluster_worker::euclidean_dist() */

  /* data members */
  static const std::vector<kmeans_cluster<T>>& clusters_;
  static int n_threads_;
};

} /* namespace rcppsw */

#endif /* INCLUDE_KMEANS_CLUSTER_WORKER_HPP_ */
