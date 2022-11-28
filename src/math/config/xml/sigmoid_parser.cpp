/**
 * \file sigmoid_parser.cpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/math/config/xml/sigmoid_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math, config, xml);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void sigmoid_parser::parse(const ticpp::Element& node) {
  ER_DEBUG("Parent node=%s: child=%s",
           node.Value().c_str(),
           kXMLRoot.c_str());

  ticpp::Element snode = node_get(node, kXMLRoot);
  m_config = std::make_unique<config_type>();

  XML_PARSE_ATTR(snode, m_config, reactivity);
  XML_PARSE_ATTR(snode, m_config, offset);
  XML_PARSE_ATTR(snode, m_config, gamma);
} /* parse() */

bool sigmoid_parser::validate(void) const {
  RCSW_CHECK(m_config->reactivity > 0.0);
  RCSW_CHECK(m_config->offset > 0.0);
  return true;

error:
  return false;
} /* validate() */

NS_END(xml, config, math, rcppsw);
