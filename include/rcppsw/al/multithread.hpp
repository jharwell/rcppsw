/**
 * \file multithread.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_AL_MULTITHREAD_HPP_
#define INCLUDE_RCPPSW_AL_MULTITHREAD_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#if defined(RCPPSW_AL_MT_SAFE_TYPES)
#include <atomic>
#endif

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, al);

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
#if defined(RCPPSW_AL_MT_SAFE_TYPES)

/**
 * \brief Abstract size_t which is atomic (and therefore multithread safe) or
 * not depending on configuration.
 */
using mt_size_t = std::atomic_size_t;

/**
 * \brief Abstract double which is atomic (and therefore multithread safe
 * without using locks) or not depending on configuration.
 */
using mt_double_t = std::atomic<double>;

/**
 * \brief Initialize an \c mt_ type. Redundant and superfluous for non-atomic
 * types, but necessary for atomic types, so this function provides a common
 * interface.
 */
template<typename LHS, typename RHS>
void mt_init(LHS* lhs, RHS rhs) { return std::atomic_init(lhs, rhs); }

/**
 * \brief Get the current value of a \c mt_ type. Redundant and superpluous for
 * non-atomic types, but necessary for atomic ones, hence this function to
 * provide a common interface.
 */
template<typename T>
T mt_load(const T& value) { return value.load(); }

/**
 * \brief Set a \ref mt_double_t to a specific value.
 */
template<typename U, typename V,
         RCPPSW_SFINAE_DECLDEF(std::is_same<U, std::atomic<double>>::value)>
void mt_set(U& lhs, const V& rhs) {
  auto tmp = lhs.load();
  lhs.compare_exchange_strong(tmp, rhs);
}

/**
 * \brief Set a \ref mt_size_t to a specific value.
 */
template<typename U, typename V,
         RCPPSW_SFINAE_DECLDEF(std::is_same<U, std::atomic<size_t>>::value)>
void mt_set(U& lhs, const V& rhs) { lhs = rhs; }

/**
 * \brief Add two \ref mt_double together, which involves a compare-exchange,
 * hence the need for this function.
 */
template<typename U, typename V,
         RCPPSW_SFINAE_DECLDEF(std::is_same<U, std::atomic<double>>::value)>
void mt_add(U& lhs, const V& rhs) {
  auto tmp = lhs.load();
  lhs.compare_exchange_strong(tmp, tmp + rhs);
}

/**
 * \brief Add two \ref mt_size_t together.
 */
template<typename U, typename V,
         RCPPSW_SFINAE_DECLDEF(std::is_same<U, std::atomic<size_t>>::value)>
void mt_add(U& lhs, const V& rhs) {
  lhs += rhs;
}

#else

using mt_size_t = std::size_t;
using mt_double_t = double;
template<typename LHS, typename RHS>
void mt_init(LHS* lhs, RHS rhs) { *lhs = rhs; }

template<typename T>
T mt_load(const T& value) { return value; }

template<typename U, typename V>
void mt_add(U& lhs, const V& rhs) {
  lhs += rhs;
}

template<typename U, typename V>
void mt_set(U& lhs, const V& rhs) { lhs = rhs; }

#endif

NS_END(al, rcppsw);

#endif /* INCLUDE_RCPPSW_AL_MULTITHREAD_HPP_ */
