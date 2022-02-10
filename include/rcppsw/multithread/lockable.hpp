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

#pragma once

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
 * contexts. Used mainly to reduce the if()s where possible.
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

  /**
   * \brief Lock \p mtx for exclusive access if \p cond is \c TRUE.
   */
  void maybe_lock_wr(std::shared_mutex* mtx, bool cond) {
    if (cond) {
      mtx->lock();
    }
  }

  /**
   * \brief Unlock \p mtx for exclusive access if \p cond is \c TRUE.
   */
  void maybe_unlock_wr(std::shared_mutex* mtx, bool cond) {
    if (cond) {
      mtx->unlock();
    }
  }

  /**
   * \brief Lock \p mtx for read-only access if \p cond is \c TRUE. Other
   * readers will still be allowed access to the resource.
   */
  void maybe_lock_rd(std::shared_mutex* mtx, bool cond) const {
    if (cond) {
      mtx->lock_shared();
    }
  }

  /**
   * \brief Unlock \p mtx for read-only access if \p cond is \c TRUE.
   */
  void maybe_unlock_rd(std::shared_mutex* mtx, bool cond) const {
    if (cond) {
      mtx->unlock_shared();
    }
  }

  /**
   * \brief Unconditionally lock \p mtx for exclusive access.
   */
  void lock_wr(std::shared_mutex* mtx) { maybe_lock_wr(mtx, true); }

  /**
   * \brief Unconditionally unlock \p mtx for exclusive access.
   */
  void unlock_wr(std::shared_mutex* mtx) { maybe_unlock_wr(mtx, true); }

  /**
   * \brief Unconditionally lock \p mtx for shared reader access.
   */
  void lock_rd(std::shared_mutex* mtx) const { maybe_lock_rd(mtx, true); }

  /**
   * \brief Unconditionally unlock \p mtx for shared reader access.
   */
  void unlock_rd(std::shared_mutex* mtx) const { maybe_unlock_rd(mtx, true); }
};

NS_END(multithread, rcppsw);

