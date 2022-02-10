/**
 * \file sigmoid_config.hpp
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

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/config/base_config.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math, config);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * \struct sigmoid_config
 * \ingroup math
 *
 * \brief Parameters for probabilistic exponentials (aka sigmoids).
 */
struct sigmoid_config final : public rcppsw::config::base_config {
  double reactivity{0.0};
  double offset{0.0};
  double gamma{0.0};
};

NS_END(config, math, rcppsw);

