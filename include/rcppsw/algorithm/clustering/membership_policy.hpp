/**
 * \file membership_policy.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <unordered_set>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, algorithm, clustering);

/*******************************************************************************
 * Template Helpers
 ******************************************************************************/
namespace policy {
/**
 * \brief NC -> Nearest centroid
 */
class NC {};

/**
 * \brief EH -> Event Horizon
 */
class EH {};

template<typename Policy>
using is_nc_ = std::is_same<Policy, NC>;

template<typename Policy>
using is_eh_ = std::is_same<Policy, EH>;

template<typename Policy>
using is_nc = typename std::enable_if_t<is_nc_<Policy>::value>;

template<typename Policy>
using is_eh = typename std::enable_if_t<is_eh_<Policy>::value>;

}  // namespace policy

namespace membership {
template<typename Policy, typename Enable = void>
struct mapping;

template<typename Policy>
struct mapping<Policy, policy::is_nc<Policy>> {
  using type = std::vector<size_t>;
};

template<typename Policy>
struct mapping<Policy, policy::is_eh<Policy>> {
  using type = std::vector<std::unordered_set<size_t>>;
};
}  // namespace membership

template<typename Policy>
using membership_type = typename membership::mapping<Policy>::type;

NS_END(clustering, algorithm, rcppsw);


