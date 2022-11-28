/**
 * \file xml_config_repository.cpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
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
