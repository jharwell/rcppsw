/**
 * \file waveform_parser.hpp
 *
 * \copyright 2018 John Harwell/Anthony Chen, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

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
namespace rcppsw::control::config::xml {

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

} /* namespace rcppsw::control::xml, config */

