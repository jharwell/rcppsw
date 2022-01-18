/**
 * \file rng_parser.cpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
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
#include "rcppsw/math/config/xml/rng_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math, config, xml);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void rng_parser::parse(const ticpp::Element& node) {
  /* tag optional in all cases */
  if (nullptr != node.FirstChild(kXMLRoot, false)) {
    m_config = std::make_unique<config_type>();
    ER_DEBUG("Parent node=%s: child=%s",
             node.Value().c_str(),
             kXMLRoot.c_str());

    ticpp::Element enode = node_get(node, kXMLRoot);
    XML_PARSE_ATTR(enode, m_config, seed);
  }
} /* parse() */

NS_END(xml, config, math, rcppsw);
