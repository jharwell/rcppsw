/**
 * \file utils.hpp
 *
 * \copyright 2022 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
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
namespace rcppsw::utils {

/*******************************************************************************
 * Free Functions
 ******************************************************************************/
static inline bool ready_to_flush(const rtypes::timestep& output_interval,
                                  const rtypes::timestep& t) {
  return (t > 0UL) && ((t % output_interval) == 0UL);
}

} /* namespace rcppsw::utils */
