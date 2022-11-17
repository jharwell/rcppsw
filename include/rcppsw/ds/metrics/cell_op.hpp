/**
 * \file cell_op.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
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
NS_START(rcppsw, ds, metrics);

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

NS_END(metrics, ds, rcppsw);

