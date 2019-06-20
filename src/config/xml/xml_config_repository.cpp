/**
 * @file xml_config_repository.cpp
 *
 * @copyright 2017 John Harwell, All rights reserved.
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
#include "rcppsw/config/xml/xml_config_repository.hpp"
#include <algorithm>

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, config, xml);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
bool xml_config_repository::validate_all(void) {
  for (auto& pair : m_parsers) {
    if (!pair.second->validate()) {
      ER_ERR("Parser '%s' failed validation", pair.first.c_str());
      return false;
    }
  } /* for(pair..) */

  return true;
} /* validate_all() */

void xml_config_repository::parse_all(const ticpp::Element& node) {
  std::for_each(m_parsers.begin(),
                m_parsers.end(),
                [&](std::pair<const std::string, xml_config_parser*>& pair) {
                  pair.second->parse(node);
                });
} /* parse_all() */

NS_END(xml, config, rcppsw);
