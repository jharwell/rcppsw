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

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void exec_estimates_parser::parse(const ticpp::Element& node) {
  if (nullptr != node.FirstChild(kXMLRoot, false)) {
    ticpp::Element enode = node_get(node, kXMLRoot);
    m_config =
        std::make_shared<std::remove_reference<decltype(*m_config)>::type>();
    m_ema.parse(enode);
    m_config->ema = *m_ema.config_get();
    XML_PARSE_ATTR(enode, m_config, seed_enabled);

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
  }
} /* parse() */

void exec_estimates_parser::show(std::ostream& stream) const {
  if (!parsed()) {
    stream << build_header() << "<< Not Parsed >>" << std::endl
           << build_footer();
    return;
  }

  stream << build_header() << XML_ATTR_STR(m_config, seed_enabled) << std::endl
         << build_footer();
} /* show() */

NS_END(xml, config, ta, rcppsw);
