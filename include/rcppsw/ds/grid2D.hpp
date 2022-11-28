/**
 * \file grid2D.hpp
 *
 * \copyright 2018 John Harwell, All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

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

