/**
 * @file task_executive_parser.cpp
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
#include "rcppsw/ta/config/xml/task_executive_parser.hpp"
#include <ext/ticpp/ticpp.h>

#include "rcppsw/utils/line_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta, config, xml);

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
constexpr char task_executive_parser::kXMLRoot[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void task_executive_parser::parse(const ticpp::Element& node) {
  m_config =
      std::make_shared<std::remove_reference<decltype(*m_config)>::type>();
  ticpp::Element pnode = node_get(node, kXMLRoot);
  XML_PARSE_ATTR(pnode, m_config, update_exec_ests);
  XML_PARSE_ATTR(pnode, m_config, update_interface_ests);
  XML_PARSE_ATTR(pnode, m_config, tab_init_method);
} /* parse() */

void task_executive_parser::show(std::ostream& stream) const {
  stream << build_header() << XML_ATTR_STR(m_config, update_exec_ests)
         << std::endl
         << XML_ATTR_STR(m_config, update_interface_ests) << std::endl
         << XML_ATTR_STR(m_config, tab_init_method) << std::endl
         << build_footer();
} /* show() */

NS_END(xml, config, ta, rcppsw);
