/**
 * @file base_config.hpp
 *
 * @copyright 2017 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_CONFIG_BASE_CONFIG_HPP_
#define INCLUDE_RCPPSW_CONFIG_BASE_CONFIG_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, config);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * @struct base_config
 * @ingroup rcppsw config
 *
 * @brief A stub base class for any and all derived configuration class types
 * that may need polymorphism or covariance.
 */
struct base_config {
  virtual ~base_config(void) = default;
};

NS_END(config, config);

#endif /* INCLUDE_RCPPSW_CONFIG_BASE_CONFIG_HPP_ */
