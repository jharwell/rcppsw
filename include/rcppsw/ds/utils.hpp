/**
 * \file utils.hpp
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

#ifndef INCLUDE_RCPPSW_DS_UTILS_HPP_
#define INCLUDE_RCPPSW_DS_UTILS_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/multi_array.hpp>

#include "rcppsw/math/range.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ds, detail);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
using index_range = boost::multi_array_types::index_range;

/**
 * \brief Contains the upper/lower X/Y coordinates of the circle when applied
 * to the specified (X,Y) coordinates.
 */
using circle_range_ret_type = math::range<index_range::index>;

/**
 * \brief Get the range in the X direction resulting from applying a circle
 * with the specified radius at the specified X coordinate, accounting for
 * edge conditions on the grid.
 *
 * \param x The X coordinate of the point.
 * \param radius The radius of the circle to apply.
 * \param xsize The size of the grid in X.
 *
 * \return A pair containing the upper/lower X coordinates of the circle when
 * applied to the specified X coordinate.
 */
static inline circle_range_ret_type circle_xrange_at_point(size_t x,
                                                    size_t radius,
                                                    size_t xsize) {
  auto lower_x = static_cast<index_range::index>(std::max<int>(0,
                                                               static_cast<int>(x) - static_cast<int>(radius)));
  auto upper_x = static_cast<index_range::index>(std::min(x + radius + 1,
                                                          xsize - 1));
  if (lower_x > upper_x) {
    lower_x = upper_x - 1;
  }
  return circle_range_ret_type(lower_x, upper_x);
}

/**
 * \brief Get the range in the Y direction resulting from applying a circle
 * with the specified radius at the specified Y coordinate, accounting for
 * edge conditions on the grid.
 *
 * \param y The Y coordinate of the point.
 * \param radius The radius of the circle to apply.
 * \param ysize The size of the grid in Y.
 *
 * \return A pair containing the upper/lower Y coordinates of the circle when
 * applied to the specified Y coordinate.
 */
static inline circle_range_ret_type circle_yrange_at_point(size_t y,
                                                           size_t radius,
                                                           size_t ysize) {
  auto lower_y = static_cast<index_range::index>(std::max<int>(static_cast<int>(0),
                                                               static_cast<int>(y) - static_cast<int>(radius)));
  auto upper_y = static_cast<index_range::index>(std::min(y + radius + 1,
                                                          ysize - 1));
  if (lower_y > upper_y) {
    lower_y = upper_y - 1;
  }
  return circle_range_ret_type(lower_y, upper_y);
}

NS_END(detail, ds, rcppsw);

#endif /* INCLUDE_RCPPSW_DS_UTILS_HPP_ */
