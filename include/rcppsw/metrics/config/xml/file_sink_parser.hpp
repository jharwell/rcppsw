/**
 * \file file_sink_parser.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <memory>
#include <string>

#include "rcppsw/metrics/config/xml/base_sink_parser.hpp"

#include "rcppsw/metrics/config/file_sink_config.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw::metrics::config::xml {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class file_sink_parser
 * \ingroup metrics config xml
 *
 * \brief Parses XML parameters related to the \ref rmetrics::file_sink  into
 * \ref file_sink_config.
 */
class file_sink_parser : public rer::client<file_sink_parser>,
                         public rmetrics::config::xml::base_sink_parser {
 public:
  using config_type = file_sink_config;

  file_sink_parser(void)
      : ER_CLIENT_INIT("rcppsw.metrics.config.xml.file_sink_parser") {}

  ~file_sink_parser(void) override = default;


  /**
   * \brief The root tag that all configuration relating to the .file metrics
   * sink should in lie under in the XML tree.
   */
  static inline const std::string kXMLRoot = "file";
 void parse(const ticpp::Element& node) override RCPPSW_COLD;

  RCPPSW_COLD std::string xml_root(void) const override { return kXMLRoot; }

 private:
  RCPPSW_COLD const rconfig::base_config* config_get_impl(void) const override {
    return m_config.get();
  }

  /* clang-format off */
  std::unique_ptr<config_type> m_config{nullptr};
  /* clang-format on */
};

} /* namespace rcppsw::metrics::xml, config */
