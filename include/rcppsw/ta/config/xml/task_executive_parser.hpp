/**
 * @file task_executive_parser.hpp
 *
 * @copyright 2018 John Harwell, All rights reserved.
 *
 * This file is part of FORDYCA.
 *
 * FORDYCA is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * FORDYCA is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * FORDYCA.  If not, see <http://www.gnu.org/licenses/
 */

#ifndef INCLUDE_RCPPSW_TA_CONFIG_XML_TASK_EXECUTIVE_PARSER_HPP_
#define INCLUDE_RCPPSW_TA_CONFIG_XML_TASK_EXECUTIVE_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "rcppsw/common/common.hpp"
#include "rcppsw/config/xml/xml_config_parser.hpp"
#include "rcppsw/ta/config/task_executive_config.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta, config, xml);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class task_executive_parser
 * @ingroup rcppsw ta config xml
 *
 * @brief Parses XML configuration for \ref base_task_executive and its derived
 * classed into \ref task_executive_config.
 */
class task_executive_parser final : public rcppsw::config::xml::xml_config_parser {
 public:
  explicit task_executive_parser(uint level) : xml_config_parser(level) {}

  /**
   * @brief The root tag that all task task_executive parameters should lie
   * under in the XML tree.
   */
  static constexpr char kXMLRoot[] = "task_executive";

  void show(std::ostream& stream) const override;
  void parse(const ticpp::Element& node) override;
  std::string xml_root(void) const override { return kXMLRoot; }

  std::shared_ptr<task_executive_config> config_get(void) const {
    return m_config;
  }

 private:
  std::shared_ptr<rcppsw::config::base_config> config_get_impl(
      void) const override {
    return m_config;
  }

  /* clang-format off */
  std::shared_ptr<task_executive_config> m_config{nullptr};
  /* clang-format on */
};

NS_END(xml, config, ta, rcppsw);

#endif /* INCLUDE_RCPPSW_TA_CONFIG_XML_TASK_EXECUTIVE_PARSER_HPP_ */