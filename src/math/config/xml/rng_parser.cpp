/**
 * \file rng_parser.cpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/math/config/xml/rng_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::math::config::xml {

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void rng_parser::parse(const ticpp::Element& node) {
  /* tag optional in all cases */
  if (nullptr != node.FirstChild(kXMLRoot, false)) {
    m_config = std::make_unique<config_type>();
    ER_DEBUG("Parent node=%s: child=%s",
             node.Value().c_str(),
             kXMLRoot.c_str());

    ticpp::Element enode = node_get(node, kXMLRoot);
    XML_PARSE_ATTR(enode, m_config, seed);
  }
} /* parse() */

} /* namespace rcppsw::math::xml, config */
