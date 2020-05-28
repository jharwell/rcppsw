/**
 * \file base_grid3D.hpp
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

#ifndef INCLUDE_RCPPSW_DS_BASE_GRID3D_HPP_
#define INCLUDE_RCPPSW_DS_BASE_GRID3D_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/multi_array.hpp>
#include <algorithm>

#include "rcppsw/math/vector3.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class base_grid3D
 * \ingroup ds
 *
 * \brief Base class containing functionality common to all types of 3D grids.
 */
template <typename T>
class base_grid3D {
 public:
  using value_type = T;

  using grid_type = typename boost::multi_array<T, 3>;
  using grid_view = typename grid_type::template array_view<3>::type;
  using const_grid_view = typename grid_type::template const_array_view<3>::type;
  using view_range = typename grid_type::index_range;
  using index_range = boost::multi_array_types::index_range;

  base_grid3D(void) = default;
  virtual ~base_grid3D(void) = default;

  /**
   * \brief Return a reference to the element at position (i, j) in the grid.
   *
   * This is provided in the base class so that the pointer/object variants of
   * the grid (\ref grid3D, etc.) can reduce code duplication.
   */
  virtual T& access(size_t i, size_t j, size_t k) = 0;

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
   * \brief Get the discrete size of the Z dimension of the grid (i.e. what is
   * the array index in Z?)
   */
  virtual size_t zdsize(void) const = 0;

  T& access(const math::vector3z& c)  { return access(c.x(), c.y(), c.z()); }

  const T& access(const math::vector3z& c) const {
    return const_cast<base_grid3D*>(this)->access(c);
  }
  const T& access(size_t i, size_t j, size_t k) const {
    return const_cast<base_grid3D*>(this)->access(i, j, k);
  }

  RCSW_PURE T& operator[](const math::vector3z& c) { return access(c); }
  RCSW_PURE const T& operator[](const math::vector3z& c) const {
    return access(c);
  }

  /**
   * \brief Get a view of a single layer within the grid.
   *
   * \param z 0-based index of layer within the grid.
   *
   * \return The layer.
   */
  grid_view layer(size_t z) {
    return subgrid(math::vector3z(0, ydsize(), z),
                   math::vector3z(0, ydsize(), z+1));
  }

  const_grid_view layer(size_t z) const {
    return const_cast<base_grid3D<T>*>(this)->layer(z);
  }

  /**
   * \brief Create a subgrid from a grid. The specified coordinates are
   * inclusive.
   *
   * \return The subgrid.
   */
  grid_view subgrid(const math::vector3z& ll, const math::vector3z& ur) {
    typename grid_type::index_gen indices;

    index_range x(ll.x(), ur.x(), 1);
    index_range y(ll.y(), ur.y(), 1);
    index_range z(ll.z(), ur.z(), 1);
    return grid_view(grid()[indices[x][y][z]]);
  }

  const_grid_view subgrid(const math::vector3z& ll,
                          const math::vector3z& ur) const {
    typename grid_type::index_gen indices;
    index_range x(ll.x(), ur.x(), 1);
    index_range y(ll.y(), ur.y(), 1);
    index_range z(ll.z(), ur.z(), 1);
    return const_grid_view(grid()[indices[x][y][z]]);
  }

  /**
   * \brief Get a 2D subcircle gridview from a 3D grid (i.e. always has height 1
   * in Z). The subcircle extent is cropped to the maximum boundaries of the
   * parent grid.
   *
   * This means that rather than getting a 2 x 2 subgrid centered at 0 with the
   * out-of-bounds elements zeroed if you request a subcircle on the boundary of
   * the overall grid, you will get a 1 x 2 subgrid (a lopsided circle).
   *
   * \param c The X,Y,Z coordinates of the center of the subcircle.
   * \param radius Radius of subcircle.
   *
   * \return The subcircle.
   */
  grid_view subcircle(const math::vector3z& c, size_t radius) {
    auto ll_x = std::max<int>(0,
                              static_cast<int>(c.x()) - static_cast<int>(radius));
    auto ll_y = std::max<int>(0,
                              static_cast<int>(c.y()) - static_cast<int>(radius));

    /*
     * boost uses half open interval for index ranges, and we want a closed
     * interval, so we +1.
     */
    auto ur_x = std::min(c.x() + radius + 1, xdsize());
    auto ur_y = std::min(c.y() + radius + 1, ydsize());

    math::vector3z ll(ll_x, ll_y, c.z());
    math::vector3z ur(ur_x, ur_y, c.z() + 1);

    return subgrid(ll, ur);
  }

  const_grid_view subcircle(const math::vector3z& c, size_t radius) const {
    typename grid_type::index_gen indices;

    auto ll_x = std::max<int>(0,
                              static_cast<int>(c.x()) - static_cast<int>(radius));
    auto ll_y = std::max<int>(0,
                              static_cast<int>(c.y()) - static_cast<int>(radius));

    /*
     * boost uses half open interval for index ranges, and we want a closed
     * interval, so we +1.
     */
    auto ur_x = std::min(c.x() + radius + 1, xdsize());
    auto ur_y = std::min(c.y() + radius + 1, ydsize());

    math::vector3z ll(ll_x, ll_y, c.z());
    math::vector3z ur(ur_x, ur_y, c.z() + 1);

    return subgrid(ll, ur);
  }

 protected:
  virtual const grid_type& grid(void) const = 0;
  virtual grid_type& grid(void) = 0;
};

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_BASE_GRID3D_HPP_ */
