/**
 * \file grid3D.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_DS_GRID3D_HPP_
#define INCLUDE_RCPPSW_DS_GRID3D_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/ds/base_grid3D.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class grid3D
 * \ingroup ds
 *
 * \brief A 3D grid of SOMETHING. Mainly a convenience wrapper around
 * boost::multi_array.
 */
template <typename T>
class grid3D : public base_grid3D<T> {
 public:
  using typename base_grid3D<T>::index_range;
  using typename base_grid3D<T>::const_grid_view;
  using typename base_grid3D<T>::grid_view;
  using typename base_grid3D<T>::grid_type;

  using base_grid3D<T>::access;

  explicit grid3D(const math::vector3z& dims)
      : grid3D(dims.x(), dims.y(), dims.z()) {}

  grid3D(size_t x_max, size_t y_max, size_t z_max)
      : m_cells(boost::extents[x_max][y_max][z_max]) {}

  T& access(size_t i, size_t j, size_t k) override {
    return m_cells[i][j][k];
  }

  size_t xsize(void) const { return m_cells.shape()[0]; }
  size_t ysize(void) const { return m_cells.shape()[1]; }
  size_t zsize(void) const { return m_cells.shape()[2]; }

  /**
   * \brief Get a view of a single layer within the grid.
   *
   * \param z 0-based index of layer within the grid.
   *
   * \return The layer.
   */
  grid_view layer(size_t z) {
    return subgrid(math::vector3z(0, ysize(), z),
                   math::vector3z(0, ysize(), z+1));
  }

  const_grid_view layer(size_t z) const {
    return const_cast<grid3D<T>*>(this)->layer(z);
  }

  /**
   * \brief Create a subgrid from a grid. The specified coordinates are
   * inclusive.
   *
   * \return The subgrid.
   */
  grid_view subgrid(const math::vector3z& ll, const math::vector3z& ur) {
    typename grid_type::index_gen indices;

    index_range x(static_cast<typename index_range::index>(ll.x()),
                  static_cast<typename index_range::index>(ur.x()),
                  1);
    index_range y(static_cast<typename index_range::index>(ll.y()),
                  static_cast<typename index_range::index>(ur.y()),
                  1);
    index_range z(static_cast<typename index_range::index>(ll.z()),
                  static_cast<typename index_range::index>(ur.z()),
                  1);
    return grid_view(m_cells[indices[x][y][z]]);
  }

  const_grid_view subgrid(const math::vector3z& ll,
                          const math::vector3z& ur) const {
    return const_cast<grid3D<T>*>(this)->subgrid(ll, ur);
  }


 private:
  /* clang-format off */
  grid_type m_cells;
  /* clang-format on */
};

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_GRID3D_HPP_ */
