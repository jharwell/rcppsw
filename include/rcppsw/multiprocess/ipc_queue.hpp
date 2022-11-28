/**
 * \file ipc_queue.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/thread/thread_time.hpp>
#include <deque>
#include <memory>

#include "rcppsw/multiprocess/ipc.hpp"
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, multiprocess);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class ipc_queue
 * \ingroup interprocess
 *
 * \brief Interprocess synchronized queue (like \ref multithread::mt_queue, but
 * for processes).
 */
template <class T>
class ipc_queue {
 public:
  typedef bip::allocator<T, bip::managed_shared_memory::segment_manager>
      allocator_type;

  explicit ipc_queue(allocator_type alloc)
      : m_queue(alloc), m_io_mutex(), m_wait_condition() {}

  /**
   * \brief Push an element onto the queue, notifying at most 1 process waiting
   * on the queue.
   *
   * \param element The element to add.
   */
  void push(T element) {
    bip::scoped_lock<bip::interprocess_mutex> lock(m_io_mutex);
    m_queue.push_back(element);
    m_wait_condition.notify_one();
  }
  /**
   * \brief Determine if the queue is current empty or not. This function
   * performs no locking, and even if it did, the result would be immediately
   * out of date, so don't depend on this value among multiple processes without
   * additional synchronization.
   *
   * \return \c TRUE if the condition is met, \c FALSE otherwise.
   */
  bool is_empty() const {
    bip::scoped_lock<bip::interprocess_mutex> lock(m_io_mutex);
    return m_queue.empty();
  }

  /**
   * \brief Get the front element in the queue.
   *
   * \return The front element.
   */
  T pop(void) {
    bip::scoped_lock<bip::interprocess_mutex> lock(m_io_mutex);

    T element = m_queue.front();
    m_queue.pop_front();

    return element;
  }

  /**
   * \brief Get the front element in the queue if it exists.
   *
   * \param element To be filled with the front item in the queue if it exists.
   *
   * \return \c TRUE if the front element was removed, \c FALSE otherwise.
   */
  bool pop_try(T* const element) {
    bip::scoped_lock<bip::interprocess_mutex> lock(m_io_mutex);

    if (m_queue.empty()) {
      return false;
    }

    *element = m_queue.front();
    m_queue.pop_front();

    return true;
  }

  /**
   * \brief Get the front element in the queue, waiting indefinitely if the
   * queue is currently empty.
   *
   * \param element To be filled with the front item in the queue.
   */
  void pop_wait(T* const element) {
    bip::scoped_lock<bip::interprocess_mutex> lock(m_io_mutex);

    while (m_queue.empty()) {
      m_wait_condition.wait(lock);
    } /* while() */

    *element = m_queue.front();
    m_queue.pop_front();
  }

  /**
   * \brief Get the front element in the queue, waiting a set # of seconds
   * before timing out if the queue is currently empty.
   *
   * \param element To be filled with the front item in the queue.
   * \param to_sec # of seconds for timeout.
   *
   * \return \c TRUE if an item was removed from the queue, \c FALSE otherwise.
   */
  bool pop_timed_wait(T* const element, int to_sec) {
    bip::scoped_lock<bip::interprocess_mutex> lock(m_io_mutex);
    boost::system_time to =
        boost::get_system_time() + boost::posix_time::seconds(to_sec);
    m_wait_condition.timed_wait(lock, to);
    if (m_queue.empty()) {
      return false;
    }
    *element = m_queue.front();
    m_queue.pop_front();
    return true;
  } /* pop_timed_wait() */

  /**
   * \brief Empty the queue.
   */
  void clear(void) {
    bip::scoped_lock<bip::interprocess_mutex> lock(m_io_mutex);
    m_queue.clear();
  }

  /**
   * \brief Get the current # of elements in the queue. This function performs
   * no locking, and even if it did, the result would be immediately out of
   * date, so don't depend on this value among multiple processes without
   * additional synchronization.
   *
   * \return The current # elements in the queue.
   */
  size_t size() const { return m_queue.size(); }

 private:
  /* clang-format off */
  bip::deque<T, allocator_type>       m_queue;
  mutable bip::interprocess_mutex     m_io_mutex;
  mutable bip::interprocess_condition m_wait_condition;
  /* clang-format on */
};

NS_END(multiprocess, rcppsw);

