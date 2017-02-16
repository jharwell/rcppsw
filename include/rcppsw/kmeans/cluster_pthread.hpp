/*******************************************************************************
 * Name            : cluster_pthread.hpp
 * Project         : rcppsw
 * Module          : kmeans
 * Description     : K-means clustering using pthreads
 * Creation Date   : 02/02/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_KMEANS_CLUSTER_PTHREAD_HPP_
#define INCLUDE_RCPPSW_KMEANS_CLUSTER_PTHREAD_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <string>
#include "rcppsw/kmeans/cluster_algorithm.hpp"
#include "rcppsw/kmeans/pthread_worker.hpp"

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
                  const std::string& centroids_fname,
                  er_server *const erf) :
      cluster_algorithm<T>(n_iterations, n_clusters, n_threads, dimension,
                           n_points, clusters_fname, centroids_fname, erf),
      workers_() {
    std::size_t data_chunk_size = n_points/n_threads;
    std::size_t centers_chunk_size = n_clusters/n_threads;
    std::size_t prev_centers_i = 0;
    std::size_t prev_data_i = 0;
    std::size_t data_chunk_start = 0;
    std::size_t centers_chunk_start = 0;

    for (std::size_t i = 0; i < n_threads; ++i) {
      if (n_points % n_threads != 0 && i == n_threads -1) {
        data_chunk_size = n_points - data_chunk_start;
      }
      if (n_clusters % n_threads != 0 && i == n_threads -1) {
        centers_chunk_size = n_points - centers_chunk_start;
      }
      ER_REPORT(er_lvl::NOM, "Worker %lu: %lu - %lu, %lu - %lu\n", i,
                data_chunk_start,
                data_chunk_start + data_chunk_size,
                centers_chunk_start,
                centers_chunk_start + centers_chunk_size);

      workers_.emplace_back(pthread_worker<T>(i,
                                              data_chunk_start, data_chunk_size,
                                              centers_chunk_start, centers_chunk_size,
                                              dimension,
                                              cluster_algorithm<T>::clusters()));
      data_chunk_start = prev_data_i + data_chunk_size;
      centers_chunk_start = prev_centers_i + centers_chunk_size;
      prev_centers_i += centers_chunk_size;
      prev_data_i += data_chunk_size;
    } /* for(i..) */
  } /* kmeans_cluster_pthread::kmeans_cluster_pthread() */

  /* member functions */

  void first_touch_allocation(void) {
  /*
   * Perform first touch allocation for all threads
   */
  typename pthread_worker<T>::instruction_data instr = {
    pthread_worker<T>::instruction::FIRST_TOUCH,
    cluster_algorithm<T>::data(),
    cluster_algorithm<T>::membership(),
  };

  std::for_each(workers_.begin(), workers_.end(),
                [&](pthread_worker<T>& w) { w.start(&instr); });
  std::for_each(workers_.begin(), workers_.end(),
                [&](pthread_worker<T>& w) { w.join(); });
  }

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
    typename pthread_worker<T>::instruction_data instr1 = {
      pthread_worker<T>::instruction::CLUSTER_POINTS,
      cluster_algorithm<T>::data(),
      cluster_algorithm<T>::membership()
    };

    for (std::size_t i = 0; i < workers_.size(); ++i) {
      workers_[i].start(&instr1);
    } /* for(i..) */

    for (std::size_t i = 0; i < workers_.size(); ++i) {
      workers_[i].join();
    } /* for(i..) */

    /*
     * Update the center for all clusters
     */
    typename pthread_worker<T>::instruction_data instr2 = {
      pthread_worker<T>::instruction::UPDATE_CENTER,
      cluster_algorithm<T>::data(),
      cluster_algorithm<T>::membership(),
    };
    for (std::size_t i = 0; i < workers_.size(); ++i) {
      workers_[i].start(&instr2);
    } /* for(i..) */

    for (std::size_t i = 0; i < workers_.size(); ++i) {
      workers_[i].join();
    } /* for(i..) */

    /* Finally, check for convergence */
    bool ret = true;
    for (std::size_t i = 0; i < cluster_algorithm<T>::n_clusters(); ++i) {
      if (cluster_algorithm<T>::clusters()->at(i)->convergence()) {
        ER_REPORT(er_lvl::DIAG, "Cluster %lu reports convergence\n", i);
      } else {
        ER_REPORT(er_lvl::DIAG, "Cluster %lu reports no convergence\n", i);
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

#endif /* INCLUDE_RCPPSW_KMEANS_CLUSTER_PTHREAD_HPP_ */
