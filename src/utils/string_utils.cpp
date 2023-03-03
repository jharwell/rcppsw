/**
 * \file string_utils.cpp
 *
 * \copyright 2023 John Harwell, All rights reserved.
 *
 * SPDX-License Identifier: MIT
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/utils/string_utils.hpp"


/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::utils {

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void tokenize(std::string const &str,
              const char* delim,
              std::vector<std::string>& out) {
  char *token = strtok(const_cast<char*>(str.c_str()), delim);
  while (token != nullptr) {
    out.push_back(std::string(token));
    token = strtok(nullptr, delim);
  }
} /* tokenize() */

} /* namespace rcppsw::utils */
