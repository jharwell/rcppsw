/**
 * \file metrics_parser.cpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/metrics/config/xml/metrics_parser.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw::metrics::config::xml {

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void metrics_parser::parse(const ticpp::Element& node) {
  /* no metrics in XML tree--that's ok */
  if (nullptr == node.FirstChild(kXMLRoot, false)) {
    return;
  }

  ER_DEBUG("Parent node=%s: child=%s",
           node.Value().c_str(),
           kXMLRoot.c_str());

  ticpp::Element mnode = node_get(node, kXMLRoot);
  m_config = std::make_unique<config_type>();

  XML_PARSE_ATTR(mnode, m_config, metrics_path);


  ticpp::Element snode = node_get(mnode, "sinks");
  if (nullptr != snode.FirstChild(m_csv_sinks.xml_root(), false)) {
    m_csv_sinks.parse(snode);
  }
  if (nullptr != snode.FirstChild(m_network_sinks.xml_root(), false)) {
    m_network_sinks.parse(snode);
  }

  if (m_csv_sinks.is_parsed()) {
    m_config->csv = *m_csv_sinks.config_get<rmcxml::file_sink_parser::config_type>();
  }
  if (m_network_sinks.is_parsed()) {
    m_config->network = *m_network_sinks.config_get<rmcxml::network_sink_parser::config_type>();
  }
} /* parse() */

} /* namespace rcppsw::metrics::xml, config */
