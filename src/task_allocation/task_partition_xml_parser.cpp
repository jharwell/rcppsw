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
#include "rcppsw/task_allocation/task_partition_xml_parser.hpp"
#include <ext/ticpp/ticpp.h>

#include "rcppsw/utils/line_parser.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
constexpr char task_partition_xml_parser::kXMLRoot[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void task_partition_xml_parser::parse(const ticpp::Element &node) {
  m_params =
      std::make_shared<std::remove_reference<decltype(*m_params)>::type>();
  ticpp::Element pnode = get_node(const_cast<ticpp::Element &>(node), kXMLRoot);
  m_sigmoid.parse(pnode);
  m_params->src_sigmoid = *m_sigmoid.parse_results();
  XML_PARSE_ATTR(pnode, m_params, always_partition);
  XML_PARSE_ATTR(pnode, m_params, never_partition);
} /* parse() */

void task_partition_xml_parser::show(std::ostream &stream) const {
  stream << build_header() << m_sigmoid
         << XML_ATTR_STR(m_params, always_partition) << std::endl
         << XML_ATTR_STR(m_params, never_partition) << std::endl
         << build_footer();
} /* show() */

__rcsw_pure bool task_partition_xml_parser::validate(void) const {
  return m_sigmoid.validate();
} /* validate() */

NS_END(task_allocation, rcppsw);
