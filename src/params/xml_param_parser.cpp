/**
 * @file xml_param_parser.cpp
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/params/xml_param_parser.hpp"
#include <string>

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, params);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
xml_param_parser::xml_param_parser(uint level)
    : ER_CLIENT_INIT("rcppsw.params"), m_level(level) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
std::string xml_param_parser::build_header(void) const {
  uint width = kColumnWidth - level() * 20;
  std::string prettiness(width, '=');
  std::string spaces(width / 2 - xml_root().size() / 2 - 1, ' ');
  return prettiness + "\n" + spaces + "<" + xml_root() + ">" + "\n" +
         prettiness + "\n";
} /* build_header() */

std::string xml_param_parser::build_footer(void) const {
  uint width = kColumnWidth - level() * 20;
  std::string prettiness(width, '=');
  std::string spaces(width / 2 - xml_root().size() / 2 - 1, ' ');
  return prettiness + "\n" + spaces + "</" + xml_root() + ">" + "\n" +
         prettiness + "\n";
} /* build_footer() */

ticpp::Element& xml_param_parser::node_get(const ticpp::Element& node,
                                           const std::string& tag) const {
  ticpp::Iterator<ticpp::Element> it(tag);
  it = it.begin(&node);
  ER_ASSERT(it != nullptr,
            "No tag '%s' found in node '%s'",
            tag.c_str(),
            node.Value().c_str());
  return *it;
} /* node_get() */

void xml_param_parser::node_attr_get(const ticpp::Element& node,
                                     const std::string& attr,
                                     bool& buf) const {
  std::string tmp;
  node.GetAttribute(attr, &tmp, true);
  if ("true" == tmp) {
    buf = true;
  } else if ("false" == tmp) {
    buf = false;
  } else {
    ER_FATAL_SENTINEL(
        "Cannot convert '%s' into a bool. Accepted values are ['true', "
        "'false']",
        tmp.c_str());
  }
} /* node_attr_get() */

NS_END(params, rcppsw);
