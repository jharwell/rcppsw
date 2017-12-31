/**
 * @file xml_param_repository.hpp
 *
 * Handles parsing of all XML parameters at runtime.
 *
 * @copyright 2017 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_COMMON_XML_PARAM_REPOSITORY_HPP_
#define INCLUDE_RCPPSW_COMMON_XML_PARAM_REPOSITORY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <map>
#include <string>
#include "rcppsw/common/common.hpp"
#include "rcppsw/common/xml_param_parser.hpp"
#include "rcppsw/patterns/factory/sharing_factory.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, common);
namespace factory = rcppsw::patterns::factory;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class xml_param_repository
 *
 * @brief A repository for multiple \ref xml_param_parser and their parsed
 * results.
 *
 * Utilizes factory pattern for parser creation. Does not create any parsers on
 * its own--derived classes have to do that.
 */
class xml_param_repository {
 public:
  xml_param_repository(void) : m_parsers(), m_factory() {}

  /**
   * @brief Call the \ref xml_param_parser::parse_all() function on all parsers
   * in the repository, passing all parsers the same XML node.
   */
  void parse_all(ticpp::Element& node);

  bool validate_all(void);

  /**
   * @brief Get the parsed parameters associated with the named parser.
   */
  const struct base_params* get_params(const std::string& name) {
    return m_parsers[name]->get_results();
  }

  /**
   * @brief Dump all parsed (or unparsed, but that would be useless) parameters
   * to the specified stream.
   */
  void show_all(std::ostream& stream);

  template <typename T>
  void register_parser(const std::string& name) {
    m_factory.register_type<T>(name);
    m_parsers[name] = m_factory.create(name).get();
  }

 private:
  std::map<std::string, xml_param_parser*> m_parsers;
  factory::sharing_factory<xml_param_parser> m_factory;
};

NS_END(common, rcppsw);

#endif /* INCLUDE_RCPPSW_COMMON_XML_PARAM_REPOSITORY_HPP_ */
