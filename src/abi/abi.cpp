/**
 * \file abi.hpp
 *
 * \copyright 2022 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/abi/abi.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::abi {

/*******************************************************************************
 * Free Functions
 ******************************************************************************/
char* demangle(const char* name) {
  return ::abi::__cxa_demangle(name, nullptr, nullptr, nullptr);
}

std::type_info* current_exception_type(void) {
  return ::abi::__cxa_current_exception_type();
}

} /* namespace rcppsw::abi */
