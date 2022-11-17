/**
 * \file init.cpp
 *
 * \copyright 2022 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/init/init.hpp"

#include <iostream>
#include "rcppsw/version.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, init);

/*******************************************************************************
 * Free Functions
 ******************************************************************************/
void init(void) {
  std::cout << "Loaded rcppsw.v" << kVERSION << std::endl;
}

NS_END(init, rcppsw);
