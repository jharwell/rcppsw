/**
 * @file mt_vector.hpp
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

#ifndef INCLUDE_RCPPSW_MULTITHREAD_MT_VECTOR_HPP_
#define INCLUDE_RCPPSW_MULTITHREAD_MT_VECTOR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <boost/thread.hpp>
#include <boost/thread/locks.hpp>
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, multithread);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A thread-safe vector implementation. Use when you need fast access to
 *        a large contiguous chunk of memory.
 *
 */
template <typename T>
class mt_vector {
 public:
  mt_vector(void) : v_(), mtx_() {}

  /* type definitions */
  typedef typename std::vector<T>::const_iterator const_iterator;
  typename std::vector<T>::const_iterator begin(void) const {
    return v_.begin();
  }
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

NS_END(multithread, rcppsw);

#endif /* INCLUDE_RCPPSW_MULTITHREAD_MT_VECTOR_HPP_ */
