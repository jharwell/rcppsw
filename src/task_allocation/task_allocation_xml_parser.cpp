/**
 * @file task_allocation_xml_parser.cpp
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
#include "rcppsw/task_allocation/task_allocation_xml_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
constexpr char task_allocation_xml_parser::kXMLRoot[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void task_allocation_xml_parser::parse(const ticpp::Element& node) {
  ticpp::Element tnode = node_get(const_cast<ticpp::Element&>(node), kXMLRoot);
  m_params =
      std::make_shared<std::remove_reference<decltype(*m_params)>::type>();
  m_estimation.parse(tnode);
  m_abort.parse(node_get(const_cast<ticpp::Element&>(tnode), "task_abort"));
  m_subtask_sel.parse(
      node_get(const_cast<ticpp::Element&>(tnode), "subtask_sel"));
  m_partitioning.parse(tnode);
  m_tab_sel.parse(node_get(const_cast<ticpp::Element&>(tnode), "tab_sel"));

  m_params->exec_est = *m_estimation.parse_results();
  m_params->abort = *m_abort.parse_results();
  m_params->subtask_sel = *m_subtask_sel.parse_results();
  m_params->partitioning = *m_partitioning.parse_results();
  m_params->tab_sel = *m_tab_sel.parse_results();
} /* parse() */

void task_allocation_xml_parser::show(std::ostream& stream) const {
  stream << build_header() << m_abort << m_subtask_sel << m_partitioning
         << m_estimation << m_tab_sel << build_footer();
} /* show() */

NS_END(task_allocatio, rcppsw);
