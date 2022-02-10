/**
 * \file base_config.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
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

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, config);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * \struct base_config
 * \ingroup config
 *
 * \brief A stub base class for any and all derived configuration class types
 * that may need polymorphism or covariance.
 */
struct base_config {
  base_config(void) = default;
  virtual ~base_config(void) = default;
  base_config(const base_config&) = default;
  base_config& operator=(const base_config&) = default;
};

NS_END(config, config);

