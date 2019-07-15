/**
 * @file convergence_parser.hpp
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

#ifndef INCLUDE_RCPPSW_SWARM_CONVERGENCE_CONFIG_XML_CONVERGENCE_PARSER_HPP_
#define INCLUDE_RCPPSW_SWARM_CONVERGENCE_CONFIG_XML_CONVERGENCE_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <memory>

#include "rcppsw/swarm/convergence/config/convergence_config.hpp"
#include "rcppsw/common/common.hpp"
#include "rcppsw/config/xml/xml_config_parser.hpp"
#include "rcppsw/swarm/convergence/config/xml/positional_entropy_parser.hpp"
#include "rcppsw/swarm/convergence/config/xml/task_dist_entropy_parser.hpp"
#include "rcppsw/swarm/convergence/config/xml/interactivity_parser.hpp"
#include "rcppsw/swarm/convergence/config/xml/angular_order_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, swarm, convergence, config, xml);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class convergence_parser
 * @ingroup rcppsw swarm convergence config
 *
 * @brief Parses XML configuration related to calculating swarm convergence into
 * \ref convergence_config.
 */
class convergence_parser final : public rcppsw::config::xml::xml_config_parser {
 public:
  using config_type = convergence_config;

  ~convergence_parser(void) override = default;

  /**
   * @brief The root tag that all XML configuration relating to convergence
   * parameters should lie under in the XML tree.
   */
  static constexpr char kXMLRoot[] = "convergence";

  bool validate(void) const override RCSW_ATTR(const, cold);
  void parse(const ticpp::Element& node) override RCSW_COLD;

  RCSW_COLD std::string xml_root(void) const override { return kXMLRoot; }

 private:
  RCSW_COLD const rcppsw::config::base_config* config_get_impl(void) const override {
    return m_config.get();
  }

  /* clang-format off */
  std::unique_ptr<config_type> m_config{nullptr};
  positional_entropy_parser    m_pos_entropy{};
  task_dist_entropy_parser     m_task_entropy{};
  interactivity_parser         m_interactivity{};
  angular_order_parser         m_ang_order{};
  /* clang-format on */
};

NS_END(xml, config, convergence, swarm, rcppsw);

#endif /* INCLUDE_RCPPSW_SWARM_CONVERGENCE_CONFIG_XML_CONVERGENCE_PARSER_HPP_ */
