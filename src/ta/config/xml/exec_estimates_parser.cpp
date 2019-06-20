/**
 * @file exec_estimates_parser.cpp
 *
 * @copyright 2018 John Harwell, All rights reserved.
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
#include "rcppsw/ta/config/xml/exec_estimates_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta, config, xml);

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
constexpr char exec_estimates_parser::kXMLRoot[];
namespace mxml = math::config::xml;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void exec_estimates_parser::parse(const ticpp::Element& node) {
  /* tag is optional in all cases */
  if (nullptr == node.FirstChild(kXMLRoot, false)) {
    return;
  }
  m_config = std::make_unique<config_type>();
  ticpp::Element enode = node_get(node, kXMLRoot);

  XML_PARSE_ATTR_DFLT(enode, m_config, seed_enabled, false);

  if (!m_config->seed_enabled) {
    return;
  }
  m_ema.parse(enode);
  m_config->ema = *m_ema.config_get<mxml::ema_parser::config_type>();

  if (m_task_names.empty()) {
    ER_WARN("No tasks registered for parsing");
  }
  /*
   * For each registered task we want to get exec estimates for, parse the
   * estimate.
   */
  for (auto& s : m_task_names) {
    math::rangeu tmp{0, 0};
    node_attr_get(enode, s, tmp);
    m_config->ranges.insert({s, tmp});
  } /* for(&s..) */
} /* parse() */

__rcsw_pure bool exec_estimates_parser::validate(void) const {
  if (!is_parsed() || !m_config->seed_enabled) {
    return true;
  }
  return m_ema.validate();
} /* validate() */

NS_END(xml, config, ta, rcppsw);
