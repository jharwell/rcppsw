/**
 * \file base_sink_parser.hpp
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

#ifndef INCLUDE_RCPPSW_METRICS_CONFIG_XML_BASE_SINK_PARSER_HPP_
#define INCLUDE_RCPPSW_METRICS_CONFIG_XML_BASE_SINK_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/config/xml/xml_config_parser.hpp"
#include "rcppsw/metrics/config/output_mode_config.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, metrics, config, xml);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class base_sink_parser
 * \ingroup metrics config xml
 *
 * \brief Base class for parsing parameters for \ref rmetrics::base_sink derived
 * classes.
 */
class base_sink_parser : public rer::client<base_sink_parser>,
                        public rconfig::xml::xml_config_parser {
 public:
  base_sink_parser(void)
      : ER_CLIENT_INIT("rcppsw.metrics.config.xml.base_sink_parser") {}

  ~base_sink_parser(void) override = default;

 protected:
  /**
   * \brief Determine if a particular attribute under the a node is the name of
   * a metric collector or some other type of parameter.
   */
  bool is_collector_name(const ticpp::Attribute& attr) const RCPPSW_COLD;

  void output_mode_parse(const ticpp::Element& element,
                         rmetrics::config::output_mode_config* config);
};

NS_END(xml, config, metrics, rcppsw);

#endif /* INCLUDE_RCPPSW_METRICS_CONFIG_XML_BASE_SINK_PARSER_HPP_ */
