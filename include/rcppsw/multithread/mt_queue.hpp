/**
 * @file mt_queue.hpp
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

  // Add data to the queue and notify others
  void enqueue(const T& data) {
    // Acquire lock on the queue
    boost::unique_lock<boost::mutex> lock(m_mtx);

    // Add the data to the queue
    m_queue.push_back(data);

    // Notify others that data is ready
    m_cv.notify_one();
  } // Lock is automatically released here

  // Get data from the queue. Wait for data if not available
  T dequeue() {
    // Acquire lock on the queue
    boost::unique_lock<boost::mutex> lock(m_mtx);

    // When there is no data, wait till someone fills it.
    // Lock is automatically released in the wait and obtained
    // again after the wait
    while (m_queue.empty()) { m_cv.wait(lock); }

    // Retrieve the data from the queue
    auto result = static_cast<T>(m_queue.front());
    m_queue.pop_front();
    return result;
  } // Lock is automatically released here

  // get the size of the queue
  size_t size() const { return m_queue.size(); }
  T front(void) { return m_queue.front(); }
  void clear(void) { m_queue.clear(); }
  const T& operator[](std::size_t pos) const { return m_queue[pos]; }

 private:
  std::deque<T> m_queue;          /// Use STL queue to store data
  boost::mutex m_mtx;             /// The mutex to synchronise on
  boost::condition_variable m_cv; /// The condition to wait for
};

NS_END(multithread, rcppsw);

#endif /* INCLUDE_RCPPSW_MULTITHREAD_MT_QUEUE_HPP_ */
