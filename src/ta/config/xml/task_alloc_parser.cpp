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
 * Member Functions
 ******************************************************************************/
void task_alloc_parser::parse(const ticpp::Element& node) {
  /* executive not used */
  if (nullptr == node.FirstChild(kXMLRoot, false)) {
    return;
  }

  ticpp::Element tnode = node_get(node, kXMLRoot);
  m_config = std::make_unique<config_type>();

  /* mandatory */
  XML_PARSE_ATTR(tnode, m_config, policy);

  /* optional, but common to all policies */
  m_estimation.parse(tnode);
  m_abort.parse(node_get(tnode, "task_abort"));

  /* optional policies */
  m_sgn.parse(tnode);
  m_epsilon.parse(tnode);

  m_config->exec_est =
      *m_estimation.config_get<exec_estimates_parser::config_type>();
  m_config->abort = *m_abort.config_get<src_sigmoid_sel_parser::config_type>();
  m_config->stoch_greedy_nbhd =
      *m_sgn.config_get<stoch_greedy_nbhd_parser::config_type>();
  m_config->epsilon_greedy =
      *m_epsilon.config_get<epsilon_greedy_parser::config_type>();
} /* parse() */

bool task_alloc_parser::validate(void) const {
  return m_estimation.validate() && m_abort.validate() &&
      m_sgn.validate() && m_epsilon.validate();
} /* validate() */

NS_END(xml, config, ta, rcppsw);
