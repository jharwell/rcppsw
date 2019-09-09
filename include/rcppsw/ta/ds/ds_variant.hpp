/**
 * @file ds_variant.hpp
 *
 * @copyright 2019 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_TA_DS_DS_VARIANT_HPP_
#define INCLUDE_RCPPSW_TA_DS_DS_VARIANT_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <boost/variant.hpp>

#include "rcppsw/common/common.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, ta, ds);
class bi_tdgraph;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
using ds_variant = boost::variant<bi_tdgraph>;

NS_END(ds, ta, rcppsw);

#endif /* INCLUDE_RCPPSW_TA_DS_DS_VARIANT_HPP_ */
