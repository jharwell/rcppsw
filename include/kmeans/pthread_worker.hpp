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
#include <vector>
#include <limits>
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
  pthread_worker(int id, int n_threads,
                 std::vector<kmeans_cluster<T>*>* clusters) :
      threadable(), id_(id), n_threads_(n_threads), clusters_(clusters) {}

  /* member functions */
  void* thread_main(void* arg) {
    assert(clusters_->size() % n_threads_ == 0);
    if (NULL == arg) {
      int n_centers = clusters_->size()/n_threads_;
      for (int i = n_centers * id_; i < n_centers; ++i) {
        DBGD("Worker %d: updating cluster %d center\n",id_, i);
        clusters_->at(i)->update_center();
      } /* for(i..) */
      return NULL;
    }
    std::vector<T>* data = static_cast<std::vector<T>*>(arg);
    assert(data->size() % n_threads_ == 0);
    std::size_t n_iterations = data->size()/n_threads_;

    DBGN("Worker %d: %lu - %lu\n", id_, n_iterations * id_,
         n_iterations * id_ + n_iterations );
    for (std::size_t i = n_iterations * id_; i < n_iterations * id_ + n_iterations; ++i) {
      int min_queue = 0;
      float min_dist = std::numeric_limits<float>::max();
          for (std::size_t j = 0; j < clusters_->size(); ++j) {
            float dist = euclidean_dist(clusters_->at(j)->center(), data->at(i));
        if (dist < min_dist) {
          min_dist = dist;
          min_queue = j;
        }
      } /* for(j..) */
      clusters_->at(min_queue)->add(&data->at(i));
    } /* for(i..) */
    return NULL;
  } /* kmeans_pthread_worker::thread_main() */

  /* operators */
  pthread_worker(const pthread_worker& other) : threadable(),
                                                id_(other.id_),
                                                n_threads_(other.n_threads_),
                                                clusters_(other.clusters_) {}

 private:
  /* member functions */
  float euclidean_dist(const T& center,
                       const T& point) const {
    float sum1 = 0;
    float sum2 = 0;
    for (auto& e : center) {
      sum1 += e;
    } /* for(e...) */
    for (auto& e : point) {
      sum2 += std::pow(e, 2);
    } /* for(e...) */
    return std::abs(sum1 - sum2);
  } /* kmeans_pthread_worker::euclidean_dist() */

  /* operators */
  pthread_worker& operator=(pthread_worker&) = delete;

  /* data members */
  int id_;
  int n_threads_;
  std::vector<kmeans_cluster<T>*>* clusters_;
};

} /* namespace kmeans */
} /* namespace rcppsw */

#endif /* INCLUDE_KMEANS_PTHREAD_WORKER_HPP_ */
