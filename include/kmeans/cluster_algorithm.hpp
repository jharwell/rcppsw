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
#include "rcsw/include/common/dbg.h"

/*******************************************************************************
 * Constant Definitions
 ******************************************************************************/
#define M_KMEANS M_EXTERNAL
#define MODULE_ID M_KMEANS

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {
namespace kmeans {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template <typename T> class cluster_algorithm {
 public:
  /* constructors */
  cluster_algorithm(std::size_t n_iterations,
                    std::size_t n_clusters,
                    const std::string& clusters_fname,
                    const std::string& centroids_fname,
                    const std::vector<T>* const data) :
      n_iterations_(n_iterations), clusters_fname_(clusters_fname),
      centroids_fname_(centroids_fname), data_(data),
      clusters_(new std::vector<kmeans_cluster<T>*>()) {

    dbg_init();
    dbg_insmod(M_KMEANS, "KMEANS");
    DBGN("n_points=%lu, n_clusters=%lu, n_iterations=%lu\n",data->size(),
         n_clusters, n_iterations);

    for (std::size_t i = 0; i < n_clusters; ++i) {
      clusters_->push_back(new kmeans_cluster<T>(&(const_cast<std::vector<T>*>(data))->at(i)));
    } /* for(i..) */
  }

  virtual ~cluster_algorithm(void) {}

  /* member functions */
  std::vector<kmeans_cluster<T>*>* clusters(void) { return clusters_; }
  const std::vector<T>* data(void) { return data_; }

  virtual void report_clusters(void) {
    std::ofstream ofile(clusters_fname_);
    for (std::size_t j = 0; j < data_->size(); ++j) {
      std::size_t i = 0;
      for (i = 0; i < cluster_algorithm<T>::clusters()->size(); ++i) {
        if (cluster_algorithm<T>::clusters()->at(i)->contains_point(data_->at(j))) {
          ofile << i << std::endl;
          ofile.flush();
          break;
        }
      } /* for(i..) */
      assert(i < cluster_algorithm<T>::clusters()->size());
    } /* for(j..) */
  }
  virtual void report_centroids(void) {
    std::ofstream ofile(centroids_fname_);
    ofile << cluster_algorithm<T>::clusters()->size() << " " << data_->at(0).size() << std::endl;
    std::for_each(cluster_algorithm<T>::clusters()->begin(),
                  cluster_algorithm<T>::clusters()->end(),
                  [&](kmeans_cluster<T>* c) {
                    c->report_center(ofile);
                  });
  }

  void cluster(void) {
    DBGTN("Begin clustering\n")
    for (int i = 0; i < n_iterations_; ++i) {
      DBGTN("Iteration %d\n",i);
      if (cluster_iterate()) {
        DBGTN("Clusters report convergence: terminating\n");
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
  std::vector<kmeans_cluster<T>*>* clusters_;
};

} /* namespace kmeans */
} /* namespace rcppsw */

#endif /* INCLUDE_KMEANS_CLUSTER_ALGORITHM_HPP_ */
