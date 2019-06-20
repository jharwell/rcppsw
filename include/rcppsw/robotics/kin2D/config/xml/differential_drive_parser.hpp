/**
 * @file differential_drive_parser.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_KIN2D_CONFIG_XML_DIFFERENTIAL_DRIVE_PARSER_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_KIN2D_CONFIG_XML_DIFFERENTIAL_DRIVE_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <memory>

#include "rcppsw/robotics/kin2D/config/differential_drive_config.hpp"
#include "rcppsw/common/common.hpp"
#include "rcppsw/config/xml/xml_config_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, kin2D, config, xml);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @class differential_drive_parser
 * @ingroup rcppsw robotics kin2D config xml
 *
 * @brief Parses XML configuration relating to the \ref differential_drive into
 * \ref differential_drive_config.
 */
class differential_drive_parser : public rcppsw::config::xml::xml_config_parser {
 public:
  using config_type = differential_drive_config;

  /**
   * @brief The root tag that all differential drive configuration values
   * should lie under in the XML tree.
   */
  static constexpr char kXMLRoot[] = "differential_drive";

  void parse(const ticpp::Element& node) override;
  bool validate(void) const override;

  std::string xml_root(void) const override { return kXMLRoot; }

 private:
  rcppsw::config::base_config* config_get_impl(void) const override {
    return m_config.get();
  }

  /* clang-format off */
  std::unique_ptr<config_type> m_config{nullptr};
  /* clang-format on */
};

NS_END(xml, config, kin2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_KIN2D_CONFIG_XML_DIFFERENTIAL_DRIVE_PARSER_HPP_ */
