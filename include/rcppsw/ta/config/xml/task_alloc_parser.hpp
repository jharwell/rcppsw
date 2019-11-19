/**
 * \file task_alloc_parser.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_TA_CONFIG_XML_TASK_ALLOC_PARSER_HPP_
#define INCLUDE_RCPPSW_TA_CONFIG_XML_TASK_ALLOC_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <memory>

#include "rcppsw/math/config/xml/sigmoid_parser.hpp"
#include "rcppsw/config/xml/xml_config_parser.hpp"
#include "rcppsw/ta/config/xml/exec_estimates_parser.hpp"
#include "rcppsw/ta/config/xml/src_sigmoid_sel_parser.hpp"
#include "rcppsw/ta/config/task_alloc_config.hpp"
#include "rcppsw/ta/config/xml/stoch_nbhd1_parser.hpp"
#include "rcppsw/ta/config/xml/epsilon_greedy_parser.hpp"
#include "rcppsw/ta/config/xml/ucb1_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta, config, xml);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class task_alloc_parser
 * \ingroup ta config xml
 *
 * \brief Parses XML configuration used for task allocation into \ref
 * task_alloc_config.
 */
class task_alloc_parser final : public rcppsw::config::xml::xml_config_parser {
 public:
  using config_type = task_alloc_config;

  /**
   * \brief The root tag that all task allocation XML configuration should lie
   * under in the XML tree.
   */
  static constexpr char kXMLRoot[] = "task_alloc";

  void parse(const ticpp::Element& node) override RCSW_COLD;
  bool validate(void) const override RCSW_ATTR(pure, cold);

  RCSW_COLD std::string xml_root(void) const override { return kXMLRoot; }

  RCSW_COLD void exec_est_task_add(const std::string& task) {
    m_estimation.task_add(task);
  }

 private:
  RCSW_COLD rcppsw::config::base_config* config_get_impl(void) const override {
    return m_config.get();
  }

  /* clang-format off */
  std::unique_ptr<config_type> m_config{nullptr};
  exec_estimates_parser        m_estimation{};
  src_sigmoid_sel_parser       m_abort{};
  stoch_nbhd1_parser           m_snbhd1{};
  epsilon_greedy_parser        m_epsilon{};
  ucb1_parser                  m_ucb1{};
  /* clang-format on */
};

NS_END(xml, config, ta, rcppsw);

#endif /* INCLUDE_RCPPSW_TA_CONFIG_XML_TASK_ALLOC_PARSER_HPP_ */
