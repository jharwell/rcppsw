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
void executive_xml_parser::parse(const ticpp::Element &node) {
  if (nullptr != node.FirstChild(kXMLRoot, false)) {
    m_params =
        std::make_shared<std::remove_reference<decltype(*m_params)>::type>();
    ticpp::Element enode =
        get_node(const_cast<ticpp::Element &>(node), kXMLRoot);
    m_abort.parse(enode);
    m_partition.parse(enode);
    m_subtask.parse(enode);
    m_estimation.parse(enode);

    m_params->abort = *m_abort.parse_results();
    m_params->partitioning = *m_partition.parse_results();
    m_params->estimation = *m_estimation.parse_results();
    m_params->subtask_selection = *m_subtask.parse_results();
    m_parsed = true;
  }
} /* parse() */

void executive_xml_parser::show(std::ostream &stream) const {
  if (!m_parsed) {
    stream << build_header() << "<< Not Parsed >>" << std::endl
           << build_footer();
    return;
  }

  stream << build_header() << m_abort << m_partition << m_subtask
         << m_estimation << build_footer();
} /* show() */

__rcsw_pure bool executive_xml_parser::validate(void) const {
  if (m_parsed) {
    return m_abort.validate() && m_partition.validate() &&
           m_subtask.validate() && m_estimation.validate();
  }
  return true;
} /* validate() */

NS_END(task_allocation, rcppsw);
