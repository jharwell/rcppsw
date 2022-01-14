/**
 * \file csv_sink_parser.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_CONFIG_XML_CSV_SINK_PARSER_HPP_
#define INCLUDE_RCPPSW_METRICS_CONFIG_XML_CSV_SINK_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <memory>
#include <string>

#include "rcppsw/config/xml/xml_config_parser.hpp"

#include "rcppsw/metrics/config/csv_sink_config.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics, config, xml);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class csv_sink_parser
 * \ingroup metrics config xml
 *
 * \brief Parses XML parameters related to the \ref rmetrics::csv_sink  into
 * \ref csv_sink_config.
 */
class csv_sink_parser : public rer::client<csv_sink_parser>,
                        public rconfig::xml::xml_config_parser {
 public:
  using config_type = csv_sink_config;

  csv_sink_parser(void)
      : ER_CLIENT_INIT("rcppsw.metrics.config.xml.csv_sink_parser") {}

  ~csv_sink_parser(void) override = default;

  /**
   * \brief The root tag that all configuration relating to the .csv metrics
   * sink should in lie under in the XML tree.
   */
  static inline const std::string kXMLRoot = "csv";

  void parse(const ticpp::Element& node) override RCPPSW_COLD;

  RCPPSW_COLD std::string xml_root(void) const override { return kXMLRoot; }

 private:
  RCPPSW_COLD const rconfig::base_config* config_get_impl(void) const override {
    return m_config.get();
  }

  /**
   * \brief Determine if a particular attribute under the a node is the name of
   * a metric collector or some other type of parameter.
   */
  bool is_collector_name(const ticpp::Attribute& attr) const RCPPSW_COLD;

  void output_mode_parse(const ticpp::Element& element,
                         rmetrics::config::csv_sink_output_mode_config* config);

  /* clang-format off */
  std::unique_ptr<config_type> m_config{nullptr};
  /* clang-format on */
};

NS_END(xml, config, metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_CONFIG_XML_CSV_SINK_PARSER_HPP_ */
