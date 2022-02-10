/**
 * \file er.hpp
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

#ifndef INCLUDE_RCPPSW_ER_ER_HPP_
#define INCLUDE_RCPPSW_ER_ER_HPP_

/*******************************************************************************
 * Macros

 ******************************************************************************/
/*
 * If rcppsw is used in a context where this is not defined it is almost
 * assuredly an error.
 */
#if !defined(LIBRA_ER)
#error LIBRA_ER not defined--defaulting to ER_NONE
#endif

#if defined(LIBRA_ER_INHERIT) && !defined(LIBRA_ER)
#error LIBRA_ER_INHERIT but LIBRA_ER not defined
#endif

#define RCPPSW_ER LIBRA_ER

#define LIBRA_ER_NONE  0 /* No event reporting */
#define LIBRA_ER_FATAL 1 /* Fatal events only */
#define LIBRA_ER_ALL   2 /* All event reporting  */

#define RCPPSW_ER_NONE  LIBRA_ER_NONE
#define RCPPSW_ER_FATAL LIBRA_ER_FATAL
#define RCPPSW_ER_ALL   LIBRA_ER_ALL

/*
 * Size of buffers to put on stack for creating debug strings.
 */
#define RCPPSW_ER_MSG_LEN_MAX 1000
#define RCPPSW_ER_FATAL_MSG_LEN_MAX 10000

#endif /* INCLUDE_RCPPSW_ER_ER_HPP_ */
