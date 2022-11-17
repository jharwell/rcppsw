/**
 * \file sigmoid_parser.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <memory>

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/math/config/sigmoid_config.hpp"
#include "rcppsw/config/xml/xml_config_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math, config, xml);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class sigmoid_parser
 * \ingroup math config xml
 *
 * \brief Parses XML configuration for sigmoids into \ref sigmoid_config.
 */
class sigmoid_parser : public rer::client<sigmoid_parser>,
                       public rconfig::xml::xml_config_parser {
 public:
  using config_type = sigmoid_config;

  sigmoid_parser(void)
      : ER_CLIENT_INIT("rcppsw.math.config.xml.sigmoid_parser") {}

  /**
   * \brief The root tag that all task sigmoid configuration values should lie
   * under in the XML tree.
   */
  static inline const std::string kXMLRoot = "sigmoid";

  void parse(const ticpp::Element& node) override RCPPSW_COLD;
  bool validate(void) const override RCPPSW_ATTR(pure, cold);
  RCPPSW_COLD std::string xml_root(void) const override { return kXMLRoot; }

 private:
  RCPPSW_COLD rcppsw::config::base_config* config_get_impl(void) const override {
    return m_config.get();
  }

  /* clang-format off */
  std::unique_ptr<sigmoid_config> m_config{nullptr};
  /* clang-format on */
};

NS_END(xml, config, math, rcppsw);

