/**
 * \file base_grid_overlay.hpp
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

#ifndef INCLUDE_RCPPSW_DS_BASE_GRID_OVERLAY_HPP_
#define INCLUDE_RCPPSW_DS_BASE_GRID_OVERLAY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/er/client.hpp"
#include "rcppsw/math/vector2.hpp"
#include "rcppsw/math/vector3.hpp"
#include "rcppsw/types/discretize_ratio.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class base_grid_overlay
 * \ingroup ds
 *
 * \brief Base class for logical grids that are overlayed over a continuous
 * environment. It discretizes the continuous volume into a grid of a specified
 * resolution (e.g. it takes a continuous 10.0 x 5.0 x 5.0 space and discretizes
 * it into a 50 x 25 x 25 grid of cells with a resolution of 0.2).
 *
 * The origin of the continuous environment onto which the discretized grid is
 * overlayed are not necessarily the same, so an anchor/origin point for the
 * discretized grid is required.
 */
template <typename TOriginType>
class base_grid_overlay : public er::client<base_grid_overlay<TOriginType>> {
 public:
  static_assert(std::is_same<TOriginType, math::vector2d>::value ||
                    std::is_same<TOriginType, math::vector3d>::value,
                "Bad origin type: not 2D or 3D vector");

  using origin_rtype =
      typename std::conditional<std::is_same<TOriginType, math::vector2d>::value,
                                math::vector2d,
                                math::vector3d>::type;
  using origin_dtype =
      typename std::conditional<std::is_same<TOriginType, math::vector2z>::value,
                                math::vector2z,
                                math::vector3z>::type;
  base_grid_overlay(const origin_rtype& origin,
               const types::discretize_ratio& grid_resolution,
               const types::discretize_ratio& field_resolution)
      : ER_CLIENT_INIT("rcppsw.ds.base_grid_overlay"),
        mc_resolution(grid_resolution),
        mc_originr(origin),
        mc_origind(math::dvec2zvec(origin, field_resolution.v())) {}

  virtual ~base_grid_overlay(void) = default;

  /**
   * \brief Return the resolution of the grid.
   */
  const types::discretize_ratio& resolution(void) const { return mc_resolution; }

  /**
   * \brief Return the real origin of the grid in real coordinates.
   */
  const origin_rtype& originr(void) const { return mc_originr; }

  /**
   * \brief Return the discretized origin of the grid.
   */
  const origin_dtype& origind(void) const { return mc_origind; }

 private:
  /* clang-format off */
  const types::discretize_ratio mc_resolution;
  const origin_rtype            mc_originr;
  const origin_dtype            mc_origind;
  /* clang-format on */
};

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_BASE_GRID_OVERLAY_HPP_ */
