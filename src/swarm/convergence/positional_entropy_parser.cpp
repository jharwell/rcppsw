/**
 * @file positional_entropy_parser.cpp
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
#include "rcppsw/swarm/convergence/positional_entropy_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, swarm, convergence);

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
constexpr char positional_entropy_parser::kXMLRoot[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void positional_entropy_parser::parse(const ticpp::Element& node) {
  if (nullptr != node.FirstChild(kXMLRoot, false)) {
    ticpp::Element mnode = node_get(const_cast<ticpp::Element&>(node), kXMLRoot);
    XML_PARSE_ATTR(mnode, m_params, enable);
    if (m_params->enable) {
      XML_PARSE_ATTR(mnode, m_params, horizon);
      XML_PARSE_ATTR(mnode, m_params, horizon_delta);
    }
  }
} /* parse() */

NS_END(convergence, swarm, rcppsw);
