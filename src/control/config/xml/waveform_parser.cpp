/**
 * \file waveform_parser.cpp
 *
 * \copyright 2018 John Harwell/Anthony Chen, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/control/config/xml/waveform_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, control, config, xml);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void waveform_parser::parse(const ticpp::Element& node) {
  /* waveforms are usually optional */
  if (nullptr == node.FirstChild(xml_root(), false)) {
    return;
  }

  ER_DEBUG("Parent node=%s: child=%s",
           node.Value().c_str(),
           kXMLRoot.c_str());

  ticpp::Element vnode = node_get(node, xml_root());
  m_config = std::make_unique<config_type>();

  /*
   * type is the only required parameter if the waveform itself is present in
   * the XML file.
   */
  XML_PARSE_ATTR(vnode, m_config, type);
  XML_PARSE_ATTR_DFLT(vnode, m_config, frequency, -1.0);
  XML_PARSE_ATTR_DFLT(vnode, m_config, amplitude, -1.0);
  XML_PARSE_ATTR_DFLT(vnode, m_config, offset, -1.0);
  XML_PARSE_ATTR_DFLT(vnode, m_config, phase, -1.0);
} /* parse() */

NS_END(xml, config, control, rcppsw);
