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
#include "rcppsw/robotics/kin2D/config/xml/differential_drive_parser.hpp"
#include "rcppsw/math/angles.hpp"
#include "rcppsw/math/degrees.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, kin2D, config, xml);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void differential_drive_parser::parse(const ticpp::Element& node) {
  ticpp::Element wnode = node_get(node, kXMLRoot);
  m_config = std::make_unique<config_type>();

  XML_PARSE_ATTR(wnode, m_config, max_speed);

  math::degrees angle;
  node_attr_get(wnode, "soft_turn_max", angle);
  m_config->soft_turn_max = math::to_radians(angle);
} /* parse() */

bool differential_drive_parser::validate(void) const {
  CHECK(m_config->soft_turn_max.value() > 0.0);
  CHECK(m_config->max_speed > 0.0);
  return true;

error:
  return false;
} /* validate() */

NS_END(xml, config, kin2D, robotics, rcppsw);
