/**
 * @file arrival_force_xml_parser.cpp
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
#include "rcppsw/robotics/steering2D/arrival_force_xml_parser.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, steering2D);

/*******************************************************************************
 * Class Constants
 ******************************************************************************/
constexpr char arrival_force_xml_parser::kXMLRoot[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void arrival_force_xml_parser::parse(const argos::TConfigurationNode& node) {
  if (nullptr != node.FirstChild(kXMLRoot, false)) {
    ticpp::Element anode =
        argos::GetNode(const_cast<ticpp::Element&>(node), kXMLRoot);
    m_params =
        std::make_shared<std::remove_reference<decltype(*m_params)>::type>();
    XML_PARSE_PARAM(anode, m_params, max);
    XML_PARSE_PARAM(anode, m_params, slowing_radius);
    XML_PARSE_PARAM(anode, m_params, slowing_speed_min);
    m_parsed = true;
  }
} /* parse() */

void arrival_force_xml_parser::show(std::ostream& stream) const {
  stream << build_header() << XML_PARAM_STR(m_params, max) << std::endl
         << XML_PARAM_STR(m_params, slowing_radius) << std::endl
         << XML_PARAM_STR(m_params, slowing_speed_min) << std::endl
         << build_footer();
} /* show() */

__rcsw_pure bool arrival_force_xml_parser::validate(void) const {
  if (m_parsed) {
    CHECK(m_params->slowing_radius > 0.0);
    CHECK(m_params->slowing_speed_min > 0.0);
    CHECK(m_params->max > 0.0 && m_params->max > m_params->slowing_speed_min);
  }
  return true;

error:
  return false;
} /* validate() */

NS_END(steering2D, robotics, rcppsw);
