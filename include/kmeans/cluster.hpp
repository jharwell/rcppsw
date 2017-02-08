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
#include <iomanip>
#include <vector>

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
  kmeans_cluster(std::size_t id, std::size_t dimension,
                 const T* const data, std::size_t * const membership) :
      id_(id),
      dimension_(dimension),
      data_(data),
      membership_(membership),
      center_(dimension),
      prev_center_(dimension) {

    /* initialize center */
    for (std::size_t i = 0; i < dimension_; ++i) {
      center_[i] = data_[id_*dimension_ + i];
    } /* for(i..) */
  }

  void add_point(std::size_t idx) { membership_[idx] = id_; }

  double dist_to_center(const T* const point) {
    T sum = 0;
    for (std::size_t i = 0; i < dimension_; ++i) {
      sum += std::pow(point[i] - center_[i],2);
    } /* for(i..) */

    return sum;
  }
  /* Each cluster knows how to report its own center to a file */
  void report_center(std::ofstream& stream) const {
    for (std::size_t i = 0; i < (dimension_); ++i) {
      stream << std::fixed << std::setprecision(3) << center_[i]  << " ";
    } /* for(i..) */
    stream << std::endl;
  } /* report_center() */

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
  void update_center(std::size_t total_points) {
    std::vector<T> accum(dimension_);
    prev_center_ = center_;
    /*
     * To compute the center, square each point currently in the cluster, and
     * sum. Divide the sum by the # of points in the cluster to get the new
     * center. Note that no sqrt() is used, as all calculations can be done in
     * "squared" space to save CPU cycles.
     */
    std::size_t cluster_points = 0;
    for (std::size_t i = 0; i < total_points; ++i) {
      if (membership_[i] == id_) {
        for (std::size_t j = 0; j < dimension_; ++j) {
          accum[j] += data_[i*dimension_ + j];
        } /* for(j..) */
        ++cluster_points;
      }
    } /* for(i..) */

    /*
     * Normalize sum by dividing by # items in cluster
     */
    for (std::size_t i = 0; i < accum.size(); ++i) {
      accum[i] /= cluster_points;
    } /* for(i..) */
    center_ = accum;
  } /* kmeans_cluster::update_center() */

 private:
  /* member functions */

  /* data members */
  std::size_t id_;
  std::size_t dimension_;
  const T* const data_;
  std::size_t* const membership_;
  std::vector<T> center_;
  std::vector<T> prev_center_;
};

} /* namespace kmeans */
} /* namespace rcppsw */

#endif /* INCLUDE_KMEANS_CLUSTER_HPP_ */
