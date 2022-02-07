/**
 * \file base_sink_parser.cpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
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
#include "rcppsw/metrics/config/xml/base_sink_parser.hpp"

#include <list>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics, config, xml);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void base_sink_parser::output_mode_parse(const ticpp::Element& element,
                                         output_mode_config* config) {
  XML_PARSE_ATTR(element, config, output_interval);
  ticpp::Iterator<ticpp::Attribute> it;
  for (it = element.FirstAttribute(); it != it.end(); ++it) {
    if (is_collector_name(*it)) {
      std::string name;
      std::string value;
      it->GetName(&name);
      it->GetValue(&value);
      config->enabled.insert({ name, value });
    }
  } /* for(it..) */
} /* output_mode_parse() */

bool base_sink_parser::is_collector_name(const ticpp::Attribute& attr) const {
  std::list<std::string> non_names = { "output_interval" };
  std::string name;
  attr.GetName(&name);
  return non_names.end() == std::find(non_names.begin(), non_names.end(), name);
} /* is_collector_name() */

NS_END(xml, config, metrics, rcppsw);
