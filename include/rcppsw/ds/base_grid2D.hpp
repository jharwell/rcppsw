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
#include <algorithm>
#include <boost/multi_array.hpp>

#include "rcppsw/math/vector2.hpp"

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
  using coord_type = math::vector2z;

  using grid_type = typename boost::multi_array<T, 2>;
  using grid_view = typename grid_type::template array_view<2>::type;
  using const_grid_view = typename grid_type::template const_array_view<2>::type;
  using index_range = typename grid_type::index_range;

  base_grid2D(void) = default;
  virtual ~base_grid2D(void) = default;

  /**
   * \brief Get the size of the X dimension of the grid (i.e. what is the array
   * index in X?)
   */
  virtual size_t xsize(void) const = 0;

  /**
   * \brief Get the size of the Y dimension of the grid (i.e. what is the array
   * index in Y?)
   */
  virtual size_t ysize(void) const = 0;

  /**
   * \brief Return a reference to the element at position (i, j) in the grid.
   *
   * This is provided in the base class so that the pointer/object variants of
   * the grid (\ref grid2D, \ref grid2D_overlay) can reduce code duplication.
   */
  virtual T& access(size_t i, size_t j) = 0;

  T& access(const coord_type& c) { return access(c.x(), c.y()); }

  RCPPSW_PURE T& operator[](const coord_type& c) { return access(c); }
  RCPPSW_PURE const T& operator[](const coord_type& c) const {
    return access(c);
  }

  const T& access(const coord_type& c) const {
    return const_cast<base_grid2D*>(this)->access(c);
  }
  const T& access(size_t i, size_t j) const {
    return const_cast<base_grid2D*>(this)->access(i, j);
  }

  bool contains(size_t i, size_t j) {
    return i < xsize() && j < ysize();
  }

  bool contains(const coord_type& pt) {
    return contains(pt.x(), pt.y());
  }

  /**
   * \brief Get a subcircle gridview from a grid. The subcircle extent is
   * cropped to the maximum boundaries of the parent grid.
   *
   * This means that rather than getting a 2 x 2 subgrid centered at 0 with the
   * out-of-bounds elements zeroed if you request a subcircle on the boundary of
   * the overall grid, you will get a 1 x 2 subgrid (a lopsided circle).
   *
   * \param c Coordinates of center of subcircle.
   * \param radius Radius of subcircle.
   *
   * \return The subcircle (closed interval).
   */
  grid_view subcircle(const coord_type& c, size_t radius) {
    auto ll_x =
        std::max<int>(0, static_cast<int>(c.x()) - static_cast<int>(radius));
    auto ll_y =
        std::max<int>(0, static_cast<int>(c.y()) - static_cast<int>(radius));

    /*
     * boost uses half open interval for index ranges, and we want a closed
     * interval, so we +1.
     */
    auto ur_x = std::min(c.x() + radius + 1, xsize() - 1);
    auto ur_y = std::min(c.y() + radius + 1, ysize() - 1);

    coord_type ll(ll_x, ll_y);
    coord_type ur(ur_x, ur_y);

    return subgrid(ll, ur);
  }

  const_grid_view subcircle(const coord_type& c, size_t radius) const {
    auto ll_x =
        std::max<int>(0, static_cast<int>(c.x()) - static_cast<int>(radius));
    auto ll_y =
        std::max<int>(0, static_cast<int>(c.y()) - static_cast<int>(radius));

    /*
     * boost uses half open interval for index ranges, and we want a closed
     * interval, so we +1.
     */
    auto ur_x = std::min(c.x() + radius + 1, xsize());
    auto ur_y = std::min(c.y() + radius + 1, ysize());

    coord_type ll(ll_x, ll_y);
    coord_type ur(ur_x, ur_y);
    return subgrid(ll, ur);
  }

  /**
   * \brief Create a subgrid from a grid.
   *
   * \param ll Lower left of the subgrid, inclusive.
   * \param ur Upper right of the subgrid, inclusive.
   *
   * \return The subgrid (closed interval).
   */
  grid_view subgrid(const coord_type& ll, const coord_type& ur) {
    /*
     * boost uses half open interval for index ranges, and we want a closed
     * interval, so we +1.
     */
    index_range x(ll.x(), ur.x() + 1, 1);
    index_range y(ll.y(), ur.y() + 1, 1);
    return grid_view(grid()[boost::indices[x][y]]);
  }

  const_grid_view subgrid(const coord_type& ll,
                          const coord_type& ur) const {
    index_range x(ll.x(), ur.x(), 1);
    index_range y(ll.y(), ur.y(), 1);
    return const_grid_view(grid()[boost::indices[x][y]]);
  }

 protected:
  virtual const grid_type& grid(void) const = 0;
  virtual grid_type& grid(void) = 0;
};

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_BASE_GRID2D_HPP_ */
