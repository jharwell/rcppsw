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

#ifndef INCLUDE_RCPPSW_KMEANS_PTHREAD_WORKER_HPP_
#define INCLUDE_RCPPSW_KMEANS_PTHREAD_WORKER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <sched.h>
#include <pthread.h>
#include <list>
#include <limits>
#include <boost/shared_ptr.hpp>
#include "rcppsw/threadable.hpp"
#include "rcppsw/kmeans/cluster.hpp"
#include "rcsw/multithread/threadm.h"

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
  pthread_worker(std::size_t id, std::size_t points_start,
                 std::size_t points_size, std::size_t centers_start,
                 std::size_t centers_size, std::size_t dimension,
                 const boost::shared_ptr<std::vector<kmeans_cluster<T>*>>& clusters) :
      threadable(), id_(id), points_start_(points_start),
      points_size_(points_size), centers_start_(centers_start),
      centers_size_(centers_size), dimension_(dimension),
      clusters_(const_cast<boost::shared_ptr<std::vector<kmeans_cluster<T>*>>&>(clusters)) {
  }

  enum instruction {
    FIRST_TOUCH,
    UPDATE_CENTER,
    CLUSTER_POINTS
  };
  struct instruction_data {
    enum instruction type;
    T* const data;
    std::size_t* membership;
  };

  /* member functions */
  void* thread_main(void* arg) {
    ER_REPORT(er_lvl::DIAG, "%lu: points %lu - %lu, centers %lu - %lu\n",id_, 
               points_start_, points_start_ + points_size_, centers_start_, 
               centers_start_ + centers_size_); 
    /*
     * Lock each new invocation to a core--don't want the OS moving threads
     * around.
     */
    threadm_core_lock(thread_handle(), id_);
    struct instruction_data* instr = (struct instruction_data*)arg;

    if (FIRST_TOUCH == instr->type) {
      for (std::size_t i = points_start_; i < points_start_ + points_size_; ++i) {
        for (std::size_t j = 0; j < dimension_; ++j) {
          instr->data[i*dimension_+j] = 0;
        } /* for(j..) */
        instr->membership[i] = -1;
      } /* for(i...) */
      return NULL;
    } else if (UPDATE_CENTER == instr->type) {

      /*
       * Each thread is responsible for update the centers of clusters that fall
       * within a range based on the id of the thread
       */
      for (std::size_t i = centers_start_; i < centers_start_ + centers_size_; ++i) {
        clusters_->at(i)->update_center();
      } /* for(i..) */
      return NULL;
    } else {

    /*
     * For each point in the data that is assigned to the current thread,
     * calculate its Euclidean distance from the center of each to the point,
     * and assign the point to the closest cluster.
     */
      for (std::size_t i = points_start_; i < points_start_ + points_size_; ++i) {
      int closest = -1;
      double min_dist = std::numeric_limits<float>::max();
      for (std::size_t j = 0; j < clusters_->size(); ++j) {
        double dist = clusters_->at(j)->dist_to_center(instr->data + i * dimension_);
        if (dist < min_dist) {
          min_dist = dist;
          closest = j;
        }
      } /* for(j..) */
      clusters_->at(closest)->add_point(i);
    } /* for(i..) */

    return NULL;
    }
  } /* kmeans_pthread_worker::thread_main() */

  /* operators */
  pthread_worker(const pthread_worker& other) : threadable(),
                                                id_(other.id_),
                                                points_start_(other.points_start_),
                                                points_size_(other.points_size_),
                                                centers_start_(other.centers_start_),
                                                centers_size_(other.centers_size_),
                                                dimension_(other.dimension_),
                                                clusters_(other.clusters_) {}

 private:
  /* operators */
  pthread_worker& operator=(pthread_worker&) = delete;

  /* data members */
  std::size_t id_;
  std::size_t points_start_;
  std::size_t points_size_;
  std::size_t centers_start_;
  std::size_t centers_size_;
  std::size_t dimension_;
  boost::shared_ptr<std::vector<kmeans_cluster<T>*>> clusters_;
};

} /* namespace kmeans */
} /* namespace rcppsw */

#endif /* INCLUDE_RCPPSW_KMEANS_PTHREAD_WORKER_HPP_ */
