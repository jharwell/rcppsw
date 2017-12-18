/**
 * @file pthread_worker.hpp
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

#ifndef INCLUDE_RCPPSW_KMEANS_PTHREAD_WORKER_HPP_
#define INCLUDE_RCPPSW_KMEANS_PTHREAD_WORKER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <pthread.h>
#include <sched.h>
#include <boost/shared_ptr.hpp>
#include <limits>
#include <list>
#include <vector>
#include "rcppsw/common/common.hpp"
#include "rcppsw/kmeans/cluster.hpp"
#include "rcppsw/multithread/threadable.hpp"
#include "rcsw/multithread/threadm.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, kmeans);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template <typename T>
class pthread_worker : public multithread::threadable {
 public:
  pthread_worker(
      std::size_t id,
      std::size_t points_start,
      std::size_t points_size,
      std::size_t centers_start,
      std::size_t centers_size,
      std::size_t dimension,
      const boost::shared_ptr<std::vector<kmeans_cluster<T>*>>& clusters)
      : threadable(),
        m_id(id),
        m_points_start(points_start),
        m_points_size(points_size),
        m_centers_start(centers_start),
        m_centers_size(centers_size),
        m_dimension(dimension),
        m_clusters(
            const_cast<boost::shared_ptr<std::vector<kmeans_cluster<T>*>>&>(
                clusters)) {}

  enum instruction { FIRST_TOUCH, UPDATE_CENTER, CLUSTER_POINTS };
  struct instruction_data {
    enum instruction type;
    T* const data;
    std::size_t* membership;
  };

  void* thread_main(void* arg) {
    ER_REPORT("%lu: points %lu - %lu, centers %lu - %lu\n",
              m_id,
              m_points_start,
              m_points_start + m_points_size,
              m_centers_start,
              m_centers_start + m_centers_size);
    /*
     * Lock each new invocation to a core--don't want the OS moving threads
     * around.
     */
    threadm_core_lock(thread_handle(), m_id);
    struct instruction_data* instr = (struct instruction_data*)arg;

    if (FIRST_TOUCH == instr->type) {
      for (std::size_t i = m_points_start; i < m_points_start + m_points_size;
           ++i) {
        for (std::size_t j = 0; j < m_dimension; ++j) {
          instr->data[i * m_dimension + j] = 0;
        } /* for(j..) */
        instr->membership[i] = -1;
      } /* for(i...) */
      return NULL;
    } else if (UPDATE_CENTER == instr->type) {
      /*
       * Each thread is responsible for update the centers of clusters that fall
       * within a range based on the id of the thread
       */
      for (std::size_t i = m_centers_start; i < m_centers_start + m_centers_size;
           ++i) {
        m_clusters->at(i)->update_center();
      } /* for(i..) */
      return NULL;
    } else {
      /*
       * For each point in the data that is assigned to the current thread,
       * calculate its Euclidean distance from the center of each to the point,
       * and assign the point to the closest cluster.
       */
      for (std::size_t i = m_points_start; i < m_points_start + m_points_size;
           ++i) {
        int closest = -1;
        double min_dist = std::numeric_limits<float>::max();
        for (std::size_t j = 0; j < m_clusters->size(); ++j) {
          double dist =
              m_clusters->at(j)->dist_to_center(instr->data + i * m_dimension);
          if (dist < min_dist) {
            min_dist = dist;
            closest = j;
          }
        } /* for(j..) */
        m_clusters->at(closest)->add_point(i);
      } /* for(i..) */

      return NULL;
    }
  } /* kmeans_pthread_worker::thread_main() */

  pthread_worker(const pthread_worker& other)
      : threadable(),
        m_id(other.m_id),
        m_points_start(other.m_points_start),
        m_points_size(other.m_points_size),
        m_centers_start(other.m_centers_start),
        m_centers_size(other.m_centers_size),
        m_dimension(other.m_dimension),
        m_clusters(other.m_clusters) {}

 private:
  pthread_worker& operator=(pthread_worker&) = delete;

  std::size_t m_id;
  std::size_t m_points_start;
  std::size_t m_points_size;
  std::size_t m_centers_start;
  std::size_t m_centers_size;
  std::size_t m_dimension;
  boost::shared_ptr<std::vector<kmeans_cluster<T>*>> m_clusters;
};

NS_END(kmeans, rcppsw);

#endif /* INCLUDE_RCPPSW_KMEANS_PTHREAD_WORKER_HPP_ */
