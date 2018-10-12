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
#include <string>
#include <vector>
#include <sstream>
#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, utils);

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
template<typename T>
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
