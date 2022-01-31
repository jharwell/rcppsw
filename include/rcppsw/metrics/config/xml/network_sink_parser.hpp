/**
 * \file network_sink_parser.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_METRICS_CONFIG_XML_NETWORK_SINK_PARSER_HPP_
#define INCLUDE_RCPPSW_METRICS_CONFIG_XML_NETWORK_SINK_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <memory>
#include <string>

#include "rcppsw/metrics/config/xml/base_sink_parser.hpp"

#include "rcppsw/metrics/config/network_sink_config.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics, config, xml);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class network_sink_parser
 * \ingroup metrics config xml
 *
 * \brief Parses XML parameters related to the \ref rmetrics::network_sink  into
 * \ref network_sink_config.
 */
class network_sink_parser : public rer::client<network_sink_parser>,
                            public rmetrics::config::xml::base_sink_parser {
 public:
  using config_type = network_sink_config;

  network_sink_parser(void)
      : ER_CLIENT_INIT("rcppsw.metrics.config.xml.network_sink_parser") {}

  ~network_sink_parser(void) override = default;

  /**
   * \brief The root tag that all configuration relating to the .file metrics
   * sink should in lie under in the XML tree.
   */
  static inline const std::string kXMLRoot = "network";

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

NS_END(xml, config, metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_CONFIG_XML_NETWORK_SINK_PARSER_HPP_ */
