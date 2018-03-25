/**
 * @file kinematics2D_xml_parser.hpp
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

#ifndef INCLUDE_RCPPSW_CONTROL_KINEMATICS2D_XML_PARSER_HPP_
#define INCLUDE_RCPPSW_CONTROL_KINEMATICS2D_XML_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <argos3/core/utility/configuration/argos_configuration.h>

#include "rcppsw/common/common.hpp"
#include "rcppsw/params/xml_param_parser.hpp"
#include "rcppsw/control/kinematics2D_params.hpp"
#include "rcppsw/control/avoidance_force_xml_parser.hpp"
#include "rcppsw/control/arrival_force_xml_parser.hpp"
#include "rcppsw/control/wander_force_xml_parser.hpp"
#include "rcppsw/control/polar_force_xml_parser.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @class kinematics2D_xml_parser
 * @ingroup control
 *
 * @brief Parses XML parameters for \ref kinematics2D into
 * \ref kinematics2D_params. Assumes it is handed an XML parent in which the
 * child tag \ref kXMLRoot is found.
 */
class kinematics2D_xml_parser : public rcppsw::params::xml_param_parser {
 public:
  static constexpr char kXMLRoot[] = "kinematics2D";

  explicit kinematics2D_xml_parser(uint level)
      : xml_param_parser(level),
        m_params(),
        m_avoidance(level + 1),
        m_arrival(level + 1),
        m_wander(level + 1),
        m_polar(level + 1) {}

  void parse(const ticpp::Element& node) override;
  void show(std::ostream& stream) const override;
  bool validate(void) const override;

  std::string xml_root(void) const override { return kXMLRoot; }
  const kinematics2D_params* parse_results(void) const override { return &m_params; }

 private:
  // clang-format off
  struct kinematics2D_params m_params;
  avoidance_force_xml_parser m_avoidance;
  arrival_force_xml_parser   m_arrival;
  wander_force_xml_parser    m_wander;
  polar_force_xml_parser     m_polar;
  // clang-format on
};

NS_END(control, rcppsw);

#endif /* INCLUDE_RCPPSW_CONTROL_KINEMATICS2D_XML_PARSER_HPP_ */
