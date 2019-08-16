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
#include "rcppsw/patterns/decorator/decorator.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, multithread);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class mt_queue
 * @ingroup rcppsw multithread
 *
 * @brief A simple multiple-producer/consumer queue with locking.
 */
namespace decorator = rcppsw::patterns::decorator;
template <typename T>
class mt_queue : public decorator::decorator<std::deque<T>> {
 public:
  mt_queue(void) : m_mtx(), m_cv() {}

  using const_iterator = typename std::deque<T>::const_iterator;

  DECORATE_FUNC_TEMPLATE(T, begin, const);
  DECORATE_FUNC_TEMPLATE(T, end, const);

  /**
   * @brief Add data to the queue and notify others
   */
  void enqueue(const T& data) {
    boost::unique_lock<boost::mutex> lock(m_mtx);
    decorator::decorator<std::deque<T>>::decoratee().push_back(data);
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
    while (decorator::decorator<std::deque<T>>::decoratee().empty()) {
      m_cv.wait(lock);
    } /* while() */

    auto result =
        static_cast<T>(decorator::decorator<std::deque<T>>::decoratee().front());
    decorator::decorator<std::deque<T>>::decoratee().pop_front();
    return result;
  }

  DECORATE_FUNC_TEMPLATE(T, size, const);
  DECORATE_FUNC_TEMPLATE(T, front, const);
  DECORATE_FUNC_TEMPLATE(T, clear, const);
  DECORATE_FUNC_TEMPLATE(T, operator[], const);

 private:
  boost::mutex m_mtx;
  boost::condition_variable m_cv;
};

NS_END(multithread, rcppsw);

#endif /* INCLUDE_RCPPSW_MULTITHREAD_MT_QUEUE_HPP_ */
