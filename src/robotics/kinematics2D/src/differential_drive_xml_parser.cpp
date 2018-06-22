/**
 * @file differential_drive_xml_parser.cpp
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
#include "rcppsw/robotics/kinematics2D/differential_drive_xml_parser.hpp"
#include <argos3/core/utility/configuration/argos_configuration.h>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, kinematics2D);

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
constexpr char differential_drive_xml_parser::kXMLRoot[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void differential_drive_xml_parser::parse(const ticpp::Element& node) {
  ticpp::Element wnode =
      argos::GetNode(const_cast<ticpp::Element&>(node), kXMLRoot);
  m_params =
      std::make_shared<std::remove_reference<decltype(*m_params)>::type>();

  XML_PARSE_PARAM(wnode, m_params, max_speed);

  argos::CDegrees angle;
  argos::GetNodeAttribute(wnode, "soft_turn_max", angle);
  m_params->soft_turn_max = argos::ToRadians(angle);
} /* parse() */

void differential_drive_xml_parser::show(std::ostream& stream) const {
  stream << build_header()
         << XML_PARAM_STR(m_params, soft_turn_max)
         << std::endl
         << XML_PARAM_STR(m_params, max_speed) << std::endl
         << build_footer();
} /* show() */

__rcsw_pure bool differential_drive_xml_parser::validate(void) const {
  CHECK(m_params->soft_turn_max.GetValue() > 0.0);
  CHECK(m_params->max_speed > 0.0);
  return true;

error:
  return false;
} /* validate() */

NS_END(kinematics2D, robotics, rcppsw);
