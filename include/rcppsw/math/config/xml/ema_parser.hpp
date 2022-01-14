/**
 * \file ema_parser.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * This file is part of FORDYCA.
 *
 * FORDYCA is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * FORDYCA is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * FORDYCA.  If not, see <http://www.gnu.org/licenses/
 */

#ifndef INCLUDE_RCPPSW_MATH_CONFIG_XML_EMA_PARSER_HPP_
#define INCLUDE_RCPPSW_MATH_CONFIG_XML_EMA_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <memory>

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/math/config/ema_config.hpp"
#include "rcppsw/config/xml/xml_config_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math, config, xml);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class ema_parser
 * \ingroup math config xml
 *
 * \brief Parses XML configuration for relating to exponential moving averages
 * (EMAs).
 */
class ema_parser : public rer::client<ema_parser>,
                   public rconfig::xml::xml_config_parser {
 public:
  using config_type = ema_config;

  ema_parser(void) : ER_CLIENT_INIT("rcppsw.math.config.xml.ema_parser") {}

  /**
   * \brief The root tag that all ema configuration values should lie under in
   * the XML tree.
   */
  static inline const std::string kXMLRoot = "ema";

  bool validate(void) const override RCPPSW_ATTR(pure, cold);
  void parse(const ticpp::Element& node) override RCPPSW_COLD;

  RCPPSW_COLD std::string xml_root(void) const override { return kXMLRoot; }

 private:
  RCPPSW_COLD rcppsw::config::base_config* config_get_impl(void) const override {
    return m_config.get();
  }

  /* clang-format off */
  std::unique_ptr<ema_config> m_config{nullptr};
  /* clang-format on */
};

NS_END(xml, config, math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_CONFIG_XML_EMA_PARSER_HPP_ */
