/**
 * @file grid2D_ptr.hpp
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

#ifndef INCLUDE_RCPPSW_DS_GRID2D_PTR_HPP_
#define INCLUDE_RCPPSW_DS_GRID2D_PTR_HPP_

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
 * @class grid2D_ptr
 *
 * @brief A 2D logical grid that is overlayed over a continuous environment. It
 * discretizes the continuous arena into a grid of a specified resolution.
 *
 * Whatever the template type is must have a zero parameter constructor
 * available.
 */
template<typename T, typename ...Args>
class grid2D_ptr: public base_grid2D<T> {
 public:
  grid2D_ptr(double resolution, size_t x_max, size_t y_max, Args&&... args) :
      base_grid2D<T>(resolution, x_max, y_max),
      m_cells(boost::extents[base_grid2D<T>::xsize()][base_grid2D<T>::ysize()]) {
    for (auto i = m_cells.origin();
         i < m_cells.origin() + m_cells.num_elements(); ++i) {
      *i = new T(std::forward<Args>(args)...);
    } /* for(i..) */
  }

  ~grid2D_ptr(void) {
    for (auto i = m_cells.origin();
         i < m_cells.origin() + m_cells.num_elements(); ++i) {
      delete *i;
    } /* for(i..) */
  }

  /**
   * @brief Create a subgrid (really an array view) from a grid. The grid is
   * clamped to the maximum boundaries of the parent grid, so rather than
   * getting a 2 x 2 subgrid centered at 0 with the out-of-bounds elements
   * zeroed, you will get a 1 x 2 subgrid.
   *
   * @param x X coord of center of subgrid.
   * @param y Y coord of center of subgrid.
   * @param radius Radius of subgrid.
   *
   * @return The subcircle.
   */
  grid_view<T*> subcircle(size_t x, size_t y, size_t radius) {
    index_range::index lower_x = static_cast<index_range::index>(
        std::max(0UL, x - radius));
    index_range::index lower_y = static_cast<index_range::index>(
        std::max(0UL, y - radius));
    index_range::index upper_x = static_cast<index_range::index>(
        std::min(x + radius + 1, base_grid2D<T>::xsize() - 1));
    index_range::index upper_y = static_cast<index_range::index>(
        std::min(y  + radius + 1, base_grid2D<T>::ysize() - 1));
    if (lower_x > upper_x) {
      lower_x = upper_x - 1;
    }
    if (lower_y > upper_y) {
      lower_y = upper_y - 1;
    }
    typename grid_type<T*>::index_gen indices;
    return grid_view<T*>(m_cells[indices[index_range(lower_x, upper_x, 1)]
                                 [index_range(lower_y, upper_y, 1)]]);
  }
  T& access(size_t i, size_t j) override {
    return *m_cells[static_cast<index_range::index>(i)][static_cast<index_range::index>(j)];
  }
  const T& access(size_t i, size_t j) const override {
    return *m_cells[static_cast<index_range::index>(i)][static_cast<index_range::index>(j)];
  }

 private:
  grid_type<T*> m_cells;
};

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_GRID2D_PTR_HPP_ */
