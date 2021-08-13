/**
 * \file cell_op.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
 *
 * This file is part of RCPPSW.
 *
 * RCPPSW is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * RCPPSW is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * RCPPSW.  If not, see <http://www.gnu.org/licenses/
 */

#ifndef INCLUDE_RCPPSW_DS_METRICS_CELL_OP_HPP_
#define INCLUDE_RCPPSW_DS_METRICS_CELL_OP_HPP_

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

#endif /* INCLUDE_RCPPSW_DS_METRICS_CELL_OP_HPP_ */
