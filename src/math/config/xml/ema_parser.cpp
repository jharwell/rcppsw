/**
 * \file ema_parser.cpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/math/config/xml/ema_parser.hpp"

#include "rcppsw/utils/line_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math, config, xml);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void ema_parser::parse(const ticpp::Element& node) {
  ER_DEBUG("Parent node=%s: child=%s",
           node.Value().c_str(),
           kXMLRoot.c_str());
  m_config = std::make_unique<config_type>();
  ticpp::Element enode = node_get(node, kXMLRoot);
  XML_PARSE_ATTR(enode, m_config, alpha);
} /* parse() */

bool ema_parser::validate(void) const {
  RCSW_CHECK(m_config->alpha > 0.0);
  return true;

error:
  return false;
} /* validate() */

NS_END(xml, config, math, rcppsw);
