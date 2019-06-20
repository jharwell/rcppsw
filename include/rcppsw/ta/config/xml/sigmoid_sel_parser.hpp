/**
 * @file sigmoid_sel_parser.hpp
 *
 * @copyright 2018 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_TA_CONFIG_XML_SIGMOID_SEL_PARSER_HPP_
#define INCLUDE_RCPPSW_TA_CONFIG_XML_SIGMOID_SEL_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <memory>

#include "rcppsw/common/common.hpp"
#include "rcppsw/math/config/xml/sigmoid_parser.hpp"
#include "rcppsw/config/xml/xml_config_parser.hpp"
#include "rcppsw/ta/config/sigmoid_sel_config.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta, config, xml);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class sigmoid_sel_parser
 * @ingroup rcppsw ta config xml
 *
 * @brief Parses XML configuration relating to \ref sigmoid_sel_probability into
 * \ref sigmoid_sel_config.
 */
class sigmoid_sel_parser : public rcppsw::config::xml::xml_config_parser {
 public:
  using config_type = sigmoid_sel_config;

  /**
   * @brief The root tag that all XML configuration for \ref
   * sigmoid_sel_probability should lie under in the XML tree.
   */
  static constexpr char kXMLRoot[] = "sigmoid_sel";

  void parse(const ticpp::Element& node) override;
  bool validate(void) const override;
  std::string xml_root(void) const override { return kXMLRoot; }

 private:
  rcppsw::config::base_config* config_get_impl(void) const override {
    return m_config.get();
  }

  /* clang-format off */
  std::unique_ptr<config_type>      m_config{nullptr};
  math::config::xml::sigmoid_parser m_sigmoid{};
  /* clang-format on */
};

NS_END(xml, config, ta, rcppsw);

#endif /* INCLUDE_RCPPSW_TA_CONFIG_XML_SIGMOID_SEL_PARSER_HPP_ */
