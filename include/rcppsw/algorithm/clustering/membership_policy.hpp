/**
 * \file membership_policy.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_MEMBERSHIP_POLICY_HPP_
#define INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_MEMBERSHIP_POLICY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <unordered_set>

#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, algorithm, clustering, detail);

/*******************************************************************************
 * Template Helpers
 ******************************************************************************/
namespace policy {
  class NC {};
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

NS_END(detail, clustering, algorithm, rcppsw);


#endif /* INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_MEMBERSHIP_POLICY_HPP_ */
