/**
 * \file metrics_parser.cpp
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
#include "rcppsw/metrics/config/xml/metrics_parser.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics, config, xml);

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

NS_END(xml, config, metrics, rcppsw);
