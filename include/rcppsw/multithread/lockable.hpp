/**
 * \file lockable.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
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

