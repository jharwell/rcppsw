/*******************************************************************************
 * Name            : ipc_queue.hpp
 * Project         : rcppsw
 * Module          : ds
 * Description     : Interprocess synchronized queue
 * Creation Date   : 07/26/15
 * Copyright       : Copyright 2015 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_IPC_QUEUE_HPP_
#define INCLUDE_IPC_QUEUE_HPP_

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

  void push(T element) {
    bip::scoped_lock<bip::interprocess_mutex> lock(io_mutex_);
    queue_.push_back(element);
    wait_condition.notify_one();
  }
  bool empty() const {
    bip::scoped_lock<bip::interprocess_mutex> lock(io_mutex_);
    return queue_.empty();
  }
  T pop(void) {
    bip::scoped_lock<bip::interprocess_mutex> lock(io_mutex_);

    T element = queue_.front();
    queue_.pop_front();

    return element;
  }
  bool pop(T *const element) {
    bip::scoped_lock<bip::interprocess_mutex> lock(io_mutex_);

    if (queue_.empty()) {
      return false;
    }

    *element = queue_.front();
    queue_.pop_front();

    return true;
  }
  unsigned int size() const {
    // try to lock the mutex
    bip::scoped_lock<bip::interprocess_mutex> lock(io_mutex_);
    return queue_.size();
  }
  void pop_wait(T *const element) {
    bip::scoped_lock<bip::interprocess_mutex> lock(io_mutex_);

    while (queue_.empty()) {
      wait_condition.wait(lock);
    }

    *element = queue_.front();
    queue_.pop_front();
  }
  bool pop_timed_wait(T &element, int to_sec) {
    bip::scoped_lock<bip::interprocess_mutex> lock(io_mutex_);
    boost::system_time to =
        boost::get_system_time() + boost::posix_time::seconds(to_sec);
    wait_condition.timed_wait(lock, to);
    if (queue_.empty()) {
      return false;
    }
    element = queue_.front();
    queue_.pop_front();
    return true;
  } /* pop_timed_wait() */
  void clear(void) { queue_.clear(); }
};

#endif /* INCLUDE_IPC_QUEUE_HPP_ */
