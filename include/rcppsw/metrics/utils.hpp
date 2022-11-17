/**
 * \file utils.hpp
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

#include "rcppsw/types/timestep.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, utils);

/*******************************************************************************
 * Free Functions
 ******************************************************************************/
static inline bool ready_to_flush(const rtypes::timestep& output_interval,
                                  const rtypes::timestep& t) {
  return (t > 0UL) && ((t % output_interval) == 0UL);
}

NS_END(utils, rcppsw);
