/**
 * @file kinematics2D_xml_parser.cpp
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
#include "rcppsw/control/kinematics2D_xml_parser.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Class Constants
 ******************************************************************************/
constexpr char kinematics2D_xml_parser::kXMLRoot[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void kinematics2D_xml_parser::parse(const argos::TConfigurationNode& node) {
  ticpp::Element knode =
      argos::GetNode(const_cast<ticpp::Element&>(node), kXMLRoot);
  m_avoidance.parse(knode);
  m_arrival.parse(knode);
  m_wander.parse(knode);
  m_polar.parse(knode);
  m_params.avoidance = *m_avoidance.parse_results();
  m_params.arrival = *m_arrival.parse_results();
  m_params.wander = *m_wander.parse_results();
  m_params.polar = *m_polar.parse_results();
} /* parse() */

void kinematics2D_xml_parser::show(std::ostream& stream) const {
  stream << build_header() << m_avoidance << m_arrival << m_wander << m_polar
         << std::endl
         << build_footer();
} /* show() */

__pure bool kinematics2D_xml_parser::validate(void) const {
  return m_avoidance.validate() && m_arrival.validate() &&
         m_wander.validate() && m_polar.validate();
  return true;
} /* validate() */

NS_END(params, rcppsw);
