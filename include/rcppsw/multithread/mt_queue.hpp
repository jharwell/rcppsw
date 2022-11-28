/**
 * \file mt_queue.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

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

  RCPPSW_DECORATE_DECLDEF_TEMPLATE(T, begin, const);
  RCPPSW_DECORATE_DECLDEF_TEMPLATE(T, end, const);

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

  RCPPSW_DECORATE_DECLDEF_TEMPLATE(T, size, const);
  RCPPSW_DECORATE_DECLDEF_TEMPLATE(T, front, const);
  RCPPSW_DECORATE_DECLDEF_TEMPLATE(T, clear, const);
  RCPPSW_DECORATE_DECLDEF_TEMPLATE(T, operator[], const);

 private:
  /* clang-format off */
  boost::mutex              m_mtx;
  boost::condition_variable m_cv;
  /* clang-format on */
};

NS_END(multithread, rcppsw);

