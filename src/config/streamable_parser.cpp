/**
 * \file streamable_parser.cpp
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
  uint width = kColumnWidth - level() * 20;
  std::string prettiness(width, '=');
  std::string spaces(width / 2 - xml_root.size() / 2 - 1, ' ');
  return prettiness + "\n" + spaces + "<" + xml_root + ">" + "\n" + prettiness +
         "\n";
} /* header_build() */

std::string streamable_parser::footer_build(const std::string& xml_root) const {
  uint width = kColumnWidth - level() * 20;
  std::string prettiness(width, '=');
  std::string spaces(width / 2 - xml_root.size() / 2 - 1, ' ');
  return prettiness + "\n" + spaces + "</" + xml_root + ">" + "\n" +
         prettiness + "\n";
} /* footer_build() */

NS_END(config, rcppsw);
