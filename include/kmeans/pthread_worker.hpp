/*******************************************************************************
 * Name            : pthread_worker.hpp
 * Project         : rcppsw
 * Module          : kmeans
 * Description     : Workers for pthread-based implementation of K-means
 *                   clustering
 * Creation Date   : 02/02/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_KMEANS_PTHREAD_WORKER_HPP_
#define INCLUDE_KMEANS_PTHREAD_WORKER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <limits>
#include <boost/shared_ptr.hpp>
#include "include/threadable.hpp"
#include "include/kmeans/cluster.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {
namespace kmeans {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template <typename T> class pthread_worker: public threadable {
 public:
  /* constructors */
  pthread_worker(std::size_t id, std::size_t n_threads, std::size_t chunk_size, std::size_t dimension,
                 const boost::shared_ptr<std::vector<kmeans_cluster<T>*>>& clusters) :
      threadable(), id_(id), n_threads_(n_threads), chunk_size_(chunk_size), dimension_(dimension),
      clusters_(const_cast<boost::shared_ptr<std::vector<kmeans_cluster<T>*>>&>(clusters)) {}

  /* member functions */
  void* thread_main(void* arg) {
    if (NULL == arg) {
      std::size_t n_centers = clusters_->size()/n_threads_;
      for (std::size_t i = n_centers * id_; i < n_centers * id_ + n_centers; ++i) {
        DBGD("Worker %lu: updating cluster %lu center\n",id_, i);
        clusters_->at(i)->update_center();
      } /* for(i..) */
      return NULL;
    }
    double *data = (double*)arg;

    DBGN("Worker %lu: %lu - %lu\n", id_, chunk_size_ * id_,
         chunk_size_ * id_ + chunk_size_);

    /*
     * For each point in the data that is assigned to the current thread,
     * calculate its Euclidean distance from the center of each to the point,
     * and assign the point to the closest cluster.
     */
    for (std::size_t i = id_ * chunk_size_; i < id_ * chunk_size_ + chunk_size_; ++i) {
      int closest = -1;
      double min_dist = std::numeric_limits<float>::max();
          for (std::size_t j = 0; j < clusters_->size(); ++j) {
            double dist = clusters_->at(j)->dist_to_center(data + (i * dimension_));
            if (dist < min_dist) {
              min_dist = dist;
              closest = j;
            }
          } /* for(j..) */
          clusters_->at(closest)->add_point(data + i * dimension_);
    } /* for(i..) */

    DBGD("Worker%lu FINISHED: cluster size: %d/%lu %d/%lu\n",id_, 0,
         clusters_->at(0)->size(),1, clusters_->at(1)->size());
    return NULL;
  } /* kmeans_pthread_worker::thread_main() */

  /* operators */
  pthread_worker(const pthread_worker& other) : threadable(),
                                                id_(other.id_),
                                                n_threads_(other.n_threads_),
                                                chunk_size_(other.chunk_size_),
                                                dimension_(other.dimension_),
                                                clusters_(other.clusters_) {}

 private:
  /* operators */
  pthread_worker& operator=(pthread_worker&) = delete;

  /* data members */
  std::size_t id_;
  std::size_t n_threads_;
  std::size_t chunk_size_;
  std::size_t dimension_;
  boost::shared_ptr<std::vector<kmeans_cluster<T>*>> clusters_;
};

} /* namespace kmeans */
} /* namespace rcppsw */

#endif /* INCLUDE_KMEANS_PTHREAD_WORKER_HPP_ */
