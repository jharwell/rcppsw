/**
 * \file grid2D_ptr_overlay.hpp
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

#ifndef INCLUDE_RCPPSW_DS_GRID2D_PTR_OVERLAY_HPP_
#define INCLUDE_RCPPSW_DS_GRID2D_PTR_OVERLAY_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <utility>

#include "rcppsw/ds/base_grid2D_overlay.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class grid2D_ptr_overlay
 * \ingroup ds
 *
 * \brief A 2D logical grid that is overlayed over a continuous environment. It
 * discretizes the continuous arena into a grid of a specified resolution, using
 * pointers to the managed elements, so a zero parameter constructor is not
 * needed.
 */
template <typename T, typename... Args>
class grid2D_ptr_overlay : public base_grid2D_overlay<T> {
 public:
  using typename base_grid2D<T*>::index_range;
  using grid_view = typename base_grid2D<T*>::grid_view;
  using const_grid_view = typename base_grid2D<T*>::const_grid_view;
  using typename base_grid2D<T*>::grid_type;

  using base_grid2D_overlay<T*>::xdsize;
  using base_grid2D_overlay<T*>::ydsize;

  grid2D_ptr_overlay(const math::vector2d& dims,
                     const types::discretize_ratio& resolution,
                     Args&&... args)
      : base_grid2D_overlay<T>(dims, resolution),
        m_cells(boost::extents[static_cast<typename index_range::index>(
            xdsize())][static_cast<typename index_range::index>(ydsize())]) {
    for (auto i = m_cells.origin();
         i < m_cells.origin() + m_cells.num_elements();
         ++i) {
      *i = new T(std::forward<Args>(args)...);
    } /* for(i..) */
  }

  ~grid2D_ptr_overlay(void) {
    for (auto i = m_cells.origin();
         i < m_cells.origin() + m_cells.num_elements();
         ++i) {
      delete *i;
    } /* for(i..) */
  }

  /**
   * \brief Create a subgrid (really an array view) from a grid. The grid is
   * clamped to the maximum boundaries of the parent grid, so rather than
   * getting a 2 x 2 subgrid centered at 0 with the out-of-bounds elements
   * zeroed, you will get a 1 x 2 subgrid.
   *
   * \param c Coord of center of subgrid.
   * \param radius Radius of subgrid.
   *
   * \return The subcircle.
   */
  grid_view subcircle(const math::vector2z& c, size_t radius) {
    auto x_range = base_grid2D_overlay<T>::circle_xrange_at_point(c.x(),
                                                                  radius);
    auto y_range = base_grid2D_overlay<T>::circle_yrange_at_point(c.y(),
                                                                  radius);
    typename grid_type::index_gen indices;

    index_range x1(x_range.first, x_range.second, 1);
    index_range y1(y_range.first, y_range.second, 1);
    return grid_view(m_cells[indices[x1][y1]]);
  }

  const_grid_view subcircle(const math::vector2z& c, size_t radius) const {
    return const_cast<grid2D_ptr_overlay<T>*>(this)->subcircle(c, radius);
  }

  /**
   * \brief Create a subgrid (really an array view) from a grid. The grid is
   * clamped to the maximum boundaries of the parent grid, so rather than
   * getting a 2 x 2 subgrid centered at 0 with the out-of-bounds elements
   * zeroed, you will get a 1 x 2 subgrid.
   *
   * \return The grid.
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
    return const_cast<grid2D_ptr_overlay<T>*>(this)->subgrid(ll, ur);
  }

    RCSW_PURE T& access(size_t i, size_t j) override {
    return *m_cells[static_cast<typename index_range::index>(i)]
                   [static_cast<typename index_range::index>(j)];
  }

 private:
  /* clang-format off */
  grid_type m_cells;
  /* clang-format on */
};

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_GRID2D_PTR_OVERLAY_HPP_ */
