/**
 * @file grid2D.hpp
 * @ingroup ds
 *
 * @copyright 2017 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_DS_GRID2D_HPP_
#define INCLUDE_RCPPSW_DS_GRID2D_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/ds/base_grid2D.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, ds);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class grid2D
 *
 * @brief A 2D logical grid overlayed over a continuous environment using a
 * \a contiguous array of the template parameter type.
 *
 * As such, the template type must have must have a zero parameter constructor
 * available or it won't compile.
 */
template <typename T>
class grid2D : public base_grid2D<T> {
 public:
  grid2D(double resolution, size_t x_max, size_t y_max)
      : base_grid2D<T>(resolution, x_max, y_max),
        m_cells(
            boost::extents[base_grid2D<T>::xsize()][base_grid2D<T>::ysize()]) {}

  /**
   * @brief Get a subcircle gridview from a grid. The subcircle extent is
   * cropped to the maximum boundaries of the parent grid.
   *
   * This means that rather than getting a 2 x 2 subgrid centered at 0 with the
   * out-of-bounds elements zeroed if you request a subcircle on the boundary of
   * the overall grid, you will get a 1 x 2 subgrid (a lopsided circle).
   *
   * @param x X coord of center of subgrid.
   * @param y Y coord of center of subgrid.
   * @param radius Radius of subgrid.
   *
   * @return The subcircle.
   */
  grid_view<T> subcircle(size_t x, size_t y, size_t radius) {
    auto x_range = base_grid2D<T>::circle_xrange_at_point(x, radius);
    auto y_range = base_grid2D<T>::circle_yrange_at_point(y, radius);
    typename grid_type<T>::index_gen indices;

    index_range x1(x_range.first, x_range.second, 1);
    index_range y1(y_range.first, y_range.second, 1);
    return grid_view<T>(m_cells[indices[x1][y1]]);
  }

  T& access(size_t i, size_t j) override {
    return m_cells[static_cast<index_range::index>(i)]
                  [static_cast<index_range::index>(j)];
  }

 private:
  grid_type<T> m_cells;
};

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_GRID2D_HPP_ */
