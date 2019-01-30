/**
 * @file wander_force_xml_parser.cpp
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
#include "rcppsw/robotics/steering2D/wander_force_xml_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, steering2D);

/*******************************************************************************
 * Class Constants
 ******************************************************************************/
constexpr char wander_force_xml_parser::kXMLRoot[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void wander_force_xml_parser::parse(const ticpp::Element &node) {
  if (nullptr != node.FirstChild(kXMLRoot, false)) {
    ticpp::Element wnode =
        node_get(const_cast<ticpp::Element &>(node), kXMLRoot);
    m_params =
        std::make_shared<std::remove_reference<decltype(*m_params)>::type>();
    XML_PARSE_ATTR(wnode, m_params, interval);
    XML_PARSE_ATTR(wnode, m_params, max);
    XML_PARSE_ATTR(wnode, m_params, circle_distance);
    XML_PARSE_ATTR(wnode, m_params, circle_radius);
    XML_PARSE_ATTR(wnode, m_params, max_angle_delta);
    XML_PARSE_ATTR(wnode, m_params, normal_dist);
    m_parsed = true;
  }
} /* parse() */

void wander_force_xml_parser::show(std::ostream &stream) const {
  if (!m_parsed) {
    stream << build_header() << "<< Not Parsed >>" << std::endl
           << build_footer();
    return;
  }

  stream << build_header() << XML_ATTR_STR(m_params, interval) << std::endl
         << XML_ATTR_STR(m_params, max) << std::endl
         << XML_ATTR_STR(m_params, circle_distance) << std::endl
         << XML_ATTR_STR(m_params, circle_radius) << std::endl
         << XML_ATTR_STR(m_params, max_angle_delta) << std::endl
         << XML_ATTR_STR(m_params, normal_dist) << std::endl
         << build_footer();
} /* show() */

__rcsw_pure bool wander_force_xml_parser::validate(void) const {
  if (m_parsed) {
    CHECK(m_params->circle_distance > 0.0);
    CHECK(m_params->circle_radius > 0.0);
    CHECK(m_params->max_angle_delta < 360);
    CHECK(m_params->interval > 0);
    CHECK(m_params->max > 0);
  }
  return true;

error:
  return false;
} /* validate() */

NS_END(steering2D, robotics, rcppsw);
