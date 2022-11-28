/**
 * \file mt_vector.hpp
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
#include <vector>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, multithread);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class mt_vector
 * \ingroup multithread
 *
 * \brief A thread-safe vector implementation. Use when you need fast access to
 *        a large contiguous chunk of memory.
 */
template <typename T>
class mt_vector {
 public:
  using const_iterator = typename std::vector<T>::const_iterator;

  mt_vector(void) = default;

  void push_back(const T& data) {
    boost::unique_lock<boost::mutex> lock(m_mtx);
    m_v.push_back(data);
  }

 private:
  /* clang-format off */
  std::vector<T> m_v;
  boost::mutex   m_mtx;
  /* clang-format on */

 public:
  RCPPSW_WRAP_DECLDEF(size, m_v, const);
  RCPPSW_WRAP_DECLDEF(operator[], m_v);
  RCPPSW_WRAP_DECLDEF(begin, m_v, const);
  RCPPSW_WRAP_DECLDEF(end, m_v, const);
};

NS_END(multithread, rcppsw);

