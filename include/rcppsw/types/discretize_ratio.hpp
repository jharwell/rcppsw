/**
 * \file discretize_ratio.hpp
 *
 * \copyright 2019 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_TYPES_DISCRETIZE_RATIO_HPP_
#define INCLUDE_RCPPSW_TYPES_DISCRETIZE_RATIO_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rcppsw/types/named_type.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, types);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * \class discretize_ratio
 * \ingroup types
 *
 * \brief Specifies the ratio of discretized space to real space, and therefore
 * should always be <= 1.0.
 */
using discretize_ratio = named_type<double, struct discretize_ratio_tag>;

NS_END(types, rcppsw);

#endif /* INCLUDE_RCPPSW_TYPES_DISCRETIZE_RATIO_HPP_ */
