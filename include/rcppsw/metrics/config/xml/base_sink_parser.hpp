/**
 * \file base_sink_parser.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/config/xml/xml_config_parser.hpp"
#include "rcppsw/metrics/config/output_mode_config.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw::metrics::config::xml {

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

  void  output_mode_parse(const ticpp::Element& element,
                         rmetrics::config::output_mode_config* config);
};

} /* namespace rcppsw::metrics::xml::config */
