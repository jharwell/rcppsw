/**
 * \file file_parser.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

#include "rcppsw/rcppsw.hpp"
#include "rcppsw/utils/line_parser.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, utils);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class file_parser
 * \ingroup utils
 *
 * \brief File parsing class using template design pattern. Parses each line of
 * a file into a vector of whitespace delimited tokens, and returns a vector of
 * vectors (1 vector of parsed tokens per line).
 *
 * \tparam T The type of tokens the file contains.
 */
template <typename T>
class file_parser {
 public:
  explicit file_parser(const std::string& fname) : m_fname(fname) {}

  /**
   * \brief Parse a file into a vector of sets of tokens.
   *
   * \return A vector of the parse results.
   */
  std::vector<T>* parse_file(char delim) {
    std::vector<T>* tokens_set = new std::vector<T>;
    std::string line;
    std::ifstream infile(m_fname);
    line_parser parser(delim);
    while (std::getline(infile, line)) {
      tokens_set->push_back(parser.parse(line));
    } /* while() */

    return tokens_set;
  }

 private:
  /* clang-format off */
  const std::string& m_fname;
  /* clang-format on */
};

NS_END(utils, rcppsw);

