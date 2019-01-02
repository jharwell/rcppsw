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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_EXEC_ESTIMATES_PARSER_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_EXEC_ESTIMATES_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <list>

#include "rcppsw/params/xml_param_parser.hpp"
#include "rcppsw/task_allocation/exec_estimates_params.hpp"
#include "rcppsw/math/ema_xml_parser.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class exec_estimates_parser
 * @ingroup params depth0
 *
 * @brief Parses XML parameters used for estimation of task execution
 * times at the start of simulation.
 */
class exec_estimates_parser: public params::xml_param_parser,
                             public er::client<exec_estimates_parser> {
 public:
  explicit exec_estimates_parser(uint level,
                                 const std::list<std::string>& task_names = std::list<std::string>())
      : xml_param_parser(level),
        ER_CLIENT_INIT("rcppsw.ta.exec_estimates_parser"),
        m_ema(level + 1),
        m_task_names(task_names) {}

  /**
   * @brief The root tag that all cache parameters should lie under in the
   * XML tree.
   */
  static constexpr char kXMLRoot[] = "task_exec_estimates";

  void parse(const ticpp::Element& node) override;
  void show(std::ostream& stream) const override;

  std::string xml_root(void) const override { return kXMLRoot; }
  std::shared_ptr<exec_estimates_params> parse_results(void) const {
    return m_params;
  }

  bool parsed(void) const override { return m_parsed; }
  void task_add(const std::string& task) { m_task_names.push_back(task); }

 protected:
  void parsed(bool parsed) { m_parsed = parsed; }

 private:
  std::shared_ptr<rcppsw::params::base_params> parse_results_impl(void) const override {
    return m_params;
  }

  /* clang-format off */
  bool                                   m_parsed{false};
  std::shared_ptr<exec_estimates_params> m_params{nullptr};
  math::ema_xml_parser                   m_ema;
  std::list<std::string>                 m_task_names;
  /* clang-format on */
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_EXEC_ESTIMATES_PARSER_HPP_ */
