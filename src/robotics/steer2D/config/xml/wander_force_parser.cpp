/**
 * @file wander_force_parser.cpp
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
#include "rcppsw/robotics/steer2D/config/xml/wander_force_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, steer2D, config, xml);

/*******************************************************************************
 * Class Constants
 ******************************************************************************/
constexpr char wander_force_parser::kXMLRoot[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void wander_force_parser::parse(const ticpp::Element& node) {
  if (nullptr != node.FirstChild(kXMLRoot, false)) {
    ticpp::Element wnode = node_get(node, kXMLRoot);
    m_config =
        std::make_shared<std::remove_reference<decltype(*m_config)>::type>();
    XML_PARSE_ATTR(wnode, m_config, interval);
    XML_PARSE_ATTR(wnode, m_config, max);
    XML_PARSE_ATTR(wnode, m_config, circle_distance);
    XML_PARSE_ATTR(wnode, m_config, circle_radius);
    XML_PARSE_ATTR(wnode, m_config, max_angle_delta);
    XML_PARSE_ATTR(wnode, m_config, normal_dist);
    m_parsed = true;
  }
} /* parse() */

void wander_force_parser::show(std::ostream& stream) const {
  if (!m_parsed) {
    stream << build_header() << "<< Not Parsed >>" << std::endl
           << build_footer();
    return;
  }

  stream << build_header() << XML_ATTR_STR(m_config, interval) << std::endl
         << XML_ATTR_STR(m_config, max) << std::endl
         << XML_ATTR_STR(m_config, circle_distance) << std::endl
         << XML_ATTR_STR(m_config, circle_radius) << std::endl
         << XML_ATTR_STR(m_config, max_angle_delta) << std::endl
         << XML_ATTR_STR(m_config, normal_dist) << std::endl
         << build_footer();
} /* show() */

__rcsw_pure bool wander_force_parser::validate(void) const {
  if (m_parsed) {
    CHECK(m_config->circle_distance > 0.0);
    CHECK(m_config->circle_radius > 0.0);
    CHECK(m_config->max_angle_delta < 360);
    CHECK(m_config->interval > 0);
    CHECK(m_config->max > 0);
  }
  return true;

error:
  return false;
} /* validate() */

NS_END(xml, config, steer2D, robotics, rcppsw);
