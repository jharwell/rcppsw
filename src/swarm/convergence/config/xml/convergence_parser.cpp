/**
 * @file convergence_parser.cpp
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
#include "rcppsw/swarm/convergence/config/xml/convergence_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, swarm, convergence, config, xml);

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
constexpr char convergence_parser::kXMLRoot[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void convergence_parser::parse(const ticpp::Element& node) {
  ticpp::Element cnode = node_get(node, kXMLRoot);

  XML_PARSE_ATTR(cnode, m_config, n_threads);
  XML_PARSE_ATTR(cnode, m_config, epsilon);

  m_pos_entropy.parse(cnode);
  m_config->pos_entropy = *m_pos_entropy.config_get();
  m_task_entropy.parse(cnode);
  m_config->task_dist_entropy = *m_task_entropy.config_get();
  m_interactivity.parse(cnode);
  m_config->interactivity = *m_interactivity.config_get();
  m_ang_order.parse(cnode);
  m_config->ang_order = *m_ang_order.config_get();
} /* parse() */

__rcsw_const bool convergence_parser::validate(void) const {
  CHECK(m_config->n_threads > 0);
  CHECK(IS_BETWEEN(m_config->epsilon, 0.0, 1.0));
  CHECK(m_pos_entropy.validate());
  CHECK(m_task_entropy.validate());
  CHECK(m_interactivity.validate());
  CHECK(m_ang_order.validate());
  return true;

error:
  return false;
} /* validate() */

NS_END(xml, config, convergence, swarm, rcppsw);
