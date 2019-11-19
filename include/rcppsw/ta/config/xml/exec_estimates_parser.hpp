/**
 * @file exec_estimates_parser.hpp
 *
 * @copyright 2018 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_TA_CONFIG_XML_EXEC_ESTIMATES_PARSER_HPP_
#define INCLUDE_RCPPSW_TA_CONFIG_XML_EXEC_ESTIMATES_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <string>
#include <utility>
#include <memory>


#include "rcppsw/math/config/xml/ema_parser.hpp"
#include "rcppsw/config/xml/xml_config_parser.hpp"
#include "rcppsw/ta/config/exec_estimates_config.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta, config, xml);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class exec_estimates_parser
 * @ingroup ta config xml
 *
 * @brief Parses XML configuration used for estimation of task execution
 * times at the start of simulation.
 */
class exec_estimates_parser final : public rcppsw::config::xml::xml_config_parser,
                                    public er::client<exec_estimates_parser> {
 public:
  using config_type = exec_estimates_config;

  explicit exec_estimates_parser(
      std::list<std::string> task_names = std::list<std::string>()) noexcept
      : ER_CLIENT_INIT("rcppsw.ta.exec_estimates_parser"),
        m_task_names(std::move(task_names)) {}

  /**
   * @brief The root tag that all cache parameters should lie under in the
   * XML tree.
   */
  static constexpr char kXMLRoot[] = "task_exec_estimates";

  void parse(const ticpp::Element& node) override RCSW_COLD;
  bool validate(void) const override RCSW_ATTR(pure, cold);

  RCSW_COLD std::string xml_root(void) const override { return kXMLRoot; }

  RCSW_COLD void task_add(const std::string& task) {
    m_task_names.push_back(task);
  }

 private:
  RCSW_COLD rcppsw::config::base_config* config_get_impl(void) const override {
    return m_config.get();
  }

  /* clang-format off */
  std::unique_ptr<config_type>  m_config{nullptr};
  math::config::xml::ema_parser m_ema{};
  std::list<std::string>        m_task_names;
  /* clang-format on */
};

NS_END(xml, config, ta, rcppsw);

#endif /* INCLUDE_RCPPSW_TA_CONFIG_XML_EXEC_ESTIMATES_PARSER_HPP_ */
