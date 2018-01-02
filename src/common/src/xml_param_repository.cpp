/**
 * @file xml_param_repository.cpp
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
#include "rcppsw/common/xml_param_repository.hpp"
#include <algorithm>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, common);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
bool xml_param_repository::validate_all(void) {
  for (auto& pair : m_parsers) {
    if (!pair.second->validate()) {
      return false;
    }
  } /* for(pair..) */

  return true;
} /* validate_all() */

void xml_param_repository::parse_all(const ticpp::Element& node) {
  std::for_each(m_parsers.begin(),
                m_parsers.end(),
                [&](std::pair<const std::string, xml_param_parser*>& pair) {
                  pair.second->parse(node);
                });
} /* parse_all() */

void xml_param_repository::show_all(std::ostream& stream) {
  std::for_each(m_parsers.begin(),
                m_parsers.end(),
                [&](std::pair<const std::string, xml_param_parser*>& pair) {
                  pair.second->show(stream);
                });
} /* show_all() */

NS_END(common, rcppsw);
