/**
 * \file mt_queue.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
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

#include "rcppsw/patterns/decorator/decorator.hpp"
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, multithread);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class mt_queue
 * \ingroup multithread
 *
 * \brief A simple multiple-producer/consumer queue with locking. No guarantees
 * of fairness.
 */
template <typename T>
class mt_queue : public rpdecorator::decorator<std::deque<T>> {
 public:
  using rpdecorator::decorator<std::deque<T>>::decoratee;

  mt_queue(void) = default;

  RCPPSW_DECORATE_FUNC_TEMPLATE(T, begin, const);
  RCPPSW_DECORATE_FUNC_TEMPLATE(T, end, const);

  /**
   * \brief Add data to the queue and notify others
   */
  void enqueue(const T& data) {
    boost::unique_lock<boost::mutex> lock(m_mtx);
    decoratee().push_back(data);
    m_cv.notify_one();
  }

  /**
   * \brief Get data from the queue. Wait for data if not available.
   */
  T dequeue() {
    boost::unique_lock<boost::mutex> lock(m_mtx);

    /* When there is no data, wait till someone fills it. Lock is automatically
     * released in the wait and obtained again after the wait.
     */
    while (decoratee().empty()) {
      m_cv.wait(lock);
    } /* while() */

    auto result = static_cast<T>(decoratee().front());
    decoratee().pop_front();
    return result;
  }

  RCPPSW_DECORATE_FUNC_TEMPLATE(T, size, const);
  RCPPSW_DECORATE_FUNC_TEMPLATE(T, front, const);
  RCPPSW_DECORATE_FUNC_TEMPLATE(T, clear, const);
  RCPPSW_DECORATE_FUNC_TEMPLATE(T, operator[], const);

 private:
  /* clang-format off */
  boost::mutex              m_mtx;
  boost::condition_variable m_cv;
  /* clang-format on */
};

NS_END(multithread, rcppsw);

#endif /* INCLUDE_RCPPSW_MULTITHREAD_MT_QUEUE_HPP_ */
