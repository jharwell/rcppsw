/**
 * @file ema_parser.cpp
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
#include "rcppsw/math/ema_xml_parser.hpp"
#include <ext/ticpp/ticpp.h>

#include "rcppsw/utils/line_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
constexpr char ema_xml_parser::kXMLRoot[];

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void ema_xml_parser::parse(const ticpp::Element& node) {
  m_params =
      std::make_shared<std::remove_reference<decltype(*m_params)>::type>();
  ticpp::Element enode = node_get(const_cast<ticpp::Element&>(node), kXMLRoot);
  XML_PARSE_ATTR(enode, m_params, alpha);
} /* parse() */

void ema_xml_parser::show(std::ostream& stream) const {
  stream << build_header() << XML_ATTR_STR(m_params, alpha) << std::endl
         << build_footer();
} /* show() */

__rcsw_pure bool ema_xml_parser::validate(void) const {
  CHECK(m_params->alpha > 0.0);
  return true;

error:
  return false;
} /* validate() */

NS_END(math, rcppsw);
