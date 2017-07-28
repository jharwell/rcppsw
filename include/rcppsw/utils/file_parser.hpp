/**
 * @file file_parser.hpp
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

#ifndef INCLUDE_RCPPSW_UTILS_FILE_PARSER_HPP_
#define INCLUDE_RCPPSW_UTILS_FILE_PARSER_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief File parsing class using template design pattern. Parses each line of
 * a file into a vector of whitespace delimited tokens, and returns a vector of
 * vectors (1 per line).
 */
template <typename T> class file_parser {
 public:
  explicit file_parser(const std::string& fname): m_fname(fname) {}

  /**
   * @brief Parse a file into a vector of sets of tokens.
   *
   * @return A vector of the parse results.
   */
  std::vector<T>* parse_file(void) {
    std::vector<T>* tokens_set = new std::vector<T>;
    std::string line;
    std::ifstream infile(m_fname);

    while (std::getline(infile, line)) {
      tokens_set->push_back(parse_line(line));
    } /* while() */

    return tokens_set;
  } /* file_parser::parse_file() */

  /**
   * @brief Parse a line into a set of tokens, using a space delimiter.
   *
   * @param line The line to parse.
   *
   * @return The parsed token set.
   */
  T parse_line(const std::string& line) {
    T tokens;
    std::istringstream iss(line);

    // Iterate over the istream, using >> to grab floats
    // and push_back to store them in the vector
    std::copy(std::istream_iterator<float>(iss),
              std::istream_iterator<float>(),
              std::back_inserter(tokens));
    return tokens;
  } /* file_parser::parse_line() */

 private:
  const std::string& m_fname;
};

NS_END(rcppsw);

#endif /* INCLUDE_RCPPSW_UTILS_FILE_PARSER_HPP_ */
