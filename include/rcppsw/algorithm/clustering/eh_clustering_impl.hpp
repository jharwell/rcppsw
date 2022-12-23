/**
 * \file eh_clustering_impl.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/algorithm/clustering/base_clustering_impl.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::algorithm::clustering {

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

} /* namespace rcppsw::algorithm::clustering */

