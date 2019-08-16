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
 * Member Functions
 ******************************************************************************/
void task_partition_parser::parse(const ticpp::Element& node) {
  ticpp::Element pnode = node_get(node, kXMLRoot);
  m_config = std::make_unique<config_type>();

  m_sigmoid.parse(pnode);
  m_config->src_sigmoid =
      *m_sigmoid.config_get<src_sigmoid_sel_parser::config_type>();

  XML_PARSE_ATTR_DFLT(pnode, m_config, always_partition, false);
  XML_PARSE_ATTR_DFLT(pnode, m_config, never_partition, false);
} /* parse() */

bool task_partition_parser::validate(void) const {
  if (is_parsed()) {
    return m_sigmoid.validate();
  }
  return true;
} /* validate() */

NS_END(xml, config, ta, rcppsw);
