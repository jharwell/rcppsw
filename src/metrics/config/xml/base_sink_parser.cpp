/**
 * \file base_sink_parser.cpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/metrics/config/xml/base_sink_parser.hpp"

#include <list>
#include <algorithm>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace rcppsw::metrics::config::xml {

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void base_sink_parser::output_mode_parse(const ticpp::Element& element,
                                         output_mode_config* config) {
  XML_PARSE_ATTR(element, config, output_interval);
  ticpp::Iterator<ticpp::Attribute> it;
  for (it = element.FirstAttribute(); it != it.end(); ++it) {
    if (is_collector_name(*it)) {
      std::string name;
      std::string value;
      it->GetName(&name);
      it->GetValue(&value);
      config->enabled.insert({ name, value });
    }
  } /* for(it..) */
} /* output_mode_parse() */

bool base_sink_parser::is_collector_name(const ticpp::Attribute& attr) const {
  std::list<std::string> non_names = { "output_interval" };
  std::string name;
  attr.GetName(&name);
  return non_names.end() == std::find(non_names.begin(), non_names.end(), name);
} /* is_collector_name() */

} /* namespace rcppsw::metrics::xml, config */
