/**
 * @file positional_entropy_config.hpp
 *
 * @copyright 2018 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_SWARM_CONVERGENCE_CONFIG_POSITIONAL_ENTROPY_CONFIG_HPP_
#define INCLUDE_RCPPSW_SWARM_CONVERGENCE_CONFIG_POSITIONAL_ENTROPY_CONFIG_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/config/base_config.hpp"
#include "rcppsw/math/range.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, swarm, convergence, config);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * @struct positional_entropy_config
 * @ingroup rcppsw swarm convergence config
 */
struct positional_entropy_config : public rcppsw::config::base_config {
  positional_entropy_config(void) noexcept = default;

  bool enable{false};
  math::ranged horizon{-1, 0};
  double horizon_delta{-1};
};

NS_END(config, convergence, swarm, rcppsw);

#endif /* INCLUDE_RCPPSW_SWARM_CONVERGENCE_CONFIG_POSITIONAL_ENTROPY_CONFIG_HPP_ */
