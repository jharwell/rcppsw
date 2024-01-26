/**
 * \file xml_config_parser.cpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/config/xml/xml_config_parser.hpp"

#include <string>

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::config::xml {

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
xml_config_parser::xml_config_parser(void)
    : ER_CLIENT_INIT() {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
ticpp::Element& xml_config_parser::node_get(const ticpp::Element& node,
                                            const std::string& tag) const {
  ticpp::Iterator<ticpp::Element> it(tag);
  it = it.begin(&node);
  ER_ASSERT(it != nullptr,
            "No tag '%s' found in node '%s'",
            tag.c_str(),
            node.Value().c_str());
  return *it;
} /* node_get() */

void xml_config_parser::node_attr_get(const ticpp::Element& node,
                                      const std::string& attr,
                                      bool& buf) const {
  std::string tmp;
  node.GetAttribute(attr, &tmp, true);
  if ("true" == tmp) {
    buf = true;
  } else if ("false" == tmp) {
    buf = false;
  } else {
    ER_FATAL_SENTINEL("Cannot convert '%s' into a bool. Accepted values are "
                      "['true', "
                      "'false']",
                      tmp.c_str());
  }
} /* node_attr_get() */

} /* namespace rcppsw::config::xml */
