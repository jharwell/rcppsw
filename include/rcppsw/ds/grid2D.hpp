/**
 * \file grid2D.hpp
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

#ifndef INCLUDE_RCPPSW_DS_GRID2D_HPP_
#define INCLUDE_RCPPSW_DS_GRID2D_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/ds/base_grid2D.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class grid2D
 * \ingroup ds
 *
 * \brief A 2D grid of SOMETHING. Mainly a convenience wrapper around
 * boost::multi_array.
 */
template <typename T>
class grid2D : public base_grid2D<T> {
 public:
  using typename base_grid2D<T>::index_range;
  using typename base_grid2D<T>::coord_type;

  using base_grid2D<T>::access;

  explicit grid2D(const coord_type& dims) : grid2D(dims.x(), dims.y()) {}

  grid2D(size_t x_max, size_t y_max)
      : base_grid2D<T>(), m_cells(boost::extents[x_max][y_max]) {}

  T& access(size_t i, size_t j) override {
    return m_cells[static_cast<typename index_range::index>(i)]
                  [static_cast<typename index_range::index>(j)];
  }

  size_t xsize(void) const override { return m_cells.shape()[0]; }
  size_t ysize(void) const override { return m_cells.shape()[1]; }

 private:
  using typename base_grid2D<T>::grid_type;

  grid_type& grid(void) override { return m_cells; }
  const grid_type& grid(void) const override { return m_cells; }

  /* clang-format off */
  grid_type m_cells;
  /* clang-format on */
};

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_GRID2D_HPP_ */
