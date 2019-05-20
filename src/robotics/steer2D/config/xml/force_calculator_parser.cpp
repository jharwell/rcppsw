/**
 * @file force_calculator_parser.cpp
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
#include "rcppsw/robotics/steer2D/config/xml/force_calculator_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, steer2D, config, xml);

/*******************************************************************************
 * Class Constants
 ******************************************************************************/
constexpr char force_calculator_parser::kXMLRoot[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void force_calculator_parser::parse(const ticpp::Element& node) {
  ticpp::Element knode = node_get(node, kXMLRoot);
  m_config =
      std::make_shared<std::remove_reference<decltype(*m_config)>::type>();
  m_avoidance.parse(knode);
  m_arrival.parse(knode);
  m_wander.parse(knode);
  m_polar.parse(knode);

  if (m_avoidance.parsed()) {
    m_config->avoidance = *m_avoidance.config_get();
  }
  if (m_arrival.parsed()) {
    m_config->arrival = *m_arrival.config_get();
  }
  if (m_wander.parsed()) {
    m_config->wander = *m_wander.config_get();
  }
  if (m_polar.parsed()) {
    m_config->polar = *m_polar.config_get();
  }
} /* parse() */

void force_calculator_parser::show(std::ostream& stream) const {
  stream << build_header() << m_avoidance << m_arrival << m_wander << m_polar
         << std::endl
         << build_footer();
} /* show() */

__rcsw_pure bool force_calculator_parser::validate(void) const {
  CHECK(m_avoidance.parsed());
  return m_arrival.validate() && m_wander.validate() && m_polar.validate();

error:
  return false;
} /* validate() */

NS_END(xml, config, steer2D, robotics, rcppsw);
