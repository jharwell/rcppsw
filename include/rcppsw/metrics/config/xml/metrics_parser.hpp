/**
 * \file metrics_parser.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <memory>
#include <string>

#include "rcppsw/config/xml/xml_config_parser.hpp"
#include "rcppsw/metrics/config/xml/file_sink_parser.hpp"
#include "rcppsw/metrics/config/xml/network_sink_parser.hpp"

#include "rcppsw/metrics/config/metrics_config.hpp"
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw::metrics::config::xml {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class metrics_parser
 * \ingroup metrics config xml
 *
 * \brief Parses XML parameters related to metric collection into
 * \ref metrics_config.
 */
class metrics_parser : public rer::client<metrics_parser>,
                       public rconfig::xml::xml_config_parser {
 public:
  using config_type = metrics_config;

  metrics_parser(void)
      : ER_CLIENT_INIT("rcppsw.metrics.config.xml.metrics_parser") {}

  ~metrics_parser(void) override = default;

  /**
   * \brief The root tag that all loop functions relating to metrics parameters
   * should lie under in the XML tree.
   */
  static inline const std::string kXMLRoot = "metrics";

  void parse(const ticpp::Element& node) override RCPPSW_COLD;

  RCPPSW_COLD std::string xml_root(void) const override { return kXMLRoot; }

 private:
  RCPPSW_COLD const rconfig::base_config* config_get_impl(void) const override {
    return m_config.get();
  }

  /* clang-format off */
  std::unique_ptr<config_type> m_config{nullptr};
  rmcxml::file_sink_parser     m_csv_sinks{};
  rmcxml::network_sink_parser  m_network_sinks{};
  /* clang-format on */
};

} /* namespace rcppsw::metrics::xml, config */
