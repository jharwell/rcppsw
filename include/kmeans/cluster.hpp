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
  kmeans_cluster(T *initial_center): queue_(),
                                     center_(),
                                     prev_center_() {
    add(initial_center);
    update_center();
    reset();
  }

  /* reentrant member functions */
  void add(T *point) { queue_.enqueue(point); }

  /* non reentrant member functions */
  typename shared_queue<T>::const_iterator begin(void) { return queue_.begin(); }
  typename shared_queue<T>::const_iterator end(void) { return queue_.end(); }
  const T& center(void) const { return center_; }
  std::size_t size(void) const { return queue_.size(); }
  void reset(void) { queue_.clear(); }

  void report_center(std::ofstream& stream) {
    using value_type = typename T::value_type;
    std::for_each(center_.begin(), center_.end(),
                  [&](const value_type& p) {
                    stream << std::sqrt(p)  << " ";
                  });
    stream << std::endl;
  } /* report_center() */

  /* Determine if a point is contained within the queue */
  bool contains_point(const T& point) {
    return (std::find(queue_.begin(), queue_.end(), &point) != queue_.end());
  }

  /*
   * Determine if the cluster has converged, by checking if the center of the
   * cluster has changed.
   */
  bool convergence(void) { return (prev_center_ == center_); }

  /**
   * kmeans_cluster::update_center() - Update the center (mean) of the points
   * in the cluster after an iteration is finished
   *
   * void - N/A
   **/
  void update_center(void) {
    T accum(queue_.front()->size());
    prev_center_ = center_;

    /*
     * To compute the center, square each point currently in the cluster, and
     * sum. Divide the sum by the # of points in the cluster to get the new
     * center. Note that no sqrt() is used, as all calculations can be done in
     * "squared" space to save CPU cycles.
     */
    std::for_each(queue_.begin(), queue_.end(), [&](T* e) {
        for (std::size_t i = 0; i < e->size(); ++i) {
          accum[i] += std::pow(e->at(i), 2);
        } /* for(i..) */
      });

    for (std::size_t i = 0; i < accum.size(); ++i) {
      accum[i] = accum[i]/queue_.size();
    } /* for(i..) */
    center_ = accum;
  } /* kmeans_cluster::update_center() */

 private:
  /* member functions */

  /* data members */
  shared_queue<T*> queue_;
  T center_;
  T prev_center_;
};

} /* namespace kmeans */
} /* namespace rcppsw */

#endif /* INCLUDE_KMEANS_CLUSTER_HPP_ */
