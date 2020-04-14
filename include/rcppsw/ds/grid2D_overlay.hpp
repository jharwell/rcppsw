/**
 * \file grid2D_overlay.hpp
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

#ifndef INCLUDE_RCPPSW_DS_GRID2D_OVERLAY_HPP_
#define INCLUDE_RCPPSW_DS_GRID2D_OVERLAY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/ds/base_grid2D_overlay.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class grid2D_overlay
 * \ingroup ds
 *
 * \brief A 2D logical grid overlayed over a continuous environment using a
 * \a contiguous array of the template parameter type.
 *
 * \tparam T The type of the grid element (probably a cell of some kind). Must
 * have must have a zero parameter constructor available or it won't compile
 * (this is a limitation of the boost underneath). Furthermore, T must also have
 * a copy constructor available, as move semantics are not supported with the
 * underlying library.
 */
template <typename T>
class grid2D_overlay final : public base_grid2D_overlay<T> {
 public:
  using typename base_grid2D<T>::index_range;
  using typename base_grid2D<T>::grid_view;
  using typename base_grid2D<T>::const_grid_view;
  using typename base_grid2D<T>::grid_type;

  using base_grid2D_overlay<T>::xdsize;
  using base_grid2D_overlay<T>::ydsize;
  using base_grid2D_overlay<T>::access;

  /**
   * \param resolution The discretization unit for the grid.
   * \param dims The real size in X,Y which will be discretized into
   *             X/resolution discrete elements along the X dimension and
   *             Y/resolution discrete elements along the X dimension.
   */
  grid2D_overlay(const math::vector2d& dims,
                 const types::discretize_ratio& resolution)
      : base_grid2D_overlay<T>(dims, resolution),
        m_cells(boost::extents[static_cast<typename index_range::index>(
            xdsize())][typename index_range::index(ydsize())]) {}

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
    auto x_range = base_grid2D_overlay<T>::circle_xrange_at_point(c.x(), radius);
    auto y_range = base_grid2D_overlay<T>::circle_yrange_at_point(c.y(), radius);
    typename grid_type::index_gen indices;

    index_range x1(x_range.first, x_range.second, 1);
    index_range y1(y_range.first, y_range.second, 1);
    return grid_view(m_cells[indices[x1][y1]]);
  }
  const_grid_view subcircle(const math::vector2z& c, size_t radius) const {
    auto x_range = base_grid2D_overlay<T>::circle_xrange_at_point(c.x(), radius);
    auto y_range = base_grid2D_overlay<T>::circle_yrange_at_point(c.y(), radius);
    typename grid_type::index_gen indices;

    index_range x1(x_range.first, x_range.second, 1);
    index_range y1(y_range.first, y_range.second, 1);
    return const_grid_view(m_cells[indices[x1][y1]]);
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
    return grid_view(m_cells[indices[x][y]]);
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
    return const_grid_view(m_cells[indices[x][y]]);
  }

    /**
   * \brief Get a reference to a the cell within the grid at coordinates (i, j)
   *
   * \return Reference to the cell, of type T.
   */
  T& access(size_t i, size_t j) override {
    return m_cells[static_cast<typename index_range::index>(i)]
                  [static_cast<typename index_range::index>(j)];
  }

 private:
  /* clang-format off */
  grid_type m_cells;
  /* clang-format on */
};

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_GRID2D_OVERLAY_HPP_ */
