/**
 * @file executive_parser.cpp
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
#include "rcppsw/task_allocation/executive_xml_parser.hpp"
#include <ext/ticpp/ticpp.h>

#include "rcppsw/utils/line_parser.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
constexpr char executive_xml_parser::kXMLRoot[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void executive_xml_parser::parse(const ticpp::Element& node) {
  ticpp::Element enode =
      get_node(const_cast<ticpp::Element&>(node), kXMLRoot);

  ticpp::Element anode =
      get_node(const_cast<ticpp::Element&>(enode), "aborting");
  XML_PARSE_PARAM(anode, m_params.abort, reactivity);
  XML_PARSE_PARAM(anode, m_params.abort, offset);

  ticpp::Element tnode =
      get_node(const_cast<ticpp::Element&>(enode), "tasks");
  XML_PARSE_PARAM(tnode, m_params, estimation_alpha);

  ticpp::Element pnode =
      get_node(const_cast<ticpp::Element&>(enode), "partitioning");
  XML_PARSE_PARAM(pnode, m_params.partitioning, reactivity);
  XML_PARSE_PARAM(pnode, m_params.partitioning, offset);
  XML_PARSE_PARAM(pnode, m_params.partitioning, method);
  XML_PARSE_PARAM(pnode, m_params.partitioning, always_partition);
  XML_PARSE_PARAM(pnode, m_params.partitioning, never_partition);

  ticpp::Element snode =
      get_node(const_cast<ticpp::Element&>(enode), "subtask_selection");
  XML_PARSE_PARAM(snode, m_params.subtask_selection, reactivity);
  XML_PARSE_PARAM(snode, m_params.subtask_selection, offset);
  XML_PARSE_PARAM(snode, m_params.subtask_selection, method);
  XML_PARSE_PARAM(snode, m_params.subtask_selection, gamma);
} /* parse() */

void executive_xml_parser::show(std::ostream& stream) const {
  stream << build_header() << XML_PARAM_STR(m_params, estimation_alpha)
         << std::endl
         << XML_PARAM_STR(m_params, abort.reactivity) << std::endl
         << XML_PARAM_STR(m_params, abort.offset) << std::endl
         << XML_PARAM_STR(m_params, partitioning.reactivity) << std::endl
         << XML_PARAM_STR(m_params, partitioning.offset) << std::endl
         << XML_PARAM_STR(m_params, partitioning.method) << std::endl
         << XML_PARAM_STR(m_params, partitioning.always_partition) << std::endl
         << XML_PARAM_STR(m_params, partitioning.never_partition) << std::endl
         << XML_PARAM_STR(m_params, subtask_selection.reactivity) << std::endl
         << XML_PARAM_STR(m_params, subtask_selection.offset) << std::endl
         << XML_PARAM_STR(m_params, subtask_selection.method) << std::endl
         << XML_PARAM_STR(m_params, subtask_selection.gamma) << std::endl
         << build_footer();
} /* show() */

__rcsw_pure bool executive_xml_parser::validate(void) const {
  return !(m_params.estimation_alpha <= 0.0 ||
           m_params.abort.reactivity <= 0.0 || m_params.abort.offset <= 0.0 ||
           m_params.partitioning.reactivity <= 0.0 ||
           m_params.partitioning.offset <= 0.0);
} /* validate() */

NS_END(task_allocation, rcppsw);
