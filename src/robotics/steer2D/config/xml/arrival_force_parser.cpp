/**
 * @file arrival_force_parser.cpp
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
#include "rcppsw/robotics/steer2D/config/xml/arrival_force_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, steer2D, config, xml);

/*******************************************************************************
 * Class Constants
 ******************************************************************************/
constexpr char arrival_force_parser::kXMLRoot[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void arrival_force_parser::parse(const ticpp::Element& node) {
  if (nullptr != node.FirstChild(kXMLRoot, false)) {
    ticpp::Element anode = node_get(node, kXMLRoot);
    m_config =
        std::make_shared<std::remove_reference<decltype(*m_config)>::type>();
    XML_PARSE_ATTR(anode, m_config, max);
    XML_PARSE_ATTR(anode, m_config, slowing_radius);
    XML_PARSE_ATTR(anode, m_config, slowing_speed_min);
    m_parsed = true;
  }
} /* parse() */

void arrival_force_parser::show(std::ostream& stream) const {
  stream << build_header() << XML_ATTR_STR(m_config, max) << std::endl
         << XML_ATTR_STR(m_config, slowing_radius) << std::endl
         << XML_ATTR_STR(m_config, slowing_speed_min) << std::endl
         << build_footer();
} /* show() */

__rcsw_pure bool arrival_force_parser::validate(void) const {
  if (m_parsed) {
    CHECK(m_config->slowing_radius > 0.0);
    CHECK(m_config->slowing_speed_min > 0.0);
    CHECK(m_config->max > 0.0 && m_config->max > m_config->slowing_speed_min);
  }
  return true;

error:
  return false;
} /* validate() */

NS_END(xml, config, steer2D, robotics, rcppsw);
