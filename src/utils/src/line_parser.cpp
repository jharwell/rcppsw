/**
 * @file line_parser.cpp
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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/utils/line_parser.hpp"
#include <sstream>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, utils);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
std::vector<std::string> line_parser::parse(const std::string& line) {
  std::stringstream ss(line);
  std::vector<std::string> res;
  while (ss.good()) {
    std::string sub;
    std::getline(ss, sub, m_delim);
    res.push_back(sub);
  } /* while() */
  return res;
} /* parse() */

NS_END(utils, rcppsw);
