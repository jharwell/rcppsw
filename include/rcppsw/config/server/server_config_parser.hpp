/**
 * \file server_config_parser.hpp
 *
 * \copyright 2022 John Harwell, All rights reserved.
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
#include "rcppsw/config/base_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, config, server);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class server_config_parser
 * \ingroup config server
 *
 * \brief Interface specifying functionality for parsing parameters from a
 * server into a \ref base_config derived parameter structure.
 */
class server_config_parser : public rconfig::base_parser {
 public:
  server_config_parser(void) = default;
  ~server_config_parser(void) override = default;

  /**
   * \brief Parse the necessary parameters from the server into an internal
   * representation (should be a class/struct derived from \ref base_config).
   */
  virtual void parse(void) = 0;
};

NS_END(server, config, rcppsw);
