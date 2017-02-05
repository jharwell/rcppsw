/*******************************************************************************
 * Name            : shared_queue.hpp
 * Project         : rcppsw
 * Module          : ds
 * Description     : A simple multiple-producer, single-consumer queue with
 *                   locking
 * Creation Date   : 06/25/15
 * Copyright       : Copyright 2015 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_SHARED_QUEUE_HPP_
#define INCLUDE_SHARED_QUEUE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <deque>
#include <boost/thread.hpp>
#include <boost/thread/locks.hpp>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template <typename T>
class shared_queue {
 private:
  std::deque<T> queue_;           // Use STL queue to store data
  boost::mutex mtx_;              // The mutex to synchronise on
  boost::condition_variable cv_;  // The condition to wait for

 public:
  /* type definitions */
  typedef typename std::deque<T>::const_iterator const_iterator;
  typename std::deque<T>::const_iterator begin(void) const { return queue_.begin(); }
  typename std::deque<T>::const_iterator end(void) const { return queue_.end(); }

  // Add data to the queue and notify others
  void enqueue(const T& data) {
    // Acquire lock on the queue
    boost::unique_lock<boost::mutex> lock(mtx_);

    // Add the data to the queue
    queue_.push_back(data);

    // Notify others that data is ready
    cv_.notify_one();
  }  // Lock is automatically released here

  // Get data from the queue. Wait for data if not available
  T dequeue() {
    // Acquire lock on the queue
    boost::unique_lock<boost::mutex> lock(mtx_);

    // When there is no data, wait till someone fills it.
    // Lock is automatically released in the wait and obtained
    // again after the wait
    while (queue_.size() == 0) cv_.wait(lock);

    // Retrieve the data from the queue
    T result = static_cast<T>(queue_.front());
    queue_.pop_front();
    return result;
  }  // Lock is automatically released here

  // get the size of the queue
  size_t size() const { return queue_.size(); }
};

#endif /* INCLUDE_SHARED_QUEUE_HPP_ */
