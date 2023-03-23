/**
 * \file line_parser.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

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
namespace rcppsw::utils {

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

} /* namespace rcppsw::utils */

