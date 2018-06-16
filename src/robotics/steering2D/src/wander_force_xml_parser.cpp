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
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, steering2D);

/*******************************************************************************
 * Class Constants
 ******************************************************************************/
constexpr char wander_force_xml_parser::kXMLRoot[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void wander_force_xml_parser::parse(const argos::TConfigurationNode& node) {
  ticpp::Element wnode =
      argos::GetNode(const_cast<ticpp::Element&>(node), kXMLRoot);
  XML_PARSE_PARAM(wnode, m_params, interval);
  XML_PARSE_PARAM(wnode, m_params, max);
  XML_PARSE_PARAM(wnode, m_params, circle_distance);
  XML_PARSE_PARAM(wnode, m_params, circle_radius);
  XML_PARSE_PARAM(wnode, m_params, max_angle_delta);
} /* parse() */

void wander_force_xml_parser::show(std::ostream& stream) const {
  stream << build_header() << XML_PARAM_STR(m_params, interval) << std::endl
         << XML_PARAM_STR(m_params, max) << std::endl
         << XML_PARAM_STR(m_params, circle_distance) << std::endl
         << XML_PARAM_STR(m_params, circle_radius) << std::endl
         << XML_PARAM_STR(m_params, max_angle_delta) << std::endl
         << build_footer();
} /* show() */

__rcsw_pure bool wander_force_xml_parser::validate(void) const {
  return m_params.circle_distance > 0.0 && m_params.circle_radius > 0.0 &&
         m_params.max_angle_delta < 360 && m_params.interval > 0;
} /* validate() */

NS_END(steering2D, robotics, rcppsw);
