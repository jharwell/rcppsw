/*******************************************************************************
 * Name            : cluster_openmp.hpp
 * Project         : rcppsw
 * Module          : kmeans
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
#include <omp.h>
#include <vector>
#include <string>
#include "include/kmeans/cluster_algorithm.hpp"

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
  cluster_algorithm(std::size_t n_iterations,
                    std::size_t n_clusters,
                    std::size_t n_threads,
                    std::size_t dimension,
                    std::size_t n_points,
                    const std::string& clusters_fname,
                    const std::string& centroids_fname) :
      cluster_algorithm<T>(n_iterations, n_clusters, n_threads, dimension,
                           n_points, clusters_fname, centroids_fname) {}
  /* member functions */
  /*
   * Initialize the algorithm, performing first touch allocation and copying the
   * provided data into a format that can be efficiently processed.
   */
  void initialize(std::vector<multidim_point<T>>* data_in) {

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

    /*
     * Initialize center for all clusters
     */
    for (std::size_t i = 0; i < cluster_algorithm<T>::n_clusters(); ++i) {
      cluster_algorithm<T>::clusters()->at(i)->initialize_center(data_in->at(i).data());
    } /* for(i..) */

    for (std::size_t i = 0; i < cluster_algorithm<T>::n_points(); ++i) {
      std::copy(data_in->at(i).begin(), data_in->at(i).end(),
                cluster_algorithm<T>::data() + (i * dimension));
    } /* for(i..) */
  } /* load_data() */

  /**
   * cluster_openmp::cluster_iterate() - Perform one iteration of the
   * K-means clustering algorithm
   *
   * RETURN:
   *     bool - true if convergence was achieved, false otherwise
   **/
  bool cluster_iterate(void) {
#pragma omp parallel for num_threads(cluster_algorithm<T>::n_threads())
    for (std::size_t i = 0; i < cluster_algorithm<T>::clusters()->size(); ++i) {
      cluster_algorithm<T>::clusters()->at(i)->reset();
    } /* for(i..) */

    /*
     * cluster the data via Euclidean distance, putting each matching vector
     * into the queue with the closest centroid.
     */
#pragma omp parallel for num_threads(cluster_algorithm<T>::n_threads())
    for (std::size_t i = 0; i < cluster_algorithm<T>::data()->size(); ++i) {
      int closest = -1;
      double min_dist = std::numeric_limits<float>::max();
      for (std::size_t j = 0; j < cluster_algorithm<T>::clusters()->size(); ++j) {
        double dist = cluster_algorithm<T>::clusters()->at(j)->dist_to_center(cluster_algorithm<T>::data()->at(i));
        if (dist < min_dist) {
          min_dist = dist;
          closest = j;
        }
      } /* for(j..) */
      cluster_algorithm<T>::clusters()->at(closest)->add_point(&(const_cast<std::vector<T>*>(cluster_algorithm<T>::data())->at(i)));
    } /* for(i..) */

    /*
     * Update the center/hash for all clusters
     */
#pragma omp parallel for num_threads(cluster_algorithm<T>::n_threads())
    for (std::size_t i = 0; i < cluster_algorithm<T>::clusters()->size(); ++i) {
      cluster_algorithm<T>::clusters()->at(i)->update_center();
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

#endif /* INCLUDE_KMEANS_CLUSTER_OPENMP_HPP_ */
