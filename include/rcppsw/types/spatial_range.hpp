/**
 * \file spatial_range.hpp
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

#ifndef INCLUDE_RCPPSW_TYPES_SPATIAL_RANGE_HPP_
#define INCLUDE_RCPPSW_TYPES_SPATIAL_RANGE_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/math/range.hpp"
#include "rcppsw/types/spatial_dist.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, types);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \typedef spatial_range
 * \ingroup types
 *
 * \brief A \ref rmath::range<T> of \ref rtypes::spatial_dist.
 */
using spatial_range = math::range<types::spatial_dist>;

NS_END(types, rcppsw);

#endif /* INCLUDE_RCPPSW_TYPES_SPATIAL_RANGE_HPP_ */
