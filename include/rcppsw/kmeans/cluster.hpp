/**
 * @file cluster.hpp
 *
 * @copyright 2017 John Harwell, All rights reserved.
 *
 * This file is part of RCPPSW.
 *
 * RCPPSW is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * RCPPSW is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * RCPPSW.  If not, see <http://www.gnu.org/licenses/
 */
#ifndef INCLUDE_RCPPSW_KMEANS_CLUSTER_HPP_
#define INCLUDE_RCPPSW_KMEANS_CLUSTER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, kmeans);

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
template <typename T>
using multidim_point = std::vector<T>;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Representation of the current state of a cluster during the execution
 *        of the clustering algorithm.
 */

template <typename T>
class kmeans_cluster {
 public:
  kmeans_cluster(std::size_t id,
                 std::size_t dimension,
                 std::size_t n_points,
                 const T* const data,
                 std::size_t* const membership)
      : m_id(id),
        m_dimension(dimension),
        m_n_points(n_points),
        m_data(data),
        m_membership(membership),
        m_center(dimension),
        m_prev_center(dimension) {
    /* initialize center */
    for (std::size_t i = 0; i < m_dimension; ++i) {
      m_center[i] = m_data[m_id * m_dimension + i];
    } /* for(i..) */
  }

  void add_point(std::size_t idx) { m_membership[idx] = m_id; }

  double dist_to_center(const T* const point) {
    T sum = 0;
    for (std::size_t i = 0; i < m_dimension; ++i) {
      sum += std::pow(point[i] - m_center[i], 2);
    } /* for(i..) */

    return sum;
  }
  /* Each cluster knows how to report its own center to a file */
  void report_center(std::ofstream& stream) const {
    for (std::size_t i = 0; i < (m_dimension); ++i) {
      stream << std::fixed << std::setprecision(3) << m_center[i] << " ";
    } /* for(i..) */
    stream << std::endl;
  } /* report_center() */

  /*
   * Determine if the cluster has converged, by checking if the center of the
   * cluster has changed.
   */
  std::size_t convergence(void) { return (m_prev_center == m_center); }

  /**
   * kmeans_cluster::update_center() - Update the center (mean) of the points
   * in the cluster after an iteration is finished
   *
   * void - N/A
   **/
  void update_center(void) {
    std::vector<T> accum(m_dimension);
    m_prev_center = m_center;
    /*
     * To compute the center, square each point currently in the cluster, and
     * sum. Divide the sum by the # of points in the cluster to get the new
     * center. Note that no sqrt() is used, as all calculations can be done in
     * "squared" space to save CPU cycles.
     */
    std::size_t cluster_points = 0;
    for (std::size_t i = 0; i < m_n_points; ++i) {
      if (m_membership[i] == m_id) {
        for (std::size_t j = 0; j < m_dimension; ++j) {
          accum[j] += m_data[i * m_dimension + j];
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
    m_center = accum;
  } /* kmeans_cluster::update_center() */

 private:
  kmeans_cluster& operator=(const kmeans_cluster&) = delete;
  kmeans_cluster(const kmeans_cluster&) = delete;

  std::size_t m_id;
  std::size_t m_dimension;
  std::size_t m_n_points;
  const T* const m_data;
  std::size_t* const m_membership;
  std::vector<T> m_center;
  std::vector<T> m_prev_center;
};

NS_END(kmeans, rcppsw);

#endif /* INCLUDE_RCPPSW_KMEANS_CLUSTER_HPP_ */
