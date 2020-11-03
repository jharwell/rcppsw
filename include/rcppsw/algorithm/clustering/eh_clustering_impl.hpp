/**
 * \file eh_clustering_impl.hpp
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

#ifndef INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_EH_CLUSTERING_IMPL_HPP_
#define INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_EH_CLUSTERING_IMPL_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/algorithm/clustering/base_clustering_impl.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, algorithm, clustering);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \interface eh_clustering_impl
 * \ingroup algorithm clustering
 *
 * \brief Templated implementation class interface to guide the implementation
 * of various Event Horizon (EH) clustering algorithms.
 */
template<typename T>
class eh_clustering_impl : public base_clustering_impl<T, policy::EH> {
 public:
  ~eh_clustering_impl(void) override = default;

  void horizon(double horizon) { m_horizon = horizon; }
  double horizon(void) const { return m_horizon; }

  /* clang-format off */
 private:
  double m_horizon{-1};
  /* clang-format on */
};

NS_END(clustering, algorithm, rcppsw);

#endif /* INCLUDE_RCPPSW_ALGORITHM_CLUSTERING_EH_CLUSTERING_IMPL_HPP_ */
