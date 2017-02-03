/*******************************************************************************
 * Name            : kmeans_cluster.hpp
 * Project         : rcppsw
 * Module          : algorithm
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

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template <typename T> class kmeans_cluster {
 public:
  /* constructors */
  kmeans_cluster(void): queue_(), center_(), hash_(0) {}

  /* member functions */
  const std::vector<T>& center(void) { return center_; }
  std::size_t size(void) { return queue_.size(); }

  void add(const std::vector<T>& point) { queue_.push_back(&point); }
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
  void update_center(void) const {
    std::vector<T> accum(queue_[0]->size());
    prev_center_ = center_;
    prev_hash_ = hash_;
    hash_ = 0;
    std::for_each(queue_.begin(), queue_.end(), [&](const T& e) {
        hash_ ^= 0x9e3779b9 + (hash_ << 6) + (hash_ >> 2);
        accum += *e;
      });

    /* std::for_each(accum.begin(), accum.end(), [&](const T& e) { */
    /*     e = e/accum.size(); */
    /*   }); */
    center_ = accum/accum.size();
  } /* kmeans_cluster::update_center() */

 private:
  /* member functions */

  /* data members */
  shared_queue<std::vector<T>*> queue_;
  std::vector<T> center_;
  std::vector<T> prev_center_;
  std::size_t hash_;
  std::size_t prev_hash_;
};

} /* namespace rcppsw */

#endif /* INCLUDE_KMEANS_CLUSTER_HPP_ */
