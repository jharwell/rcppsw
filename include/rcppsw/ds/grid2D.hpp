/**
 * @file grid2D.hpp
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
 * @ingroup ds
 *
 * @brief A 2D grid of SOMETHING. Mainly a convenience wrapper around boost.
 */
template <typename T>
class grid2D : public base_grid2D<T> {
 public:
  grid2D(uint x_max, uint y_max)
      : base_grid2D<T>(),
        m_cells(boost::extents[x_max][y_max]) {}

  T& access(uint i, uint j) override {
    return m_cells[static_cast<index_range::index>(i)]
                  [static_cast<index_range::index>(j)];
  }
  uint xsize(void) const { return m_cells.shape()[0]; }
  uint ysize(void) const { return m_cells.shape()[1]; }

  __rcsw_pure T& access(const math::dcoord2& c) override {
    return m_cells[static_cast<index_range::index>(c.first)]
        [static_cast<index_range::index>(c.second)];
  }

  using base_grid2D<T>::access;
 private:
  grid_type<T> m_cells;
};

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_GRID2D_HPP_ */
