/**
 * \file string_utils.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <sstream>
#include <string>
#include <vector>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, utils);

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
/**
 * \brief Parse values from a delimited string stream into a set of tokens.
 *
 * \param is The input stream.
 * \param n_fields The # of fields that should exist in the stream.
 * \param buf The buffer to put the tokens into.
 * \param delim The delimiter separating the tokens (\\n by default).
 *
 * \return \c TRUE if n_fields tokens were parsed from the stream, and \c FALSE
 * otherwise.
 */
template <typename T>
bool parse_values(std::istream& is, size_t n_fields, T* buf, char delim = '\n') {
  std::vector<std::string> s(n_fields);
  size_t i = 0;

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

