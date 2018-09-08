/**
 * @file executive_parser.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_EXECUTIVE_XML_PARSER_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_EXECUTIVE_XML_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "rcppsw/common/common.hpp"
#include "rcppsw/params/xml_param_parser.hpp"
#include "rcppsw/task_allocation/executive_params.hpp"
#include "rcppsw/task_allocation/task_abort_xml_parser.hpp"
#include "rcppsw/task_allocation/task_partition_xml_parser.hpp"
#include "rcppsw/task_allocation/subtask_selection_xml_parser.hpp"
#include "rcppsw/task_allocation/task_estimation_xml_parser.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class executive_xml_parser
 * @ingroup task_allocation
 *
 * @brief Parses XML parameters for relating to the task executive and the tasks
 * it runs.
 */
class executive_xml_parser: public rcppsw::params::xml_param_parser {
 public:
  executive_xml_parser(const std::string& er_parent, uint level)
      : xml_param_parser(er_parent, level),
        m_abort(er_parent, level + 1),
        m_partition(er_parent, level + 1),
        m_estimation(er_parent, level + 1),
        m_subtask(er_parent, level  + 1) {}

  /**
   * @brief The root tag that all task executive parameters should lie under in
   * the XML tree.
   */
  static constexpr char kXMLRoot[] = "task_executive";

  void show(std::ostream& stream) const override;
  bool validate(void) const override;
  void parse(const ticpp::Element& node) override;

  std::string xml_root(void) const override { return kXMLRoot; }
  bool parsed(void) const override { return m_parsed; }

  std::shared_ptr<executive_params> parse_results(void) const {
    return m_params;
  }

 private:
  std::shared_ptr<rcppsw::params::base_params> parse_results_impl(void) const override {
    return m_params;
  }

  // clang-format off
  bool                              m_parsed{false};
  std::shared_ptr<executive_params> m_params{nullptr};
  task_abort_xml_parser             m_abort;
  task_partition_xml_parser         m_partition;
  task_estimation_xml_parser        m_estimation;
  subtask_selection_xml_parser      m_subtask;
  // clang-format on
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_EXECUTIVE_XML_PARSER_HPP_ */
