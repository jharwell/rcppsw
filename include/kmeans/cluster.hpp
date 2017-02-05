/*******************************************************************************
 * Name            : cluster.hpp
 * Project         : rcppsw
 * Module          : kmeans
 * Description     : Representation of the current state of a cluster during the
 *                   execution of the clustering algorithm
 * Creation Date   : 02/02/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_KMEANS_CLUSTER_HPP_
#define INCLUDE_KMEANS_CLUSTER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <algorithm>
#include "include/shared_queue.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw {
namespace kmeans {

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
template <typename T>
using multidim_point = std::vector<T>;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template <typename T> class kmeans_cluster {
 public:
  /* constructors */
  kmeans_cluster(void): queue_(), center_(), hash_(0) {}

  /* member functions */
  friend std::ostream& operator<<(std::ostream& stream,
                                  const kmeans_cluster<T>& cluster) {
    std::for_each(cluster.queue_.begin(), cluster.queue_.end(),
                  [&](const T* p) {
                    stream << p;
                  });
    return stream;
  } /* operator<<() */

  /* Const iterators: thread safe */
  typename shared_queue<T>::const_iterator begin(void) { return queue_.begin(); }
  typename shared_queue<T>::const_iterator end(void) { return queue_.end(); }

  const T& center(void) const { return center_; }
  std::size_t size(void) const { return queue_.size(); }
  void add(T *point) { queue_.enqueue(point); }

  bool convergence(void) {
    if (prev_hash_ == hash_ && prev_center_ == center_) {
      return true;
    }
    return false;
  } /* kmeans_cluster::convergence() */

  /**
   * kmeans_cluster::update_center() - Update the center (mean) of the points
   * in the cluster after an iteration is finished
   *
   * void - N/A
   **/
  void update_center(void) {
    T accum(queue_.size());
    prev_center_ = center_;
    prev_hash_ = hash_;
    hash_ = 0;

    std::for_each(queue_.begin(), queue_.end(), [&](T* e) {
        for (std::size_t i = 0; i < e->size(); ++i) {
          /* hash_ ^= 0x9e3779b9 + (hash_ << 6) + (hash_ >> 2); */
          accum[i] += e->at(i);
        } /* for(i..) */
      });

    for (std::size_t i = 0; i < accum.size(); ++i) {
      accum[i] = accum[i]/accum.size();
    } /* for(i..) */
    center_ = accum;
  } /* kmeans_cluster::update_center() */

 private:
  /* member functions */

  /* data members */
  shared_queue<T*> queue_;
  T center_;
  T prev_center_;
  std::size_t hash_;
  std::size_t prev_hash_;
};

} /* namespace kmeans */
} /* namespace rcppsw */

#endif /* INCLUDE_KMEANS_CLUSTER_HPP_ */
