/**
 * @file overlay_grid2D_ptr.hpp
 *
 * @copyright 2018 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_DS_OVERLAY_GRID2D_PTR_HPP_
#define INCLUDE_RCPPSW_DS_OVERLAY_GRID2D_PTR_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/ds/base_overlay_grid2D.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class overlay_grid2D_ptr
 * @ingroup rcppsw ds
 *
 * @brief A 2D logical grid that is overlayed over a continuous environment. It
 * discretizes the continuous arena into a grid of a specified resolution, using
 * pointers to the managed elements, so a zero parameter constructor is not
 * needed.
 */
template <typename T, typename... Args>
class overlay_grid2D_ptr : public base_overlay_grid2D<T> {
 public:
  using typename base_grid2D<T*>::index_range;
  using grid_view = typename base_grid2D<T*>::grid_view;
  using const_grid_view = typename base_grid2D<T*>::const_grid_view;
  using typename base_grid2D<T*>::grid_type;

  using base_overlay_grid2D<T*>::xdsize;
  using base_overlay_grid2D<T*>::ydsize;

  overlay_grid2D_ptr(double resolution,
                     size_t x_max,
                     size_t y_max,
                     Args&&... args)
      : base_overlay_grid2D<T>(resolution, x_max, y_max),
        m_cells(boost::extents[static_cast<typename index_range::index>(
            xdsize())][static_cast<typename index_range::index>(ydsize())]) {
    for (auto i = m_cells.origin();
         i < m_cells.origin() + m_cells.num_elements();
         ++i) {
      *i = new T(std::forward<Args>(args)...);
    } /* for(i..) */
  }

  ~overlay_grid2D_ptr(void) {
    for (auto i = m_cells.origin();
         i < m_cells.origin() + m_cells.num_elements();
         ++i) {
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
  grid_view subcircle(size_t x, size_t y, uint radius) {
    auto x_range = base_overlay_grid2D<T>::circle_xrange_at_point(x, radius);
    auto y_range = base_overlay_grid2D<T>::circle_yrange_at_point(y, radius);
    typename grid_type::index_gen indices;

    index_range x1(x_range.first, x_range.second, 1);
    index_range y1(y_range.first, y_range.second, 1);
    return grid_view(m_cells[indices[x1][y1]]);
  }

  grid_view subcircle(size_t x, size_t y, uint radius) const {
    return const_cast<overlay_grid2D_ptr<T>*>(this)->subcircle(x, y, radius);
  }

  /**
   * @brief Create a subgrid (really an array view) from a grid. The grid is
   * clamped to the maximum boundaries of the parent grid, so rather than
   * getting a 2 x 2 subgrid centered at 0 with the out-of-bounds elements
   * zeroed, you will get a 1 x 2 subgrid.
   *
   * @return The grid.
   */
  grid_view subgrid(size_t x_min, size_t y_min, size_t x_max, size_t y_max) {
    typename grid_type::index_gen indices;

    index_range x(x_min, x_max, 1);
    index_range y(y_min, y_max, 1);
    return grid_view(m_cells[indices[x][y]]);
  }

  grid_view subgrid(size_t x_min, size_t y_min, size_t x_max, size_t y_max) const {
    return const_cast<overlay_grid2D_ptr<T>*>(this)->subgrid(
        x_min, y_min, x_max, y_max);
  }

  __rcsw_pure T& access(size_t i, size_t j) override {
    return *m_cells[static_cast<typename index_range::index>(i)]
                   [static_cast<typename index_range::index>(j)];
  }
  __rcsw_pure T& access(const math::vector2u& c) override {
    return *m_cells[static_cast<typename index_range::index>(c.x())]
                   [static_cast<typename index_range::index>(c.y())];
  }

 private:
  /* clang-format off */
  grid_type m_cells;
  /* clang-format on */
};

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_OVERLAY_GRID2D_PTR_HPP_ */
