/*******************************************************************************
 * Name            : ipc_queue.hpp
 * Project         : rcppsw
 * Module          : multiprocess
 * Description     : Interprocess synchronized queue.
 * Creation Date   : 07/26/15
 * Copyright       : Copyright 2015 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_IPC_QUEUE_HPP_
#define INCLUDE_RCPPSW_IPC_QUEUE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/thread/thread_time.hpp>
#include <deque>
#include <memory>
#include "rcppsw/ipc.hpp"

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template <class T>
class ipc_queue {
 public:
  typedef bip::allocator<T, bip::managed_shared_memory::segment_manager>
      allocator_type;

 private:
  bip::deque<T, allocator_type> queue_;
  mutable bip::interprocess_mutex io_mutex_;
  mutable bip::interprocess_condition wait_condition;

 public:
  explicit ipc_queue(allocator_type alloc)
      : queue_(alloc), io_mutex_(), wait_condition() {}

  /**
   * @brief Push an element onto the queue, notifying at most 1 process waiting
   * on the queue.
   *
   * @param element The element to add.
   */
  void push(T element) {
    bip::scoped_lock<bip::interprocess_mutex> lock(io_mutex_);
    queue_.push_back(element);
    wait_condition.notify_one();
  }
  /**
   * @brief Determine if the queue is current empty or not. This function
   * performs no locking, and even if it did, the result would be immediately
   * out of date, so don't depend on this value among multiple processes without
   * additional synchronization.
   *
   * @return TRUE if the condition is met, FALSE otherwise.
   */
  bool is_empty() const {
    bip::scoped_lock<bip::interprocess_mutex> lock(io_mutex_);
    return queue_.empty();
  }

  /**
   * @brief Get the front element in the queue.
   *
   * @return The front element.
   */
  T pop(void) {
    bip::scoped_lock<bip::interprocess_mutex> lock(io_mutex_);

    T element = queue_.front();
    queue_.pop_front();

    return element;
  }

  /**
   * @brief Get the front element in the queue if it exists.
   *
   * @param element To be filled with the front item in the queue if it exists.
   *
   * @return TRUE if the front element was removed, FALSE otherwise.
   */
  bool pop_try(T *const element) {
    bip::scoped_lock<bip::interprocess_mutex> lock(io_mutex_);

    if (queue_.empty()) {
      return false;
    }

    *element = queue_.front();
    queue_.pop_front();

    return true;
  }

  /**
   * @brief Get the front element in the queue, waiting indefinitely if the
   * queue is currently empty.
   *
   * @param element To be filled with the front item in the queue.
   */
  void pop_wait(T *const element) {
    bip::scoped_lock<bip::interprocess_mutex> lock(io_mutex_);

    while (queue_.empty()) {
      wait_condition.wait(lock);
    } /* while() */

    *element = queue_.front();
    queue_.pop_front();
  }

  /**
   * @brief Get the front element in the queue, waiting a set # of seconds
   * before timing out if the queue is currently empty.
   *
   * @param element To be filled with the front item in the queue.
   * @param to_sec # of seconds for timeout.
   *
   * @return TRUE if an item was removed from the queue, FALSE otherwise.
   */
    bool pop_timed_wait(T * const element, int to_sec) {
      bip::scoped_lock<bip::interprocess_mutex> lock(io_mutex_);
    boost::system_time to =
        boost::get_system_time() + boost::posix_time::seconds(to_sec);
    wait_condition.timed_wait(lock, to);
    if (queue_.empty()) {
      return false;
    }
    *element = queue_.front();
    queue_.pop_front();
    return true;
  } /* pop_timed_wait() */

  /**
   * @brief Empty the queue.
   */
  void clear(void) {
    bip::scoped_lock<bip::interprocess_mutex> lock(io_mutex_);
    queue_.clear();
  }

  /**
   * @brief Get the current # of elements in the queue. This function performs
   * no locking, and even if it did, the result would be immediately out of
   * date, so don't depend on this value among multiple processes without
   * additional synchronization.
   *
   * @return The current # elements in the queue.
   */
  size_t size() const {
    return queue_.size();
  }
};

#endif /* INCLUDE_RCPPSW_IPC_QUEUE_HPP_ */
