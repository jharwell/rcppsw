/**
 * \file ientropy.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <vector>

#include "rcppsw/math/expression.hpp"
#include "rcppsw/math/radians.hpp"
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::math {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class ientropy
 * \ingroup math
 *
 * \brief Calculates the informational entropy of a cluster (Shannon's
 * definition).
 *
 * Uses the formula:
 *
 * H(S) = - SUM( p_i * log2(p_i)) over all i in m.
 */
class ientropy : public math::expression<double> {
 public:
  /**
   * \brief Calculate the informational entropy.
   *
   * \param[in] groups A vector of the proportional representation of each group
   *                   within the cluster. Should sum to 1, though this is not
   *                   checked.
   */
  double operator()(const std::vector<double>& groups) {
    double entropy = 0.0;
    std::for_each(groups.begin(), groups.end(), [&](const auto& prop) {
      entropy += prop * std::log2(prop);
    });
    return eval(-entropy);
  }
};

} /* namespace rcppsw::math */
