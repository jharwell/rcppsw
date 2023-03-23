/**
 * \file init.hpp
 *
 * \copyright 2022 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::init {

/*******************************************************************************
 * Free Functions
 ******************************************************************************/
/**
 * \brief Initialize RCPPSW library.
 *
 * Current this just prints the version and build information.
 */
void init(void) RCPPSW_LIB_INIT;

} /* namespace rcppsw::init */
