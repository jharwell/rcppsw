/**
 * \file range.hpp
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

#pragma once

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/math/range.hpp"
#include "rcppsw/spatial/euclidean_dist.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
namespace rcppsw::spatial {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \typedef range
 * \ingroup spatial
 *
 * \brief A \ref rmath::range<T> of \ref rspatial::euclidean_dist.
 */
using erange = math::range<spatial::euclidean_dist>;

} /* namespace rcppsw::spatial */
