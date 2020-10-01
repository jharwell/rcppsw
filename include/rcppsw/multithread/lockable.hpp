/**
 * \file lockable.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_MULTITHREAD_LOCKABLE_HPP_
#define INCLUDE_RCPPSW_MULTITHREAD_LOCKABLE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <shared_mutex>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, multithread);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class lockable
 * \ingroup multithread
 *
 * \brief Simple class allowing explicit declaration that a derived class can be
 * locked (un)conditionally in exclusive write and non-exclusive read-only
 * contexts.
 *
 * Uses std::shared_mutex underneath.
 */
class lockable {
 public:
  lockable(void) = default;
  virtual ~lockable(void) = default;

  /* Not move/copy constructable/assignable by default */
  lockable(const lockable&) = delete;
  const lockable& operator=(const lockable&) = delete;
  lockable(lockable&&) = delete;
  lockable& operator=(lockable&&) = delete;

  void maybe_lock_wr(std::shared_mutex* mtx, bool cond) {
    if (cond) {
      mtx->lock();
    }
  }
  void maybe_unlock_wr(std::shared_mutex* mtx, bool cond) {
    if (cond) {
      mtx->unlock();
    }
  }

  void maybe_lock_rd(std::shared_mutex* mtx, bool cond) const {
    if (cond) {
      mtx->lock_shared();
    }
  }
  void maybe_unlock_rd(std::shared_mutex* mtx, bool cond) const {
    if (cond) {
      mtx->unlock_shared();
    }
  }

  void lock_wr(std::shared_mutex* mtx) {
    maybe_lock_wr(mtx, true);
  }
  void unlock_wr(std::shared_mutex* mtx) {
    maybe_unlock_wr(mtx, true);
  }

  void lock_rd(std::shared_mutex* mtx) const {
    maybe_lock_rd(mtx, true);
  }
  void unlock_rd(std::shared_mutex* mtx) const {
    maybe_unlock_rd(mtx, true);
  }
};

NS_END(multithread, rcppsw);

#endif /* INCLUDE_RCPPSW_MULTITHREAD_LOCKABLE_HPP_ */
