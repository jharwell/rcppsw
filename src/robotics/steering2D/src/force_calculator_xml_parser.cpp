/**
 * @file force_calculator_xml_parser.cpp
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
#include "rcppsw/robotics/steering2D/force_calculator_xml_parser.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, steering2D);

/*******************************************************************************
 * Class Constants
 ******************************************************************************/
constexpr char force_calculator_xml_parser::kXMLRoot[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void force_calculator_xml_parser::parse(const argos::TConfigurationNode &node) {
  ticpp::Element knode =
      argos::GetNode(const_cast<ticpp::Element &>(node), kXMLRoot);
  m_params =
      std::make_shared<std::remove_reference<decltype(*m_params)>::type>();
  m_avoidance.parse(knode);
  m_arrival.parse(knode);
  m_wander.parse(knode);
  m_polar.parse(knode);

  if (m_avoidance.parsed()) {
    m_params->avoidance = *m_avoidance.parse_results();
  }
  if (m_arrival.parsed()) {
    m_params->arrival = *m_arrival.parse_results();
  }
  if (m_wander.parsed()) {
    m_params->wander = *m_wander.parse_results();
  }
  if (m_polar.parsed()) {
    m_params->polar = *m_polar.parse_results();
  }
} /* parse() */

void force_calculator_xml_parser::show(std::ostream &stream) const {
  stream << build_header() << m_avoidance << m_arrival << m_wander << m_polar
         << std::endl
         << build_footer();
} /* show() */

__rcsw_pure bool force_calculator_xml_parser::validate(void) const {
  CHECK(m_avoidance.parsed());
  return m_arrival.validate() && m_wander.validate() && m_polar.validate();

error:
  return false;
} /* validate() */

NS_END(steering2D, robotics, rcppsw);
