/**
 * \file init.hpp
 *
 * \copyright 2022 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, init);

/*******************************************************************************
 * Free Functions
 ******************************************************************************/
/**
 * \brief Initialize RCPPSW library.
 *
 * Current this just prints the version.
 */
void init(void) RCPPSW_LIB_INIT;

NS_END(init, rcppsw);
