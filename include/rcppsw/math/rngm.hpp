/**
 * @file rngm.hpp
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

#ifndef INCLUDE_RCPPSW_MATH_RNGM_HPP_
#define INCLUDE_RCPPSW_MATH_RNGM_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <map>
#include <string>
#include <memory>

#include "rcppsw/common/common.hpp"
#include "rcppsw/patterns/prototype/caching_factory.hpp"
#include "rcppsw/patterns/singleton/singleton.hpp"

/*******************************************************************************
 * Namespaces/Decls
 ******************************************************************************/
NS_START(rcppsw, math);
class rng;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @class rngm
 * @ingroup rcppsw math
 *
 * @brief Random Number Generator (RNG) Manager. A caching factory that
 * returns references to previously created objects rather than creating new
 * objects each time like a regular factory.
 */
class rngm : public patterns::prototype::caching_factory<rng, uint>,
             public patterns::singleton::singleton<rngm> {};

NS_END(math, rcppsw);

#endif /* INCLUDE_RCPPSW_MATH_RNGM_HPP_ */
