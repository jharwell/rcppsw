/**
 * @file task_alloc_parser.cpp
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
#include "rcppsw/ta/config/xml/task_alloc_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta, config, xml);

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
constexpr char task_alloc_parser::kXMLRoot[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void task_alloc_parser::parse(const ticpp::Element& node) {
  ticpp::Element tnode = node_get(node, kXMLRoot);
  m_config =
      std::make_shared<std::remove_reference<decltype(*m_config)>::type>();
  m_estimation.parse(tnode);
  m_abort.parse(node_get(tnode, "task_abort"));
  m_subtask_sel.parse(node_get(tnode, "subtask_sel"));
  m_partitioning.parse(tnode);
  m_tab_sel.parse(node_get(tnode, "tab_sel"));

  m_config->exec_est = *m_estimation.config_get();
  m_config->abort = *m_abort.config_get();
  m_config->subtask_sel = *m_subtask_sel.config_get();
  m_config->partitioning = *m_partitioning.config_get();
  m_config->tab_sel = *m_tab_sel.config_get();
} /* parse() */

void task_alloc_parser::show(std::ostream& stream) const {
  stream << build_header() << m_abort << m_subtask_sel << m_partitioning
         << m_estimation << m_tab_sel << build_footer();
} /* show() */

NS_END(xml, config, ta, rcppsw);
