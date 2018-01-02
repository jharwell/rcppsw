/**
 * @file line_parser.hpp
 * @ingroup utils
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

#ifndef INCLUDE_RCPPSW_UTILS_LINE_PARSER_HPP_
#define INCLUDE_RCPPSW_UTILS_LINE_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <vector>
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, utils);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class line_parser
 *
 * @brief Parses a single line into a vector of tokens broken on the specified
 * delimiter.
 */
class line_parser {
 public:
  explicit line_parser(char delim) : m_delim(delim) {}

  /**
   * @brief Parse a line into a vector of tokens, split on delimiter.
   */
  std::vector<std::string> parse(const std::string& line);

 private:
  char m_delim;
};

NS_END(utils, rcppsw);

#endif /* INCLUDE_RCPPSW_UTILS_LINE_PARSER_HPP_ */
