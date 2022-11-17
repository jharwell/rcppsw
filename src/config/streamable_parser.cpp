/**
 * \file streamable_parser.cpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/config/streamable_parser.hpp"

#include <string>

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, config);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
std::string streamable_parser::header_build(const std::string& xml_root) const {
  size_t width = kColumnWidth - level() * 20;
  std::string prettiness(width, '=');
  std::string spaces(width / 2 - xml_root.size() / 2 - 1, ' ');
  return prettiness + "\n" + spaces + "<" + xml_root + ">" + "\n" + prettiness +
         "\n";
} /* header_build() */

std::string streamable_parser::footer_build(const std::string& xml_root) const {
  size_t width = kColumnWidth - level() * 20;
  std::string prettiness(width, '=');
  std::string spaces(width / 2 - xml_root.size() / 2 - 1, ' ');
  return prettiness + "\n" + spaces + "</" + xml_root + ">" + "\n" + prettiness +
         "\n";
} /* footer_build() */

NS_END(config, rcppsw);
