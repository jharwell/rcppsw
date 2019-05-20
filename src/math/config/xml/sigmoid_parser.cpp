/**
 * @file sigmoid_parser.cpp
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
#include "rcppsw/math/config/xml/sigmoid_parser.hpp"
#include <ext/ticpp/ticpp.h>

#include "rcppsw/utils/line_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math, config, xml);

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
constexpr char sigmoid_parser::kXMLRoot[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void sigmoid_parser::parse(const ticpp::Element& node) {
  ticpp::Element snode = node_get(node, kXMLRoot);
  m_config =
      std::make_shared<std::remove_reference<decltype(*m_config)>::type>();

  XML_PARSE_ATTR(snode, m_config, reactivity);
  XML_PARSE_ATTR(snode, m_config, offset);
  XML_PARSE_ATTR(snode, m_config, gamma);
} /* parse() */

void sigmoid_parser::show(std::ostream& stream) const {
  stream << build_header() << XML_ATTR_STR(m_config, reactivity) << std::endl
         << XML_ATTR_STR(m_config, offset) << std::endl
         << XML_ATTR_STR(m_config, gamma) << std::endl
         << build_footer();
} /* show() */

__rcsw_pure bool sigmoid_parser::validate(void) const {
  CHECK(m_config->reactivity > 0.0);
  CHECK(m_config->offset > 0.0);
  return true;

error:
  return false;
} /* validate() */

NS_END(xml, config, math, rcppsw);
