/**
 * @file task_partition_parser.cpp
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
#include "rcppsw/ta/config/xml/task_partition_parser.hpp"
#include <ext/ticpp/ticpp.h>

#include "rcppsw/utils/line_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta, config, xml);

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
constexpr char task_partition_parser::kXMLRoot[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void task_partition_parser::parse(const ticpp::Element& node) {
  m_config =
      std::make_shared<std::remove_reference<decltype(*m_config)>::type>();
  ticpp::Element pnode = node_get(node, kXMLRoot);
  m_sigmoid.parse(pnode);
  m_config->src_sigmoid = *m_sigmoid.config_get();
  XML_PARSE_ATTR(pnode, m_config, always_partition);
  XML_PARSE_ATTR(pnode, m_config, never_partition);
} /* parse() */

void task_partition_parser::show(std::ostream& stream) const {
  stream << build_header() << m_sigmoid
         << XML_ATTR_STR(m_config, always_partition) << std::endl
         << XML_ATTR_STR(m_config, never_partition) << std::endl
         << build_footer();
} /* show() */

__rcsw_pure bool task_partition_parser::validate(void) const {
  return m_sigmoid.validate();
} /* validate() */

NS_END(xml, config, ta, rcppsw);
