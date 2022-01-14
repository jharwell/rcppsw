/**
 * \file waveform_parser.hpp
 *
 * \copyright 2018 John Harwell/Anthony Chen, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_CONTROL_CONFIG_XML_WAVEFORM_PARSER_HPP_
#define INCLUDE_RCPPSW_CONTROL_CONFIG_XML_WAVEFORM_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <memory>

#include "rcppsw/control/config/waveform_config.hpp"
#include "rcppsw/config/xml/xml_config_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, control, config, xml);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class waveform_parser
 * \ingroup control config xml
 *
 * \brief Parses XML configuration related to temporal waveform generation into
 * \ref waveform_config.
 *
 * Any configuration values not present under the \ref kXMLRoot will be given a
 * value of -1.0.
 */
class waveform_parser final : public rer::client<waveform_parser>,
                              public rconfig::xml::xml_config_parser {
 public:
  using config_type = waveform_config;

  waveform_parser(void)
      : ER_CLIENT_INIT("rcppsw.controller.config.xml.waveform_parser") {}

  /**
   * \brief The XML tag that all configration values should appear under.
   */
  static inline const std::string kXMLRoot = "waveform";

  void parse(const ticpp::Element& node) override RCPPSW_COLD;

  RCPPSW_COLD std::string xml_root(void) const override { return kXMLRoot; }

 private:
  RCPPSW_COLD rcppsw::config::base_config* config_get_impl(void) const override {
    return m_config.get();
  }

  /* clang-format off */
  std::unique_ptr<config_type> m_config{nullptr};
  /* clang-format on */
};

NS_END(xml, config, control, rcppsw);

#endif /* INCLUDE_RCPPSW_CONTROL_CONFIG_XML_WAVEFORM_PARSER_HPP_ */
