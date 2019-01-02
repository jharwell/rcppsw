/**
 * @file src_sigmoid_sel_parser.hpp
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

#ifndef INCLUDE_RCPPSW_TASK_ALLOCATION_SRC_SIGMOID_SEL_XML_PARSER_HPP_
#define INCLUDE_RCPPSW_TASK_ALLOCATION_SRC_SIGMOID_SEL_XML_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "rcppsw/common/common.hpp"
#include "rcppsw/params/xml_param_parser.hpp"
#include "rcppsw/task_allocation/src_sigmoid_sel_params.hpp"
#include "rcppsw/task_allocation/sigmoid_sel_xml_parser.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, task_allocation);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class src_sigmoid_sel_xml_parser
 * @ingroup task_allocation
 *
 * @brief Parses XML parameters for relating to sourced sigmoid selection of
 * stuff.
 */
class src_sigmoid_sel_xml_parser: public rcppsw::params::xml_param_parser {
 public:
  explicit src_sigmoid_sel_xml_parser(uint level)
      : xml_param_parser(level),
        m_sigmoid(level + 1) {}

  /**
   * @brief The root tag that all task src_sigmoid_sel parameters should lie
   * under in the XML tree.
   */
  static constexpr char kXMLRoot[] = "src_sigmoid_sel";

  void show(std::ostream& stream) const override;
  void parse(const ticpp::Element& node) override;
  bool validate(void) const override;
  std::string xml_root(void) const override { return kXMLRoot; }

  std::shared_ptr<src_sigmoid_sel_params> parse_results(void) const {
    return m_params;
  }

 private:
  std::shared_ptr<rcppsw::params::base_params> parse_results_impl(void) const override {
    return m_params;
  }

  /* clang-format off */
  std::shared_ptr<src_sigmoid_sel_params> m_params{nullptr};
  sigmoid_sel_xml_parser                  m_sigmoid;
  /* clang-format on */
};

NS_END(task_allocation, rcppsw);

#endif /* INCLUDE_RCPPSW_TASK_ALLOCATION_SRC_SIGMOID_SEL_XML_PARSER_HPP_ */
