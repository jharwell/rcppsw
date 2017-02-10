/*******************************************************************************
 * Name            : mt_vector.hpp
 * Project         : rcppsw
 * Module          : multithread
 * Description     : A thread-safe vector implementation. Use when you need fast
 *                   access to a large contiquous chunk of memory.
 * Creation Date   : 02/06/17
 * Copyright       : Copyright 2017 John Harwell, All rights reserved
 *
 ******************************************************************************/

#ifndef INCLUDE_RCPPSW_MULTITHREAD_MT_VECTOR_HPP_
#define INCLUDE_RCPPSW_MULTITHREAD_MT_VECTOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <boost/thread.hpp>
#include <boost/thread/locks.hpp>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
template <typename T>
class mt_vector {
 public:
  mt_vector(void) : v_(), mtx_() {}

  /* type definitions */
  typedef typename std::vector<T>::const_iterator const_iterator;
  typename std::vector<T>::const_iterator begin(void) const { return v_.begin(); }
  typename std::vector<T>::const_iterator end(void) const { return v_.end(); }

  // Add data to the queue and notify others
  void push_back(const T& data) {
    // Acquire lock on the queue
    boost::unique_lock<boost::mutex> lock(mtx_);

    v_.push_back(data);
  }  // Lock is automatically released here

  size_t size() const { return v_.size(); }
  void clear(void) { v_.clear(); }
  const T& operator[](std::size_t pos) const { return v_[pos]; }

 private:
  std::vector<T> v_;
  boost::mutex mtx_;
};

#endif /* INCLUDE_RCPPSW_MULTITHREAD_MT_VECTOR_HPP_ */
