/**
 * \file base_grid3D.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <boost/multi_array.hpp>

#include "rcppsw/common/common.hpp"
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
  using coord_type = rmath::vector3z;

  using grid_type = typename boost::multi_array<T, 3>;
  using grid_view = typename grid_type::template array_view<3>::type;
  using const_grid_view = typename grid_type::template const_array_view<3>::type;
  using index_range = typename grid_type::index_range;

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
   * \brief Get the size of the X dimension of the grid (i.e. what is
   * the array index in X?)
   */
  virtual size_t xsize(void) const = 0;

  /**
   * \brief Get the size of the Y dimension of the grid (i.e. what is the array
   * index in Y?)
   */
  virtual size_t ysize(void) const = 0;

  /**
   * \brief Get the size of the Z dimension of the grid (i.e. what is the array
   * index in Z?)
   */
  virtual size_t zsize(void) const = 0;

  T& access(const coord_type& c) { return access(c.x(), c.y(), c.z()); }

  const T& access(const coord_type& c) const {
    return const_cast<base_grid3D*>(this)->access(c);
  }
  const T& access(size_t i, size_t j, size_t k) const {
    return const_cast<base_grid3D*>(this)->access(i, j, k);
  }

  bool contains(size_t i, size_t j, size_t k) {
    return i < xsize() && j < ysize() && k < zsize();
  }

  bool contains(const coord_type& pt) {
    return contains(pt.x(), pt.y(), pt.z());
  }

  RCPPSW_PURE T& operator[](const coord_type& c) { return access(c); }
  RCPPSW_PURE const T& operator[](const coord_type& c) const {
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
    return subgrid(coord_type(0, ysize(), z),
                   coord_type(0, ysize(), z + 1));
  }

  const_grid_view layer(size_t z) const {
    return const_cast<base_grid3D<T>*>(this)->layer(z);
  }

  /**
   * \brief Create a subgrid from a grid. The specified coordinates are
   * inclusive.
   *
   * \param ll Lower left of the subgrid, inclusive.
   * \param ur Upper right of the subgrid, inclusive.
   *
   * \return The subgrid (closed interval).
   */
  grid_view subgrid(const coord_type& ll, const coord_type& ur) {
    index_range x(ll.x(), ur.x(), 1);
    index_range y(ll.y(), ur.y(), 1);
    index_range z(ll.z(), ur.z(), 1);
    return grid_view(grid()[boost::indices[x][y][z]]);
  }

  const_grid_view subgrid(const coord_type& ll,
                          const coord_type& ur) const {
    index_range x(ll.x(), ur.x(), 1);
    index_range y(ll.y(), ur.y(), 1);
    index_range z(ll.z(), ur.z(), 1);
    return const_grid_view(grid()[boost::indices[x][y][z]]);
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
  grid_view subcircle(const coord_type& c, size_t radius) {
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

    coord_type ll(ll_x, ll_y, c.z());
    coord_type ur(ur_x, ur_y, c.z() + 1);

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

    coord_type ll(ll_x, ll_y, c.z());
    coord_type ur(ur_x, ur_y, c.z() + 1);

    return subgrid(ll, ur);
  }

 protected:
  /**
   * \brief Return a reference to the underlying grid, defined by derived classes.
   */
  virtual const grid_type& grid(void) const = 0;
  virtual grid_type& grid(void) = 0;
};

NS_END(ds, rcppsw);

