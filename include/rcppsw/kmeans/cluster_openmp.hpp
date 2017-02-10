/*******************************************************************************
 * Name            : cluster_openmp.hpp
 * Project         : rcppsw
 * Module          : kmeans
 * Description     : K-means clustering using OpenMP
 * Creation Date   : 02/02/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_KMEANS_CLUSTER_OPENMP_HPP_
#define INCLUDE_RCPPSW_KMEANS_CLUSTER_OPENMP_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <omp.h>
#include <vector>
#include <string>
#include "rcppsw/kmeans/cluster_algorithm.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {
namespace kmeans {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template <typename T> class cluster_openmp : public cluster_algorithm<T> {
 public:
  /* constructors */
  cluster_openmp(std::size_t n_iterations,
                 std::size_t n_clusters,
                 std::size_t n_threads,
                 std::size_t dimension,
                 std::size_t n_points,
                 const std::string& clusters_fname,
                 const std::string& centroids_fname,
                 er_frmwk *const erf) :
      cluster_algorithm<T>(n_iterations, n_clusters, n_threads, dimension,
                           n_points, clusters_fname, centroids_fname, erf) {}
  /* member functions */

  void first_touch_allocation(void) {
#pragma omp parallel for num_threads(cluster_algorithm<T>::n_threads())
    for (std::size_t i = 0; i < cluster_algorithm<T>::n_points(); ++i) {
      cluster_algorithm<T>::data()[i*cluster_algorithm<T>::dimension()] = 0;
      cluster_algorithm<T>::membership()[i] = -1;
    } /* for(i...) */
  }

  /**
   * cluster_openmp::cluster_iterate() - Perform one iteration of the
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
#pragma omp parallel for num_threads(cluster_algorithm<T>::n_threads())
    for (std::size_t i = 0; i < cluster_algorithm<T>::n_points(); ++i) {
      int closest = -1;
      double min_dist = std::numeric_limits<float>::max();
      for (std::size_t j = 0; j < cluster_algorithm<T>::clusters()->size(); ++j) {
        double dist = cluster_algorithm<T>::clusters()->at(j)->dist_to_center(cluster_algorithm<T>::data() + i * cluster_algorithm<T>::dimension());
        if (dist < min_dist) {
          min_dist = dist;
          closest = j;
        }
      } /* for(j..) */
      cluster_algorithm<T>::clusters()->at(closest)->add_point(i);
    } /* for(i..) */

    /*
     * Update the center for all clusters
     */
#pragma omp parallel for num_threads(cluster_algorithm<T>::n_threads())
    for (std::size_t i = 0; i < cluster_algorithm<T>::clusters()->size(); ++i) {
      cluster_algorithm<T>::clusters()->at(i)->update_center(cluster_algorithm<T>::n_points());
    } /* for(i..) */

    /* Finally, check for convergence */
    for (std::size_t i = 0; i < cluster_algorithm<T>::clusters()->size(); ++i) {
      if (!cluster_algorithm<T>::clusters()->at(i)->convergence()) {
        return false;
      }
    } /* for(i..) */
    return true;
  } /* cluster_openmp::cluster_iterate() */

 private:
  /* member functions */

  /* data members */
};

} /* namespace kmeans */
} /* namespace rcppsw */

#endif /* INCLUDE_RCPPSW_KMEANS_CLUSTER_OPENMP_HPP_ */
