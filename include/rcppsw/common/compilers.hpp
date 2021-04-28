/**
 * \file compilers.hpp
 *
 * \copyright 2021 John Harwell, All rights reserved.
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

#ifndef INCLUDE_RCPPSW_COMMON_COMPILERS_HPP_
#define INCLUDE_RCPPSW_COMMON_COMPILERS_HPP_

/*******************************************************************************
 * Includes
 ******************************************************************************/

/*******************************************************************************
 * Macros
 ******************************************************************************/
/**
 * \def RCPPSW_NODISCARD
 *
 * Mark a function result as no-discard, so that a compiler warning is issued if
 * this happens.
 */

#define RCPPSW_NODISCARD [[nodiscard]]

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/


#endif /* INCLUDE_RCPPSW_COMMON_COMPILERS_HPP_ */
