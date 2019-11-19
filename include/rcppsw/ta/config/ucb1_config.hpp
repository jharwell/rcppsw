/**
 * \file ucb1_config.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_TA_CONFIG_UCB1_CONFIG_HPP_
#define INCLUDE_RCPPSW_TA_CONFIG_UCB1_CONFIG_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "rcppsw/config/base_config.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta, config);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * \struct ucb1_config
 * \ingroup ta config
 *
 * \brief Configuration for the UCB1 task allocation algorithm, as described in
 * \todo paper ref.
 */
struct ucb1_config final : public rcppsw::config::base_config {
  double gamma{-1};
};

NS_END(config, ta, rcppsw);

#endif /* INCLUDE_RCPPSW_TA_CONFIG_UCB1_CONFIG_HPP_ */
