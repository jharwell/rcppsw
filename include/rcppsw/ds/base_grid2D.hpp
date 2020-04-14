/**
 * \file base_grid2D.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_DS_BASE_GRID2D_HPP_
#define INCLUDE_RCPPSW_DS_BASE_GRID2D_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/multi_array.hpp>

#include "rcppsw/math/vector2.hpp"
#include "rcppsw/ds/utils.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class base_grid2D
 * \ingroup ds
 *
 * \brief Base class containing functionality common to all types of 2D grids.
 */
template <typename T>
class base_grid2D {
 public:
  using value_type = T;

  using grid_type = typename boost::multi_array<T, 2>;
  using grid_view = typename grid_type::template array_view<2>::type;
  using const_grid_view = typename grid_type::template const_array_view<2>::type;
  using view_range = typename grid_type::index_range;
  using index_range = boost::multi_array_types::index_range;

  base_grid2D(void) = default;
  virtual ~base_grid2D(void) = default;

  /**
   * \brief Get the discrete size of the X dimension of the grid (i.e. what is
   * the array index in X?)
   */
  virtual size_t xdsize(void) const = 0;

  /**
   * \brief Get the discrete size of the Y dimension of the grid (i.e. what is
   * the array index in Y?)
   */
  virtual size_t ydsize(void) const = 0;

  /**
   * \brief Return a reference to the element at position (i, j) in the grid.
   *
   * This is provided in the base class so that the pointer/object variants of
   * the grid (\ref grid2D, \ref overlay_grid2D) can reduce code duplication.
   */
  virtual T& access(size_t i, size_t j) = 0;

  T& access(const math::vector2z& c) { return access(c.x(), c.y()); }

  RCSW_PURE T& operator[](const math::vector2z& c) { return access(c); }
  RCSW_PURE const T& operator[](const math::vector2z& c) const {
    return access(c);
  }

  const T& access(const math::vector2z& c) const {
    return const_cast<base_grid2D*>(this)->access(c);
  }
  const T& access(size_t i, size_t j) const {
    return const_cast<base_grid2D*>(this)->access(i, j);
  }

  /**
   * \brief Get a subcircle gridview from a grid. The subcircle extent is
   * cropped to the maximum boundaries of the parent grid.
   *
   * This means that rather than getting a 2 x 2 subgrid centered at 0 with the
   * out-of-bounds elements zeroed if you request a subcircle on the boundary of
   * the overall grid, you will get a 1 x 2 subgrid (a lopsided circle).
   *
   * \param x X coord of center of subgrid.
   * \param y Y coord of center of subgrid.
   * \param radius Radius of subgrid.
   *
   * \return The subcircle.
   */
  grid_view subcircle(const math::vector2z& c, uint radius) {
    typename grid_type::index_gen indices;

    auto x_range = detail::circle_xrange_at_point(c.x(), radius, xdsize());
    auto y_range = detail::circle_yrange_at_point(c.y(), radius, ydsize());
    index_range x1(x_range.lb(), x_range.ub(), 1);
    index_range y1(y_range.lb(), y_range.ub(), 1);
    return grid_view(grid()[indices[x1][y1]]);
  }

  const_grid_view subcircle(const math::vector2z& c, size_t radius) const {
    typename grid_type::index_gen indices;
    auto x_range = detail::circle_xrange_at_point(c.x(), radius, xdsize());
    auto y_range = detail::circle_yrange_at_point(c.y(), radius, ydsize());

    index_range x1(x_range.lb(), x_range.ub(), 1);
    index_range y1(y_range.lb(), y_range.ub(), 1);
    return const_grid_view(grid()[indices[x1][y1]]);
  }

  /**
   * \brief Create a subgrid (really an array view) from a grid. The grid is
   * clamped to the maximum boundaries of the parent grid, so rather than
   * getting a 2 x 2 subgrid centered at 0 with the out-of-bounds elements
   * zeroed, you will get a 1 x 2 subgrid.
   *
   * The 4 parameters specify the 4 corners of the subgrid in terms of the
   * indices of the grid the subgrid is being drawn from.
   *
   * \return The subgrid.
   */
  grid_view subgrid(const math::vector2z& ll, const math::vector2z& ur) {
    typename grid_type::index_gen indices;

    index_range x(static_cast<typename index_range::index>(ll.x()),
                  static_cast<typename index_range::index>(ur.x()),
                  1);
    index_range y(static_cast<typename index_range::index>(ll.y()),
                  static_cast<typename index_range::index>(ur.y()),
                  1);
    return grid_view(grid()[indices[x][y]]);
  }

  const_grid_view subgrid(const math::vector2z& ll,
                          const math::vector2z& ur) const {
    typename grid_type::index_gen indices;

    index_range x(static_cast<typename index_range::index>(ll.x()),
                  static_cast<typename index_range::index>(ur.x()),
                  1);
    index_range y(static_cast<typename index_range::index>(ll.y()),
                  static_cast<typename index_range::index>(ur.y()),
                  1);
    return const_grid_view(grid()[indices[x][y]]);
  }

 protected:
  virtual const grid_type& grid(void) const = 0;
  virtual grid_type& grid(void) = 0;
};

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_BASE_GRID2D_HPP_ */
