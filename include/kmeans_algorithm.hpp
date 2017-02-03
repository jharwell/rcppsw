/*******************************************************************************
 * Name            : kmeans_algorithm.hpp
 * Project         : rcppsw
 * Module          : algorithm
 * Description     : Base class implementation of K-means clustering algorithm
 * Creation Date   : 02/02/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_KMEANS_ALGORITHM_HPP_
#define INCLUDE_KMEANS_ALGORITHM_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "include/kmeans_cluster.hpp"
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
template <typename T> class kmeans_algorithm {
 public:
  /* constructors */
  kmeans_algorithm(void);

  /* member functions */
  void report_algorithms(const std::vector<std::vector<T>>& clusters) = 0;
  void report_centroids(const std::vector<T>& centroids) = 0;
  std::vector<kmeans_cluster<T>>& clusters(void) { return clusters_; }
  std::vector<std::vector<T>>& data(void) { return data_; }

  void cluster(void) {
    for (int i = 0; i < n_iterations_; ++i) {
      if (cluster_iterate()) {
        break;
      }
    } /* for(i..) */
  } /* kmeans_algorithm::cluster() */

 protected:
  bool cluster_iterate(void) = 0;

 private:
  /* member functions */

  /* data members */
  std::vector<std::vector<T>> data_;
  int n_iterations_;
  std::vector<kmeans_cluster<T>> clusters_;
};

} /* namespace rcppsw */

/*******************************************************************************
 * Operater Definitions
 ******************************************************************************/

#endif /* INCLUDE_KMEANS_ALGORITHM_HPP_ */
