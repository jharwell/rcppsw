/**
 * @file avoidance_force_xml_parser.cpp
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
#include "rcppsw/robotics/steering2D/avoidance_force_xml_parser.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, steering2D);

/*******************************************************************************
 * Class Constants
 ******************************************************************************/
constexpr char avoidance_force_xml_parser::kXMLRoot[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void avoidance_force_xml_parser::parse(const ticpp::Element &node) {
  if (nullptr != node.FirstChild(kXMLRoot, false)) {
    ticpp::Element anode =
        get_node(const_cast<ticpp::Element &>(node), kXMLRoot);
    m_params =
        std::make_shared<std::remove_reference<decltype(*m_params)>::type>();
    XML_PARSE_PARAM(anode, m_params, max);
    m_parsed = true;
  }
} /* parse() */

void avoidance_force_xml_parser::show(std::ostream &stream) const {
  if (!m_parsed) {
    stream << build_header() << "<< Not Parsed >>" << std::endl
           << build_footer();
    return;
  }

  stream << build_header() << std::endl
         << XML_PARAM_STR(m_params, max) << std::endl
         << build_footer();
} /* show() */

__rcsw_pure bool avoidance_force_xml_parser::validate(void) const {
  if (m_parsed) {
    CHECK(m_params->max > 0.0);
  }
  return true;

error:
  return false;
} /* validate() */

NS_END(steering2D, robotics, rcppsw);
