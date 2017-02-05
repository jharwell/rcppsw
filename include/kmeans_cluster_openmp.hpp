/*******************************************************************************
 * Name            : kmeans_cluster_openmp.hpp
 * Project         : rcppsw
 * Module          : algorithm
 * Description     : K-means clustering using OpenMP
 * Creation Date   : 02/02/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_KMEANS_CLUSTER_OPENMP_HPP_
#define INCLUDE_KMEANS_CLUSTER_OPENMP_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <string>
#include "include/kmeans_cluster_algorithm.hpp"

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
template <typename T> class kmeans_cluster_openmp : public kmeans_cluster_algorithm<T> {
 public:
  /* constructors */
  kmeans_cluster_openmp(int n_iterations,
                        const std::vector<T>* const data,
                        const std::string& clusters_fname,
                        const std::string& centroids_fname) :
      kmeans_cluster_algorithm<T>(n_iterations, clusters_fname,
                                  centroids_fname, data) {}

  /* member functions */
  /**
   * kmeans_cluster_Openmp::cluster_iterate() - Perform one iteration of the
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

    for (std::size_t i = 0; i < kmeans_cluster_algorithm<T>::data()->size(); ++i) {
      int min_queue;
      float min_dist = std::numeric_limits<float>::max();
      for (std::size_t j = 0; j < kmeans_cluster_algorithm<T>::clusters()->at(j).size(); ++j) {
        float dist = euclidean_dist(kmeans_cluster_algorithm<T>::clusters()->at(j).center(),
                                    kmeans_cluster_algorithm<T>::data()->at(i));
        if (dist < min_dist) {
          min_dist = dist;
          min_queue = j;
        }
      } /* for(j..) */
      kmeans_cluster_algorithm<T>::clusters()->at(min_queue).add(const_cast<T*>(&kmeans_cluster_algorithm<T>::data()->at(i)));
    } /* for(i..) */

    /*
     * Update the center/hash for the queue corresponding to the thread ID
     * of the worker.
     */
    for (std::size_t i = 0; i < kmeans_cluster_algorithm<T>::data()->size(); ++i) {
      kmeans_cluster_algorithm<T>::clusters()->at(i).update_center();
    } /* for(i..) */

    /* Finally, check for convergence */
    for (std::size_t i = 0; i < kmeans_cluster_algorithm<T>::clusters()->size(); ++i) {
      if (!kmeans_cluster_algorithm<T>::clusters()->at(i).convergence()) {
        return false;
      }
    } /* for(i..) */
    return true;
  } /* kmeans_cluster_Openmp::cluster_iterate() */

  float euclidean_dist(const T& p1,
                       const T& p2) const {
    float dist = -1;
    for (auto& e1 : p1) {
      for (auto& e2 : p2) {
        dist += std::pow(e1 - e2, 2);
      } /* for(e2...) */
    } /* for(e1...) */

    return dist;
  } /* kmeans_cluster_worker::euclidean_dist() */

 private:
  /* member functions */

  /* data members */
};

} /* namespace rcppsw */

#endif /* INCLUDE_KMEANS_CLUSTER_OPENMP_HPP_ */
