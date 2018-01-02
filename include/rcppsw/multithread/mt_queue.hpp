/**
 * @file mt_queue.hpp
 * @ingroup multithread
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

#ifndef INCLUDE_RCPPSW_MULTITHREAD_MT_QUEUE_HPP_
#define INCLUDE_RCPPSW_MULTITHREAD_MT_QUEUE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/thread.hpp>
#include <boost/thread/locks.hpp>
#include <deque>
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, multithread);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A simple multiple-producer/consumer queue with locking.
 */
template <typename T>
class mt_queue {
 public:
  mt_queue(void) : m_queue(), m_mtx(), m_cv() {}

  using const_iterator = typename std::deque<T>::const_iterator;

  typename std::deque<T>::const_iterator begin(void) const {
    return m_queue.begin();
  }
  typename std::deque<T>::const_iterator end(void) const {
    return m_queue.end();
  }

  /**
   * @brief Add data to the queue and notify others
   */
  void enqueue(const T& data) {
    boost::unique_lock<boost::mutex> lock(m_mtx);
    m_queue.push_back(data);
    m_cv.notify_one();
  }

  /**
   * @brief Get data from the queue. Wait for data if not available.
   */
  T dequeue() {
    boost::unique_lock<boost::mutex> lock(m_mtx);

    /* When there is no data, wait till someone fills it. Lock is automatically
     * released in the wait and obtained again after the wait.
     */
    while (m_queue.empty()) { m_cv.wait(lock); }

    auto result = static_cast<T>(m_queue.front());
    m_queue.pop_front();
    return result;
  }

  size_t size() const { return m_queue.size(); }
  T front(void) { return m_queue.front(); }
  void clear(void) { m_queue.clear(); }
  const T& operator[](std::size_t pos) const { return m_queue[pos]; }

 private:
  std::deque<T> m_queue;
  boost::mutex m_mtx;
  boost::condition_variable m_cv;
};

NS_END(multithread, rcppsw);

#endif /* INCLUDE_RCPPSW_MULTITHREAD_MT_QUEUE_HPP_ */
