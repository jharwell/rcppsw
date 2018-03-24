/**
 * @file avoidance_force_xml_parser.cpp
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
#include "rcppsw/control/avoidance_force_xml_parser.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void avoidance_force_xml_parser::parse(const argos::TConfigurationNode& node) {
  ticpp::Element anode = argos::GetNode(const_cast<ticpp::Element&>(node),
                                        kXMLRoot);
  XML_PARSE_PARAM(anode, m_params, lookahead);
  XML_PARSE_PARAM(anode, m_params, max);
} /* parse() */

void avoidance_force_xml_parser::show(std::ostream& stream) const {
  stream << emit_header()
         << XML_PARAM_STR(m_params, lookahead) << std::endl
         << XML_PARAM_STR(m_params, max) << std::endl;
} /* show() */

__pure bool avoidance_force_xml_parser::validate(void) const {
  return m_params.lookahead > 0.0 && m_params.max > 0.0;
} /* validate() */

NS_END(params, rcppsw);
