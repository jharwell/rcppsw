/**
 * \file file_sink_parser.cpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/metrics/config/xml/file_sink_parser.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics, config, xml);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void file_sink_parser::parse(const ticpp::Element& node) {
  /* This sink may not be used */
  if (nullptr == node.FirstChild(kXMLRoot, false)) {
    return;
  }
  ER_DEBUG("Parent node=%s: child=%s",
           node.Value().c_str(),
           kXMLRoot.c_str());

  ticpp::Element mnode = node_get(node, kXMLRoot);
  m_config = std::make_unique<config_type>();

  if (nullptr != mnode.FirstChild("create", false)) {
    output_mode_parse(node_get(mnode, "create"), &m_config->create);
  }
  if (nullptr != mnode.FirstChild("append", false)) {
    output_mode_parse(node_get(mnode, "append"), &m_config->append);
  }
  if (nullptr != mnode.FirstChild("truncate", false)) {
    output_mode_parse(node_get(mnode, "truncate"), &m_config->truncate);
  }
} /* parse() */

NS_END(xml, config, metrics, rcppsw);
