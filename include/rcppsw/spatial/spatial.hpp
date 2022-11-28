/**
 * \file spatial.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/math/vector3.hpp"
#include "rcppsw/math/vector2.hpp"
#include "rcppsw/spatial/euclidean_dist.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::spatial {

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

} /* namespace rcppsw::spatial */
