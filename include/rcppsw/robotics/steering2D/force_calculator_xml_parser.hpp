/**
 * @file force_calculator_xml_parser.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_STEERING2D_FORCE_CALCULATOR_XML_PARSER_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_STEERING2D_FORCE_CALCULATOR_XML_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "rcppsw/common/common.hpp"
#include "rcppsw/robotics/steering2D/force_calculator_xml_parser.hpp"
#include "rcppsw/robotics/steering2D/force_calculator_params.hpp"
#include "rcppsw/robotics/steering2D/avoidance_force_xml_parser.hpp"
#include "rcppsw/robotics/steering2D/arrival_force_xml_parser.hpp"
#include "rcppsw/robotics/steering2D/wander_force_xml_parser.hpp"
#include "rcppsw/robotics/steering2D/polar_force_xml_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, robotics, steering2D);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @class force_calculator_xml_parser
 * @ingroup control
 *
 * @brief Parses XML parameters for \ref force_calculator into
 * \ref force_calculator_params. Assumes it is handed an XML parent in which the
 * child tag \ref kXMLRoot is found.
 */
class force_calculator_xml_parser : public rcppsw::params::xml_param_parser {
 public:
  static constexpr char kXMLRoot[] = "steering2D";

  explicit force_calculator_xml_parser(uint level)
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
  std::shared_ptr<force_calculator_params> parse_results(void) const {
    return m_params;
  }

 private:
  std::shared_ptr<rcppsw::params::base_params> parse_results_impl(void) const override {
    return m_params;
  }

  /* clang-format off */
  std::shared_ptr<force_calculator_params> m_params{nullptr};
  avoidance_force_xml_parser               m_avoidance;
  arrival_force_xml_parser                 m_arrival;
  wander_force_xml_parser                  m_wander;
  polar_force_xml_parser                   m_polar;
  /* clang-format on */
};

NS_END(steering2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_STEERING2D_FORCE_CALCULATOR_XML_PARSER_HPP_ */
