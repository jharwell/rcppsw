/**
 * @file xml_param_parser.hpp
 * @ingroup common
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

#ifndef INCLUDE_RCPPSW_COMMON_XML_PARAM_PARSER_HPP_
#define INCLUDE_RCPPSW_COMMON_XML_PARAM_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iosfwd>
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace ticpp { class Element; }

NS_START(rcppsw, common);
struct base_params;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class xml_param_parser
 *
 * @brief Interface specifying functionality for parsing XML into a
 * \ref base_params derived parameter structure.
 */
class xml_param_parser {
 public:
  xml_param_parser(void) = default;
  virtual ~xml_param_parser(void) = default;

  /**
   * @brief Parse the provided XML node into an internal representation (should
   * be a class/struct derived from \ref base_params).
   */
  virtual void parse(const ticpp::Element& node) = 0;

  /**
   * @brief Dump the parsed (or possibly unparsed, but that's kind of useless)
   * parameters to the specified stream.
   */
  virtual void show(__unused std::ostream& stream) {}

  /**
   * @brief Validate the range, value, etc. of all parsed parameters. As such,
   * don't call this unless the parameters have already been parsed.
   *
   * @return \c TRUE if all parameters are valid, \c FALSE otherwise.
   */
  virtual bool validate(void) { return true; }

  /**
   * @brief Get the results of parameter parse.
   */
  virtual const struct base_params* get_results(void) = 0;
};

NS_END(common, rcppsw);

#endif /* INCLUDE_RCPPSW_COMMON_XML_PARAM_PARSER_HPP_ */
