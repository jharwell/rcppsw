/**
 * @file differential_drive_xml_parser.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_KINEMATICS2D_DIFFERENTIAL_DRIVE_XML_PARSER_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_KINEMATICS2D_DIFFERENTIAL_DRIVE_XML_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "rcppsw/robotics/kinematics2D/differential_drive_params.hpp"
#include "rcppsw/common/common.hpp"
#include "rcppsw/params/xml_param_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, kinematics2D);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @class differential_drive_xml_parser
 * @ingroup robotics kinematics2D
 *
 * @brief Parses XML parameters relating to the \ref differential_drive into
 * \ref differential_drive_xml_params.
 */
class differential_drive_xml_parser : public rcppsw::params::xml_param_parser {
 public:
  /**
   * @brief The root tag that all differential_drive_xml parameters should lie
   * under in the XML tree.
   */
  static constexpr char kXMLRoot[] = "differential_drive";

  explicit differential_drive_xml_parser(uint level)
      : xml_param_parser(level) {}

  void parse(const ticpp::Element& node) override;
  void show(std::ostream& stream) const override;
  bool validate(void) const override;

  std::string xml_root(void) const override { return kXMLRoot; }

  std::shared_ptr<differential_drive_params> parse_results(void) const {
    return m_params;
  }

 private:
  std::shared_ptr<rcppsw::params::base_params> parse_results_impl(void) const override {
    return m_params;
  }

 private:
  std::shared_ptr<differential_drive_params> m_params{nullptr};
};

NS_END(kinematics2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_KINEMATICS2D_DIFFERENTIAL_DRIVE_XML_PARSER_HPP_ */
