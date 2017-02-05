/*******************************************************************************
 * Name            : cluster_algorithm.hpp
 * Project         : rcppsw
 * Module          : kmeans
 * Description     : Base class implementation of K-means clustering algorithm
 * Creation Date   : 02/02/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_KMEANS_CLUSTER_ALGORITHM_HPP_
#define INCLUDE_KMEANS_CLUSTER_ALGORITHM_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "include/kmeans/cluster.hpp"

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
template <typename T> class cluster_algorithm {
 public:
  /* constructors */
  cluster_algorithm(int n_iterations,
                           const std::string& clusters_fname,
                           const std::string& centroids_fname,
                           const std::vector<T>* const data) :
      n_iterations_(n_iterations), clusters_fname_(clusters_fname),
      centroids_fname_(centroids_fname), data_(data), clusters_(NULL) {}
  virtual ~cluster_algorithm(void) {}

  /* member functions */
  std::vector<kmeans_cluster<T>>* clusters(void) { return clusters_; }
  const std::vector<T>* data(void) { return data_; }

  virtual void report_clusters(void) {
    std::ofstream ofile(clusters_fname_);
    std::for_each(cluster_algorithm<T>::clusters()->begin(),
                  cluster_algorithm<T>::clusters()->end(),
                  [&](const kmeans_cluster<T>& c) {
                    ofile << c;
                  });
  }
  virtual void report_centroids(void) {
    std::ofstream ofile(centroids_fname_);
    std::for_each(cluster_algorithm<T>::clusters()->begin(),
                  cluster_algorithm<T>::clusters()->end(),
                  [&](const kmeans_cluster<T>& c) {
                    ofile << &c.center();
                  });
  }

  void cluster(void) {
    for (int i = 0; i < n_iterations_; ++i) {
      if (cluster_iterate()) {
        break;
      }
    } /* for(i..) */
  } /* cluster_algorithm::cluster() */

 protected:
  virtual bool cluster_iterate(void) = 0;

 private:
  /* member functions */
  cluster_algorithm(const cluster_algorithm& other) = delete;
  cluster_algorithm& operator=(const cluster_algorithm& other) = delete;

  /* data members */
  int n_iterations_;
  const std::string& clusters_fname_;
  const std::string& centroids_fname_;
  const std::vector<T>* const data_;
  std::vector<kmeans_cluster<T>>* clusters_;
};

} /* namespace kmeans */
} /* namespace rcppsw */

#endif /* INCLUDE_KMEANS_CLUSTER_ALGORITHM_HPP_ */
