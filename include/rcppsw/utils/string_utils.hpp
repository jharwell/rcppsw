/**
 * @file string_utils.hpp
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

#ifndef INCLUDE_RCPPSW_UTILS_STRING_UTILS_HPP_
#define INCLUDE_RCPPSW_UTILS_STRING_UTILS_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <sstream>
#include <string>
#include <vector>

#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, utils);

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
/**
 * @brief Parse values from a delimited string stream into a set of tokens.
 *
 * @param is The input stream.
 * @param n_fields The # of fields that should exist in the stream.
 * @param buf The buffer to put the tokens into.
 * @param delim The delimiter separating the tokens (\\n by default).
 *
 * @return \c TRUE if n_fields tokens were parsed from the stream, and \c FALSE
 * otherwise.
 */
template <typename T>
bool parse_values(std::istream& is, uint n_fields, T* buf, char delim = '\n') {
  std::vector<std::string> s(n_fields);
  uint i = 0;

  /*
   * Get actual # fields present in stream
   */
  while (i < n_fields && std::getline(is, s[i], delim)) {
    i++;
  } /* while() */

  if (i == n_fields) {
    is.clear(); /* the istream was read completely */

    /* parse fields */
    for (i = 0; i < n_fields; i++) {
      std::istringstream iss(s[i]);
      iss >> buf[i];
    }
    return true;
  }
  return false;
}

NS_END(utils, rcppsw);

#endif /* INCLUDE_RCPPSW_UTILS_STRING_UTILS_HPP_ */
