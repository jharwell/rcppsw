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
#include "include/mt_vector.hpp"

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
  kmeans_cluster(std::size_t dimension): vector_(),
                                         center_(dimension),
                                         prev_center_(dimension),
                                         hash_(),
                                         prev_hash_(),
                                         dimension_(dimension) {}

    /* reentrant member functions */
  void add_point(T *point) { vector_.push_back(point); }

  /* non reentrant member functions */
  void initialize_center(T* center) {
    add_point(center);
    update_center();
    reset();
  }
  typename mt_vector<T>::const_iterator begin(void) { return vector_.begin(); }
  typename mt_vector<T>::const_iterator end(void) { return vector_.end(); }
  const T* center(void) const { return center_; }
  std::size_t size(void) const { return vector_.size(); }
  void reset(void) { vector_.clear(); }

  double dist_to_center(const T* const point) {
    T sum = 0;
    for (std::size_t i = 0; i < dimension_; ++i) {
      sum += std::pow(point[i] - center_[i],2);
    } /* for(i..) */

    return sum;
  }

  void report_center(std::ofstream& stream) const {
    for (std::size_t i = 0; i < dimension_; ++i) {
      stream << std::fixed << std::setprecision(3) << center_[i]  << " ";
    } /* for(i..) */
    stream << std::endl;
  } /* report_center() */

  /* Determine if a point is contained within the vector */
  bool contains_point(const T* const point) {
    for (std::size_t i = 0; i < vector_.size(); ++i) {
      if (memcmp(vector_[i], point, dimension_* sizeof(T)) == 0) {
        return true;
      }
    } /* for(i..) */
    return false;
  }

  /*
   * Determine if the cluster has converged, by checking if the center of the
   * cluster has changed.
   */
  bool convergence(void) { return (prev_hash_ == hash_ && prev_center_ == center_); }

  /**
   * kmeans_cluster::update_center() - Update the center (mean) of the points
   * in the cluster after an iteration is finished
   *
   * void - N/A
   **/
  void update_center(void) {
    std::vector<T> accum(dimension_);
    prev_center_ = center_;
    prev_hash_ = hash_;

    /*
     * To compute the center, square each point currently in the cluster, and
     * sum. Divide the sum by the # of points in the cluster to get the new
     * center. Note that no sqrt() is used, as all calculations can be done in
     * "squared" space to save CPU cycles.
     */
    std::size_t hash_ = vector_.size();
    for (std::size_t i = 0; i < vector_.size(); ++i) {
      for (std::size_t j = 0; j < dimension_; ++j) {
        accum[j] += vector_[i][j];
        hash_ ^= (std::size_t)vector_[i][j] + 0x9e3779b9 + (hash_ << 6) + (hash_ >> 2);
      } /* for(j..) */
    } /* for(i..) */

    for (std::size_t i = 0; i < accum.size(); ++i) {
      accum[i] /= vector_.size();
    } /* for(i..) */
    center_ = accum;
  } /* kmeans_cluster::update_center() */

 private:
  /* member functions */

  /* data members */
  mt_vector<T*> vector_;
  std::vector<T> center_;
  std::vector<T> prev_center_;
  std::size_t hash_;
  std::size_t prev_hash_;
  std::size_t dimension_;
};

} /* namespace kmeans */
} /* namespace rcppsw */

#endif /* INCLUDE_KMEANS_CLUSTER_HPP_ */
