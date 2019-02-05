/**
 * @file waveform_xml_parser.hpp
 *
 * @copyright 2018 John Harwell/Anthony Chen, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_CONTROL_WAVEFORM_XML_PARSER_HPP_
#define INCLUDE_RCPPSW_CONTROL_WAVEFORM_XML_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "rcppsw/control/waveform_params.hpp"
#include "rcppsw/params/xml_param_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, control);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class waveform_xml_parser
 * @ingroup control
 *
 * @brief Parses XML parameters related to temporal waveform generation into
 * \ref waveform_params.
 *
 * Any parameters not present under the \ref kXMLRoot will be given a value of
 * -1.0.
 */
class waveform_xml_parser : public rcppsw::params::xml_param_parser {
 public:
  explicit waveform_xml_parser(uint level)
      : xml_param_parser(level),
        m_params() {}

  /**
   * @brief The XML tag that all parameters should appear under.
   */

  static constexpr char kXMLRoot[] = "waveform";
  void parse(const ticpp::Element& node) override;

  std::string xml_root(void) const override { return kXMLRoot; }
  std::shared_ptr<waveform_params> parse_results(void) const {
    return m_params;
  }

 private:
  std::shared_ptr<rcppsw::params::base_params> parse_results_impl(void) const override {
    return m_params;
  }

  /* clang-format off */
  std::shared_ptr<waveform_params> m_params{nullptr};
  /* clang-format on */
};

NS_END(control, rcppsw);

#endif /* INCLUDE_RCPPSW_CONTROL_WAVEFORM_XML_PARSER_HPP_ */
