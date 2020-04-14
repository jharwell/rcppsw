/**
 * \file base_grid2D_overlay.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_DS_BASE_GRID2D_OVERLAY_HPP_
#define INCLUDE_RCPPSW_DS_BASE_GRID2D_OVERLAY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <utility>

#include "rcppsw/ds/base_grid2D.hpp"
#include "rcppsw/types/discretize_ratio.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class base_grid2D_overlay
 * \ingroup ds
 *
 * \brief A 2D logical grid that is overlayed over a continuous environment. It
 * discretizes the continuous arena into a grid of a specified resolution
 * (e.g. it takes a continuous 10.0 x 5.0 space and discretizes it into a 50 x
 * 25 grid of cells with a resolution of 0.2).
 */
template <typename T>
class base_grid2D_overlay : public base_grid2D<T> {
 public:
  using typename base_grid2D<T>::index_range;

  /**
   * \brief Contains the upper/lower X/Y coordinates of the circle when applied
   * to the specified X/Y coordinate.
   */
  using circle_range_ret_type =
      std::pair<typename index_range::index, typename index_range::index>;

  base_grid2D_overlay(const math::vector2d& dim,
                      const types::discretize_ratio& resolution)
      : mc_resolution(resolution),
        mc_dim(dim) {}

  virtual ~base_grid2D_overlay(void) = default;

  /**
   * \brief Return the resolution of the grid.
   */
  types::discretize_ratio resolution(void) const { return mc_resolution; }

  /**
   * \brief Get the size of the X dimension of the discretized subgrid, at
   * whatever the resolution specified during object construction was.
   */
  size_t xdsize(void) const {
    return static_cast<size_t>(std::ceil(mc_dim.x() / mc_resolution.v()));
  }
  /**
   * \brief Get the size of the Y dimension of the discretized subgrid, at
   * whatever the resolution specified during object construction was.
   */
  size_t ydsize(void) const {
    return static_cast<size_t>(std::ceil(mc_dim.y() / mc_resolution.v()));
  }

  /**
   * \brief Get the size of the X dimension (non-discretized).
   */
  double xrsize(void) const { return mc_dim.x(); }

  /**
   * \brief Get the size of the Y dimension (non-discretized).
   */
  double yrsize(void) const { return mc_dim.y(); }

  /**
   * \brief Get the range in the X direction resulting from applying a circle
   * with the specified radius at the specified X coordinate, accounting for
   * edge conditions on the grid.
   *
   * \param x The X coordinate of the point.
   * \param radius The radius of the circle to apply.
   *
   * \return A pair containing the upper/lower X coordinates of the circle when
   * applied to the specified X coordinate.
   */
  circle_range_ret_type circle_xrange_at_point(size_t x, uint radius) const {
    typename index_range::index lower_x =
        static_cast<typename index_range::index>(
            std::max<int>(0, static_cast<int>(x) - static_cast<int>(radius)));
    typename index_range::index upper_x =
        static_cast<typename index_range::index>(
            std::min(x + radius + 1, xdsize() - 1));
    if (lower_x > upper_x) {
      lower_x = upper_x - 1;
    }
    return std::make_pair(lower_x, upper_x);
  }

  /**
   * \brief Get the range in the Y direction resulting from applying a circle
   * with the specified radius at the specified Y coordinate, accounting for
   * edge conditions on the grid.
   *
   * \param y The Y coordinate of the point.
   * \param radius The radius of the circle to apply.
   *
   * \return A pair containing the upper/lower Y coordinates of the circle when
   * applied to the specified Y coordinate.
   */
  circle_range_ret_type circle_yrange_at_point(size_t y, size_t radius) const {
    typename index_range::index lower_y =
        static_cast<typename index_range::index>(
            std::max<int>(static_cast<int>(0),
                          static_cast<int>(y) - static_cast<int>(radius)));
    typename index_range::index upper_y =
        static_cast<typename index_range::index>(
            std::min(y + radius + 1, ydsize() - 1));
    if (lower_y > upper_y) {
      lower_y = upper_y - 1;
    }
    return std::make_pair(lower_y, upper_y);
  }

 private:
  /* clang-format off */
  const types::discretize_ratio mc_resolution;
  const math::vector2d          mc_dim;
  /* clang-format on */
};

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_BASE_GRID2D_OVERLAY_HPP_ */
