/**
 * \file init.cpp
 *
 * \copyright 2022 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/init/init.hpp"

#include <iostream>

#include "rcppsw/version/version.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::init {

/*******************************************************************************
 * Free Functions
 ******************************************************************************/
void init(void) {
  std::cout << "Loaded Reusable C++ Software (RCPPSW): ";
  std::cout << rversion::meta_info_to_str(&rversion::kVersion);
}

} /* namespace rcppsw::init */
