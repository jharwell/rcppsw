/**
 * @file arrival_force_xml_parser.hpp
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

#ifndef INCLUDE_RCPPSW_ROBOTICS_STEERING2D_ARRIVAL_FORCE_XML_PARSER_HPP_
#define INCLUDE_RCPPSW_ROBOTICS_STEERING2D_ARRIVAL_FORCE_XML_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "rcppsw/common/common.hpp"
#include "rcppsw/params/xml_param_parser.hpp"
#include "rcppsw/robotics/steering2D/arrival_force_params.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, robotics, steering2D);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @class arrival_force_xml_parser
 * @ingroup robotics steering2D
 *
 * @brief Parses XML parameters for \ref arrival_force into
 * \ref arrival_force_params. Assumes it is handed an XML parent in which the
 * child tag \ref kXMLRoot is found.
 *
 * Parameter tags under the XML root are expected to exactly match the names of
 * the fields in the \ref arrival_force_params struct.
 */
class arrival_force_xml_parser : public rcppsw::params::xml_param_parser {
 public:
  static constexpr char kXMLRoot[] = "arrival_force";

  explicit arrival_force_xml_parser(const std::shared_ptr<er::server>& server,
                                    uint level)
      : xml_param_parser(server, level),
        m_params() {}

  void parse(const ticpp::Element& node) override;
  void show(std::ostream& stream) const override;
  bool validate(void) const override;

  std::string xml_root(void) const override { return kXMLRoot; }
  bool parsed(void) const override { return m_parsed; }

  std::shared_ptr<arrival_force_params> parse_results(void) const {
    return m_params;
  }

 private:
  std::shared_ptr<rcppsw::params::base_params> parse_results_impl(void) const override {
    return m_params;
  }

 private:
  // clang-format off
  bool                                  m_parsed{false};
  std::shared_ptr<arrival_force_params> m_params{nullptr};
  // clang-format on
};

NS_END(steering2D, robotics, rcppsw);

#endif /* INCLUDE_RCPPSW_ROBOTICS_STEERING2D_ARRIVAL_FORCE_XML_PARSER_HPP_ */
