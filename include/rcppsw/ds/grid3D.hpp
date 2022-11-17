/**
 * \file grid3D.hpp
 *
 * \copyright 2020 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

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
  using typename base_grid3D<T>::coord_type;

  using base_grid3D<T>::access;

  explicit grid3D(const coord_type& dims)
      : grid3D(dims.x(), dims.y(), dims.z()) {}

  grid3D(size_t x_max, size_t y_max, size_t z_max)
      : m_cells(boost::extents[x_max][y_max][z_max]) {}

  T& access(size_t i, size_t j, size_t k) override { return m_cells[i][j][k]; }

  size_t xsize(void) const override { return m_cells.shape()[0]; }
  size_t ysize(void) const override { return m_cells.shape()[1]; }
  size_t zsize(void) const override { return m_cells.shape()[2]; }

 private:
  grid_type& grid(void) override { return m_cells; }
  const grid_type& grid(void) const override { return m_cells; }

  /* clang-format off */
  grid_type m_cells;
  /* clang-format on */
};

NS_END(ds, rcppsw);

