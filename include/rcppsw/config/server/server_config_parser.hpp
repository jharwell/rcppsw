/**
 * \file server_config_parser.hpp
 *
 * \copyright 2022 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/config/base_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::config::server {

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

} /* namespace rcppsw::config::server */
