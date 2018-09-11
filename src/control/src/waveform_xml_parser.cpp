/**
 * @file waveform_xml_parser.cpp
 *
 * @copyright 2018 John Harwell/Anthony Chen, All rights reserved.
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
#include "rcppsw/control/waveform_xml_parser.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Class Constants
 ******************************************************************************/
constexpr char waveform_xml_parser::kXMLRoot[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void waveform_xml_parser::parse(const ticpp::Element &node) {
  if (nullptr != node.FirstChild(xml_root(), false)) {
    ticpp::Element vnode =
        get_node(const_cast<ticpp::Element &>(node), xml_root());
    m_params =
        std::make_shared<std::remove_reference<decltype(*m_params)>::type>();

    XML_PARSE_PARAM(vnode, m_params, type);
    XML_PARSE_PARAM(vnode, m_params, frequency);
    XML_PARSE_PARAM(vnode, m_params, amplitude);
    XML_PARSE_PARAM(vnode, m_params, offset);
    m_parsed = true;
  }
} /* parse() */

void waveform_xml_parser::show(std::ostream &stream) const {
  if (!m_parsed) {
    stream << build_header() << "<< Not Parsed >>" << std::endl
           << build_footer();
    return;
  }

  stream << build_header() << std::endl
         << XML_PARAM_STR(m_params, type) << std::endl
         << XML_PARAM_STR(m_params, frequency) << std::endl
         << XML_PARAM_STR(m_params, amplitude) << std::endl
         << XML_PARAM_STR(m_params, offset) << std::endl
         << build_footer();
} /* show() */

NS_END(control, rcppsw);
