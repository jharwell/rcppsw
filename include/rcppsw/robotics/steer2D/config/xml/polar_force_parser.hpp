/**
 * @file polar_force_parser.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_STEER2D_CONFIG_XML_POLAR_FORCE_PARSER_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_STEER2D_CONFIG_XML_POLAR_FORCE_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <memory>

#include "rcppsw/common/common.hpp"
#include "rcppsw/config/xml/xml_config_parser.hpp"
#include "rcppsw/robotics/steer2D/config/polar_force_config.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, steer2D, config, xml);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @class polar_force_parser
 * @ingroup rcppsw robotics steer2D config xml
 *
 * @brief Parses XML configuration for \ref polar_force into \ref
 * polar_force_config. Assumes it is handed an XML parent in which the child tag
 * \ref kXMLRoot is found.
 */
class polar_force_parser : public rcppsw::config::xml::xml_config_parser {
 public:
  static constexpr char kXMLRoot[] = "polar_force";

  explicit polar_force_parser(uint level)
      : xml_config_parser(level) {}

  void parse(const ticpp::Element& node) override;
  void show(std::ostream& stream) const override;
  bool validate(void) const override;

  std::string xml_root(void) const override { return kXMLRoot; }
  bool parsed(void) const override { return m_parsed; }

  std::shared_ptr<polar_force_config> config_get(void) const {
    return m_config;
  }

 private:
  std::shared_ptr<rcppsw::config::base_config> config_get_impl(void) const override {
    return m_config;
  }

 private:
  /* clang-format off */
  bool                                m_parsed{false};
  std::shared_ptr<polar_force_config> m_config{nullptr};
  /* clang-format on */
};

NS_END(xml, config, steer2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_STEER2D_CONFIG_XML_POLAR_FORCE_PARSER_HPP_ */
