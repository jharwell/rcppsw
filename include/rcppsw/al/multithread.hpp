/**
 * \file multithread.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

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
namespace rcppsw::al {

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
typename T::value_type mt_load(const T& value) { return value.load(); }

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
         RCPPSW_SFINAE_DECLDEF(std::is_same<U, std::atomic<size_t>>::value &&
                               !std::is_same<V, std::atomic<size_t>>::value)>
void mt_set(U& lhs, const V& rhs) { lhs = rhs; }

/**
 * \brief Set a \ref mt_size_t to a specific value.
 */
template<typename U, typename V,
         RCPPSW_SFINAE_DECLDEF(std::is_same<U, std::atomic<size_t>>::value &&
                               std::is_same<V, std::atomic<size_t>>::value)>
void mt_set(U& lhs, const V& rhs) { lhs = rhs.load(); }

/**
 * \brief Add two \ref mt_double together, which involves a compare-exchange,
 * hence the need for this function.
 */
template<typename U, typename V,
         RCPPSW_SFINAE_DECLDEF(std::is_same<U, std::atomic<double>>::value)>
void mt_accum(U& lhs, const V& rhs) {
  auto tmp = lhs.load();
  lhs.compare_exchange_strong(tmp, tmp + rhs);
}

/**
 * \brief Add two \ref mt_size_t together.
 */
template<typename U, typename V,
         RCPPSW_SFINAE_DECLDEF(std::is_same<U, std::atomic<size_t>>::value)>
void mt_accum(U& lhs, const V& rhs) {
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
void mt_accum(U& lhs, const V& rhs) {
  lhs += rhs;
}

template<typename U, typename V>
void mt_set(U& lhs, const V& rhs) { lhs = rhs; }

#endif

} /* namespace rcppsw::al */
