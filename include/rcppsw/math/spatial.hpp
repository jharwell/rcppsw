/**
 * \file spatial.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_MATH_SPATIAL_HPP_
#define INCLUDE_RCPPSW_MATH_SPATIAL_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/math/vector3.hpp"
#include "rcppsw/math/vector2.hpp"
#include "rcppsw/types/spatial_dist.hpp"

#include "rcppsw/rcppsw.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);

/*******************************************************************************
 * Macros
 ******************************************************************************/
#define RCPPSW_MATH_SPAN_FUNC_FLT(component)                            \
  template<typename TCoord,                                             \
           RCPPSW_SFINAE_DECLDEF(std::is_floating_point<typename TCoord::value_type>::value)> \
static inline rmath::ranged component##span(const TCoord& anchor, \
                                            const double& dim) {        \
    return { anchor.component(), (anchor.component() + dim) }; \
  }

#define RCPPSW_MATH_SPAN_FUNC_DISC(component) \
  template <typename TCoord,                                            \
            RCPPSW_SFINAE_DECLDEF(!std::is_floating_point<typename TCoord::value_type>::value)>\
static inline rmath::rangez component##span(const TCoord& anchor, size_t dim) { \
  /* rely on truncation of the 0.5 remainder (if it exists) to 0 */     \
  return { anchor.component(), anchor.component() + dim - 1 };          \
}

/*******************************************************************************
 * Free Functions
 ******************************************************************************/
/**
 * \brief Calculate the span in {X,Y,Z} in real coordinates of an entity given
 * the position of its 3D center and dimension in {X,Y<Z}.
 *
 * \return The span in {X,Y,Z} of the entity.
 */
RCPPSW_MATH_SPAN_FUNC_FLT(x);
RCPPSW_MATH_SPAN_FUNC_FLT(y);
RCPPSW_MATH_SPAN_FUNC_FLT(z);

/**
 * \brief Calculate the span in {X,Y,Z} in discrete coordinates of an entity
 * given its discrete anchor (2D or 3D) and {X,Y,Z} dimension.
 *
 * This function can only be called for entities which have a defined discrete
 * center.
 *
 * \return The span in {X,Y,Z} of the entity (closed interval).
 */
RCPPSW_MATH_SPAN_FUNC_DISC(x);
RCPPSW_MATH_SPAN_FUNC_DISC(y);
RCPPSW_MATH_SPAN_FUNC_DISC(z);

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_SPATIAL_HPP_ */
