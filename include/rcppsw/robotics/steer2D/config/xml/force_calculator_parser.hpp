/**
 * @file force_calculator_parser.hpp
 *
 * @copyright 2017 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_STEER2D_CONFIG_XML_FORCE_CALCULATOR_PARSER_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_STEER2D_CONFIG_XML_FORCE_CALCULATOR_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <memory>

#include "rcppsw/common/common.hpp"
#include "rcppsw/robotics/steer2D/config/xml/force_calculator_parser.hpp"
#include "rcppsw/robotics/steer2D/config/force_calculator_config.hpp"
#include "rcppsw/robotics/steer2D/config/xml/avoidance_force_parser.hpp"
#include "rcppsw/robotics/steer2D/config/xml/arrival_force_parser.hpp"
#include "rcppsw/robotics/steer2D/config/xml/wander_force_parser.hpp"
#include "rcppsw/robotics/steer2D/config/xml/polar_force_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, steer2D, config, xml);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @class force_calculator_parser
 * @ingroup rcppsw robotics steer2D config xml
 *
 * @brief Parses XML configuration for \ref force_calculator into
 * \ref force_calculator_config. Assumes it is handed an XML parent in which the
 * child tag \ref kXMLRoot is found.
 */
class force_calculator_parser : public rcppsw::config::xml::xml_config_parser {
 public:
  static constexpr char kXMLRoot[] = "steering2D";

  explicit force_calculator_parser(uint level)
      : xml_config_parser(level),
        m_avoidance(level + 1),
        m_arrival(level + 1),
        m_wander(level + 1),
        m_polar(level + 1) {}

  void parse(const ticpp::Element& node) override;
  void show(std::ostream& stream) const override;
  bool validate(void) const override;

  std::string xml_root(void) const override { return kXMLRoot; }
  std::shared_ptr<force_calculator_config> config_get(void) const {
    return m_config;
  }

 private:
  std::shared_ptr<rcppsw::config::base_config> config_get_impl(void) const override {
    return m_config;
  }

  /* clang-format off */
  std::shared_ptr<force_calculator_config> m_config{nullptr};
  avoidance_force_parser                   m_avoidance;
  arrival_force_parser                     m_arrival;
  wander_force_parser                      m_wander;
  polar_force_parser                       m_polar;
  /* clang-format on */
};

NS_END(xml, config, steer2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_STEER2D_CONFIG_XML_FORCE_CALCULATOR_PARSER_HPP_ */
