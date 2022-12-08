/**
 * \file abi.hpp
 *
 * \copyright 2022 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cxxabi.h>

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::abi {

/*******************************************************************************
 * Free Functions
 ******************************************************************************/
/**
 * \brief Return the demangled string using the compiler ABI.
 */
char* demangle(const char* name);

/**
 * \brief Return type info for the the current exception using the compiler
 * ABI.
 */
std::type_info* current_exception_type(void);

} /* namespace rcppsw::abi */
