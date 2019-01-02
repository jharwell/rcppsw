/**
 * @file task_allocation_xml_parser.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_TASK_ALLOCATION_XML_PARSER_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_TASK_ALLOCATION_XML_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "rcppsw/params/xml_param_parser.hpp"
#include "rcppsw/task_allocation/task_allocation_params.hpp"
#include "rcppsw/task_allocation/exec_estimates_parser.hpp"
#include "rcppsw/math/sigmoid_xml_parser.hpp"
#include "rcppsw/task_allocation/src_sigmoid_sel_xml_parser.hpp"
#include "rcppsw/task_allocation/task_partition_xml_parser.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class task_allocation_xml_parser
 * @ingroup params
 *
 * @brief Parses XML parameters used for task allocation at the start of
 * simulation.
 */
class task_allocation_xml_parser: public rcppsw::params::xml_param_parser {
 public:
  explicit task_allocation_xml_parser(uint level)
      : xml_param_parser(level),
        m_estimation(level + 1),
        m_abort(level + 1),
        m_subtask_sel(level + 1),
        m_partitioning(level + 1),
        m_tab_sel(level + 1) {}

  /**
   * @brief The root tag that all cache parameters should lie under in the
   * XML tree.
   */
  static constexpr char kXMLRoot[] = "task_allocation";

  void parse(const ticpp::Element& node) override;
  void show(std::ostream& stream) const override;

  std::string xml_root(void) const override { return kXMLRoot; }
  std::shared_ptr<task_allocation_params> parse_results(void) const {
    return m_params;
  }

  bool parsed(void) const override { return m_parsed; }
  void exec_est_task_add(const std::string& task) { m_estimation.task_add(task); }

 protected:
  void parsed(bool parsed) { m_parsed = parsed; }

 private:
  std::shared_ptr<rcppsw::params::base_params> parse_results_impl(void) const override {
    return m_params;
  }

  /* clang-format off */
  bool                                    m_parsed{false};
  std::shared_ptr<task_allocation_params> m_params{nullptr};
  exec_estimates_parser                   m_estimation;
  src_sigmoid_sel_xml_parser              m_abort;
  src_sigmoid_sel_xml_parser              m_subtask_sel;
  task_partition_xml_parser               m_partitioning;
  src_sigmoid_sel_xml_parser              m_tab_sel;
  /* clang-format on */
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_TASK_ALLOCATION_XML_PARSER_HPP_ */
