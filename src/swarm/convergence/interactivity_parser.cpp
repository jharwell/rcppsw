/**
 * @file interactivity_parser.cpp
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
#include "rcppsw/swarm/convergence/interactivity_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, swarm, convergence);

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
constexpr char interactivity_parser::kXMLRoot[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void interactivity_parser::parse(const ticpp::Element& node) {
    ticpp::Element mnode = node_get(const_cast<ticpp::Element&>(node), kXMLRoot);
    XML_PARSE_ATTR(mnode, m_params, enable);
} /* parse() */

NS_END(convergence, swarm, rcppsw);