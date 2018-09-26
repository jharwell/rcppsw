/**
 * @file base_grid2D.hpp
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

#ifndef INCLUDE_RCPPSW_DS_BASE_GRID2D_HPP_
#define INCLUDE_RCPPSW_DS_BASE_GRID2D_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/multi_array.hpp>
#include "rcppsw/common/common.hpp"
#include "rcppsw/math/dcoord.hpp"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NS_START(rcppsw, ds);

template <typename T>
using grid_type = typename boost::multi_array<T, 2>;
template <typename T>
using grid_view = typename grid_type<T>::template array_view<2>::type;
template <typename T>
using const_grid_view = typename grid_type<T>::template const_array_view<2>::type;
template <typename T>
using view_range = typename grid_type<T>::index_range;
using index_range = boost::multi_array_types::index_range;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class base_grid2D
 * @ingroup ds
 *
 * @brief Base class containing functionality common to all types of 2D grids.
 */
template <typename T>
class base_grid2D {
 public:
  using value_type = T;

  base_grid2D(void) = default;
  virtual ~base_grid2D(void) = default;

  /**
   * @brief Return a reference to the element at position (i, j) in the grid.
   *
   * This is provided in the base class so that the pointer/object variants of
   * the grid (\ref grid2D, \ref grid2D_ptr) can reduce code duplication.
   */
  virtual T& access(uint i, uint j) = 0;
  virtual T& access(const math::dcoord2& c) = 0;

  const T& access(const math::dcoord2& c) const {
    return const_cast<base_grid2D*>(this)->access(c);
  }
  const T& access(uint i, uint j) const {
    return const_cast<base_grid2D*>(this)->access(i, j);
  }
};

NS_END(ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_BASE_GRID2D_HPP_ */
