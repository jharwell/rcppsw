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
#include <limits>

#include "rcppsw/ds/base_grid2D.hpp"
#include "rcppsw/ds/base_grid_overlay.hpp"
#include "rcppsw/er/client.hpp"

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
 * \a contiguous array of the template parameter type (\see \ref base_grid_overlay).
 *
 * \tparam T The type of the grid element (probably a cell of some kind). Must
 * have must have a zero parameter constructor available or it won't compile
 * (this is a limitation of boost::multi_array). Furthermore, \p T must also
 * have a copy constructor available, as move semantics are not supported by
 * boost::multi_array.
 */
template <typename T>
class grid2D_overlay final : public base_grid2D<T>,
                             public base_grid_overlay<math::vector2d>,
                             public er::client<grid2D_overlay<T>> {
 public:
  using typename base_grid2D<T>::index_range;
  using typename base_grid2D<T>::grid_view;
  using typename base_grid2D<T>::const_grid_view;
  using typename base_grid2D<T>::grid_type;
  using typename base_grid2D<T>::coord_type;

  using base_grid2D<T>::access;

  using base_grid_overlay<math::vector2d>::resolution;
  using base_grid_overlay<math::vector2d>::originr;
  using base_grid_overlay<math::vector2d>::origind;

  /**
   * \param origin The anchor point of the overlay grid in continuous space.
   * \param dims The real size in X,Y which will be discretized into
   *             X/\p grid_res discrete elements along the X dimension and
   *             Y/\p grid_res discrete elements along the Y dimension.
   * \param grid_res The discretization unit for the grid.
   * \param field_res The discretization unit for the field the grid is
   *                  contained in (can be the same as the \p grid_res).
   */
  grid2D_overlay(const math::vector2d& origin,
                 const math::vector2d& dims,
                 const types::discretize_ratio& grid_res,
                 const types::discretize_ratio& field_res)
      : base_grid_overlay(origin, grid_res, field_res),
        ER_CLIENT_INIT("rcppsw.ds.grid2D_overlay"),
        mc_dim(dims),
        m_cells(boost::extents[static_cast<typename index_range::index>(xdsize())]
                              [typename index_range::index(ydsize())]) {
    RCPPSW_UNUSED double remx = std::remainder(mc_dim.x(), resolution().v());
    RCPPSW_UNUSED double remy = std::remainder(mc_dim.y(), resolution().v());

    /*
     * Some values of dimensions and grid resolution might not be able to be
     * represented exactly, so we can't just assert that the mod result =
     * 0.0. Instead, we verify that IF the mod result is > 0.0 that it is also
     * VERY close to the grid resolution.
     */
    ER_ASSERT(remx <= 1.0 / ONEE9,
              "X dimension (%f) not an even multiple of resolution (%f)",
              mc_dim.x(),
              resolution().v());
    ER_ASSERT(remy <= 1.0 / ONEE9,
              "Y dimension (%f) not an even multiple of resolution (%f)",
              mc_dim.y(),
              resolution().v());
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

  /**
   * \brief Get the discrete size of the X dimension of the grid (i.e. what is
   * the array index in X?)
   */
  size_t xdsize(void) const {
    return static_cast<size_t>(mc_dim.x() / resolution().v());
  }

  /**
   * \brief Get the discrete size of the Y dimension of the grid (i.e. what is
   * the array index in Y?)
   */
  size_t ydsize(void) const {
    return static_cast<size_t>(mc_dim.y() / resolution().v());
  }

  /**
   * \brief Get the size of the X dimension (non-discretized).
   */
  double xrsize(void) const { return mc_dim.x(); }

  /**
   * \brief Get the size of the Y dimension (non-discretized).
   */
  double yrsize(void) const { return mc_dim.y(); }

  /**
   * \brief Get the real dimensions of the grid; that is, continuous floating
   * point.
   */
  const math::vector2d& rdims2D(void) const { return mc_dim; }

  /**
   * \brief Get the discrete dimensions of the grid.
   */
  coord_type ddims2D(void) const {
    return math::dvec2zvec(mc_dim, resolution().v());
  }

 private:
  size_t xsize(void) const override { return xdsize(); }
  size_t ysize(void) const override { return ydsize(); }

  grid_type& grid(void) override { return m_cells; }
  const grid_type& grid(void) const override { return m_cells; }

  /* clang-format off */
  const math::vector2d          mc_dim;

  grid_type                     m_cells;
  /* clang-format on */
};

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_GRID2D_OVERLAY_HPP_ */
