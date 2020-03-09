/**
 * \file base_grid3D.hpp
 *
 * \copyright 2017 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_DS_BASE_GRID3D_HPP_
#define INCLUDE_RCPPSW_DS_BASE_GRID3D_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/multi_array.hpp>

#include "rcppsw/common/common.hpp"
#include "rcppsw/math/vector3.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class base_grid3D
 * \ingroup ds
 *
 * \brief Base class containing functionality common to all types of 3D grids.
 */
template <typename T>
class base_grid3D {
 public:
  using value_type = T;

  using grid_type = typename boost::multi_array<T, 3>;
  using grid_view = typename grid_type::template array_view<3>::type;
  using const_grid_view = typename grid_type::template const_array_view<3>::type;
  using view_range = typename grid_type::index_range;
  using index_range = boost::multi_array_types::index_range;

  base_grid3D(void) = default;
  virtual ~base_grid3D(void) = default;

  /**
   * \brief Return a reference to the element at position (i, j) in the grid.
   *
   * This is provided in the base class so that the pointer/object variants of
   * the grid (\ref grid3D, \ref overlay_grid3D) can reduce code duplication.
   */
  virtual T& access(size_t i, size_t j, size_t k) = 0;
  virtual T& access(const math::vector3u& c) = 0;

  const T& access(const math::vector3u& c) const {
    return const_cast<base_grid3D*>(this)->access(c);
  }
  const T& access(size_t i, size_t j, size_t k) const {
    return const_cast<base_grid3D*>(this)->access(i, j, k);
  }
};

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_BASE_GRID3D_HPP_ */
