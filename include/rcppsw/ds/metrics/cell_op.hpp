/**
 * \file cell_op.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::ds::metrics {

/*******************************************************************************
 * Aliases
 ******************************************************************************/

/**
 * \brief Specify that the contents of the 2D or 3D cells should be averaged by
 * dividing by the total number of occurences (i.e. a density map).
 */
using cell_avg = std::true_type;

/**
 * \brief Specify that the contents of the 2D or 3D cells should be accumulated
 * without averaging.
 */
using cell_accum = std::false_type;

} /* namespace rcppsw::ds::metrics */

