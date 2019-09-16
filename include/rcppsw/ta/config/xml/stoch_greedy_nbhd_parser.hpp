/**
 * @file stoch_greedy_nbhd_parser.hpp
 *
 * @copyright 2019 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_TA_CONFIG_XML_STOCH_GREEDY_NBHD_PARSER_HPP_
#define INCLUDE_RCPPSW_TA_CONFIG_XML_STOCH_GREEDY_NBHD_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <memory>

#include "rcppsw/math/config/xml/sigmoid_parser.hpp"
#include "rcppsw/config/xml/xml_config_parser.hpp"
#include "rcppsw/ta/config/xml/src_sigmoid_sel_parser.hpp"
#include "rcppsw/ta/config/stoch_greedy_nbhd_config.hpp"
#include "rcppsw/ta/config/xml/task_partition_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta, config, xml);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class stoch_greedy_nbhd_parser
 * @ingroup rcppsw ta config xml
 *
 * @brief Parses XML configuration used for task allocation into \ref
 * stoch_greedy_nbhd_config.
 */
class stoch_greedy_nbhd_parser final : public rcppsw::config::xml::xml_config_parser {
 public:
  using config_type = stoch_greedy_nbhd_config;

  /**
   * @brief The root tag that all task allocation XML configuration should lie
   * under in the XML tree.
   */
  static constexpr char kXMLRoot[] = "stoch_greedy_nbhd";

  void parse(const ticpp::Element& node) override RCSW_COLD;
  bool validate(void) const override RCSW_ATTR(pure, cold);

  RCSW_COLD std::string xml_root(void) const override { return kXMLRoot; }

 private:
  RCSW_COLD rcppsw::config::base_config* config_get_impl(void) const override {
    return m_config.get();
  }

  /* clang-format off */
  std::unique_ptr<config_type> m_config{nullptr};
  src_sigmoid_sel_parser       m_subtask_sel{};
  task_partition_parser        m_partitioning{};
  src_sigmoid_sel_parser       m_tab_sel{};
  /* clang-format on */
};

NS_END(xml, config, ta, rcppsw);

#endif /* INCLUDE_RCPPSW_TA_CONFIG_XML_STOCH_GREEDY_NBHD_PARSER_HPP_ */
