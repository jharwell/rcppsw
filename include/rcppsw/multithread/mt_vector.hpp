/**
 * @file mt_vector.hpp
 * @ingroup multithread
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
#include <boost/thread.hpp>
#include <boost/thread/locks.hpp>
#include <vector>
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, multithread);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class mt_vector
 *
 * @brief A thread-safe vector implementation. Use when you need fast access to
 *        a large contiguous chunk of memory.
 */
template <typename T>
class mt_vector {
 public:
  mt_vector(void) : m_v(), m_mtx() {}

  /* type definitions */
  typedef typename std::vector<T>::const_iterator const_iterator;
  typename std::vector<T>::const_iterator begin(void) const {
    return m_v.begin();
  }
  typename std::vector<T>::const_iterator end(void) const { return m_v.end(); }

  void push_back(const T& data) {
    boost::unique_lock<boost::mutex> lock(m_mtx);
    m_v.push_back(data);
  }

  size_t size() const { return m_v.size(); }
  void clear(void) { m_v.clear(); }
  const T& operator[](std::size_t pos) const { return m_v[pos]; }

 private:
  std::vector<T> m_v;
  boost::mutex m_mtx;
};

NS_END(multithread, rcppsw);

#endif /* INCLUDE_RCPPSW_MULTITHREAD_MT_VECTOR_HPP_ */
