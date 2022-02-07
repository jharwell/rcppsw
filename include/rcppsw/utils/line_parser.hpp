/**
 * \file line_parser.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
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
#include <sstream>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, utils);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class line_parser
 * \ingroup utils
 *
 * \brief Parses a single line into a vector of tokens broken on the specified
 * delimiter.
 */
class line_parser {
 public:
  template<typename T>
  static std::vector<T> as(const std::vector<std::string>& v) {
    std::vector<T> res(v.size());
    for (size_t i = 0; i < v.size(); ++i) {
      std::istringstream iss(v[i]);
      iss >> res[i];
    } /* for(i..) */
    return res;
  }

  explicit line_parser(char delim) : mc_delim(delim) {}

  /**
   * \brief Parse a line into a vector of tokens, split on delimiter.
   */
  std::vector<std::string> operator()(const std::string& line) const {
    std::stringstream ss(line);
    return operator()(ss);
  }

  std::vector<std::string> operator()(std::stringstream& ss) const {
    std::vector<std::string> res;

    while (ss.good()) {
      std::string sub;
      std::getline(ss, sub, mc_delim);
      res.push_back(sub);
    } /* while() */
    return res;
  }

 private:
  /* clang-format off */
  const char mc_delim;
  /* clang-format on */
};

NS_END(utils, rcppsw);

#endif /* INCLUDE_RCPPSW_UTILS_LINE_PARSER_HPP_ */
