/**
 * @file stoch_greedy_nbhd_parser.cpp
 *
 * @copyright 2019 John Harwell, All rights reserved.
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
#include "rcppsw/ta/config/xml/stoch_greedy_nbhd_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta, config, xml);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void stoch_greedy_nbhd_parser::parse(const ticpp::Element& node) {
  /* executive not used */
  if (nullptr == node.FirstChild(kXMLRoot, false)) {
    return;
  }

  ticpp::Element tnode = node_get(node, kXMLRoot);
  m_config = std::make_unique<config_type>();
  m_subtask_sel.parse(node_get(tnode, "subtask_sel"));
  m_partitioning.parse(tnode);
  m_tab_sel.parse(node_get(tnode, "tab_sel"));

  m_config->subtask_sel =
      *m_subtask_sel.config_get<src_sigmoid_sel_parser::config_type>();
  m_config->partitioning =
      *m_partitioning.config_get<task_partition_parser::config_type>();
  m_config->tab_sel =
      *m_tab_sel.config_get<src_sigmoid_sel_parser::config_type>();
} /* parse() */

bool stoch_greedy_nbhd_parser::validate(void) const {
  return m_subtask_sel.validate() && m_partitioning.validate() &&
         m_tab_sel.validate();
} /* validate() */

NS_END(xml, config, ta, rcppsw);
